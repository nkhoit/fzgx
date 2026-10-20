#include "types.h"
#include "rel/main_rel/globals.h"
#include "psvec.h"
#include "dolphin/hw_regs.h"

typedef struct {
    f32 x, y, z;
} Vec;

typedef f32 Mtx[3][4];

/* the matrix the math library keeps in the locked cache */
#define LC_MTX (*(Mtx *)LC_BASE)

typedef struct {
    u32 flags;
    u32 mask;
    u8 pad_8[0x4];
    Vec pos;
    s16 rot_x;
    s16 rot_y;
    s16 rot_z;
    u8 pad_1E[0x2];
    Vec scale;
    u8 pad_2C[0x14];
} TowObj;

/* the camera-facing objects and search lights */
typedef struct {
    s32 count;
    s32 light_count;
    TowObj *model;
    TowObj *models[16];
    s32 flags[16];
    Vec pos[4];        /* 0x8C */
    Vec front[4];      /* 0xBC */
    Vec up[4];         /* 0xEC */
    Mtx mtx[4];        /* 0x11C */
    Vec target[4];     /* 0x1DC */
    Vec dir[4];        /* 0x20C */
    Mtx view[4];       /* 0x23C */
    Mtx lights[16];    /* 0x2FC */
} TowSub;

/* the window objects */
typedef struct {
    s32 count;
    TowObj *objs[64];
    s32 counter[64];
    f32 timer[64];
    f32 progress[64];
    f32 cooldown[64];
    Mtx mtx[64];
    u32 unk_1104;
    TowSub sub;
} TowWork;

extern u32 lbl_801A63C0;
extern Mtx *lbl_801A6D00;
extern void OSPanic(const char *, int, const char *, ...);
extern void fn_80008BEC(void *dst, u32 value, u32 size);
extern void fn_80072558(void);
extern void fn_8006F1F0(Vec *, Vec *, Vec *);
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006D784(void *);
extern void lbl_8006D7DC(void *);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006DB74(void *);
extern void lbl_8006DD7C(void);
extern void lbl_8006DFC4(void *);
extern void lbl_8006DFE8(void *);
extern void lbl_8006E0A4(void *);
extern void lbl_8006E0C8(void *);
extern void lbl_8006E13C(void *);
extern void mathutil_mtxA_rotate_x(s16);
extern void mathutil_mtxA_rotate_y(s16);
extern void mathutil_mtxA_rotate_z(s16);
extern s16 camera_get_mode(void);
extern s32 fn_1_58C4(void);
extern s32 fn_1_5910(void);
extern void fn_1_5948(s32);
extern void fn_1_627C(s32);
extern void fn_1_55210(void *);
extern void fn_1_560F0(s32, void *);
extern void fn_1_862D4(s32, Vec *);
extern void fn_1_8636C(s32, Mtx *);
extern void fn_1_869B0(s32, Vec *);
extern void fn_1_9A508(void);
extern void fn_1_9AD54(void);
extern void fn_1_9AD88(void);
extern void fn_1_9BBE4(TowObj *, u32, u32, void *);
extern void fn_1_9D260(void);

void fn_1_153AF8(u32 *entries);
void fn_1_153B24(TowWork *work);
void fn_1_153C60(u8 *base);
void fn_1_153D48(TowWork *work);
void fn_1_153D74(TowWork *work);
void fn_1_1540B0(TowWork *work);
void fn_1_154164(TowWork *work, const Vec *pos, void *view, s32 all);

static inline s32 tow_rand(void) {
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    return (lbl_801A63C0 >> 16) & 0x7FFF;
}

/* fzgx:begin fn_1_153988 */
void fn_1_153988(void) {
}
/* fzgx:end fn_1_153988 */

/* fzgx:begin fn_1_15398C */
// Prepares the shared background object and advances the background system.
void fn_1_15398C(void) {
    TowWork *work = (TowWork *)lbl_1_data_2A7E0.unk_3C;
    fn_1_153AF8((u32 *)&work->count);
    fn_1_153D48(work);
    fn_1_9A508();
}
/* fzgx:end fn_1_15398C */

/* fzgx:begin fn_1_1539D0 */
void fn_1_1539D0(void) {
    int count = fn_1_58C4();
    int i;
    for (i = 0; i < count; i++) {
        fn_1_5948(i);
        fn_1_627C(i);
    }
}
/* fzgx:end fn_1_1539D0 */

/* fzgx:begin fn_1_153A28 */
void fn_1_153A28(void) {
    TowWork *work;
    int count;
    int i;

    work = (TowWork *)lbl_1_data_2A7E0.unk_3C;
    fn_1_9D260();
    fn_1_9AD54();
    count = fn_1_58C4();
    for (i = 0; i < count; i++) {
        fn_1_5948(i);
        fn_1_153D74(work);
        fn_1_627C(i);
    }
    fn_1_153B24(work);
}
/* fzgx:end fn_1_153A28 */

/* fzgx:begin fn_1_153AAC */
void fn_1_153AAC(void) {
}
/* fzgx:end fn_1_153AAC */

/* fzgx:begin fn_1_153AB0 */
void fn_1_153AB0(void) {
    TowWork *work = (TowWork *)lbl_1_data_2A7E0.unk_3C;
    fn_1_153C60((u8 *)work);
    fn_1_1540B0(work);
    fn_1_9AD88();
}
/* fzgx:end fn_1_153AB0 */

/* fzgx:begin fn_1_153AF4 */
void fn_1_153AF4(void) {
}
/* fzgx:end fn_1_153AF4 */

/* fzgx:begin fn_1_153AF8 */
// Clears the first entry and any following entries selected by its count.
void fn_1_153AF8(u32 *entries) {
    u32 *current = entries;
    int index = 0;
    entries[0] = 0;
    while (index < (int)entries[0]) {
        *++current = 0;
        index++;
    }
}
/* fzgx:end fn_1_153AF8 */

/* fzgx:begin fn_1_153B24 */
// Animates the window lights: each one flickers down its column and restarts.
void fn_1_153B24(TowWork *work) {
    f32 base;
    f32 prod;
    s32 i;

    for (i = 0; i < work->count; i++) {
        work->timer[i] -= 0.15f;
        if (work->timer[i] <= -0.95f) {
            work->counter[i]++;
            work->timer[i] = 0.031f;
        }

        base = 0.005f;
        prod = -0.032f * (f32)work->counter[i];
        work->progress[i] = base + prod;

        if (work->progress[i] <= -0.923f) {
            work->timer[i] = -0.95f;
            work->progress[i] = -0.923f;
            work->counter[i] = (s32)((work->progress[i] - 0.005f) / -0.032f);
        }

        if (work->progress[i] == -0.923f) {
            work->cooldown[i] -= -0.032f;
            if (work->cooldown[i] > 1.0f) {
                work->cooldown[i] = 0.0f;
                work->timer[i] = 0.031f;
                work->progress[i] = 0.005f;
                work->counter[i] = (s32)((work->progress[i] - 0.005f) / -0.032f);
            }
        }
    }
}
/* fzgx:end fn_1_153B24 */

/* fzgx:begin fn_1_153C60 */
void fn_1_153C60(u8 *base) {
    u8 *entry;
    u8 *slot;
    s32 i;
    u8 *obj;
    u8 work0[0x30];
    u8 work1[0x30];

    entry = base;
    slot = base;
    i = 0;

    while (i < *(s32 *)base) {
        obj = *(u8 **)(entry + 4);
        {
            u32 value = *(u32 *)(obj + 4);

            if ((value + 0x10000) == 0xffff || (value & lbl_1_data_2A7E0.unk_50) != 0) {
                lbl_8006DFE8(slot + 0x504);
                lbl_8006E13C(obj + 0x20);
                lbl_8006E0A4((u8 *)*(void **)(base + 0x1104) + 8);
                fn_80072558();
                lbl_8006D784(work0);
                *(f32 *)(work0 + 0xC) = *(f32 *)(entry + 0x204);
                *(f32 *)(work0 + 0x1C) = *(f32 *)(entry + 0x304);
                fn_1_560F0(0, work0);
                lbl_8006D784(work1);
                *(f32 *)(work1 + 0x1C) = *(f32 *)(entry + 0x404);
                fn_1_560F0(1, work1);
                fn_1_55210(*(void **)(base + 0x1104));
            }
        }

        entry += 4;
        slot += 0x30;
        i++;
    }
}
/* fzgx:end fn_1_153C60 */

/* fzgx:begin fn_1_153D48 */
// Clears the search-light work area.
void fn_1_153D48(TowWork *work) {
    fn_80008BEC(&work->sub, 0, sizeof(TowSub));
}
/* fzgx:end fn_1_153D48 */

/* fzgx:begin fn_1_153D74 */
// Points each camera's search light at a spot ahead of the camera and eases it there.
void fn_1_153D74(TowWork *work_) {
    TowSub *work = &work_->sub;
    s32 count;
    s32 i;
    s32 mode;
    f32 len;
    f32 dist;
    f32 height;
    f32 rate;
    f32 max;
    f32 dx;
    f32 dy;
    f32 dz;
    Vec eye;
    Vec delta;

    if (work->model == NULL) {
        return;
    }
    count = fn_1_58C4();
    dist = 200.0f;
    height = 50.0f;
    rate = 0.1f;
    max = 5.0f;
    for (i = 0; i < count; i++) {
        fn_1_5948(i);
        mode = camera_get_mode();
        if (mode == -1) {
            eye = (Vec){0.0f, 0.0f, 0.0f};
            work->front[i] = (Vec){0.0f, 0.0f, 1.0f};
            work->up[i] = (Vec){0.0f, 1.0f, 0.0f};
            work->dir[i] = (Vec){0.0f, 0.0f, 1.0f};
            work->target[i] = (Vec){0.0f, 0.0f, 0.0f};
            lbl_8006D784(&work->mtx[i]);
            lbl_8006D784(&work->view[i]);
        } else {
            lbl_8006DAEC();
            fn_1_862D4(mode, &eye);
            fn_1_8636C(mode, lbl_801A6D00);
            LC_MTX[0][3] = 0.0f;
            LC_MTX[1][3] = 0.0f;
            LC_MTX[2][3] = 0.0f;
            work->front[i].x = -(*lbl_801A6D00)[0][2];
            work->front[i].y = -(*lbl_801A6D00)[1][2];
            work->front[i].z = -(*lbl_801A6D00)[2][2];
            work->up[i].x = (*lbl_801A6D00)[0][1];
            work->up[i].y = (*lbl_801A6D00)[1][1];
            work->up[i].z = (*lbl_801A6D00)[2][1];
            lbl_8006DB74(&work->mtx[i]);
            fn_1_869B0(mode, &work->dir[i]);
            fn_8006F1F0(&eye, &work->up[i], &work->pos[i]);
            LC_MTX[0][3] = 0.0f;
            LC_MTX[1][3] = 0.0f;
            LC_MTX[2][3] = 0.0f;
            lbl_8006DD7C();
            lbl_8006DB74(&work->view[i]);
            lbl_8006DB30();
        }
        work->target[i].x = eye.x + (f32)(work->dir[i].x * dist) + (f32)(work->up[i].x * height);
        work->target[i].y = eye.y + (f32)(work->dir[i].y * dist) + (f32)(work->up[i].y * height);
        work->target[i].z = eye.z + (f32)(work->dir[i].z * dist) + (f32)(work->up[i].z * height);
        dx = rate * (work->target[i].x - work->pos[i].x);
        dy = rate * (work->target[i].y - work->pos[i].y);
        dz = rate * (work->target[i].z - work->pos[i].z);
        delta.x = dx;
        delta.y = dy;
        delta.z = dz;
        len = dx * dx;
        len = dy * dy + len;
        len = dz * dz + len;
        len = lbl_8006D0B4(len);
        if (len > max) {
            len = max / len;
            delta.x *= len;
            delta.y *= len;
            delta.z *= len;
        }
        psvec_add(&work->pos[i], &delta, &work->pos[i]);
    }
}
/* fzgx:end fn_1_153D74 */

/* fzgx:begin fn_1_1540B0 */
void fn_1_1540B0(TowWork *work) {
    u8 *table;
    s32 i;
    TowSub *sub;

    sub = &work->sub;
    {
        s32 slot;
        slot = fn_1_5910();
        fn_1_154164(work, (Vec *)((u8 *)sub + slot * 0xc + 0x8c), (u8 *)sub + slot * 0x30 + 0x23c, 0);
    }

    table = (u8 *)sub;
    for (i = 0; i < sub->light_count; i++) {
        Vec zero = {0.0f, 0.0f, 0.0f};
        fn_1_154164(work, &zero, table + 0x2fc, 1);
        table += 0x30;
    }
}
/* fzgx:end fn_1_1540B0 */

/* fzgx:begin fn_1_154164 */
// Draws the search-light model and every camera-facing object relative to `pos`.
void fn_1_154164(TowWork *work_, const Vec *pos, void *view, s32 all) {
    s32 i;
    TowSub *work = &work_->sub;
    TowObj objs[17];
    Mtx mtx;

    if (work->model == NULL) {
        return;
    }
    objs[0] = *work->model;
    objs[0].flags &= ~0x80000000;
    psvec_add(&objs[0].pos, pos, &objs[0].pos);
    lbl_8006D7DC(&objs[0].pos);
    lbl_8006DFC4(view);
    lbl_8006E13C(&objs[0].scale);
    lbl_8006DB74(&mtx);
    fn_1_9BBE4(&objs[0], 0, 0, &mtx);
    for (i = 0; i < work->count; i++) {
        if (all == 0 && work->flags[i] != 0) {
            continue;
        }
        objs[i + 1] = *work->models[i];
        objs[i + 1].flags &= ~0x80000000;
        psvec_add(&objs[i + 1].pos, pos, &objs[i + 1].pos);
        lbl_8006D7DC(&objs[0].pos);
        lbl_8006DFC4(view);
        lbl_8006E0C8(&objs[0].pos);
        lbl_8006E0A4(&objs[i + 1].pos);
        mathutil_mtxA_rotate_z(objs[i + 1].rot_z);
        mathutil_mtxA_rotate_y(objs[i + 1].rot_y);
        mathutil_mtxA_rotate_x(objs[i + 1].rot_x);
        lbl_8006E13C(&objs[i + 1].scale);
        lbl_8006DB74(&mtx);
        fn_1_9BBE4(&objs[i + 1], 0, 0, &mtx);
    }
}
/* fzgx:end fn_1_154164 */

/* fzgx:begin fn_1_1543E8 */
u32 fn_1_1543E8(s32 value, u32 *source) {
    TowWork *work = (TowWork *)lbl_1_data_2A7E0.unk_3C;

    switch (value) {
    case 0:
        work->unk_1104 = *source;
        break;
    default:
        break;
    }

    return 1;
}
/* fzgx:end fn_1_1543E8 */


/* fzgx:begin fn_1_154410 */
// Registers a tow background object with the stage work area by kind.
s32 fn_1_154410(s32 kind, TowObj *obj) {
    TowWork *work = (TowWork *)lbl_1_data_2A7E0.unk_3C;

    switch (kind) {
    case 0:
        obj->flags |= 0x80000000;
        work->objs[work->count] = obj;
        work->timer[work->count] = -0.95f + (f32)(0.981f * ((f32)tow_rand() / 32767.0f));
        work->progress[work->count] = 0.005f + (f32)(-0.928f * ((f32)tow_rand() / 32767.0f));
        work->counter[work->count] = (s32)((work->progress[work->count] - 0.005f) / -0.032f);
        work->cooldown[work->count] = 0.0f;
        lbl_8006D7DC(&obj->pos);
        mathutil_mtxA_rotate_z(obj->rot_z);
        mathutil_mtxA_rotate_y(obj->rot_y);
        mathutil_mtxA_rotate_x(obj->rot_x);
        lbl_8006DB74(work->mtx[work->count]);
        work->count++;
        if (work->count >= 64) {
            OSPanic("bg_tow.c", 0x1E2, "WINDOW NUM OVER!");
        }
        break;
    case 1:
        obj->flags |= 0x80000000;
        work->sub.model = obj;
        break;
    case 2:
    case 3:
    case 5: {
        TowSub *sub = &work->sub;
        obj->flags |= 0x80000000;
        sub->models[sub->count] = obj;
        if (kind == 5) {
            sub->flags[sub->count] = 1;
        } else {
            sub->flags[sub->count] = 0;
        }
        sub->count++;
        if (sub->count >= 16) {
            OSPanic("bg_tow.c", 0x1FE, "BG_TOW_SEARCH OTHER NUM OVER\n");
        }
        break;
    }
    case 4: {
        TowSub *sub = &work->sub;
        lbl_8006D7DC(&obj->pos);
        mathutil_mtxA_rotate_z(obj->rot_z);
        mathutil_mtxA_rotate_y(obj->rot_y);
        mathutil_mtxA_rotate_x(obj->rot_x);
        lbl_8006DB74(sub->lights[sub->light_count]);
        sub->light_count++;
        if (sub->light_count >= 16) {
            OSPanic("bg_tow.c", 0x20F, "BG_TOW_SCAMPOINT01 NUM OVER!");
        }
        break;
    }
    }
    return 1;
}
/* fzgx:end fn_1_154410 */
