#include "types.h"
#include "rel/replay/globals.h"

extern u32 fn_1_D0790(void);
extern u32 lbl_13_bss_38;
extern int fn_13_A40(void);
extern s32 fn_13_A48(void);
extern s16 lbl_1_bss_962;
extern struct fn_13_B08_lbl_13_data_18 lbl_13_data_18;
extern u32 lbl_1_bss_71688;
extern u32 lbl_1_bss_7168C;
extern u32 lbl_1_bss_26C60;
extern void fn_13_3FC(void);
extern u32 fn_1_3F038(void);
extern u32 lbl_13_bss_40;
extern u8 lbl_13_bss_3C;
extern u32 lbl_1_bss_7167C;
extern u32 lbl_1_bss_71680;
extern u32 lbl_1_bss_71684;
extern u16 lbl_1_bss_96A;
extern void fn_13_AFC(void);
extern void fn_13_B00(void);
extern void fn_13_B08(void);
extern void fn_1_A8F78(void);

/* fzgx:begin fn_13_0 */
typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u8 unk_4;
    u8 unk_5;
    u8 unk_6[5];
    u8 unk_b;
} ReplayPlayer;

typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u8 unk_4;
} ReplayEntrant;

typedef struct {
    u8 pad_0[0x8];
    u32 unk_8;
    u8 pad_c[0x2c];
    u8 unk_38[4];
    u8 unk_3c[4];
} ReplayHeader;

typedef struct {
    u8 pad_0[0x8];
    s16 unk_8;
} ReplayMode;

typedef struct {
    u8 data[0x81c0];
} ReplayGhost;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u8 *fzgx_obj_lbl_13_bss_0;
u32 fzgx_obj_lbl_13_bss_4;
ReplayPlayer lbl_13_bss_4__fzgx_offset_4[4];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_13_bss_0;
    s = *(u8 *)&fzgx_obj_lbl_13_bss_4;
    s = *(u8 *)&lbl_13_bss_4__fzgx_offset_4;
}
#pragma section code_type ".text"
extern u8 *lbl_801A63D0;
extern u32 lbl_801A63C0;
extern ReplayMode lbl_1_bss_8B3A0;
extern ReplayEntrant lbl_1_bss_26B80[];
extern ReplayHeader lbl_1_bss_7EFD8;

extern u32 fn_1_F453C(u8 *data, u32 *pos, u32 bits);
extern void fn_1_F47A0(u32);
extern u8 *fn_1_36AD0(void);
extern void fn_80008BA8(void *, void *, u32);
extern void fn_1_12F10C(u8 *);
extern void fn_80008BEC(void *, int, u32);
extern void fn_1_3EF8C(u8);
extern void fn_1_3ED8C(u32, u8, u32, u8, u32, u8, u32);
extern void fn_1_3EB78(u8, u8 *, u8 *, u32);
extern void fn_1_3EC88(u8, ReplayPlayer *);
extern void fn_1_3EFF0(void *, u8);
extern void fn_1_3FCB0(u32);
extern void fn_1_3FCD4(u32);
extern void fn_13_A6C(void *);

void fn_13_0(void) {
    u32 count;
    u32 course;
    ReplayEntrant *entrant;
    u8 index;
    u32 i;
    u8 active;
    u8 mode;
    u8 flag;
    u8 version;
    s32 j;
    u8 slots[4];
    u8 bits[4];

    fzgx_obj_lbl_13_bss_4 = 0;
    fzgx_obj_lbl_13_bss_0 = lbl_801A63D0;
    fn_1_F453C(fzgx_obj_lbl_13_bss_0, &fzgx_obj_lbl_13_bss_4, 8);
    version = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &fzgx_obj_lbl_13_bss_4, 7);
    course = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &fzgx_obj_lbl_13_bss_4, 6);
    fn_1_F47A0(fn_1_F453C(fzgx_obj_lbl_13_bss_0, &fzgx_obj_lbl_13_bss_4, 32));
    lbl_801A63C0 = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &fzgx_obj_lbl_13_bss_4, 32);
    count = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &fzgx_obj_lbl_13_bss_4, 5);
    lbl_1_bss_8B3A0.unk_8 = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &fzgx_obj_lbl_13_bss_4, 3);
    fn_1_F453C(fzgx_obj_lbl_13_bss_0, &fzgx_obj_lbl_13_bss_4, 2);
    flag = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &fzgx_obj_lbl_13_bss_4, 1);
    mode = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &fzgx_obj_lbl_13_bss_4, 7);
    active = 0;
    for (i = 0; i < count; i++) {
        entrant = &lbl_1_bss_26B80[i];
        entrant->unk_0 = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &fzgx_obj_lbl_13_bss_4, 1);
        entrant->unk_1 = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &fzgx_obj_lbl_13_bss_4, 6);
        if (version >= 3) {
            entrant->unk_4 = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &fzgx_obj_lbl_13_bss_4, 5);
        }
        if (version >= 2) {
            entrant->unk_3 = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &fzgx_obj_lbl_13_bss_4, 7);
        }
        if (entrant->unk_0 != 0) {
            entrant->unk_2 = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &fzgx_obj_lbl_13_bss_4, 2);
            if (version < 2) {
                entrant->unk_3 = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &fzgx_obj_lbl_13_bss_4, 7);
            }
            index = active;
            slots[index] = entrant->unk_1;
            bits[index] = entrant->unk_2;
            if ((u8)fn_1_F453C(fzgx_obj_lbl_13_bss_0, &fzgx_obj_lbl_13_bss_4, 1) != 0) {
                for (j = 0; j < sizeof(ReplayGhost); j++) {
                    ((u8 *)((ReplayGhost *)fn_1_36AD0() + i))[j] = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &fzgx_obj_lbl_13_bss_4, 8);
                }
                {
                    u8 *src = (u8 *)((ReplayGhost *)fn_1_36AD0() + i) + 4;
                    fn_80008BA8(&lbl_13_bss_4__fzgx_offset_4[index], src, 12);
                }
                fn_1_12F10C(fn_1_36AD0());
            } else {
                lbl_13_bss_4__fzgx_offset_4[index].unk_1 = entrant->unk_1;
                lbl_13_bss_4__fzgx_offset_4[index].unk_2 = 1 << entrant->unk_2;
                lbl_13_bss_4__fzgx_offset_4[index].unk_b = entrant->unk_3;
                lbl_13_bss_4__fzgx_offset_4[index].unk_4 = 0;
                lbl_13_bss_4__fzgx_offset_4[index].unk_3 = 0;
                lbl_13_bss_4__fzgx_offset_4[index].unk_5 = 0;
                lbl_13_bss_4__fzgx_offset_4[index].unk_0 = 0;
                fn_80008BEC(lbl_13_bss_4__fzgx_offset_4[i].unk_6, 'A', 5);
            }
            active++;
        } else {
            entrant->unk_2 = 0;
            entrant->unk_3 = 0;
        }
    }
    if (version >= 4) {
        for (j = 0; j < (u8)active; j++) {
            lbl_1_bss_7EFD8.unk_3c[j] = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &fzgx_obj_lbl_13_bss_4, 1);
        }
    }
    for (j = 0; j < (u8)active; j++) {
        lbl_1_bss_7EFD8.unk_38[j] = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &fzgx_obj_lbl_13_bss_4, 2) + 1;
    }
    if (version >= 5) {
        lbl_1_bss_7EFD8.unk_8 = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &fzgx_obj_lbl_13_bss_4, 20);
    }
    fn_1_3EF8C(6);
    fn_1_3ED8C(0, mode, 1, course, 10, count, 0);
    fn_1_3EB78(active, slots, bits, 0);
    fn_1_3EC88(active, lbl_13_bss_4__fzgx_offset_4);
    fn_1_3EFF0(fn_13_A6C, 1);
    if (flag != 0) {
        fn_1_3FCB0(0x20000);
    } else {
        fn_1_3FCD4(0x20000);
    }
    fn_1_3FCB0(0x800000);
}
/* fzgx:end fn_13_0 */

/* fzgx:begin fn_13_3FC */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} ReplayVec;

typedef struct {
    u32 start : 15;
    u32 unk_0_14 : 3;
    u32 unk_0_9 : 5;
    u32 unk_0_4 : 5;
    u32 pad_0 : 4;
    u32 end : 15;
    u32 unk_4_12 : 5;
    u32 unk_4_7 : 5;
    u32 unk_4_2 : 5;
    u32 pad_4 : 2;
    ReplayVec unk_8[4];
    ReplayVec unk_38[4];
    ReplayVec unk_68;
    ReplayVec unk_74;
} ReplayEvent;

typedef struct {
    u8 unk_0[7];
} ReplayInput;

typedef struct {
    u8 pad_0[0xa0];
    u16 unk_a0;
    u8 pad_a2[0x2];
    ReplayInput unk_a4[9264];
    u8 pad_fdf4[0xfc];
    u16 unk_fef0;
    u8 pad_fef2[0x5a];
    ReplayEvent unk_ff4c[1];
} ReplayData;

typedef struct {
    u8 pad_0[0x8];
    u32 unk_8;
    u8 pad_c[0xc];
    u8 unk_18;
    u8 pad_19[0x1f];
    u8 unk_38[4];
    u8 unk_3c[4];
    ReplayData *unk_40;
} ReplayHeader;

typedef struct {
    u8 pad_0[0x8];
    u8 unk_8;
    u8 pad_9[0x14af];
} ReplayInfo;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u8 *fzgx_obj_lbl_13_bss_0;
u32 fzgx_obj_lbl_13_bss_4;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_13_bss_0;
    s = *(u8 *)&fzgx_obj_lbl_13_bss_4;
}
#pragma section code_type ".text"

extern ReplayHeader lbl_1_bss_7EFD8;

extern u32 fn_1_F453C(u8 *data, u32 *pos, u32 bits);
extern void fn_80008BA8(void *, void *, u32);
extern void fn_1_3EF14(ReplayInfo *);
extern void fn_1_F4794(u16);

static inline f32 replay_read_f32(void) {
    u32 bits;
    f32 value;

    bits = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &fzgx_obj_lbl_13_bss_4, 32);
    fn_80008BA8(&value, &bits, 4);
    return value;
}

void fn_13_3FC(void) {
    ReplayInfo info;
    s32 i;
    s32 j;
    ReplayEvent *event;

    fn_1_3EF14(&info);
    lbl_1_bss_7EFD8.unk_40->unk_fef0 = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &fzgx_obj_lbl_13_bss_4, 8);
    lbl_1_bss_7EFD8.unk_18 = info.unk_8;
    for (i = 0; i < lbl_1_bss_7EFD8.unk_40->unk_fef0; i++) {
        lbl_1_bss_7EFD8.unk_40->unk_ff4c[i].start = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &fzgx_obj_lbl_13_bss_4, 14);
        lbl_1_bss_7EFD8.unk_40->unk_ff4c[i].end = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &fzgx_obj_lbl_13_bss_4, 14);
        lbl_1_bss_7EFD8.unk_40->unk_ff4c[i].unk_0_14 = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &fzgx_obj_lbl_13_bss_4, 4);
        lbl_1_bss_7EFD8.unk_40->unk_ff4c[i].unk_0_9 = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &fzgx_obj_lbl_13_bss_4, 5);
        lbl_1_bss_7EFD8.unk_40->unk_ff4c[i].unk_0_4 = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &fzgx_obj_lbl_13_bss_4, 5);
        lbl_1_bss_7EFD8.unk_40->unk_ff4c[i].unk_4_12 = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &fzgx_obj_lbl_13_bss_4, 5);
        lbl_1_bss_7EFD8.unk_40->unk_ff4c[i].unk_4_7 = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &fzgx_obj_lbl_13_bss_4, 5);
        lbl_1_bss_7EFD8.unk_40->unk_ff4c[i].unk_4_2 = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &fzgx_obj_lbl_13_bss_4, 5);
        for (j = 0; j < lbl_1_bss_7EFD8.unk_18; j++) {
            lbl_1_bss_7EFD8.unk_40->unk_ff4c[i].unk_8[j].x = replay_read_f32();
            lbl_1_bss_7EFD8.unk_40->unk_ff4c[i].unk_8[j].y = replay_read_f32();
            lbl_1_bss_7EFD8.unk_40->unk_ff4c[i].unk_8[j].z = replay_read_f32();
            lbl_1_bss_7EFD8.unk_40->unk_ff4c[i].unk_38[j].x = replay_read_f32();
            lbl_1_bss_7EFD8.unk_40->unk_ff4c[i].unk_38[j].y = replay_read_f32();
            lbl_1_bss_7EFD8.unk_40->unk_ff4c[i].unk_38[j].z = replay_read_f32();
        }
        lbl_1_bss_7EFD8.unk_40->unk_ff4c[i].unk_68.x = replay_read_f32();
        lbl_1_bss_7EFD8.unk_40->unk_ff4c[i].unk_68.y = replay_read_f32();
        lbl_1_bss_7EFD8.unk_40->unk_ff4c[i].unk_68.z = replay_read_f32();
        lbl_1_bss_7EFD8.unk_40->unk_ff4c[i].unk_74.x = replay_read_f32();
        lbl_1_bss_7EFD8.unk_40->unk_ff4c[i].unk_74.y = replay_read_f32();
        lbl_1_bss_7EFD8.unk_40->unk_ff4c[i].unk_74.z = replay_read_f32();
    }
    lbl_1_bss_7EFD8.unk_40->unk_a0 = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &fzgx_obj_lbl_13_bss_4, 14);
    for (i = 0; i <= lbl_1_bss_7EFD8.unk_40->unk_a0; i++) {
        lbl_1_bss_7EFD8.unk_40->unk_a4[i].unk_0[0] = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &fzgx_obj_lbl_13_bss_4, 8);
        lbl_1_bss_7EFD8.unk_40->unk_a4[i].unk_0[3] = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &fzgx_obj_lbl_13_bss_4, 8);
        lbl_1_bss_7EFD8.unk_40->unk_a4[i].unk_0[4] = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &fzgx_obj_lbl_13_bss_4, 7);
        lbl_1_bss_7EFD8.unk_40->unk_a4[i].unk_0[5] = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &fzgx_obj_lbl_13_bss_4, 7);
        lbl_1_bss_7EFD8.unk_40->unk_a4[i].unk_0[6] = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &fzgx_obj_lbl_13_bss_4, 8);
        lbl_1_bss_7EFD8.unk_40->unk_a4[i].unk_0[1] = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &fzgx_obj_lbl_13_bss_4, 8);
        lbl_1_bss_7EFD8.unk_40->unk_a4[i].unk_0[2] = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &fzgx_obj_lbl_13_bss_4, 8);
    }
    fn_1_F4794(lbl_1_bss_7EFD8.unk_40->unk_a0);
    lbl_1_bss_7EFD8.unk_40->unk_a0 = 0;
}
/* fzgx:end fn_13_3FC */

/* fzgx:begin fn_13_A40 */
// fn_13_A40: returns a constant.
int fn_13_A40(void) {
    return 0;
}
/* fzgx:end fn_13_A40 */

/* fzgx:begin fn_13_A48 */
s32 fn_13_A48(void) {
    fn_1_D0790();
    return 0;
}
/* fzgx:end fn_13_A48 */

/* fzgx:begin fn_13_A6C */
struct fn_13_A6C_Arg0 {
    u8 pad_0[0xAC];
    u32 unk_AC;
    u8 pad_B0[0x1C];
    u32 unk_CC;
};

void fn_13_A6C(struct fn_13_A6C_Arg0 *arg0) {
    arg0->unk_CC = (u32)fn_13_A40;
    arg0->unk_AC = (u32)fn_13_A48;
    lbl_13_bss_38 = 0;
}
/* fzgx:end fn_13_A6C */

/* fzgx:begin _prolog */
void _prolog(void) {
    lbl_1_bss_7167C = (u32)fn_13_AFC;
    lbl_1_bss_71680 = (u32)fn_13_B00;
    lbl_1_bss_71684 = (u32)fn_13_B08;
    lbl_1_bss_96A = 0xA7;
    fn_1_A8F78();
    lbl_13_bss_3C = 0;
}
/* fzgx:end _prolog */

/* fzgx:begin fn_13_AFC */
// fn_13_AFC: empty in retail (single blr).
void fn_13_AFC(void) {
}
/* fzgx:end fn_13_AFC */

/* fzgx:begin fn_13_B00 */
// fn_13_B00: empty in retail (single blr).
void fn_13_B00(void) {
}
/* fzgx:end fn_13_B00 */

/* fzgx:begin _epilog */
// _epilog: empty in retail (single blr).
void _epilog(void) {
}
/* fzgx:end _epilog */

/* fzgx:begin fn_13_B08 */
typedef u32 (*fn_13_B08_Fn0)(void);
struct fn_13_B08_lbl_13_data_18_0_E16 {
    u8 pad_0[0x4];
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
};
struct fn_13_B08_lbl_13_data_18 {
    struct fn_13_B08_lbl_13_data_18_0_E16 unk_0[1];
};

void fn_13_B08(void) {
    s32 index;
    struct fn_13_B08_lbl_13_data_18_0_E16 *p;
    index = lbl_1_bss_962;
    index -= 167;
    p = &lbl_13_data_18.unk_0[0];
    p += index;
    lbl_1_bss_71688 = p->unk_8;
    lbl_1_bss_7168C = p->unk_C;
    ((fn_13_B08_Fn0)p->unk_4)();
}
/* fzgx:end fn_13_B08 */

/* fzgx:begin fn_13_B64 */
void fn_13_B64(void) {
    lbl_1_bss_26C60 = (u32)fn_13_3FC;
}
/* fzgx:end fn_13_B64 */

/* fzgx:begin fn_13_B78 */
// fn_13_B78: empty in retail (single blr).
void fn_13_B78(void) {
}
/* fzgx:end fn_13_B78 */

/* fzgx:begin fn_13_B7C */
struct fn_13_B7C_lbl_13_bss_3C {
    u8 unk_0;
};

void fn_13_B7C(void) {
    u32 t0;
    t0 = fn_1_3F038();
    if ((s32)t0 != 0) {
    (*(struct fn_13_B7C_lbl_13_bss_3C *)&lbl_13_bss_3C).unk_0 = 1;
    lbl_1_bss_96A = 169;
    lbl_13_bss_40 = 167;
    }
}
/* fzgx:end fn_13_B7C */
