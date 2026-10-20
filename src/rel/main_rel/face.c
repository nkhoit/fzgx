#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/face.h"

extern u32 lbl_801A6410;
extern u32 lbl_1_bss_7ACEC;
extern u32 fn_1_45D0(u32, u32, void*, u32);
extern u32 fn_80008F88(void*, u32);
extern void fn_80009064(u32);
extern void fn_1_46B4(u32, u32, u8*, int);
extern void fn_1_D2F50(void);
extern void fn_80071718(u32);
extern void fn_800711A8(u32);
extern void fn_1_D2F84(void);
extern s16 fn_1_3F0C8(void *obj);
extern u32 fn_1_864E8(u32 value);
extern void OSPanic(char*, ...);
extern u32 fn_1_86810(u32);
extern void qsort(void*, u32, u32, void*);
extern s32 fn_1_D2E18(u8*, u8*);
extern u32 lbl_1_bss_7AD00;
extern u32 lbl_1_bss_7AD04;
extern u32 lbl_1_bss_7AD08[7];
extern u32 lbl_1_bss_7AD24[9];
extern u32 lbl_801A6CE0;
extern u32 lbl_801A6CFC;
extern void* fn_1_48E8(u32, u32);
extern void OSLink(void*, void*);
extern void OSReport(char*, ...);

/* fzgx:begin fn_1_D1780 */
void fn_1_D1780(void) {
    u32 result;

    lbl_1_bss_7ACEC = 0x40000;
    result = fn_1_45D0(lbl_801A6410, 0x40000, lbl_1_data_3DA2C, 0x14a);
    lbl_1_bss_7ACF0 = result;
    lbl_1_data_3D924 = fn_80008F88((void*)result, result + lbl_1_bss_7ACEC);
}
/* fzgx:end fn_1_D1780 */

/* fzgx:begin fn_1_D17E8 */
void fn_1_D17E8(void) {
    fn_80009064(lbl_1_data_3D924);
    fn_1_46B4(lbl_801A6410, lbl_1_bss_7ACF0, lbl_1_data_3DA2C, 0x152);
    lbl_1_data_3D924 = -1;
}
/* fzgx:end fn_1_D17E8 */

/* fzgx:begin fn_1_D1848 pool noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/face.h"

extern u32 lbl_801A6410;
extern u32 fn_1_45D0(u32, u32, void*, u32);
extern u32 fn_1_4630(u32, u32, void*, u32);
extern u8 fn_1_86624(void);
extern void fn_1_D2F50(void);
extern void fn_1_D2F84(void);
extern u32 GXGetTexBufferSize(u16, u16, u32, u8, u8);
extern void *memset(void *, int, u32);

typedef struct {
    f32 x, y, z;
} Vec3_60A0;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u8 unk_C;
    u8 unk_D;
    u8 pad_E[0x2];
    s32 unk_10;
} State_7ACD8;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u8 pad_C[0x10];
    u32 unk_1C;
    u8 pad_20[0xC];
    Vec3_60A0 unk_2C;
    u8 pad_38[0x28];
    u32 unk_60;
} Ent;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_7ACD8;
u32 lbl_1_bss_7ACDC;
u32 lbl_1_bss_7ACE0;
u8 lbl_1_bss_7ACE0__fzgx_offset_4;
u8 fzgx_obj_lbl_1_bss_7ACE5;
u16 fzgx_pool_gap_bss_7ACE6;
s32 fzgx_obj_lbl_1_bss_7ACE8;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7ACD8;
    s = *(u8 *)&lbl_1_bss_7ACDC;
    s = *(u8 *)&lbl_1_bss_7ACE0;
    s = *(u8 *)&lbl_1_bss_7ACE0__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7ACE5;
    s = *(u8 *)&fzgx_pool_gap_bss_7ACE6;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7ACE8;
}
#pragma section code_type ".text"

extern void OSReport(const char *, ...);
#pragma section code_type ".fzgxpool"
static void fzgx_string_layout(void) {
    /* fzgx-allow: S2 layout primer: MWCC emits string literals in first-use order; the section is dropped at integration */
    OSReport("face.c");
}
#pragma section code_type ".text"

void fn_1_D1848(void) {
    u32 size;
    s32 i;
    Ent *obj;
    u8 c;

    
    fn_1_D2F50();
    fzgx_obj_lbl_1_bss_7ACD8 = fn_1_4630(lbl_801A6410, 600, "face.c", 0x15f);
    fzgx_obj_lbl_1_bss_7ACE8 = 0;
    c = fn_1_86624();
    lbl_1_bss_7ACE0__fzgx_offset_4 = c;
    lbl_1_bss_7ACDC = fn_1_4630(lbl_801A6410, c << 2, "face.c", 0x173);
    lbl_1_bss_7ACE0 = fn_1_4630(lbl_801A6410, lbl_1_bss_7ACE0__fzgx_offset_4 << 2, "face.c", 0x174);
    size = GXGetTexBufferSize(64, 64, 5, 0, 0);
    obj = (Ent *)fzgx_obj_lbl_1_bss_7ACD8;
    for (i = 0; i < 6; i++, obj++) {
        Vec3_60A0 v = {0.0f, 0.0f, 1.8f};
        obj->unk_2C = v;
        obj->unk_1C = 0;
        obj->unk_4 = 0xff;
        obj->unk_0 &= 0x7FFFFFFF;
        obj->unk_0 &= 0xBFFFFFFF;
        obj->unk_60 = fn_1_45D0(lbl_801A6410, size, "face.c", 0x18a);
        memset((void *)obj->unk_60, 0, 4);
    }
    fn_1_D2F84();
}
/* fzgx:end fn_1_D1848 */

/* fzgx:begin fn_1_D1C94 noprologue */
#include "types.h"

extern u32 lbl_1_data_3D924;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u8 unk_C;
    u8 unk_D;
    u8 pad_E[0x2];
    s32 unk_10;
} State_7ACD8;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u8 pad_C[0x4];
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u8 pad_20[0x18];
    u32 unk_38;
    u32 unk_3C;
    u8 pad_40[0x24];
} Ent;

extern State_7ACD8 lbl_1_bss_7ACD8;
extern u32 fn_1_864E8(s32);
extern s32 fn_1_D2E44(u32);
extern s8 fn_1_86690(s8);
extern s16 fn_1_12C7B8(s16);
extern s32 fn_1_D123C(u32);
extern s32 fn_1_3F440(u32);
extern void fn_1_D2F50(void);
extern void fn_1_D2F84(void);
extern void fn_80071718(u32);
extern void fn_800711A8(u32);

void fn_1_D1C94(void) {
    State_7ACD8 *p;
    Ent *obj;
    s32 count;
    u32 mask;
    s32 i;
    s32 n;

    p = (State_7ACD8 *)&lbl_1_bss_7ACD8;
    if ((s32)lbl_1_data_3D924 != -1) {
        fn_1_D2F50();
        if (p->unk_10 != 0) {
            u8 c = p->unk_C;
            p->unk_D = c;
            if (c > 4) {
                p->unk_D = 4;
            }
        } else {
            p->unk_D = 0;
            mask = 0x20000880;
            n = 0;
            while ((u32)n < p->unk_C) {
                if ((fn_1_864E8(n) & mask) == 0) {
                    p->unk_D++;
                }
                n++;
            }
            if (p->unk_D > 6) {
                p->unk_D = 6;
            }
        }

        obj = (Ent *)p->unk_0;
        i = 0;
        while ((u32)i < p->unk_D) {
            if (obj == 0) {
                fn_1_D2F84();
                return;
            }
            if (obj->unk_4 != 0xff) {
                u32 off = (obj->unk_4 & 0xFF) << 2;
                obj->unk_4 = obj->unk_4;
                if (*(u32 *)(p->unk_8 + off) != 0) {
                    fn_80071718(*(u32 *)(p->unk_8 + off));
                    *(u32 *)(p->unk_8 + off) = 0;
                }
                if (*(u32 *)(p->unk_4 + off) != 0) {
                    fn_800711A8(*(u32 *)(p->unk_4 + off));
                    *(u32 *)(p->unk_4 + off) = 0;
                }
            }
            i++;
            obj++;
        }

        count = 0;
        if (p->unk_10 != 0) {
            i = 0;
            obj = (Ent *)p->unk_0;
            while ((u32)i < p->unk_D) {
                u32 res = fn_1_D2E44(i);
                if (obj == 0) {
                    fn_1_D2F84();
                    return;
                }
                if ((u32)count <= (u32)(p->unk_D - 1)) {
                    u32 v = res & 0xFF;
                    obj->unk_10 = v;
                    obj->unk_14 = v;
                    obj->unk_18 = i;
                    obj->unk_4 = i;
                    obj->unk_8 = (s16)fn_1_12C7B8(fn_1_86690((s8)i));
                    obj->unk_3C = 0;
                    obj->unk_38 = 0;
                    obj->unk_1C = 20;
                    if (fn_1_D123C(obj->unk_4 & 0xFF) != 0) {
                        obj->unk_0 &= 0x7FFFFFFF;
                    } else {
                        obj->unk_0 |= 0x80000000;
                    }
                    count++;
                    obj++;
                }
                i++;
            }
        } else {
{
    s32 fzgx_loop_i_3321;
            obj = (Ent *)p->unk_0;
            fzgx_loop_i_3321 = 0;
            while ((u32)fzgx_loop_i_3321 < p->unk_C) {
                u32 res = fn_1_D2E44(fzgx_loop_i_3321);
                s32 lim;
                if (obj == 0) {
                    fn_1_D2F84();
                    return;
                }
                lim = p->unk_D - 1;
                if ((s32)(res & 0xFF) <= lim && (u32)count <= (u32)lim) {
                    u32 v = res & 0xFF;
                    obj->unk_10 = v;
                    obj->unk_14 = v;
                    obj->unk_18 = fn_1_3F440(res);
                    obj->unk_4 = fzgx_loop_i_3321;
                    obj->unk_8 = (s16)fn_1_12C7B8(fn_1_86690((s8)fzgx_loop_i_3321));
                    obj->unk_3C = 0;
                    obj->unk_38 = 0;
                    obj->unk_1C = 20;
                    if (fn_1_D123C(obj->unk_4 & 0xFF) != 0) {
                        obj->unk_0 &= 0x7FFFFFFF;
                    } else {
                        obj->unk_0 |= 0x80000000;
                    }
                    count++;
                    obj++;
                }
                fzgx_loop_i_3321++;
            }
    i = fzgx_loop_i_3321;
}
        }
        fn_1_D2F84();
    }
}
/* fzgx:end fn_1_D1C94 */

/* fzgx:begin fn_1_D1F88 */
void fn_1_D1F88(void) {
    Obj_1_bss_7ACD8_Target* state;
    s32 i;
    Obj_1_bss_7ACD8_Target* obj;
    u32 index;

    state = (Obj_1_bss_7ACD8_Target*)&lbl_1_bss_7ACD8;
    if ((s32)lbl_1_data_3D924 != -1) {
        fn_1_D2F50();
        i = 0;
        obj = (Obj_1_bss_7ACD8_Target*)state->unk_0;
        for (; i < 6; i++, obj = (Obj_1_bss_7ACD8_Target*)((u8*)obj + 0x64)) {
            if (obj->unk_60 != 0) {
                fn_1_46B4(lbl_801A6410, obj->unk_60, lbl_1_data_3DA2C, 0x271);
                obj->unk_60 = 0;
            }
            if (i < *(u8*)((u8*)state + 0xD)) {
                index = (obj->unk_4 & 0xFF) << 2;
                if (*(u32*)(state->unk_8 + index) != 0) {
                    fn_80071718(*(u32*)(state->unk_8 + index));
                    *(u32*)(state->unk_8 + index) = 0;
                }
                if (*(u32*)(state->unk_4 + index) != 0) {
                    fn_800711A8(*(u32*)(state->unk_4 + index));
                    *(u32*)(state->unk_4 + index) = 0;
                }
            }
        }
        if (state->unk_4 != 0) {
            fn_1_46B4(lbl_801A6410, state->unk_4, lbl_1_data_3DA2C, 0x277);
            state->unk_4 = 0;
        }
        if (state->unk_8 != 0) {
            fn_1_46B4(lbl_801A6410, state->unk_8, lbl_1_data_3DA2C, 0x278);
            state->unk_8 = 0;
        }
        if (state->unk_0 != 0) {
            fn_1_46B4(lbl_801A6410, state->unk_0, lbl_1_data_3DA2C, 0x27B);
            state->unk_0 = 0;
        }
        fn_1_D2F84();
    }
}
/* fzgx:end fn_1_D1F88 */

/* fzgx:begin fn_1_D2110 */
extern u16 fn_1_584AC(void);

typedef struct {
    f32 x, y, z;
} FaceVec;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u8 pad_C[0x14];
    FaceVec unk_20;
    FaceVec unk_2C;
    u32 unk_38;
    u32 unk_3C;
} FaceEnt;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile FaceVec v = {0.0f, 0.0f, 1.8f};  /* fzgx-allow: S2 pool primer sinks */
}
#pragma section code_type ".text"

void fn_1_D2110(FaceEnt *obj) {
    f32 z;
    f32 y;
    f32 x;
    f32 scale;
    FaceVec d = {0.0f, 0.0f, 0.0f};

    if (obj->unk_3C != 0) {
        if (obj->unk_3C > 35 && obj->unk_3C < 40) {
            d.y = 0.08f;
        }
        if (obj->unk_3C > 25 && obj->unk_3C < 30) {
            d.y = 0.08f;
        }
        if (obj->unk_3C < 20) {
            d.y = 0.08f;
        }
    }
    obj->unk_2C.x += d.x;
    obj->unk_2C.y -= d.y;
    obj->unk_2C.z -= d.z;
    if (obj->unk_3C != 0) {
        obj->unk_2C.x += (f64)(0.1 * (0.0f - obj->unk_2C.x));
        obj->unk_2C.y += (f64)(0.1 * (0.0f - obj->unk_2C.y));
        obj->unk_2C.z += (f64)(0.1 * (1.8f - obj->unk_2C.z));
    } else if (obj->unk_38 != 0) {
        scale = (f32)obj->unk_38 / 10.0f;
        x = 0.5 * (scale * ((f32)fn_1_584AC() / 32767.0f - 0.5));
        y = scale * ((f32)fn_1_584AC() / 32767.0f - 0.5);
        z = 1.8f + (f64)(scale * ((f32)fn_1_584AC() / 32767.0f - 0.5));
        obj->unk_2C.x += (f64)(0.2 * (x - obj->unk_2C.x));
        obj->unk_2C.y += (f64)(0.2 * (y - obj->unk_2C.y));
        obj->unk_2C.z += (f64)(0.2 * (z - obj->unk_2C.z));
    } else {
        obj->unk_2C.x += (f64)(0.1 * (0.0f - obj->unk_2C.x));
        obj->unk_2C.y += (f64)(0.1 * (0.0f - obj->unk_2C.y));
        obj->unk_2C.z += (f64)(0.1 * (1.8f - obj->unk_2C.z));
    }
    obj->unk_20 = obj->unk_2C;
}
/* fzgx:end fn_1_D2110 */

/* fzgx:begin fn_1_D27B8 noprologue */
#include "types.h"
#include "mtxa.h"

extern u32 lbl_1_data_3D924;
extern u8 lbl_1_data_3DB00[];
extern u8 *lbl_801A6D00;
extern u32 lbl_801A66A0;
extern u32 fn_1_58C4(void);
extern void fn_1_D2F50(void);
extern void fn_1_D2F84(void);
extern s16 fn_1_3F0C8();
extern void lbl_8006DD14(void *, void *);
extern void fn_80038F10(f32 *);
extern void fn_80038FD8(u32 *, u32 *, u32 *, u32 *);
extern void fn_80038BFC(f32 *);
extern void fn_1_550A8(void);
extern void fn_1_550E0(void);
extern void fn_80074918(u8, s32, u8);
extern void fn_80015E18(void *, f32, f32, f32, f32);
extern void fn_800737E4(void *, s32);
extern void fn_80038EEC(f32, f32, f32, f32, f32, f32);
extern void fn_80074188(u32, u32, u32, u32);
extern void fn_8006F120(void *, void *);
extern void lbl_8006DB74(void *);
extern void fn_1_56298(f32, f32, f32, f32);
extern f32 fn_1_867F8(u32);
extern void fn_80074CF4(f32, f32, f32);
extern void lbl_8006D758(void);
extern void fn_80074300(u32, u32, u32, u32);
extern void fn_80074438(u32, u32, u32, u32);
extern void fn_800744F8(void *, u32);
extern void fn_8003526C(u32, u8);
extern void fn_80007C2C(void);
extern void fn_80077A18(void);
extern void *fn_80071268(void *, void *);
extern void lbl_8006DFE8(void *);
extern void mathutil_mtxA_rotate_x(s16);
extern void mathutil_mtxA_rotate_y(s16);
extern void mathutil_mtxA_rotate_z(s16);
extern void fn_80072558(void);
extern void fn_1_556B8(void *);
extern void GXInvalidateTexAll(void);
extern void fn_80072270(void *);

typedef struct {
    f32 x, y, z;
} FaceVec;

typedef struct {
    u8 r, g, b, a;
} FaceColor;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    s32 unk_8;
    u8 pad_C[0x4];
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    FaceVec unk_20;
    FaceVec unk_2C;
    u32 unk_38;
    u32 unk_3C;
    u8 pad_40[0x20];
    u32 unk_60;
} FaceEnt;

typedef struct {
    FaceEnt *unk_0;
    u32 unk_4;
    u32 unk_8;
    u8 unk_C;
    u8 unk_D;
    u8 pad_E[0x2];
    s32 unk_10;
} FaceWork;

typedef struct {
    u8 pad_0[0x94];
    u32 unk_94;
    u32 unk_98;
    u32 unk_9C;
    u32 unk_A0;
    u32 unk_A4;
    u8 pad_A8[0xE8];
    u32 unk_190;
    u8 pad_194[0x2];
    u8 unk_196;
    u8 pad_197[0x2E1];
    f32 unk_478;
} FacePlayer;

extern FaceWork lbl_1_bss_7ACD8;
extern FacePlayer *fn_1_86254(u32);

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    volatile FaceVec v0 = {0.0f, 0.0f, 1.8f};  /* fzgx-allow: S2 pool primer sink */
    volatile FaceVec v1 = {0.0f, 0.0f, 0.0f};  /* fzgx-allow: S2 pool primer sink */
    s = 0.08f;
    d = 0.1;
    s = 1.8f;
    s = 10.0f;
    d = 0.5;
    s = 32767.0f;
    d = 1.7999999523162842;
    d = 0.2;
    d = 4503599627370496.0;
    s = 5.0f;
    s = 0.1f;
    s = 90000.0f;
    s = 0.0f;
    s = 1.0f;
    s = -0.02f;
    s = 0.00004f;
    s = 65536.0f;
    s = 10430.378f;
}
#pragma section code_type ".text"


static inline void face_set_color(void) {
    FaceColor color = {0, 0, 0, 0};
    fn_800744F8(&color, 0xFFFFFF);
}

#pragma opt_loop_invariants off
void fn_1_D27B8(void) {
    f32 cam[3][4];
    u32 sc_x;
    f32 t;
    f32 dist;
    u32 s;
    u32 id;
    void *tex;
    f32 persp[4][4];
    f32 vp[6];
    u32 sc_y;
    u32 sc_w;
    f32 scale;
    f32 ry;
    u32 sc_h;
    s32 n;
    f32 mtx[3][4];
    s32 i;
    FaceEnt *e;
    FaceWork *p;
    f32 rx;
    FacePlayer *pl;
    f32 proj[7];
    f64 size;

    p = (FaceWork *)&lbl_1_bss_7ACD8;
    if (fn_1_58C4() > 1) {
        return;
    }
    if ((s32)lbl_1_data_3D924 == -1) {
        return;
    }
    fn_1_D2F50();
    lbl_8006DD14(lbl_801A6D00 + 0x30, cam);
    fn_80038F10(vp);
    fn_80038FD8(&sc_x, &sc_y, &sc_w, &sc_h);
    fn_80038BFC(proj);
    fn_1_550A8();
    fn_80074918(1, 7, 0);
    fn_80015E18(persp, 5.0f, 1.0f, 0.1f, 90000.0f);
    fn_800737E4(persp, 0);
    fn_80038EEC(512.0f, 352.0f, 128.0f, 128.0f, 0.0f, 1.0f);
    fn_80074188(0x200, 0x160, 0x80, 0x80);
    for (i = 0, e = p->unk_0; i < p->unk_D; i++, e++) {
        if (e->unk_10 >= 6) {
            continue;
        }
        if (fn_1_3F0C8() == 0x2A) {
            e->unk_3C = 0;
            e->unk_38 = 0;
        }
        {
            FaceVec pos = {0.0f, 0.0f, 0.0f};
            fn_8006F120(&e->unk_20, &pos);
        }
        lbl_8006DB74(lbl_801A6D00 + 0x30);
        if (e->unk_38 != 0 && fn_1_3F0C8() == 0x29) {
            if (e->unk_38 % 3 == 0) {
                fn_1_56298(0.5f, 0.5f, 0.5f, 0.5f);
            } else {
                fn_1_56298(0.1f, 0.1f, 0.1f, 0.5f);
            }
        } else {
            fn_1_56298(0.0f, 0.0f, 0.0f, 0.0f);
        }
        dist = fn_1_867F8(e->unk_4);
        if (dist < 25.0f && fn_1_3F0C8() == 0x29) {
            n = 30;
            if (dist < 15.0f) {
                n = 15;
            }
            t = (f32)(lbl_801A66A0 % n) / (f32)n;
            t = (t < 0.1f) ? 0.1f : ((t > 1.0f) ? 1.0f : t);
            fn_80074CF4(1.0f, t, t);
        } else {
            fn_80074CF4(1.0f, 1.0f, 1.0f);
        }
        tex = *(void **)(p->unk_4 + (e->unk_4 << 2));
        lbl_8006D758();
        fn_80074300(0x200, 0x160, 0x80, 0x80);
        size = 64.0;
        fn_80074438((int)size, (long)size, 5, 1);
        face_set_color();
        fn_8003526C(e->unk_60, 1);
        fn_80007C2C();
        if (tex != 0) {
            id = e->unk_4;
            fn_80077A18();
            lbl_8006DB74(mtx);
            tex = fn_80071268(tex, lbl_1_data_3DB00);
            if (tex != 0) {
                lbl_8006DFE8(mtx);
                mathutil_mtxA_rotate_x(-0x4000);
                mathutil_mtxA_rotate_z(-0x4000);
                mtxa_translate_z(-0.02f);
                if (fn_1_3F0C8() == 0x29) {
                    pl = fn_1_86254(id);
                    if (pl->unk_190 != 0) {
                        if (pl->unk_196 != 0) {
                            mathutil_mtxA_rotate_z(-pl->unk_190);
                        } else {
                            mathutil_mtxA_rotate_z(pl->unk_190);
                        }
                    }
                    s = pl->unk_94 ^ pl->unk_98 ^ pl->unk_9C;
                    scale = 0.00004f * pl->unk_478;
                    rx = scale * ((f32)(u16)(s ^ pl->unk_A4) / 65536.0f);
                    ry = scale * ((f32)(u16)(s ^ pl->unk_A0) / 65536.0f);
                    mathutil_mtxA_rotate_x((s16)((s16)(10430.378f * rx) * 2));
                    mathutil_mtxA_rotate_y((s16)((s16)(10430.378f * ry) * 2));
                }
                fn_80072558();
                fn_1_556B8(tex);
            }
            fn_8003526C(e->unk_60, 1);
        }
        GXInvalidateTexAll();
        fn_1_56298(0.0f, 0.0f, 0.0f, 0.0f);
    }
    fn_80074918(1, 3, 1);
    fn_1_550E0();
    lbl_8006DD14(cam, lbl_801A6D00 + 0x30);
    fn_80038EEC(vp[0], vp[1], vp[2], vp[3], vp[4], vp[5]);
    fn_80074188(sc_x, sc_y, sc_w, sc_h);
    fn_80072270(proj);
    fn_1_D2F84();
}
#pragma opt_loop_invariants reset
/* fzgx:end fn_1_D27B8 */

/* fzgx:begin fn_1_D2D24 */
Obj_1_bss_7ACD8_Target *fn_1_D2D24(s32 index) {
    return &lbl_1_bss_7ACD8[index];
}
/* fzgx:end fn_1_D2D24 */

/* fzgx:begin fn_1_D2D38 */
u32 fn_1_D2D38(void) {
    return lbl_1_bss_7ACE8;
}
/* fzgx:end fn_1_D2D38 */

/* fzgx:begin fn_1_D2D48 */
u8 fn_1_D2D48(void) {
    return lbl_1_bss_7ACE5;
}
/* fzgx:end fn_1_D2D48 */

/* fzgx:begin fn_1_D2D58 */
Obj_1_bss_7ACD8_Target *fn_1_D2D58(void *obj) {
    s32 i;

    for (i = 0; i < lbl_1_bss_7ACE5; i++) {
        if ((u32)obj == lbl_1_bss_7ACD8[i].unk_10) {
            if (fn_1_3F0C8(obj) == 0x29 &&
                (fn_1_864E8(lbl_1_bss_7ACD8[i].unk_4) & 0x20000880) != 0) {
                return 0;
            }
            return &lbl_1_bss_7ACD8[i];
        }
    }
    return 0;
}
/* fzgx:end fn_1_D2D58 */

/* fzgx:begin fn_1_D2E18 */
// fn_1_D2E18: 3-way byte comparison (a > b returns 1, a < b returns -1, a == b returns 0)
s32 fn_1_D2E18(u8* a, u8* b) {
    u8 va = *a;
    u8 vb = *b;
    s32 d1;
    s32 d2;
    if (va > vb) {
        return 1;
    }
    d1 = va - vb;
    d2 = vb - va;
    return (d1 | d2) >> 31;
}
/* fzgx:end fn_1_D2E18 */

/* fzgx:begin fn_1_D2E44 */
s32 fn_1_D2E44(u32 index) {
    u8 values[4];
    u32 j;
    u32 i;

    if ((s32)lbl_1_bss_7ACE8 != 0) {
        if (index >= 4) {
            OSPanic((char*)lbl_1_data_3DA2C, 0x4f3, (char*)lbl_1_data_3DB2C);
        }
        for (i = 0; (u8)i < lbl_1_bss_7ACE5; i++) {
            values[(u8)i] = fn_1_86810((u8)i);
        }
        qsort(values, lbl_1_bss_7ACE5, 1, fn_1_D2E18);
        for (j = 0; (u8)j < lbl_1_bss_7ACE5; j++) {
            if (values[(u8)j] == (u8)fn_1_86810(index)) {
                return j;
            }
        }
        return values[index];
    }
    return fn_1_86810(index);
}
/* fzgx:end fn_1_D2E44 */

/* fzgx:begin fn_1_D2FB0 */
u32 fn_1_D2FB0(void) {
    return lbl_1_data_3D924;
}
/* fzgx:end fn_1_D2FB0 */

/* fzgx:begin fn_1_D2FC0 noprologue */
#include "types.h"

extern u32 fn_1_D3020(void *, void *);
extern u8 lbl_1_bss_7ACF8[8];
extern void fn_80083DB0(void *, void *);
extern void strcat(void *, void *);

extern void OSReport(const char *, ...);
#pragma section code_type ".fzgxpool"
static void fzgx_string_layout(void) {
    /* fzgx-allow: S2 layout primer: MWCC emits string literals in first-use order; the section is dropped at integration */
    OSReport("fze.");
    OSReport("window");
    OSReport(".rel");
}
#pragma section code_type ".text"

void fn_1_D2FC0(void) {
    struct {
        u32 a[16];
    } loc_8;

    
    fn_80083DB0((void *)&loc_8, (void *)(u32)("fze."));
    strcat((void *)&loc_8, (void *)(u32)("window"));
    strcat((void *)&loc_8, (void *)(u32)(".rel"));
    fn_1_D3020((void *)&loc_8, (void *)&lbl_1_bss_7ACF8);
}
/* fzgx:end fn_1_D2FC0 */

/* fzgx:begin fn_1_D3020 */
#include "types.h"

typedef struct LocalData {
    u8 unk_0[0x34];
    u32 size;
} LocalData;

typedef struct Output {
    void* data;
    void* aux;
} Output;

typedef struct Allocated {
    u8 unk_0[0x20];
    u32 size;
    u8 unk_24[0x10];
    void (*init)(void);
} Allocated;

extern int DVDOpen(void*, LocalData*);
extern int fn_80006354(LocalData*, void*, u32, u32);
extern void DVDClose(LocalData*);

void fn_1_D3020(void* unused, Output* output) {
    LocalData local;
    Allocated* object;
    s32 size;

    if ((lbl_801A6CE0 & 0x8) == 0) {
        return;
    }
    output->data = 0;
    output->aux = 0;
    if (DVDOpen(unused, &local) == 0) {
        return;
    }
    size = (local.size + 0x1f) & ~0x1f;
    if (lbl_801A6CFC < 0x82000000) {
        object = fn_1_48E8(size, 0x20);
        output->data = object;
    } else {
        OSReport((*(char (*)[51])&lbl_1_data_3DB58));
        return;
    }
    if (fn_80006354(&local, output->data, size, 0) != 0) {
        object = output->data;
        size = 0x20;
        if (object->size != 0) {
            size = object->size;
        }
        output->aux = fn_1_48E8(size, 0x20);
        OSLink(output->data, output->aux);
        object = output->data;
        object->init();
    } else {
        OSReport((*(char (*)[51])&lbl_1_data_3DB8C));
        output->data = 0;
    }
    DVDClose(&local);
}
/* fzgx:end fn_1_D3020 */

/* fzgx:begin fn_1_D3144 */
// fn_1_D3144: Conditionally call function pointer from BSS
void fn_1_D3144(void) {
    u32 fn_ptr = lbl_1_bss_7AD00;
    if (fn_ptr != 0) {
        ((void (*)(void))fn_ptr)();
    }
}
/* fzgx:end fn_1_D3144 */

/* fzgx:begin fn_1_D3178 */
void fn_1_D3178(void) {
    u32 fn_ptr = lbl_1_bss_7AD04;
    if (fn_ptr != 0) {
        ((void (*)(void))fn_ptr)();
    }
}
/* fzgx:end fn_1_D3178 */

/* fzgx:begin fn_1_D31AC */
void fn_1_D31AC(void) {
    u32 fn_ptr = lbl_1_bss_7AD08[0];
    if (fn_ptr != 0) {
        ((void (*)(void))fn_ptr)();
    }
}
/* fzgx:end fn_1_D31AC */

/* fzgx:begin fn_1_D31E0 */
void fn_1_D31E0(void) {
    u32 fn_ptr = lbl_1_bss_7AD24[0];
    if (fn_ptr != 0) {
        ((void (*)(void))fn_ptr)();
    }
}
/* fzgx:end fn_1_D31E0 */
