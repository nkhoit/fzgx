#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/ghost.h"

extern void fn_1_F23E8(void);
extern void fn_1_EE530(void);
extern u8 fn_1_B7C00(void);
extern void fn_1_B9BE0(void);
extern void fn_1_B9DE8(Obj_1_bss_7ECB4 *obj);
extern u8 lbl_1_bss_7EA00[56];
extern int fn_1_B7CD4(void);
extern int fn_1_B7C5C(void);
extern u32 lbl_1_bss_7B19C[2];
extern u32 lbl_801A6410[];
extern void fn_1_46B4(u32, u32, void *, u32);
extern void fn_1_C1394(void);
extern void OSReport(const char *, ...);
extern void fn_1_49410(void);
extern void fn_1_495FC(void);
extern const f32 lbl_1_rodata_6D20;
extern const f32 lbl_1_rodata_6D24;
extern void fn_1_496FC(f32, f32);
extern void fn_1_495C8(s32);
extern s32 lbl_1_bss_7B198;
extern void fn_1_4AE0C(void *, ...);
extern u8 lbl_1_bss_7C8CE[70];
extern void fn_1_F1D70(void);
extern u32 lbl_1_bss_7EA38[159];
extern const f64 lbl_1_rodata_6B68;
extern const f32 lbl_1_rodata_6D10;
extern const f32 lbl_1_rodata_6D44;
extern void fn_80008BEC(void *dst, int value, int size);
extern void fn_1_F1950(void);
extern u32 fn_8002071C(void *arg);
extern void fn_800206FC(u32 arg);
extern u32 ARGetDMAStatus(void);
extern void DCFlushRange(void *addr, u32 size);
extern u32 lbl_1_bss_7C848[2];
extern u8 lbl_1_bss_7C8CD;
extern u32 lbl_1_bss_7C948;
extern void fn_1_12EF80(s16 arg, s16 *out_a, s16 *out_b);
extern u32 lbl_1_bss_7B190[2];
extern u32 lbl_1_bss_7ED58[158];

extern void fn_1_12EF80(s16 arg, s16 *out_a, s16 *out_b);

extern void OSReport(const char *, ...);
extern void fn_1_12EF80(s16 arg, s16 *out_a, s16 *out_b);

extern void fn_1_12EF80(s16 arg, s16 *out_a, s16 *out_b);

extern void fn_1_12EF80(s16 arg, s16 *out_a, s16 *out_b);
extern f64 lbl_1_rodata_6C88;
extern void fn_80008BA8(u32 *out, const void *value, s32 size);
extern s32 fn_1_F21B8(s32 arg);
extern void fn_1_F0D10(s32, void *);
extern void fn_1_F0B5C(s32, void *);
extern void fn_1_F0E00(s32, void *);
extern s32 fn_1_3F164(void);
extern void fn_1_B9C0C(void);
extern void fn_1_1596DC(s32);
extern void fn_1_484CC(s32);
extern u32 lbl_1_bss_7C914[13];
extern const f32 lbl_1_rodata_6D38;
extern const f32 lbl_1_rodata_6D3C;
extern const f32 lbl_1_rodata_6D40;
extern void lbl_8006DD14(void *a, void *b);
extern f32 lbl_8006D0B4(f32 x);
extern void lbl_8006D7DC(void *a);
extern void lbl_8006DFC4(void *a);
extern void lbl_8006DB74(void *a);
extern const f32 lbl_1_rodata_6BBC;
extern const f32 lbl_1_rodata_6BD0;
extern const f64 lbl_1_rodata_6D48;
extern const f32 lbl_1_rodata_6D50;
extern f64 fn_80088598(f64, f64);

/* fzgx:begin fn_1_E9680 noprologue */
#include "types.h"
#include "rel/main_rel/phys.h"

extern void fn_80008BEC(void* dst, int value, int size);

void fn_1_E9680(void) {
    u8* base = (u8*)&lbl_1_bss_7B180;
    u32* p0;
    u32* p1;
    u32* p2;
    u32* p3;
    u32* p4;
    u32* p5;
    u32* p6;
    u32* p7;
    u32* p8;
    u32* p9;
    int i;

    fn_80008BEC(base + 0x2c, 0, 0x13d8);
    fn_80008BEC(base + 0x1404, 0, 0x1fc);

    p0 = (u32*)(base + 0x1600);
    p1 = (u32*)(base + 0x1614);
    p2 = (u32*)(base + 0x1628);
    p3 = (u32*)(base + 0x163c);
    p4 = (u32*)(base + 0x1650);
    p5 = (u32*)(base + 0x1664);
    p6 = (u32*)(base + 0x1678);
    p7 = (u32*)(base + 0x168c);
    p8 = (u32*)(base + 0x16a0);
    p9 = (u32*)(base + 0x16b4);

    for (i = 5; i != 0; i--) {
        *p0++ = 0;
        *p1++ = 0;
        *p2++ = 0;
        *p3++ = 0;
        *p4++ = 0;
        *p5++ = 0;
        *p6++ = 0;
        *p7++ = 0;
        *p8++ = 0;
        *p9++ = 0;
    }

    *(s32*)(base + 0x16c8) = -1;
    *(u8*)(base + 0x16cc) = 0xff;
    *(u32*)(base + 0x16d0) = 0;
}
/* fzgx:end fn_1_E9680 */

/* fzgx:begin fn_1_E9BA8 noprologue */
#include "types.h"

// Advances the scene-gated physics state machine.











typedef struct Phys {
    u8 _00[0x98];
    void (*handlers[1])(void);                   // 0x98
    u8 _9c[0x1d4 - 0x9c];
    s32 current;                                 // 0x1d4
    s32 pending;                                 // 0x1d8
} Phys;

typedef void (*Handler)(void);

extern s16 lbl_1_bss_960;
extern s32 lbl_1_bss_7B188;
extern void *lbl_1_bss_7C85C;
extern Phys lbl_1_data_3E358;
extern int fn_1_4C10(void);
extern u32 fn_1_3F8C0(void);
extern void *fn_80008E84();

#pragma opt_propagation off
void fn_1_E9BA8(void) {
    Phys *p = &lbl_1_data_3E358;
    if (lbl_1_bss_7B188 != 0) {
        if (fn_1_4C10() != 0) {
            return;
        }
        if (lbl_1_bss_960 == 9) {
            lbl_1_bss_7C85C = fn_80008E84(fn_1_3F8C0());
        }
        if (p->pending >= 0) {
            p->current = p->pending;
            p->pending = -1;
        }
        if (p->current >= 0) {
            s32 off = p->current * sizeof(Handler);
            Handler *tbl = p->handlers;
            (*(Handler *)((u8 *)tbl + off))();
        }
        if (lbl_1_bss_960 == 9) {
            fn_80008E84(lbl_1_bss_7C85C);
        }
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_E9BA8 */

/* fzgx:begin fn_1_E9C68 */
extern u32 fn_1_3F8C0(void);
extern u32 fn_80008E84(u32 value);
// lbl_1_bss_7B188: .bss size 0x8, 6 refs from phys.c
extern u32 lbl_1_bss_7B188;
// lbl_1_data_3E52C: .data size 0x4, 5 refs from phys.c (own data block)
extern u32 lbl_1_data_3E52C;
// lbl_1_bss_7C85C: .bss size 0x71, 2 refs from phys.c
typedef struct {
    u32 unk_0;  // 2 loads, 2 stores
    u8 pad_4[0x6D];
} Obj_1_bss_7C85C;
extern Obj_1_bss_7C85C lbl_1_bss_7C85C;
// lbl_1_data_3E434: .data size 0x44, 1 refs from phys.c (own data block)
extern u8 lbl_1_data_3E434[0x44];

// Updates the active physics callback and refreshes its associated state.
void fn_1_E9C68(void) {
    u32 value;

    if ((s32)lbl_1_bss_7B188 == 0) {
        return;
    }

    if (*(s16 *)&lbl_1_bss_960 == 9) {
        value = fn_80008E84(fn_1_3F8C0());
        lbl_1_bss_7C85C.unk_0 = value;
    }

    if ((s32)lbl_1_data_3E52C >= 0) {
        ((void (**)(void))lbl_1_data_3E434)[lbl_1_data_3E52C]();
    }

    if (*(s16 *)&lbl_1_bss_960 == 9) {
        fn_80008E84(lbl_1_bss_7C85C.unk_0);
    }
}
/* fzgx:end fn_1_E9C68 */

/* fzgx:begin fn_1_EB074 */
extern u32 lbl_1_bss_7C94C[67];

void fn_1_EB074(u32 value) {
    lbl_1_bss_7C94C[0] = value;
}
/* fzgx:end fn_1_EB074 */

/* fzgx:begin fn_1_EB080 */
// lbl_1_bss_7B188: .bss size 0x8, 6 refs from phys.c
extern u32 lbl_1_bss_7B188;
// lbl_1_data_3E358: .data size 0xC, 5 refs from phys.c (own data block)
extern u8 lbl_1_data_3E358[0xC];

// Preserve the previous mode when switching to mode 11, then update the active mode.
void fn_1_EB080(int mode) {
    u32* state = (u32*)lbl_1_data_3E358;

    if ((int)lbl_1_bss_7B188 == 0) {
        return;
    }

    if (mode == 11) {
        state[0x1e0 / 4] = state[0x1d4 / 4];
    }

    state[0x1d8 / 4] = mode;
}
/* fzgx:end fn_1_EB080 */

/* fzgx:begin fn_1_EB0B0 noprologue */
#include "types.h"

// Provides accessors for physics subsystem state.









extern s32 lbl_1_bss_7C94C;
extern s32 lbl_1_bss_7B188;
extern u8  lbl_1_bss_7C8CE;

typedef struct {
    u8  pad0[0x1d4];
    s32 unk_0x1d4;
    s32 unk_0x1d8;
    u8  pad1[0x1e0 - 0x1dc];
    s32 unk_0x1e0;
} PhysTable;
extern PhysTable lbl_1_data_3E358;
void fn_1_EB074(s32 v);
void fn_1_EB080(s32 arg);

s32 fn_1_EB0B0(void) {
    return lbl_1_bss_7B188 ? lbl_1_bss_7C8CE : 0;
}
/* fzgx:end fn_1_EB0B0 */

/* fzgx:begin fn_1_EB200 */
// lbl_1_bss_7B188: .bss size 0x8, 6 refs from phys.c
extern u32 lbl_1_bss_7B188;
// lbl_1_data_3E52C: .data size 0x4, 5 refs from phys.c (own data block)
extern u32 lbl_1_data_3E52C;

// Return whether the active state is one of the physics states.
int fn_1_EB200(void) {
    if ((s32)lbl_1_bss_7B188 == 0) {
        return 0;
    }

    if ((s32)lbl_1_data_3E52C == 14 ||
        (s32)lbl_1_data_3E52C == 16 ||
        (s32)lbl_1_data_3E52C == 15) {
        return 1;
    }

    return 0;
}
/* fzgx:end fn_1_EB200 */

/* fzgx:begin fn_1_EB248 */
// lbl_1_bss_7B188: .bss size 0x8, 6 refs from phys.c
extern u32 lbl_1_bss_7B188;
// lbl_1_data_3E52C: .data size 0x4, 5 refs from phys.c (own data block)
extern u32 lbl_1_data_3E52C;

// Return whether the current state is one of the supported race states.
int fn_1_EB248(void) {
    if ((s32)lbl_1_bss_7B188 == 0) {
        return 0;
    }

    {
        s32 state = lbl_1_data_3E52C;

        if ((u32)(state - 9) <= 4 ||
            (u32)(state - 5) <= 2 ||
            state == 8) {
            return 1;
        }
    }

    return 0;
}
/* fzgx:end fn_1_EB248 */

/* fzgx:begin fn_1_EB330 noprologue */
#include "types.h"
#include "rel/main_rel/ghost.h"

extern u32 lbl_801A6410;
extern u8 lbl_1_data_3E62C[128];
extern void fn_1_46B4(u32, u32, u8 *, s32);
extern s32 fn_1_B7E98(s32);
extern void fn_1_B9C0C(void);
extern void fn_1_B9BE0(void);
extern void fn_1_AA6D8(s32, s32, void *);
extern void fn_1_F1D70(void);
extern void fn_80008BEC(void *, s32, u32);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_7B180[2];
u32 fzgx_obj_lbl_1_bss_7B188[2];
u32 lbl_1_bss_7B190[2];
u32 lbl_1_bss_7B198;
u32 lbl_1_bss_7B19C[2];
s32 fzgx_obj_lbl_1_bss_7B1A4;
u32 lbl_1_bss_7B1A4__fzgx_offset_4;
u8 fzgx_obj_lbl_1_bss_7B1AC;
u8 lbl_1_bss_7B1AC__fzgx_offset_1;
u16 lbl_1_bss_7B1AC__fzgx_offset_2;
u32 lbl_1_bss_7B1AC__fzgx_offset_4[1269];
u8 fzgx_obj_lbl_1_bss_7C584;
u8 lbl_1_bss_7C584__fzgx_offset_1;
u16 lbl_1_bss_7C584__fzgx_offset_2;
u32 lbl_1_bss_7C584__fzgx_offset_4[176];
u32 lbl_1_bss_7C848[2];
u32 lbl_1_bss_7C850[3];
u32 fzgx_obj_lbl_1_bss_7C85C[28];
u8 lbl_1_bss_7C85C__fzgx_offset_70;
u8 lbl_1_bss_7C8CD;
u16 lbl_1_bss_7C8CE;
u32 lbl_1_bss_7C8CE__fzgx_offset_2[17];
u32 lbl_1_bss_7C914[13];
u32 lbl_1_bss_7C948;
u32 lbl_1_bss_7C94C[67];
u32 lbl_1_bss_7CA58[2020];
u32 lbl_1_bss_7E9E8__fzgx_offset_0[4];
s32 lbl_1_bss_7E9E8__fzgx_offset_10;
s32 lbl_1_bss_7E9E8__fzgx_offset_14;
u8 lbl_1_bss_7EA00;
u8 lbl_1_bss_7EA00__fzgx_offset_1;
u16 lbl_1_bss_7EA00__fzgx_offset_2;
s32 lbl_1_bss_7EA00__fzgx_offset_4;
s32 lbl_1_bss_7EA00__fzgx_offset_8;
u8 lbl_1_bss_7EA00__fzgx_offset_C;
u8 lbl_1_bss_7EA00__fzgx_offset_D;
u16 lbl_1_bss_7EA00__fzgx_offset_E;
s32 lbl_1_bss_7EA00__fzgx_offset_10;
u32 lbl_1_bss_7EA00__fzgx_offset_14[9];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B180;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B188;
    s = *(u8 *)&lbl_1_bss_7B190;
    s = *(u8 *)&lbl_1_bss_7B198;
    s = *(u8 *)&lbl_1_bss_7B19C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B1A4;
    s = *(u8 *)&lbl_1_bss_7B1A4__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B1AC;
    s = *(u8 *)&lbl_1_bss_7B1AC__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_7B1AC__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_7B1AC__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7C584;
    s = *(u8 *)&lbl_1_bss_7C584__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_7C584__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_7C584__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_7C848;
    s = *(u8 *)&lbl_1_bss_7C850;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7C85C;
    s = *(u8 *)&lbl_1_bss_7C85C__fzgx_offset_70;
    s = *(u8 *)&lbl_1_bss_7C8CD;
    s = *(u8 *)&lbl_1_bss_7C8CE;
    s = *(u8 *)&lbl_1_bss_7C8CE__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_7C914;
    s = *(u8 *)&lbl_1_bss_7C948;
    s = *(u8 *)&lbl_1_bss_7C94C;
    s = *(u8 *)&lbl_1_bss_7CA58;
    s = *(u8 *)&lbl_1_bss_7E9E8__fzgx_offset_0;
    s = *(u8 *)&lbl_1_bss_7E9E8__fzgx_offset_10;
    s = *(u8 *)&lbl_1_bss_7E9E8__fzgx_offset_14;
    s = *(u8 *)&lbl_1_bss_7EA00;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_C;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_D;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_E;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_10;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_14;
}
#pragma section code_type ".text"

void fn_1_EB330(void) {
    
    u8 *entry = (u8 *)&fzgx_obj_lbl_1_bss_7C584;
    s32 i;
    u8 local[0x2c];

    for (i = 0; i < 0x7f; i++, entry += 4) {
        if (*(u32 *)entry != 0) {
            fn_1_46B4(lbl_801A6410, *(u32 *)entry, lbl_1_data_3E62C, 0x626);
        }
    }

    lbl_1_bss_7E9E8__fzgx_offset_10 = -1;
    fzgx_obj_lbl_1_bss_7B1A4 = 1;
    fn_80008BEC((u8 *)&fzgx_obj_lbl_1_bss_7B1AC, 0, 0x13d8);
    fn_80008BEC((u8 *)&fzgx_obj_lbl_1_bss_7C584, 0, 0x1fc);

    if (fn_1_B7E98(0) == 0 && fn_1_B7E98(1) == 0) {
        lbl_1_bss_7E9E8__fzgx_offset_14 = 0;
        return;
    }

    fn_1_B9C0C();
    fn_1_B9BE0();
    fn_80008BEC(local, 0, 0x24);
    fn_80008BEC(&lbl_1_bss_77380, 0, 0x30);
    local[0] = 2;
    *(u32 *)(local + 0xc) = (u32)&lbl_1_bss_77380;
    *(u32 *)(local + 0x20) = 4;

    if (fn_1_B7E98(0) != 0 && fn_1_B7E98(1) != 0) {
        fn_1_AA6D8(4, 2, local);
    } else {
        fn_1_AA6D8(4, 4, local);
    }

    lbl_1_bss_7E9E8__fzgx_offset_14 = 1;
    lbl_1_bss_7EA00 = 0;
    fn_1_F1D70();
    lbl_1_bss_7EA00__fzgx_offset_4 = 0x14;
    lbl_1_bss_7EA00__fzgx_offset_8 = 0;
    lbl_1_bss_7EA00__fzgx_offset_C = 0;
    lbl_1_bss_7EA00__fzgx_offset_10 = 0;
}
/* fzgx:end fn_1_EB330 */

/* fzgx:begin fn_1_EB85C */
typedef struct {
    u8 pad_0[0x1];
    u8 unk_1;
    u8 pad_2[0x26];
} GhostEntry;

int fn_1_EB85C(void) {
    int result;
    GhostEntry *entry;
    int i;

    if (fn_1_B7C00() != 0) {
        return 0;
    }

    if ((s32)lbl_1_bss_7B1A4 == 0) {
        return 0;
    }

    result = fn_1_F21B8(lbl_1_bss_8B3A0.unk_90) != 0;
    entry = (GhostEntry *)&lbl_1_bss_7B1AC;
    for (i = 0; i < 0x7f; i++) {
        if (lbl_1_bss_8B3A0.unk_90 == entry[i].unk_1) {
            result++;
        }
    }

    return result;
}
/* fzgx:end fn_1_EB85C */

/* fzgx:begin fn_1_EC900 */
// Return the current ghost state value.
u32 fn_1_EC900(void) {
    return lbl_1_bss_7B1A4;
}
/* fzgx:end fn_1_EC900 */

/* fzgx:begin fn_1_ECDFC */
// fn_1_ECDFC: empty in retail (single blr).
void fn_1_ECDFC(void) {
}
/* fzgx:end fn_1_ECDFC */

/* fzgx:begin fn_1_ECE00 */
// fn_1_ECE00: empty in retail (single blr).
void fn_1_ECE00(void) {
}
/* fzgx:end fn_1_ECE00 */

/* fzgx:begin fn_1_ECE04 noprologue */
#include "types.h"

// Resets ghost playback state and rebuilds active ghost records.










extern u8 lbl_1_bss_7B180[];
extern const f32 lbl_1_rodata_6B60;
extern const f32 lbl_1_rodata_6C90;
extern int lbl_1_data_3E530;

extern void *fn_1_8627C(int i);
extern int fn_1_F2F34(void);
extern void fn_1_ECF88(void);
extern void fn_1_98634(f32 v);
extern void fn_1_983CC(void *rec, int v);

void fn_1_ECE04(void) {
    u8 *const g = lbl_1_bss_7B180;

    *(u32 *)(g + 0x3894) = 0;
    *(u8 *)(g + 0x174c) = 0;
    *(u8 *)(g + 0x174d) = 0;
    *(void **)(g + 0x3898) = fn_1_8627C(0);
    *(f32 *)(g + 0x389c) = lbl_1_rodata_6B60;
    *(f32 *)(g + 0x38a0) = lbl_1_rodata_6B60;
    *(u8 *)(g + 0x38a4) = 0;
    *(u8 *)(g + 0x38a5) = 0;
    *(u8 *)(g + 0x38a6) = 0;
    *(u32 *)(g + 0x38a8) = 0;

    if (fn_1_F2F34() == 0) {
        *(u32 *)(g + 0x1820) = 0;
        *(u32 *)(g + 0x38ac) = *(u32 *)(g + 0x16e4);
        *(u32 *)(g + 0x38b0) = *(u32 *)(g + 0x16e8);
        *(u32 *)(g + 0xc) = 0;
        *(u32 *)(g + 0x0) = 0;
        *(u32 *)(g + 0x14) = 0;
        fn_1_ECF88();
        lbl_1_data_3E530 = 2;
        *(u32 *)(g + 0x38b4) = 0;
        *(u32 *)(g + 0x38b8) = 0;
    } else {
        lbl_1_data_3E530 = 3;
    }

    {
        s32 *p17dc = (s32 *)(g + 0x17dc);
        s32 *p1794 = (s32 *)(g + 0x1794);
        u8 *pg = g + 0x19c8;
        s32 *p17a8 = (s32 *)(g + 0x17a8);
        u32 i;

        for (i = 0; i < *(u8 *)(g + 0x174e); i++) {
            if (*p17dc == 0) {
                fn_1_98634(lbl_1_rodata_6C90);
                fn_1_983CC(pg, *p1794);
                fn_1_98634(lbl_1_rodata_6B60);
            } else {
                fn_1_98634(lbl_1_rodata_6C90);
                fn_1_983CC(pg, *p17a8 + 0x6e0);
                fn_1_98634(lbl_1_rodata_6B60);
            }
            p17dc++;
            p1794++;
            pg += 0x620;
            p17a8++;
        }
    }
}
/* fzgx:end fn_1_ECE04 */

/* fzgx:begin fn_1_ECF68 */
void fn_1_ECF68(void) {
    fn_1_F23E8();
}
/* fzgx:end fn_1_ECF68 */

/* fzgx:begin fn_1_EE3F4 */
extern void fn_1_F143C(void *, s32, void *, void *, void *);

void fn_1_EE3F4(void) {
    u8 *base;
    void *unk_38c4;
    void *unk_39b4;
    void *unk_39f0;
    f32 **unk_1600;
    u32 *unk_1824;
    u16 *unk_1800;
    void *unk_3a04;
    void *unk_3af4;
    void *unk_19c8;
    s32 i;
    u16 value;
    f32 converted;
    base = (u8 *)&lbl_1_bss_7B180;
    i = 0;
    unk_38c4 = base + 0x38c4;
    unk_39b4 = base + 0x39b4;
    unk_39f0 = base + 0x39f0;
    unk_1600 = (f32 **)(base + 0x1600);
    unk_1824 = (u32 *)(base + 0x1824);
    unk_1800 = (u16 *)(base + 0x1800);
    unk_3a04 = base + 0x3a04;
    unk_3af4 = base + 0x3af4;
    unk_19c8 = base + 0x19c8;

    while ((u32)i < base[0x174e]) {
        fn_1_F0D10(i, unk_38c4);
        fn_1_F0B5C(i, unk_39b4);
        fn_1_F0E00(i, unk_39f0);
        if (!fn_1_3F164()) {
            value = *unk_1800;
            converted = (f32)(u32)value;
            if (converted < (*unk_1600)[*unk_1824 - 1]) {
                *unk_1800 = value + 1;
            }
        }
        fn_1_F0D10(i, unk_3a04);
        fn_1_F0B5C(i, unk_3af4);
        fn_1_F143C(unk_19c8, i, unk_3af4, unk_39b4, unk_3a04);
        unk_38c4 = (u8 *)unk_38c4 + 0x30;
        unk_39b4 = (u8 *)unk_39b4 + 0xc;
        unk_39f0 = (u8 *)unk_39f0 + 4;
        unk_1600++;
        unk_1824++;
        unk_1800++;
        unk_3a04 = (u8 *)unk_3a04 + 0x30;
        unk_3af4 = (u8 *)unk_3af4 + 0xc;
        unk_19c8 = (u8 *)unk_19c8 + 0x620;
        i++;
    }
}
/* fzgx:end fn_1_EE3F4 */

/* fzgx:begin fn_1_EF0A0 */
// fn_1_EF0A0: empty in retail (single blr).
void fn_1_EF0A0(void) {
}
/* fzgx:end fn_1_EF0A0 */

/* fzgx:begin fn_1_EF0A4 */
// fn_1_EF0A4: empty in retail (single blr).
void fn_1_EF0A4(void) {
}
/* fzgx:end fn_1_EF0A4 */

/* fzgx:begin fn_1_EF484 */
// fn_1_EF484: empty in retail (single blr).
void fn_1_EF484(void) {
}
/* fzgx:end fn_1_EF484 */

/* fzgx:begin fn_1_EF488 */
void fn_1_EF488(void) {
    fn_1_EE530();
    if (!fn_1_B7C00()) {
        fn_1_B9BE0();
        fn_1_B9DE8(&lbl_1_bss_7ECB4);
        lbl_1_bss_7ECB4.unk_0 = 4;
        lbl_1_bss_7ECB4.unk_4 = 9;
        lbl_1_bss_7EA00[0] = 0;
        lbl_1_data_3E52C = 13;
    }
}
/* fzgx:end fn_1_EF488 */

/* fzgx:begin fn_1_EF4F4 */
// fn_1_EF4F4: empty in retail (single blr).
void fn_1_EF4F4(void) {
}
/* fzgx:end fn_1_EF4F4 */

/* fzgx:begin fn_1_EF4F8 */
#include "types.h"

typedef struct {
    u8 pad_000[0x1D4];
    s32 state;
    u8 pad_1D8[0x08];
    s32 saved_state;
    u8 work[0x100];
} MainRelData;

typedef struct {
    u32 unk_0;
    u8 pad_4[0x2C0];
} fn_1_EF4F8_Obj_1_bss_7C584;

typedef struct {
    u32 unk_0;
    u8 unk_4;
    u8 pad_5[0xF];
    u8 unk_14;
    u8 pad_15[0x33];
} fn_1_EF4F8_Obj_1_bss_7ECB4;

extern s32 fn_1_BA144(fn_1_EF4F8_Obj_1_bss_7ECB4 *);
extern void fn_1_BC310(fn_1_EF4F8_Obj_1_bss_7ECB4 *);
extern void fn_1_BC29C(fn_1_EF4F8_Obj_1_bss_7ECB4 *);

void fn_1_EF4F8(void) {
    struct { u32 * value; } entries;
    s32 i;
    MainRelData *data;
    u32 *global;
    s32 zero;
    s32 status;

    data = &(*(MainRelData *)&lbl_1_data_3E358);
    fn_1_EE530();
    status = (s8)fn_1_BA144(&(*(fn_1_EF4F8_Obj_1_bss_7ECB4 *)&lbl_1_bss_7ECB4));
    if (status == 2) {
        fn_1_BC310(&(*(fn_1_EF4F8_Obj_1_bss_7ECB4 *)&lbl_1_bss_7ECB4));
        return;
    }
    if (status == 0) {
        data->state = 5;
        return;
    }

    fn_1_BC29C(&(*(fn_1_EF4F8_Obj_1_bss_7ECB4 *)&lbl_1_bss_7ECB4));
    fn_1_B9C0C();
    entries.value = (u32 *)&(*(fn_1_EF4F8_Obj_1_bss_7C584 *)&lbl_1_bss_7C584);
    global = &(*(u32 *)&lbl_801A6410);
    i = 0;
    zero = 0;
    for (; i < 0x7F; i++) {
        if (*entries.value != 0) {
            fn_1_46B4(*global, *entries.value, &data->work[0xF0], 0xEBA);
            *entries.value = zero;
        }
        entries.value++;
    }
    data->state = data->saved_state;
    fn_1_1596DC(2);
    fn_1_484CC(2);
}
/* fzgx:end fn_1_EF4F8 */

/* fzgx:begin fn_1_EF5DC */
// fn_1_EF5DC: empty in retail (single blr).
void fn_1_EF5DC(void) {
}
/* fzgx:end fn_1_EF5DC */

/* fzgx:begin fn_1_EF764 */
// fn_1_EF764: empty in retail (single blr).
void fn_1_EF764(void) {
}
/* fzgx:end fn_1_EF764 */

/* fzgx:begin fn_1_EF768 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/ghost.h"

extern void fn_1_EE530(void);
extern u32 fn_1_4630(u32, u32, const void *, u32);
extern void fn_80008BA8(void *, const void *, u32);
extern void fn_1_C0510(void *);
extern void fn_1_46B4(u32, u32, void *, u32);
extern u32 lbl_801A6410[];

typedef struct {
    u8 pad_0[8];
    u32 unk_8;
    u32 unk_c;
    u32 unk_10;
} Obj_3B34;

typedef struct {
    u8 pad_0[0x1c];
    u32 unk_1c;
    u8 pad_20[0xc];
    u8 unk_2c[0x28];
    u8 pad_54[0x13b0];
    u32 unk_1404[0x7f];
    u8 pad_1600[0x2534];
    Obj_3B34 unk_3b34;
} GhostState;

typedef struct lbl_1_bss_7B19C_t {
    u32 unk_1c;
    u8 pad_4[0x4];
} lbl_1_bss_7B19C_t;

typedef struct lbl_1_bss_7B1AC_t {
    u8 unk_2c[0x28];
    u8 pad_28[0x13b0];
} lbl_1_bss_7B1AC_t;

typedef struct lbl_1_bss_7C584_t {
    u32 unk_1404[0x7f];
    u8 pad_1FC[0xc8];
} lbl_1_bss_7C584_t;

typedef struct lbl_1_bss_7ECB4_t {
    Obj_3B34 unk_3b34;
    u8 pad_14[0x34];
} lbl_1_bss_7ECB4_t;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_7B180[2];
u32 fzgx_obj_lbl_1_bss_7B188[2];
u32 lbl_1_bss_7B190[2];
u32 lbl_1_bss_7B198;
lbl_1_bss_7B19C_t lbl_1_bss_7B19C;
u32 fzgx_obj_lbl_1_bss_7B1A4[2];
lbl_1_bss_7B1AC_t fzgx_obj_lbl_1_bss_7B1AC;
lbl_1_bss_7C584_t fzgx_obj_lbl_1_bss_7C584;
u32 lbl_1_bss_7C848[2];
u32 lbl_1_bss_7C850[3];
u32 fzgx_obj_lbl_1_bss_7C85C[28];
u8 lbl_1_bss_7C85C__fzgx_offset_70;
u8 lbl_1_bss_7C8CD;
u16 lbl_1_bss_7C8CE;
u32 lbl_1_bss_7C8CE__fzgx_offset_2[17];
u32 lbl_1_bss_7C914[13];
u32 lbl_1_bss_7C948;
u32 lbl_1_bss_7C94C[67];
u32 lbl_1_bss_7CA58[2020];
u32 fzgx_obj_lbl_1_bss_7E9E8[6];
u32 lbl_1_bss_7EA00[14];
u32 lbl_1_bss_7EA38[159];
lbl_1_bss_7ECB4_t fzgx_obj_lbl_1_bss_7ECB4;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B180;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B188;
    s = *(u8 *)&lbl_1_bss_7B190;
    s = *(u8 *)&lbl_1_bss_7B198;
    s = *(u8 *)&lbl_1_bss_7B19C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B1A4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B1AC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7C584;
    s = *(u8 *)&lbl_1_bss_7C848;
    s = *(u8 *)&lbl_1_bss_7C850;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7C85C;
    s = *(u8 *)&lbl_1_bss_7C85C__fzgx_offset_70;
    s = *(u8 *)&lbl_1_bss_7C8CD;
    s = *(u8 *)&lbl_1_bss_7C8CE;
    s = *(u8 *)&lbl_1_bss_7C8CE__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_7C914;
    s = *(u8 *)&lbl_1_bss_7C948;
    s = *(u8 *)&lbl_1_bss_7C94C;
    s = *(u8 *)&lbl_1_bss_7CA58;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7E9E8;
    s = *(u8 *)&lbl_1_bss_7EA00;
    s = *(u8 *)&lbl_1_bss_7EA38;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7ECB4;
}
#pragma section code_type ".text"

void fn_1_EF768(void) {
    u32 *p;
    u32 i;
    u32 v;
    u32 h;
    Obj_3B34 *o;

    
    fn_1_EE530();
    h = fn_1_4630(lbl_801A6410[0], 0x3ea8, lbl_1_data_3E62C, 0xf14);
    lbl_1_bss_7B19C.unk_1c = h;
    fn_80008BA8((void *)h, fzgx_obj_lbl_1_bss_7B1AC.unk_2c, 0x28);
    fn_80008BA8((void *)(lbl_1_bss_7B19C.unk_1c + 0x28), (const void *)fzgx_obj_lbl_1_bss_7C584.unk_1404[0], 0x3e80);
    o = &fzgx_obj_lbl_1_bss_7ECB4.unk_3b34;
    o->unk_8 = lbl_1_bss_7B19C.unk_1c;
    o->unk_c = 0x3ea8;
    o->unk_10 = 2;
    fn_1_C0510(o);
    p = fzgx_obj_lbl_1_bss_7C584.unk_1404;
    for (i = 0; i < 0x7f; i++) {
        v = p[i];
        if (v != 0) {
            fn_1_46B4(lbl_801A6410[0], v, lbl_1_data_3E62C, 0xf28);
            p[i] = 0;
        }
    }
    lbl_1_data_3E52C = 7;
}
/* fzgx:end fn_1_EF768 */

/* fzgx:begin fn_1_EF85C */
// fn_1_EF85C: empty in retail (single blr).
void fn_1_EF85C(void) {
}
/* fzgx:end fn_1_EF85C */

/* fzgx:begin fn_1_EF860 */
void fn_1_EF860(void) {
    u8 *base = lbl_1_data_3E358;
    u32 value;

    fn_1_EE530();
    if (!fn_1_B7C00()) {
        if (!fn_1_B7CD4()) {
            value = fn_1_B7C5C();
            OSReport((const char *)(base + 0x3ac), value);
        }
        if (lbl_1_bss_7B19C[0] != 0) {
            fn_1_46B4(lbl_801A6410[0], lbl_1_bss_7B19C[0],
                      (void *)(base + 0x2d4), 0xf44);
            lbl_1_bss_7B19C[0] = 0;
        }
        if (lbl_1_bss_7ECB4.unk_14 == (s8)8) {
            fn_1_C1394();
            *((u32 *)(base + 0x1d4)) = 0xd;
        } else {
            *((u32 *)(base + 0x1d4)) = 8;
        }
    }
}
/* fzgx:end fn_1_EF860 */

/* fzgx:begin fn_1_EF920 */
// fn_1_EF920: empty in retail (single blr).
void fn_1_EF920(void) {
}
/* fzgx:end fn_1_EF920 */

/* fzgx:begin fn_1_EF924 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/phys.h"

extern void fn_1_EE530(void);
extern u8 lbl_1_bss_7ECB4[72];
extern void fn_1_BC29C(u8 *);
extern void fn_1_B9C0C(void);
extern void fn_1_1596DC(s32);
extern void fn_1_484CC(s32);

void fn_1_EF924(void) {
    fn_1_EE530();
    lbl_1_data_3E52C = lbl_1_data_3E538;
    fn_1_BC29C(lbl_1_bss_7ECB4);
    fn_1_B9C0C();
    fn_1_1596DC(2);
    fn_1_484CC(2);
}
/* fzgx:end fn_1_EF924 */

/* fzgx:begin fn_1_EF978 */
// fn_1_EF978: empty in retail (single blr).
void fn_1_EF978(void) {
}
/* fzgx:end fn_1_EF978 */

/* fzgx:begin fn_1_EF97C */
void fn_1_EF97C(void) {
    u8 *base = lbl_1_data_3E358;

    fn_1_EE530();

    if ((lbl_1_bss_9F8.unk_8 >> 8) & 1) {
        *(s32 *)(base + 0x1D4) = 10;
    }

    fn_1_49410();
    fn_1_495FC();
    fn_1_496FC(lbl_1_rodata_6D20, lbl_1_rodata_6D24);
    fn_1_495C8(9);

    if (lbl_1_bss_7B198) {
        fn_1_4AE0C(base + 0x40C);
    } else {
        fn_1_4AE0C(base + 0x458);
    }
}
/* fzgx:end fn_1_EF97C */

/* fzgx:begin fn_1_EFA18 */
// fn_1_EFA18: empty in retail (single blr).
void fn_1_EFA18(void) {
}
/* fzgx:end fn_1_EFA18 */

/* fzgx:begin fn_1_EFA1C */
// lbl_1_data_3E52C: .data size 0x4, 5 refs from phys.c (own data block)
extern u32 lbl_1_data_3E52C;
// lbl_1_data_3E538: .data size 0x4, 2 refs from phys.c (own data block)
extern u32 lbl_1_data_3E538;

void fn_1_EFA1C(void) {
    fn_1_EE530();
    lbl_1_data_3E52C = lbl_1_data_3E538;
}
/* fzgx:end fn_1_EFA1C */

/* fzgx:begin fn_1_EFA4C */
// fn_1_EFA4C: empty in retail (single blr).
void fn_1_EFA4C(void) {
}
/* fzgx:end fn_1_EFA4C */

/* fzgx:begin ghost_reset */
void ghost_reset(void) {
    lbl_1_bss_7C8CE[0] = 0;
    lbl_1_data_3E52C = -1;
    fn_1_F1D70();
}
/* fzgx:end ghost_reset */

/* fzgx:begin fn_1_EFA88 */
// fn_1_EFA88: empty in retail (single blr).
void fn_1_EFA88(void) {
}
/* fzgx:end fn_1_EFA88 */

/* fzgx:begin fn_1_F0164 */
// fn_1_F0164: empty in retail (single blr).
void fn_1_F0164(void) {
}
/* fzgx:end fn_1_F0164 */

/* fzgx:begin fn_1_F143C */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    u32 field_0;
    s16 field_4;
    s16 field_6;
    u8 _pad8[0x74];
    Vec3 field_7c;
    u8 _pad88[0x64];
    u8 _pad_ec[0x60];
    u8 field_14c[0xb4];
    f32 field_200;
    u8 _pad204[0x20];
    f32 field_224;
    u8 _pad228[0x24d];
    u8 field_475;
} FnObject;

#pragma opt_common_subs off
void fn_1_F143C(FnObject *obj, s32 index, const f32 *a, const f32 *b, void *arg5) {
    u32 *entry;
    f32 dz;
    f32 dy;
    f32 dx;
    f32 d2;
    f32 t;

    obj->field_4 = -2;
    entry = (u32 *)lbl_1_bss_7C914[index];
    if (entry != 0) {
        obj->field_6 = *((s8 *)entry + 0x328);
    }

    obj->field_7c = *(const Vec3 *)a;
    obj->field_0 = 0x400;
    lbl_8006DD14(arg5, obj->_pad_ec);
    obj->field_475 = 0;

    dx = a[0];
    dx = dx - b[0];
    dy = a[1];
    dy = dy - b[1];
    dz = a[2];
    dz = dz - b[2];
    d2 = dx * dx;
    d2 = d2 + dy * dy;
    d2 = d2 + dz * dz;

    if (d2 < lbl_1_rodata_6D38) {
        t = lbl_8006D0B4(d2 / lbl_1_rodata_6D38);
        t = lbl_8006D0B4(t);
        obj->field_224 = lbl_1_rodata_6D3C * t;
        obj->field_200 = lbl_1_rodata_6D40 * t;
    } else {
        obj->field_224 = lbl_1_rodata_6D3C;
        obj->field_200 = lbl_1_rodata_6D40;
    }

    lbl_8006D7DC((void *)a);
    lbl_8006DFC4(arg5);
    lbl_8006DB74(obj->field_14c);
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_F143C */

/* fzgx:begin fn_1_F1588 */
u32 fn_1_F1588(void) {
    u32 value = lbl_1_bss_7EA38[0];

    if (value == 0) {
        return 0;
    }

    if ((f32)value < lbl_1_rodata_6D10) {
        return value % 6 == 0;
    }

    if ((f32)value < lbl_1_rodata_6D44) {
        return value % 10 == 0;
    }

    return (value & 0xf) == 0;
}
/* fzgx:end fn_1_F1588 */

/* fzgx:begin fn_1_F1650 */
#include "types.h"

#pragma opt_common_subs off
f32 fn_1_F1650(const u32 *value) {
    s32 i;
    u32 bits = value[0];
    s32 sign = (s32)((bits >> 20) & 1);
    u32 exponent = (bits >> 15) & 0x1f;
    f32 place;
    f32 fraction;

    if ((bits >> 15) & 0x10) {
        exponent = ~(exponent - 16);
        exponent = exponent * -1;
    } else {
        exponent = exponent - 15;
    }

    {
    f32 fraction = lbl_1_rodata_6BD0;
    f32 place = lbl_1_rodata_6BBC;
    u32 mantissa = bits & 0x7fff;

    for (i = 0; i < 15; i++) {
        if (mantissa & (1 << (14 - i))) {
            fraction += place;
        }
        place *= lbl_1_rodata_6BBC;
    }

    fraction *= fn_80088598(lbl_1_rodata_6D48, (f64)(s32)exponent);

    if (sign != 0) {
        fraction *= lbl_1_rodata_6D50;
    }

    return fraction;
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_F1650 */

/* fzgx:begin fn_1_F17B4 */
#include "types.h"

s32 fn_1_F17B4(const void *value) {
    u32 bits;
    s32 exponent;
    s32 sign;
    s32 fraction;
    f64 converted;
    s32 magnitude;
    s32 result;

    fn_80008BA8(&bits, value, 4);

    exponent = (s32)((bits >> 23) & 0xff) - 0x7f;
    sign = bits >> 31;
    fraction = bits & 0x7fffff;

    if (exponent >= 0) {
        exponent = (exponent << 27) >> 27;
        exponent += 0xf;
    } else {
        converted = (f32)exponent;
        converted = __fabs(converted);
        magnitude = (s32)converted;
        magnitude = (magnitude << 27) >> 27;
        exponent = ~magnitude + 0x10;
        exponent = (exponent << 27) >> 27;
    }

    result = sign << 20;
    result += exponent << 15;
    result += fraction >> 8;
    return result;
}
/* fzgx:end fn_1_F17B4 */

/* fzgx:begin ghost_pack_bits */
void ghost_pack_bits(u32 *out, const u32 *x, const u32 *y, const u32 *z) {
    out[0] = 0;
    out[1] = 0;
    out[0] += x[0] << 10;
    out[0] += y[0] >> 11;
    out[1] += y[0] << 21;
    out[1] += z[0];
}
/* fzgx:end ghost_pack_bits */

/* fzgx:begin fn_1_F18C0 */
void fn_1_F18C0(const u32 *in, u32 *x, u32 *y, u32 *z) {
    x[0] = (in[0] >> 10) & 0x1fffff;
    y[0] = 0;
    y[0] += (in[0] & 0x3ff) << 11;
    y[0] += in[1] >> 21;
    z[0] = in[1] & 0x1fffff;
}
/* fzgx:end fn_1_F18C0 */

/* fzgx:begin fn_1_F190C */
void fn_1_F190C(void) {
    fn_80008BEC(&lbl_1_bss_7B1AC, 0, 0x13d8);
    fn_80008BEC(&lbl_1_bss_7C584, 0, 0x1fc);
}
/* fzgx:end fn_1_F190C */

/* fzgx:begin fn_1_F1950 */
// Set the transfer completion flag for the asynchronous callback.
void fn_1_F1950(void) {
    lbl_1_bss_7ECFC.unk_0 = 1;
}
/* fzgx:end fn_1_F1950 */

/* fzgx:begin fn_1_F1960 */
extern void ARQPostRequest(void *arg0, u32 arg1, u32 arg2, u32 arg3,
                        void *arg4, void *arg5, u32 arg6,
                        void (*callback)(void));

void fn_1_F1960(void *arg0, void *arg1, u32 arg2) {
    u32 result;
    u8 temp[0x20];
    // The completion flag is updated asynchronously by the callback.
    volatile u32 *flag;

    result = fn_8002071C(arg0);
    fn_800206FC(arg2);
    lbl_1_bss_7ECFC.unk_0 = 0;
    while (ARGetDMAStatus() != 0) {
    }
    DCFlushRange(arg1, arg2);
    ARQPostRequest(temp, 1, 0, 1, arg1, arg0, arg2, fn_1_F1950);
    flag = &lbl_1_bss_7ECFC.unk_0;
    while ((s32)*flag == 0) {
    }
    fn_800206FC(result);
}
/* fzgx:end fn_1_F1960 */

/* fzgx:begin fn_1_F1A24 noprologue */
#include "rel/main_rel/ghost.h"

extern u32 lbl_801A6410;
extern u8 lbl_1_data_3E358[];
extern void fn_1_F1950(void);
extern void fn_1_46B4(u32, u32, u8 *, u32);
extern u32 fn_1_4630(u32, u32, u8 *, u32);
extern u32 fn_8002071C(void);
extern void fn_800206FC(u32);
extern u32 ARGetDMAStatus(void);
extern void DCInvalidateRange(void *, u32);
extern void ARQPostRequest(void *, u32, u32, u32, u32, void *, u32, void (*)(void));
extern void OSReport(const char *, ...);

#pragma opt_common_subs off
#pragma opt_loop_invariants off
#pragma opt_strength_reduction off
static inline void fn_1_F1A24_read(u8 *bss, void *buf, u32 addr, u32 len) {
    s8 work[0x18];
    u32 old;

    old = fn_8002071C();
    fn_800206FC(len);
    *(u32 *)(bss + 0x3b7c) = 0;
    while (ARGetDMAStatus() != 0) {
    }
    DCInvalidateRange(buf, len);
    ARQPostRequest(work, 1, 1, 1, addr, buf, len, fn_1_F1950);
    while (*(s32 *)(bss + 0x3b7c) == 0) {
    }
    fn_800206FC(old);
}

void fn_1_F1A24(void) {
    u32 *entry;
    u32 size;
    u8 *bss;
    u8 *buffer;
    u8 *data;
    u32 i;

    data = lbl_1_data_3E358;
    bss = (u8 *)&lbl_1_bss_7B180;
    entry = (u32 *)(((0x16b4) + (bss)));
    size = 0xf24000;
    i = 0;
    while (i < bss[0x1754]) {
        if (((0) != (*entry))) {
            fn_1_46B4(lbl_801A6410, *entry, data + 0x2d4, 0x12a7);
        }
        *entry = fn_1_4630(lbl_801A6410, 0x3ec0, data + 0x2d4, 0x12a9);
        fn_1_F1A24_read(bss, (void *)*entry, size, 0x3ec0);
        buffer = (u8 *)(*entry);
        OSReport((const char *)(data + 0x4a0), *buffer);
        OSReport((const char *)(data + 0x4b0), buffer + 8);
        OSReport((const char *)(data + 0x4bc), *(u16 *)(buffer + 0x18));
        entry++;
        size += 0x3ec0;
        i++;
    }
}
#pragma opt_strength_reduction reset
#pragma opt_loop_invariants reset
#pragma opt_common_subs reset
/* fzgx:end fn_1_F1A24 */

/* fzgx:begin fn_1_F1B78 */
void fn_1_F1B78(u32 value) {
    lbl_1_bss_7C848[0] = value;
}
/* fzgx:end fn_1_F1B78 */

/* fzgx:begin fn_1_F1B84 */
u8 fn_1_F1B84(void) {
    return lbl_1_bss_7C8CD;
}
/* fzgx:end fn_1_F1B84 */

/* fzgx:begin fn_1_F1B94 noprologue */
#include "types.h"

// Compares current and rival lap times to return a race verdict.
















typedef struct { u8 _p[0x1e0]; u8 minute; u8 second; u16 msec; } PlayerRec;
typedef struct { u8 _p[0x24];  u8 minute; u8 second; u16 msec; } RivalRec;

extern s16 lbl_1_bss_960;
extern u8 lbl_1_bss_7B180[];
extern PlayerRec *fn_1_3F0D8(u8 i, f32 *outf, u8 *outb);

int fn_1_F1B94(void) {
    u8 *g = lbl_1_bss_7B180;
    int ret;
    if (lbl_1_bss_960 == 9) {
        if (*(s32*)(g + 0x16c8) >= 0) {
            f32 f;
            u8 b;
            PlayerRec *rec = fn_1_3F0D8(0, &f, &b);
            RivalRec *rival = *(RivalRec**)(g + 0x16b4);
            u32 player = rec->minute * 60000 + rec->second * 1000 + rec->msec;
            u32 other = rival->minute * 60000 + rival->second * 1000 + rival->msec;
            ret = (player >= other) ? 3 : 1;
        } else {
            ret = 0;
        }
    } else {
        ret = *(u8*)(g + 0x174c);
    }
    return ret;
}
/* fzgx:end fn_1_F1B94 */

/* fzgx:begin fn_1_F1D60 */
u32 fn_1_F1D60(void) {
    return lbl_1_bss_7C948;
}
/* fzgx:end fn_1_F1D60 */

/* fzgx:begin fn_1_F1D70 */
void fn_1_F1D70(void) {
    lbl_1_bss_7E9E8.unk_0 = 0;
    lbl_1_bss_7E9E8.unk_4 = 0;
    lbl_1_bss_7E9E8.unk_8 = 0;
    lbl_1_bss_7E9E8.unk_C = 0;
}
/* fzgx:end fn_1_F1D70 */

/* fzgx:begin fn_1_F1D8C */
void fn_1_F1D8C(s32 index) {
    if (index < 0x20) {
        lbl_1_bss_7E9E8.unk_0 |= 1 << index;
        return;
    }
    if (index < 0x40) {
        lbl_1_bss_7E9E8.unk_4 |= 1 << (index - 0x20);
        return;
    }
    if (index < 0x60) {
        lbl_1_bss_7E9E8.unk_8 |= 1 << (index - 0x40);
        return;
    }
    lbl_1_bss_7E9E8.unk_C |= 1 << (index - 0x60);
}
/* fzgx:end fn_1_F1D8C */

/* fzgx:begin fn_1_F1E30 */
void fn_1_F1E30(s32 index) {
    if (index < 0x20) {
        lbl_1_bss_7E9E8.unk_0 &= ~(1 << index);
    } else if (index < 0x40) {
        lbl_1_bss_7E9E8.unk_4 &= ~(1 << (index - 0x20));
    } else if (index < 0x60) {
        lbl_1_bss_7E9E8.unk_8 &= ~(1 << (index - 0x40));
    } else {
        lbl_1_bss_7E9E8.unk_C &= ~(1 << (index - 0x60));
    }
}
/* fzgx:end fn_1_F1E30 */

/* fzgx:begin fn_1_F1ED0 */
void fn_1_F1ED0(s32 index) {
    if (index < 0x20) {
        lbl_1_bss_7E9E8.unk_0 ^= 1 << index;
        return;
    }
    if (index < 0x40) {
        lbl_1_bss_7E9E8.unk_4 ^= 1 << (index - 0x20);
        return;
    }
    if (index < 0x60) {
        lbl_1_bss_7E9E8.unk_8 ^= 1 << (index - 0x40);
        return;
    }
    lbl_1_bss_7E9E8.unk_C ^= 1 << (index - 0x60);
}
/* fzgx:end fn_1_F1ED0 */

/* fzgx:begin ghost_test_flag */
// Tests whether a ghost flag is set in the corresponding 32-bit flag word.
u32 ghost_test_flag(s32 index) {
    if (index < 0x20) {
        return lbl_1_bss_7E9E8.unk_0 & (1 << index);
    }
    if (index < 0x40) {
        return lbl_1_bss_7E9E8.unk_4 & (1 << (index - 0x20));
    }
    if (index < 0x60) {
        return lbl_1_bss_7E9E8.unk_8 & (1 << (index - 0x40));
    }
    return lbl_1_bss_7E9E8.unk_C & (1 << (index - 0x60));
}
/* fzgx:end ghost_test_flag */

/* fzgx:begin fn_1_F2008 */
// Records the flag for the ghost entry identified by the decoded pair.
void fn_1_F2008(s32 arg) {
    s16 a;
    s16 b;
    s32 index;
    u8 *ghost_data;

    fn_1_12EF80((s16)arg, &a, &b);
    index = (a - 1) * 6 + b;
    ghost_data = (u8 *)&lbl_1_bss_7F0C0;
    ghost_data[0x4938 + index] |= 1;
}
/* fzgx:end fn_1_F2008 */

/* fzgx:begin ghost_test_record_flag0 */
// Tests the record flag selected by the supplied ghost identifier.
u32 ghost_test_record_flag0(s32 arg) {
    s16 a;
    s16 b;
    s32 index;
    u8 *record_flags;

    fn_1_12EF80((s16)arg, &a, &b);
    index = (a - 1) * 6 + b;
    record_flags = (u8 *)&lbl_1_bss_7F0C0;
    return record_flags[0x4938 + index] & 1;
}
/* fzgx:end ghost_test_record_flag0 */

/* fzgx:begin ghost_set_record_flag1 */
// Sets the second record flag for the record associated with arg.
void ghost_set_record_flag1(s32 arg) {
    s16 a;
    s16 b;
    s32 index;
    u8 *record_flags;

    fn_1_12EF80((s16)arg, &a, &b);
    index = (a - 1) * 6 + b;
    record_flags = (u8 *)&lbl_1_bss_7F0C0;
    record_flags[0x4938 + index] |= 2;
}
/* fzgx:end ghost_set_record_flag1 */

/* fzgx:begin fn_1_F210C */
u32 fn_1_F210C(s32 arg) {
    s16 out_a;
    s16 out_b;
    s32 index;
    u8 *flags;

    fn_1_12EF80((s16)arg, &out_a, &out_b);
    index = (out_a - 1) * 6 + out_b;
    flags = (u8 *)&lbl_1_bss_7F0C0;
    return flags[0x4938 + index] & 2;
}
/* fzgx:end fn_1_F210C */

/* fzgx:begin ghost_set_record_flag2 */
// Set the second flag on the record selected by the argument.
void ghost_set_record_flag2(s32 arg) {
    s16 record_group;
    s16 record_index;
    s32 flag_index;
    u8 *flags;

    fn_1_12EF80((s16)arg, &record_group, &record_index);
    flag_index = (record_group - 1) * 6 + record_index;
    flags = (u8 *)&lbl_1_bss_7F0C0;
    flags[0x4938 + flag_index] |= 4;
}
/* fzgx:end ghost_set_record_flag2 */

/* fzgx:begin fn_1_F21B8 */
// Return the selected record's second flag bit after decoding its table position.
s32 fn_1_F21B8(s32 arg) {
    s16 a;
    s16 b;
    s32 index;
    u8 *flags;

    fn_1_12EF80((s16)arg, &a, &b);
    index = (a - 1) * 6 + b;
    flags = (u8 *)&lbl_1_bss_7F0C0;
    return flags[0x4938 + index] & 4;
}
/* fzgx:end fn_1_F21B8 */

/* fzgx:begin fn_1_F220C */
// Logs the resolved course coordinates and marks the corresponding course as visited.
void fn_1_F220C(s32 arg) {
    s16 a;
    s16 b;
    s32 index;

    fn_1_12EF80((s16)arg, &a, &b);
    index = (a - 1) * 6 + b;
    OSReport((const char *)lbl_1_data_3E8A0, a, b, index);
    ((u8 *)&lbl_1_bss_7F0C0)[0x4938 + index] |= 8;
}
/* fzgx:end fn_1_F220C */

/* fzgx:begin fn_1_F2280 */
// Returns the flag for the state selected by the converted coordinates.
s32 fn_1_F2280(s32 arg) {
    s16 group;
    s16 entry;
    s32 index;
    u8 *state_flags;

    fn_1_12EF80((s16)arg, &group, &entry);
    index = (group - 1) * 6 + entry;
    state_flags = (u8 *)&lbl_1_bss_7F0C0;
    return state_flags[0x4938 + index] & 8;
}
/* fzgx:end fn_1_F2280 */

/* fzgx:begin fn_1_F22D4 */
u32 fn_1_F22D4(void) {
    return lbl_1_bss_7B190[0];
}
/* fzgx:end fn_1_F22D4 */

/* fzgx:begin fn_1_F22E4 */
extern void fn_1_12EF80(s16 arg, s16 *out_group, s16 *out_entry);
// lbl_1_data_3E53C: .data size 0x78, 1 refs from phys.c (own data block)
extern u8 lbl_1_data_3E53C[0x78];

// Maps a course selection to its associated data value.
s16 fn_1_F22E4(s32 arg) {
    s16 group;
    s16 entry;
    s32 index;

    fn_1_12EF80((s16)arg, &group, &entry);
    index = (group - 1) * 6 + entry;
    return (s16)((s32 *)lbl_1_data_3E53C)[index];
}
/* fzgx:end fn_1_F22E4 */

/* fzgx:begin fn_1_F2338 */
extern void fn_1_12EF80(s16 arg, s16 *out_group, s16 *out_entry);
// lbl_1_data_3E5B4: .data size 0x78, 2 refs from phys.c (own data block)
extern u8 lbl_1_data_3E5B4[0x78];

#include "types.h"

extern void fn_1_12EF80(s16 value, s16 *arg1, s16 *arg2);



u32 fn_1_F2338(s32 value, u32 target) {
    s16 group;
    s16 entry;
    u32 packed;
    u32 hour;
    u32 minute;
    u32 low;

    value = (s16)value;
    fn_1_12EF80(value, &group, &entry);
    packed = (*(u32 (*)[30])&lbl_1_data_3E5B4)[(group - 1) * 6 + entry];
    minute = (packed >> 12) & 0xff;
    hour = (packed >> 20) & 0xff;
    minute += 0xa;
    low = packed & 0xfff;

    if (minute > 0x3c) {
        minute -= 0x3c;
        hour += 1;
    }

    packed = (hour << 20) | (minute << 12) | low;
    if (packed > target) {
        return 1;
    }
    return 0;
}
/* fzgx:end fn_1_F2338 */

/* fzgx:begin fn_1_F23D8 */
void fn_1_F23D8(void) {
    lbl_1_bss_7ED58[0] = 0;
}
/* fzgx:end fn_1_F23D8 */

/* fzgx:begin fn_1_F2740 */
// lbl_1_data_3E5B4: .data size 0x78, 2 refs from phys.c (own data block)
extern u8 lbl_1_data_3E5B4[0x78];

u32 fn_1_F2740(u32 a, u32 b) {
    if (a >= 6) {
        return 0;
    }
    if (b >= 6) {
        return 0;
    }
    return ((u32 *)lbl_1_data_3E5B4)[(a - 1) * 6 + b];
}
/* fzgx:end fn_1_F2740 */
