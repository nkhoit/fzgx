#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_tow.h"

extern void fn_1_B9BE0(void);
extern void fn_1_B9DE8(Obj_1_bss_8EDA4 *arg0);
extern void fn_1_48418(s32 arg0);
extern void fn_1_159440(s32 arg0, s32 arg1);
extern u8 lbl_1_bss_8EDA0;
extern s32 fn_1_BA144(Obj_1_bss_8EDA4 *arg0);
extern void fn_1_1596DC(s32 arg0);
extern void fn_1_484CC(s32 arg0);
extern void fn_1_BC310(Obj_1_bss_8EDA4 *arg0);
extern void fn_1_C0510(u32 *arg0, u32 arg1, u32 arg2);
extern u32 fn_1_426C(u32);
extern u32 fn_1_46B4(u32, u32, u32, u32);
extern u32 fn_1_B9C0C(void);
extern u32 lbl_801A6410;

/* fzgx:begin fn_1_154410 */
#include "types.h"

extern void lbl_8006D7DC(void *);
extern void mathutil_mtxA_rotate_z(s16);
extern void mathutil_mtxA_rotate_y(s16);
extern void mathutil_mtxA_rotate_x(s16);
extern void lbl_8006DB74(void *);
extern void OSPanic(const char *, int, const char *, ...);
extern u32 lbl_801A63C0;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.15000000596046448f;
    s = -0.949999988079071f;
    s = 0.03099999949336052f;
    s = 0.004999999888241291f;
    s = -0.03200000151991844f;
    s = -0.9229999780654907f;
    s = 1.0f;
    s = 0.0f;
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table2[22] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x00000000, 0x43480000, 0x42480000, 0x3DCCCCCD, 0x40A00000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

typedef struct {
    u32 flags;
    u8 pad_4[0x8];
    f32 pos[3];
    s16 rot_x;
    s16 rot_y;
    s16 rot_z;
} TowObj;

typedef struct {
    s32 count;
    s32 mtx_count;
    TowObj *unk_8;
    TowObj *objs[16];
    s32 flags[16];
    u8 pad_8C[0x270];
    f32 mtx[16][12];
} TowSub;

typedef struct {
    s32 count;
    TowObj *objs[64];
    s32 unk_104[64];
    f32 unk_204[64];
    f32 unk_304[64];
    f32 unk_404[64];
    f32 mtx[64][12];
    u32 unk_1104;
    TowSub sub;
} TowWork;

static inline s32 tow_rand(void) {
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    return (lbl_801A63C0 >> 16) & 0x7FFF;
}

// Registers a tow background object with the stage work area by kind.
s32 fn_1_154410(s32 kind, TowObj *obj) {
    TowWork *work = (TowWork *)lbl_1_data_2A7E0.unk_3C;

    switch (kind) {
    case 0:
        obj->flags |= 0x80000000;
        work->objs[work->count] = obj;
        work->unk_204[work->count] = -0.95f + (f32)(0.981f * ((f32)tow_rand() / 32767.0f));
        work->unk_304[work->count] = 0.005f + (f32)(-0.928f * ((f32)tow_rand() / 32767.0f));
        work->unk_104[work->count] = (s32)((work->unk_304[work->count] - 0.005f) / -0.032f);
        work->unk_404[work->count] = 0.0f;
        lbl_8006D7DC(obj->pos);
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
        work->sub.unk_8 = obj;
        break;
    case 2:
    case 3:
    case 5: {
        TowSub *sub = &work->sub;
        obj->flags |= 0x80000000;
        sub->objs[sub->count] = obj;
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
        lbl_8006D7DC(obj->pos);
        mathutil_mtxA_rotate_z(obj->rot_z);
        mathutil_mtxA_rotate_y(obj->rot_y);
        mathutil_mtxA_rotate_x(obj->rot_x);
        lbl_8006DB74(sub->mtx[sub->mtx_count]);
        sub->mtx_count++;
        if (sub->mtx_count >= 16) {
            OSPanic("bg_tow.c", 0x20F, "BG_TOW_SCAMPOINT01 NUM OVER!");
        }
        break;
    }
    }
    return 1;
}
/* fzgx:end fn_1_154410 */

/* fzgx:begin fn_1_154708 noprologue */
#include "types.h"

struct fn_1_154708_lbl_1_data_49A18 {
    u8 pad_0[0x90];
    u32 unk_90;
    u32 unk_94;
    u32 unk_98;
    u32 unk_9C;
};
struct fn_1_154708_lbl_1_bss_8ED90 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u8 unk_10;
};

extern struct fn_1_154708_lbl_1_bss_8ED90 lbl_1_bss_8ED90;
extern struct fn_1_154708_lbl_1_data_49A18 lbl_1_data_49A18;
extern u32 fn_1_3F8C(u32, u32, u32, u32);
extern u32 fn_1_435C(u32);
extern u32 fn_1_B9BE0(u32);
extern void fn_1_154798(void);

void fn_1_154708(u32 arg0) {
    struct fn_1_154708_lbl_1_bss_8ED90 *p_lbl_1_bss_8ED90;
    u32 t1;
    p_lbl_1_bss_8ED90 = (struct fn_1_154708_lbl_1_bss_8ED90 *)&lbl_1_bss_8ED90;
    p_lbl_1_bss_8ED90->unk_C = arg0;
{
    struct fn_1_154708_lbl_1_data_49A18 * p_lbl_1_data_49A18 = (struct fn_1_154708_lbl_1_data_49A18 *)&lbl_1_data_49A18;
    p_lbl_1_data_49A18->unk_90 = -1;
    fn_1_435C(arg0);
    t1 = fn_1_3F8C((u32)((u8 *)(u32)p_lbl_1_data_49A18 + 160), (u32)fn_1_154798, 0, 18);
    p_lbl_1_data_49A18->unk_90 = t1;
    p_lbl_1_data_49A18->unk_94 = -1;
    p_lbl_1_data_49A18->unk_98 = -1;
    p_lbl_1_data_49A18->unk_9C = -1;
}
    p_lbl_1_bss_8ED90->unk_10 = 0;
    p_lbl_1_bss_8ED90->unk_8 = 0;
    p_lbl_1_bss_8ED90->unk_0 = 0;
    p_lbl_1_bss_8ED90->unk_4 = 0;
    fn_1_B9BE0(t1);
}
/* fzgx:end fn_1_154708 */

/* fzgx:begin fn_1_1547FC */
#include "types.h"

struct fn_1_1547FC_lbl_1_data_49A18 {
    u8 pad_0[0x90];
    u32 unk_90;
    u32 unk_94;
    u32 unk_98;
    u32 unk_9C;
};
struct fn_1_1547FC_lbl_1_bss_8ED90 {
    u32 unk_0;
    u32 unk_4;
    u8 pad_8[0x4];
    u32 unk_C;
};

extern u32 fn_1_435C(u32);

s32 fn_1_1547FC(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    struct fn_1_1547FC_lbl_1_data_49A18 *p_lbl_1_data_49A18;
    struct fn_1_1547FC_lbl_1_bss_8ED90 *p_lbl_1_bss_8ED90;
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;
    s32 v5;
    u32 t0, t1, t2, t3;
    p_lbl_1_bss_8ED90 = (struct fn_1_1547FC_lbl_1_bss_8ED90 *)&(*(struct fn_1_1547FC_lbl_1_bss_8ED90 *)&lbl_1_bss_8ED90);
    p_lbl_1_data_49A18 = &(*(struct fn_1_1547FC_lbl_1_data_49A18 *)&lbl_1_data_49A18);
    t0 = fn_1_B9C0C();
    v0 = p_lbl_1_bss_8ED90->unk_0;
    v1 = t0;
    v2 = arg2;
    v3 = arg3;
    if (v0 != 0) {
    v2 = (u32)((u8 *)(u32)p_lbl_1_data_49A18 + 176);
    v1 = (u32)&lbl_801A6410;
    v3 = 115;
    v1 = *(u32 *)((u8 *)v1 + 0);
    t1 = fn_1_46B4(v1, v0, (u32)v2, v3);
    v1 = t1;
    p_lbl_1_bss_8ED90->unk_0 = 0;
    p_lbl_1_bss_8ED90->unk_4 = 0;
    }
    v4 = p_lbl_1_data_49A18->unk_90;
    p_lbl_1_data_49A18->unk_94 = -1;
    p_lbl_1_data_49A18->unk_98 = -1;
    p_lbl_1_data_49A18->unk_9C = -1;
    v5 = -1;
    if ((s32)v4 != -1) {
    v5 = p_lbl_1_bss_8ED90->unk_C;
    t2 = fn_1_435C(v5);
    v5 = t2;
    v5 = p_lbl_1_data_49A18->unk_90;
    t3 = fn_1_426C(v5);
    v5 = t3;
    v5 = 0;
    p_lbl_1_bss_8ED90->unk_C = v5;
    p_lbl_1_data_49A18->unk_90 = -1;
    }
    return v5;
}
/* fzgx:end fn_1_1547FC */

/* fzgx:begin fn_1_1548A8 */
#include "types.h"

// Initialize the tow settings and select the mode-dependent input value.
void fn_1_1548A8(void) {
    s16 mode;
    s16 *mode_ptr;
    Obj_1_bss_8EDA4 *obj;

    fn_1_B9BE0();
    fn_1_B9DE8(&lbl_1_bss_8EDA4);

    mode_ptr = (s16 *)&lbl_1_bss_960;
    obj = &lbl_1_bss_8EDA4;
    mode = *mode_ptr;
    obj->unk_0 = 0x20;
    if (mode == 0xc) {
        obj->unk_4 = 0xa;
    } else {
        obj->unk_4 = 9;
    }

    if (mode != 2) {
        fn_1_48418(2);
        fn_1_159440(2, 0);
    }

    lbl_1_data_49AB4.unk_0 = 1;
}
/* fzgx:end fn_1_1548A8 */

/* fzgx:begin fn_1_154930 */
void fn_1_154930(void) {
    s8 result;

    result = fn_1_BA144(&lbl_1_bss_8EDA4);
    if (result == 0) {
        lbl_1_data_49AB4.unk_0 = 2;
    } else if (result == 1) {
        lbl_1_data_49AB4.unk_0 = 4;
        lbl_1_bss_8EDA0 = 1;
        fn_1_1596DC(2);
        fn_1_484CC(2);
    } else {
        fn_1_BC310(&lbl_1_bss_8EDA4);
    }
}
/* fzgx:end fn_1_154930 */

/* fzgx:begin fn_1_1549B8 */
#include "types.h"

// Copy the tow state into the active settings and advance the tow mode.
void fn_1_1549B8(void) {
    u32 *src = &lbl_1_bss_8ED90;
    u32 *dst = src + 5;
    u32 first = src[0];
    u32 second = src[1];

    dst[2] = first;
    dst[3] = second;
    dst[4] = 5;
    fn_1_C0510(dst, second, first);
    lbl_1_data_49AB4.unk_0 = 3;
}
/* fzgx:end fn_1_1549B8 */

/* fzgx:begin fn_1_154C84 */
#include "types.h"

extern u32 lbl_1_data_49AB0;



s32 fn_1_154C84(void) {
    u32 v0;
    if ((s32)lbl_1_data_49AB0 == 4) {
    v0 = 0;
    return v0;
    }
    if ((s32)lbl_1_data_49AB0 != -1 || (s32)(*(u32 *)&lbl_1_data_49AB4) != -1) {
    v0 = 1;
    return v0;
    }
    v0 = 0;
    return v0;
}
/* fzgx:end fn_1_154C84 */
