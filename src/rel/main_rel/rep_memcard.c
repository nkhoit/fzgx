#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/rep_memcard.h"

extern u32 lbl_801A6410;
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern void fn_1_46B4(u32 arg0, u32 arg1, u8 *arg2, s32 arg3);
extern u32 fn_1_4630(u32 arg0, u32 arg1, u8 *arg2, s32 arg3);
extern u8 lbl_1_bss_8EDA0;
extern void fn_1_154F1C(void);
extern void *memset(void *dest, int value, u32 size);
extern void fn_1_155120(void);
extern const f64 lbl_1_rodata_D5A8;
extern void fn_1_496FC(f32, f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495FC(void);
extern f32 fn_1_4B090(void *);
extern int fn_1_4B16C(void *);
extern const f32 lbl_1_rodata_D5A0;
extern void fn_1_4966C(f32, f32);
extern int fn_1_FA638(void);
extern void fn_1_4AF64(void *, ...);
extern void fn_1_49614(void);
extern const f64 lbl_1_rodata_D5B0;
extern f64 fn_80083E84(u8 *text);
extern s32 atoi(u8 *text);
extern u8 fn_1_B7C00(void);
extern void fn_1_B9C0C(void);
extern struct fn_1_154BE4_lbl_1_data_49A18 lbl_1_data_49A18;
extern void fn_1_1596DC(s32);
extern void fn_1_484CC(s32);
extern u8 *fn_1_15530C(u8 *text);
extern void fn_1_A8EB0(s32 arg0, s32 arg1);
extern f32 lbl_1_rodata_D598;
extern f32 lbl_1_rodata_D59C;
extern void fn_1_154FA8(void);

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

/* fzgx:begin fn_1_1547FC noprologue */
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

/* fzgx:begin fn_1_1548A8 noprologue */
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

/* fzgx:begin fn_1_154930 noprologue */
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

/* fzgx:begin fn_1_1549B8 noprologue */
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

/* fzgx:begin fn_1_154A08 pool */
typedef struct {
    u8 pad_0[0x8];
    u32 unk_8;
    u32 unk_C;
    u8 pad_10[0x4];
    s8 unk_14;
} fn_1_154A08_Replay;

extern void fn_1_BC29C(fn_1_154A08_Replay *arg0);
extern void fn_1_C1394(fn_1_154A08_Replay *arg0);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_8ED90;
u32 fzgx_obj_lbl_1_bss_8ED94;
u32 lbl_1_bss_8ED94_fill_8ED98[2];
u8 lbl_1_bss_8EDA0;
u8 lbl_1_bss_8ED90_gap_8EDA1;
u16 lbl_1_bss_8ED90_gap_8EDA1_fill_8EDA2;
u8 fzgx_obj_lbl_1_bss_8EDA4;
u8 lbl_1_bss_8EDA4_fill_8EDA5;
u16 lbl_1_bss_8EDA4_fill_8EDA6;
u32 lbl_1_bss_8EDA4_fill_8EDA8[18];
u32 fzgx_obj_lbl_1_bss_8EDF0[76];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout_154A08(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8ED90;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8ED94;
    s = *(u8 *)&lbl_1_bss_8ED94_fill_8ED98;
    s = *(u8 *)&lbl_1_bss_8EDA0;
    s = *(u8 *)&lbl_1_bss_8ED90_gap_8EDA1;
    s = *(u8 *)&lbl_1_bss_8ED90_gap_8EDA1_fill_8EDA2;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8EDA4;
    s = *(u8 *)&lbl_1_bss_8EDA4_fill_8EDA5;
    s = *(u8 *)&lbl_1_bss_8EDA4_fill_8EDA6;
    s = *(u8 *)&lbl_1_bss_8EDA4_fill_8EDA8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8EDF0;
}
#pragma section code_type ".text"

void fn_1_154A08(void) {
    fn_1_154A08_Replay *replay;
    u32 buf;
    fn_1_154A08_Replay *saved;
    s32 state;

    if (fn_1_B7C00()) {
        return;
    }
    if (lbl_1_bss_8ED94_fill_8ED98[0] != 0) {
        fn_1_46B4(lbl_801A6410, lbl_1_bss_8ED94_fill_8ED98[0], lbl_1_data_49AC8, 0xcd);
    }
    state = ((fn_1_154A08_Replay *)&fzgx_obj_lbl_1_bss_8EDA4)->unk_14;
    if (state == 1) {
        fn_1_B9C0C();
        fn_1_BC29C((fn_1_154A08_Replay *)&fzgx_obj_lbl_1_bss_8EDA4);
        lbl_1_data_49AB4.unk_0 = 4;
    } else if (state == 2) {
        if (fzgx_obj_lbl_1_bss_8ED90 != 0) {
            fn_1_46B4(lbl_801A6410, fzgx_obj_lbl_1_bss_8ED90, lbl_1_data_49AC8, 0xda);
        }
        replay = (fn_1_154A08_Replay *)&fzgx_obj_lbl_1_bss_8EDA4;
        if ((s32)replay->unk_C != 0) {
            buf = fn_1_4630(lbl_801A6410, replay->unk_C, lbl_1_data_49AC8, 0xdf);
            fn_80008BA8(buf, (saved = (fn_1_154A08_Replay *)&fzgx_obj_lbl_1_bss_8EDA4)->unk_8, replay->unk_C);
            fn_1_B9C0C();
            if (saved->unk_8 != 0) {
                fn_1_46B4(lbl_801A6410, saved->unk_8, lbl_1_data_49AC8, 0xe9);
                saved->unk_8 = 0;
            }
            fzgx_obj_lbl_1_bss_8ED90 = fn_1_4630(lbl_801A6410, replay->unk_C, lbl_1_data_49AC8, 0xee);
            fzgx_obj_lbl_1_bss_8ED94 = replay->unk_C;
            replay->unk_C = 0;
            fn_80008BA8(fzgx_obj_lbl_1_bss_8ED90, buf, fzgx_obj_lbl_1_bss_8ED94);
            fn_1_46B4(lbl_801A6410, buf, lbl_1_data_49AC8, 0xf9);
        }
        lbl_1_data_49AB4.unk_0 = 4;
        fn_1_BC29C((fn_1_154A08_Replay *)&fzgx_obj_lbl_1_bss_8EDA4);
    } else if (state == 8) {
        fn_1_C1394((fn_1_154A08_Replay *)&fzgx_obj_lbl_1_bss_8EDA4);
        lbl_1_data_49AB4.unk_0 = 1;
    }
}
/* fzgx:end fn_1_154A08 */

/* fzgx:begin fn_1_154BE4 pool */
struct fn_1_154BE4_lbl_1_bss_8ED90 {
    u32 unk_0;
    u32 unk_4;
    u8 pad_8[0xc];
    u8 state;
};

struct fn_1_154BE4_lbl_1_data_49A18 {
    u8 pad_0[0x94];
    u32 unk_94;
    u32 unk_98;
    u32 unk_9C;
};

#pragma opt_common_subs off
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_8ED90;
u32 fzgx_obj_lbl_1_bss_8ED94;
u32 lbl_1_bss_8ED94_fill_8ED98[2];
u8 lbl_1_bss_8EDA0;
u8 lbl_1_bss_8ED90_gap_8EDA1;
u16 lbl_1_bss_8ED90_gap_8EDA1_fill_8EDA2;
u8 fzgx_obj_lbl_1_bss_8EDA4;
u8 lbl_1_bss_8EDA4_fill_8EDA5;
u16 lbl_1_bss_8EDA4_fill_8EDA6;
u32 lbl_1_bss_8EDA4_fill_8EDA8[18];
u32 fzgx_obj_lbl_1_bss_8EDF0[76];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8ED90;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8ED94;
    s = *(u8 *)&lbl_1_bss_8ED94_fill_8ED98;
    s = *(u8 *)&lbl_1_bss_8EDA0;
    s = *(u8 *)&lbl_1_bss_8ED90_gap_8EDA1;
    s = *(u8 *)&lbl_1_bss_8ED90_gap_8EDA1_fill_8EDA2;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8EDA4;
    s = *(u8 *)&lbl_1_bss_8EDA4_fill_8EDA5;
    s = *(u8 *)&lbl_1_bss_8EDA4_fill_8EDA6;
    s = *(u8 *)&lbl_1_bss_8EDA4_fill_8EDA8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8EDF0;
}
#pragma section code_type ".text"

void fn_1_154BE4(void) {
    struct fn_1_154BE4_lbl_1_data_49A18 *p_lbl_1_data_49A18;
    u8 *p_state;
    
    p_lbl_1_data_49A18 = (struct fn_1_154BE4_lbl_1_data_49A18 *)&lbl_1_data_49A18;
    p_state = (u8 *)&fzgx_obj_lbl_1_bss_8EDA4;
    if ((s32)(*((p_state) + (0x14))) != 2 && fzgx_obj_lbl_1_bss_8ED90 != 0) {
        fn_1_46B4(lbl_801A6410, fzgx_obj_lbl_1_bss_8ED90,
            (u8 *)p_lbl_1_data_49A18 + 0xb0, 0x10d);
        fzgx_obj_lbl_1_bss_8ED90 = 0;
        fzgx_obj_lbl_1_bss_8ED94 = 0;
    }
    fn_1_B9C0C();
    fn_1_1596DC(2);
    fn_1_484CC(2);
    p_lbl_1_data_49A18->unk_94 = -1;
    p_lbl_1_data_49A18->unk_98 = -1;
    p_lbl_1_data_49A18->unk_9C = -1;
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_154BE4 */

/* fzgx:begin fn_1_154C84 noprologue */
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

/* fzgx:begin fn_1_154CC4 */
void fn_1_154CC4(u32 arg0) {
    lbl_1_data_49AB4.unk_0 = arg0;
}
/* fzgx:end fn_1_154CC4 */

/* fzgx:begin fn_1_154CD0 */
void fn_1_154CD0(u32 arg0, u32 arg1) {
    if (lbl_1_bss_8ED90 != 0) {
        fn_1_46B4(lbl_801A6410, lbl_1_bss_8ED90, lbl_1_data_49AC8, 0x12f);
        lbl_1_bss_8ED90 = 0;
        lbl_1_bss_8ED94.unk_0 = 0;
    }

    lbl_1_bss_8ED90 = fn_1_4630(lbl_801A6410, arg1, lbl_1_data_49AC8, 0x133);
    fn_80008BA8(lbl_1_bss_8ED90, arg0, arg1);
    lbl_1_bss_8ED94.unk_0 = arg1;
}
/* fzgx:end fn_1_154CD0 */

/* fzgx:begin fn_1_154D84 */
// Saves the pending memory-card data and clears the pending state.
u32 fn_1_154D84(u32 arg0) {
    if (lbl_1_bss_8ED90 == 0) {
        return 0;
    }
    if (arg0 == 0) {
        return 0;
    }

    fn_80008BA8(arg0, lbl_1_bss_8ED90, lbl_1_bss_8ED94.unk_0);
    fn_1_46B4(lbl_801A6410, lbl_1_bss_8ED90, lbl_1_data_49AC8, 0x13f);
    lbl_1_bss_8ED90 = 0;
    lbl_1_bss_8ED94.unk_0 = 0;
    return 1;
}
/* fzgx:end fn_1_154D84 */

/* fzgx:begin fn_1_154E24 */
u8 fn_1_154E24(void) {
    return lbl_1_bss_8EDA0;
}
/* fzgx:end fn_1_154E24 */

/* fzgx:begin fn_1_154E34 */
u32 fn_1_154E34(u32 *arg0) {
    *arg0 = lbl_1_bss_8ED94.unk_0;
    return lbl_1_bss_8ED90;
}
/* fzgx:end fn_1_154E34 */

/* fzgx:begin fn_1_154E4C */
// Clear the replay memory-card message state and set its default layout.
void fn_1_154E4C(void) {
    memset(&lbl_1_bss_8EDF0, 0, sizeof(lbl_1_bss_8EDF0));
    lbl_1_bss_8EDF0.unk_C = 0;
    lbl_1_bss_8EDF0.unk_28 = lbl_1_rodata_D598;
    lbl_1_bss_8EDF0.unk_30 = 2;
    lbl_1_bss_8EDF0.unk_8 &= ~2;
    lbl_1_bss_8EDF0.unk_10 = 0;
    lbl_1_bss_8EDF0.unk_20 = 80;
    lbl_1_bss_8EDF0.unk_24 = 385;
    lbl_1_bss_8EDF0.unk_2C = lbl_1_rodata_D59C;
    fn_1_154FA8();
}
/* fzgx:end fn_1_154E4C */

/* fzgx:begin fn_1_154ED0 */
typedef struct {
    u8 pad_0[0x134];
    Obj_1_bss_8EDF0_At10 *unk_134;
} Fn_1_154ED0_Arg;

void fn_1_154ED0(Fn_1_154ED0_Arg *arg0) {
    fn_1_154F1C();
    lbl_1_bss_8EDF0.unk_C = (u32)arg0;
    lbl_1_bss_8EDF0.unk_10 = arg0->unk_134;
    lbl_1_bss_8EDF0.unk_0 = 0;
    lbl_1_bss_8EDF0.unk_4 = 0;
}
/* fzgx:end fn_1_154ED0 */

/* fzgx:begin fn_1_154F1C */
// Reset the memory-card state and clear its backing buffer.
void fn_1_154F1C(void) {
    lbl_1_bss_8EDF0.unk_1C = 0;
    lbl_1_bss_8EDF0.unk_14 = 0;
    lbl_1_bss_8EDF0.unk_18 = 0;
    memset(&lbl_1_bss_8EDF0.unk_34, 0, 250);
    lbl_1_bss_8EDF0.unk_34 = 0;
}
/* fzgx:end fn_1_154F1C */

/* fzgx:begin fn_1_154F74 */
// Stores the two memory-card state values used by the replication subsystem.
void fn_1_154F74(u32 arg0, u32 arg1) {
    lbl_1_bss_8EDF0.unk_20 = arg0;
    lbl_1_bss_8EDF0.unk_24 = arg1;
}
/* fzgx:end fn_1_154F74 */

/* fzgx:begin fn_1_154F88 */
// Stores the current float value in the memory-card state.
void fn_1_154F88(f32 value) {
    lbl_1_bss_8EDF0.unk_2C = value;
}
/* fzgx:end fn_1_154F88 */

/* fzgx:begin fn_1_154F98 */
void fn_1_154F98(u32 value) {
    lbl_1_bss_8EDF0.unk_30 = value;
}
/* fzgx:end fn_1_154F98 */

/* fzgx:begin fn_1_154FA8 */
void fn_1_154FA8(void) {
    lbl_1_bss_8EDF0.unk_8 |= 4;
}
/* fzgx:end fn_1_154FA8 */

/* fzgx:begin fn_1_154FC0 */
void fn_1_154FC0(void) {
    lbl_1_bss_8EDF0.unk_8 &= ~4;
}
/* fzgx:end fn_1_154FC0 */

/* fzgx:begin fn_1_154FD8 */
void fn_1_154FD8(void) {
    Obj_1_bss_8EDF0 *obj;
    f32 value;
    f32 ratio;
    int count;

    obj = &lbl_1_bss_8EDF0;
    if ((obj->unk_8 & 1) == 0) {
        obj->unk_0++;
        if ((s32)obj->unk_4 != 0) {
            obj->unk_4--;
        }
    }

    if ((s32)obj->unk_4 <= 0) {
        if (((s32)obj->unk_0 % (s32)obj->unk_30) == 0) {
            fn_1_155120();
        }
    }

    fn_1_496FC((f32)(s32)obj->unk_20, (f32)(s32)obj->unk_24);
    fn_1_4955C(obj->unk_28, obj->unk_28);
    fn_1_495FC();

    value = fn_1_4B090(&obj->unk_34);
    ratio = value / (f32)(fn_1_4B16C(&obj->unk_34));
    fn_1_4966C(lbl_1_rodata_D5A0, ratio * obj->unk_2C);

    if (fn_1_FA638() != 0) {
        fn_1_4AF64(&obj->unk_34);
    }

    fn_1_49614();
}
/* fzgx:end fn_1_154FD8 */

/* fzgx:begin fn_1_155120 */
#define TEXT(obj) ((u8 *)(obj)->unk_10)
#define SET_TEXT(obj, p) ((obj)->unk_10 = (Obj_1_bss_8EDF0_At10 *)(p))

// Emit the next character (or bracketed group, or escape command) of the replay
// memory-card message into the text buffer.
void fn_1_155120(void) {
    Obj_1_bss_8EDF0 *obj = &lbl_1_bss_8EDF0;
    u8 *text = TEXT(obj);
    u8 c = *text;
    u8 next;

    if (c == 0) {
        return;
    }
    switch (c) {
    case '\\':
        SET_TEXT(obj, fn_1_15530C(text + 1));
        break;
    case '[':
        fn_1_A8EB0(20, 20);
        while (*TEXT(obj) != ']') {
            /* read through the global, not obj: retail reloads the cursor here */
            u8 *p = (u8 *)lbl_1_bss_8EDF0.unk_10;
            u8 ch = *p;
            if ((ch & 0x80) == 0) {
                SET_TEXT(obj, p + 1);
                obj->unk_14++;
                (&obj->unk_34)[obj->unk_1C] = ch;
            } else {
                next = TEXT(obj)[1];
                SET_TEXT(obj, p + 2);
                obj->unk_14 += 2;
                (&obj->unk_34)[obj->unk_1C] = ch;
                (&obj->unk_34)[obj->unk_1C + 1] = next;
            }
            obj->unk_1C = obj->unk_14 + obj->unk_18 * 30;
        }
        c = *TEXT(obj);
        SET_TEXT(obj, TEXT(obj) + 1);
        obj->unk_14++;
        (&obj->unk_34)[obj->unk_1C] = c;
        obj->unk_1C = obj->unk_14 + obj->unk_18 * 30;
        break;
    case '\n':
        obj->unk_14++;
        SET_TEXT(obj, text + 1);
        (&obj->unk_34)[obj->unk_1C] = '\n';
        break;
    case '\0':
        break;
    default:
        if ((c & 0x80) == 0) {
            SET_TEXT(obj, TEXT(obj) + 1);
            obj->unk_14++;
            (&obj->unk_34)[obj->unk_1C] = c;
        } else {
            next = TEXT(obj)[1];
            SET_TEXT(obj, TEXT(obj) + 2);
            obj->unk_14 += 2;
            (&obj->unk_34)[obj->unk_1C] = c;
            (&obj->unk_34)[obj->unk_1C + 1] = next;
        }
        break;
    }
    obj->unk_1C = obj->unk_14 + obj->unk_18 * 30;
}
/* fzgx:end fn_1_155120 */

/* fzgx:begin fn_1_15530C */
u8 *fn_1_15530C(u8 *text) {
    Obj_1_bss_8EDF0 *obj = &lbl_1_bss_8EDF0;

    switch (*text) {
    case 'l':
    {
        u8 *dest;
        obj->unk_1C = 0;
        dest = &obj->unk_34;
        obj->unk_14 = 0;
        text++;
        obj->unk_18 = 0;
        memset(dest, 0, 0xFA);
        *dest = 0;
        break;
    }
    case 'w':
    {
        f32 value;
        text++;
        value = (f32)fn_80083E84(text);
        while ((*text >= '0' && *text <= '9') || *text == '.') {
            text++;
        }
        obj->unk_4 = (s16)(*(const f32 *)(const void *)&lbl_1_rodata_D5B0 * value);
        break;
    }
    case 't':
    {
        s32 value;
        text++;
        value = atoi(text);
        while ((*text >= '0' && *text <= '9') || *text == '.') {
            text++;
        }
        value = value - obj->unk_0;
        if (value >= 0) {
            obj->unk_4 = value;
        } else {
            obj->unk_4 = 0;
        }
        break;
    }
    case 'p':
    {
        s32 value = 0;
        text++;
        while ((*text >= '0') && (*text <= '9')) {
            if (value != 0) {
                value *= 10;
            }
            value = *text + value;
            text++;
            value -= 0x30;
        }
        break;
    }
    case 's':
    {
        f32 value;
        text++;
        value = (f32)fn_80083E84(text);
        while ((*text >= '0' && *text <= '9') || *text == '.') {
            text++;
        }
        obj->unk_28 = value;
        break;
    }
    default:
        text++;
        break;
    }

    return text;
}
/* fzgx:end fn_1_15530C */
