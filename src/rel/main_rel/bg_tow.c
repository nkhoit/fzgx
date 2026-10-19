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

/* fzgx:begin fn_1_153988 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_aur.h"

extern int fn_8003BE1C(void *arg0, void *arg1);
extern int fn_8003C1A4(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4);
extern void fn_8003CE74(void *arg0, void *arg1, int arg2);
extern void fn_8003CBB0(void *arg0, void *arg1, void *arg2, void *arg3);
extern void fn_8003C6D0(void *arg0, void *arg1, void *arg2, void *arg3);
extern u16 lbl_1_bss_8ED8C;
extern u16 lbl_1_bss_8ED8E;
extern void fn_1_151C9C(void);
extern void fn_80074A7C(void (*callback)(void));
extern void fn_1_153AF8(u32 *entries);
extern void fn_1_153D48(void *background);
extern void fn_1_9A508(void);
extern int fn_1_58C4(void);
extern void fn_1_5948(int);
extern void fn_1_627C(int);
extern void fn_1_9D260(void);
extern void fn_1_9AD54(void);
extern void fn_1_153D74(void *);
extern void fn_1_153B24(void *);
extern void fn_1_153C60(Obj_1_data_2A7E0_At3C *value);
extern void fn_1_1540B0(Obj_1_data_2A7E0_At3C *value);
extern void fn_1_9AD88(void);
extern void fn_80008BEC(void *arg0, u32 arg1, u32 arg2);

extern void fn_1_153AF8(u32 *entries);
extern void fn_1_153D48(void *background);
extern void fn_1_9A508(void);
extern u8 lbl_1_rodata_D048[1200];
extern int fn_1_8D690(s16 value);
extern int fn_1_8D72C(s16 value);

// fn_1_153988: empty in retail (single blr).
void fn_1_153988(void) {
}
/* fzgx:end fn_1_153988 */

/* fzgx:begin fn_1_15398C noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_aur.h"

extern int fn_8003BE1C(void *arg0, void *arg1);
extern int fn_8003C1A4(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4);
extern void fn_8003CE74(void *arg0, void *arg1, int arg2);
extern void fn_8003CBB0(void *arg0, void *arg1, void *arg2, void *arg3);
extern void fn_8003C6D0(void *arg0, void *arg1, void *arg2, void *arg3);
extern u16 lbl_1_bss_8ED8C;
extern u16 lbl_1_bss_8ED8E;
extern void fn_1_151C9C(void);
extern void fn_80074A7C(void (*callback)(void));
extern void fn_1_153AF8(u32 *entries);
extern void fn_1_153D48(void *background);
extern void fn_1_9A508(void);
extern int fn_1_58C4(void);
extern void fn_1_5948(int);
extern void fn_1_627C(int);
extern void fn_1_9D260(void);
extern void fn_1_9AD54(void);
extern void fn_1_153D74(void *);
extern void fn_1_153B24(void *);
extern void fn_1_153C60(Obj_1_data_2A7E0_At3C *value);
extern void fn_1_1540B0(Obj_1_data_2A7E0_At3C *value);
extern void fn_1_9AD88(void);
extern void fn_80008BEC(void *arg0, u32 arg1, u32 arg2);

extern void fn_1_153AF8(u32 *entries);
extern void fn_1_153D48(void *background);
extern void fn_1_9A508(void);
extern u8 lbl_1_rodata_D048[1200];
extern int fn_1_8D690(s16 value);
extern int fn_1_8D72C(s16 value);

// Prepares the shared background object and advances the background system.
void fn_1_15398C(void) {
    Obj_1_data_2A7E0_At3C *background = lbl_1_data_2A7E0.unk_3C;

    fn_1_153AF8(&background->unk_0);
    fn_1_153D48(background);
    fn_1_9A508();
}
/* fzgx:end fn_1_15398C */

/* fzgx:begin fn_1_1539D0 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_aur.h"

extern int fn_8003BE1C(void *arg0, void *arg1);
extern int fn_8003C1A4(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4);
extern void fn_8003CE74(void *arg0, void *arg1, int arg2);
extern void fn_8003CBB0(void *arg0, void *arg1, void *arg2, void *arg3);
extern void fn_8003C6D0(void *arg0, void *arg1, void *arg2, void *arg3);
extern u16 lbl_1_bss_8ED8C;
extern u16 lbl_1_bss_8ED8E;
extern void fn_1_151C9C(void);
extern void fn_80074A7C(void (*callback)(void));
extern void fn_1_153AF8(u32 *entries);
extern void fn_1_153D48(void *background);
extern void fn_1_9A508(void);
extern int fn_1_58C4(void);
extern void fn_1_5948(int);
extern void fn_1_627C(int);
extern void fn_1_9D260(void);
extern void fn_1_9AD54(void);
extern void fn_1_153D74(void *);
extern void fn_1_153B24(void *);
extern void fn_1_153C60(Obj_1_data_2A7E0_At3C *value);
extern void fn_1_1540B0(Obj_1_data_2A7E0_At3C *value);
extern void fn_1_9AD88(void);
extern void fn_80008BEC(void *arg0, u32 arg1, u32 arg2);

extern void fn_1_153AF8(u32 *entries);
extern void fn_1_153D48(void *background);
extern void fn_1_9A508(void);
extern u8 lbl_1_rodata_D048[1200];
extern int fn_1_8D690(s16 value);
extern int fn_1_8D72C(s16 value);

// Calls initialization, then loops calling two functions for each item
void fn_1_1539D0(void) {
    int count = fn_1_58C4();
    int i;
    for (i = 0; i < count; i++) {
        fn_1_5948(i);
        fn_1_627C(i);
    }
}
/* fzgx:end fn_1_1539D0 */

/* fzgx:begin fn_1_153A28 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_aur.h"

extern int fn_8003BE1C(void *arg0, void *arg1);
extern int fn_8003C1A4(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4);
extern void fn_8003CE74(void *arg0, void *arg1, int arg2);
extern void fn_8003CBB0(void *arg0, void *arg1, void *arg2, void *arg3);
extern void fn_8003C6D0(void *arg0, void *arg1, void *arg2, void *arg3);
extern u16 lbl_1_bss_8ED8C;
extern u16 lbl_1_bss_8ED8E;
extern void fn_1_151C9C(void);
extern void fn_80074A7C(void (*callback)(void));
extern void fn_1_153AF8(u32 *entries);
extern void fn_1_153D48(void *background);
extern void fn_1_9A508(void);
extern int fn_1_58C4(void);
extern void fn_1_5948(int);
extern void fn_1_627C(int);
extern void fn_1_9D260(void);
extern void fn_1_9AD54(void);
extern void fn_1_153D74(void *);
extern void fn_1_153B24(void *);
extern void fn_1_153C60(Obj_1_data_2A7E0_At3C *value);
extern void fn_1_1540B0(Obj_1_data_2A7E0_At3C *value);
extern void fn_1_9AD88(void);
extern void fn_80008BEC(void *arg0, u32 arg1, u32 arg2);

extern void fn_1_153AF8(u32 *entries);
extern void fn_1_153D48(void *background);
extern void fn_1_9A508(void);
extern u8 lbl_1_rodata_D048[1200];
extern int fn_1_8D690(s16 value);
extern int fn_1_8D72C(s16 value);

void fn_1_153A28(void) {
    Obj_1_data_2A7E0_At3C *obj;
    int count;
    int i;

    obj = lbl_1_data_2A7E0.unk_3C;
    fn_1_9D260();
    fn_1_9AD54();
    count = fn_1_58C4();
    for (i = 0; i < count; i++) {
        fn_1_5948(i);
        fn_1_153D74(obj);
        fn_1_627C(i);
    }
    fn_1_153B24(obj);
}
/* fzgx:end fn_1_153A28 */

/* fzgx:begin fn_1_153AAC noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_aur.h"

extern int fn_8003BE1C(void *arg0, void *arg1);
extern int fn_8003C1A4(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4);
extern void fn_8003CE74(void *arg0, void *arg1, int arg2);
extern void fn_8003CBB0(void *arg0, void *arg1, void *arg2, void *arg3);
extern void fn_8003C6D0(void *arg0, void *arg1, void *arg2, void *arg3);
extern u16 lbl_1_bss_8ED8C;
extern u16 lbl_1_bss_8ED8E;
extern void fn_1_151C9C(void);
extern void fn_80074A7C(void (*callback)(void));
extern void fn_1_153AF8(u32 *entries);
extern void fn_1_153D48(void *background);
extern void fn_1_9A508(void);
extern int fn_1_58C4(void);
extern void fn_1_5948(int);
extern void fn_1_627C(int);
extern void fn_1_9D260(void);
extern void fn_1_9AD54(void);
extern void fn_1_153D74(void *);
extern void fn_1_153B24(void *);
extern void fn_1_153C60(Obj_1_data_2A7E0_At3C *value);
extern void fn_1_1540B0(Obj_1_data_2A7E0_At3C *value);
extern void fn_1_9AD88(void);
extern void fn_80008BEC(void *arg0, u32 arg1, u32 arg2);

extern void fn_1_153AF8(u32 *entries);
extern void fn_1_153D48(void *background);
extern void fn_1_9A508(void);
extern u8 lbl_1_rodata_D048[1200];
extern int fn_1_8D690(s16 value);
extern int fn_1_8D72C(s16 value);

// fn_1_153AAC: empty in retail (single blr).
void fn_1_153AAC(void) {
}
/* fzgx:end fn_1_153AAC */

/* fzgx:begin fn_1_153AB0 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_aur.h"

extern int fn_8003BE1C(void *arg0, void *arg1);
extern int fn_8003C1A4(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4);
extern void fn_8003CE74(void *arg0, void *arg1, int arg2);
extern void fn_8003CBB0(void *arg0, void *arg1, void *arg2, void *arg3);
extern void fn_8003C6D0(void *arg0, void *arg1, void *arg2, void *arg3);
extern u16 lbl_1_bss_8ED8C;
extern u16 lbl_1_bss_8ED8E;
extern void fn_1_151C9C(void);
extern void fn_80074A7C(void (*callback)(void));
extern void fn_1_153AF8(u32 *entries);
extern void fn_1_153D48(void *background);
extern void fn_1_9A508(void);
extern int fn_1_58C4(void);
extern void fn_1_5948(int);
extern void fn_1_627C(int);
extern void fn_1_9D260(void);
extern void fn_1_9AD54(void);
extern void fn_1_153D74(void *);
extern void fn_1_153B24(void *);
extern void fn_1_153C60(Obj_1_data_2A7E0_At3C *value);
extern void fn_1_1540B0(Obj_1_data_2A7E0_At3C *value);
extern void fn_1_9AD88(void);
extern void fn_80008BEC(void *arg0, u32 arg1, u32 arg2);

extern void fn_1_153AF8(u32 *entries);
extern void fn_1_153D48(void *background);
extern void fn_1_9A508(void);
extern u8 lbl_1_rodata_D048[1200];
extern int fn_1_8D690(s16 value);
extern int fn_1_8D72C(s16 value);

// Initializes the background Aurora object.
void fn_1_153AB0(void) {
    Obj_1_data_2A7E0_At3C *object = lbl_1_data_2A7E0.unk_3C;

    fn_1_153C60(object);
    fn_1_1540B0(object);
    fn_1_9AD88();
}
/* fzgx:end fn_1_153AB0 */

/* fzgx:begin fn_1_153AF4 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_aur.h"

extern int fn_8003BE1C(void *arg0, void *arg1);
extern int fn_8003C1A4(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4);
extern void fn_8003CE74(void *arg0, void *arg1, int arg2);
extern void fn_8003CBB0(void *arg0, void *arg1, void *arg2, void *arg3);
extern void fn_8003C6D0(void *arg0, void *arg1, void *arg2, void *arg3);
extern u16 lbl_1_bss_8ED8C;
extern u16 lbl_1_bss_8ED8E;
extern void fn_1_151C9C(void);
extern void fn_80074A7C(void (*callback)(void));
extern void fn_1_153AF8(u32 *entries);
extern void fn_1_153D48(void *background);
extern void fn_1_9A508(void);
extern int fn_1_58C4(void);
extern void fn_1_5948(int);
extern void fn_1_627C(int);
extern void fn_1_9D260(void);
extern void fn_1_9AD54(void);
extern void fn_1_153D74(void *);
extern void fn_1_153B24(void *);
extern void fn_1_153C60(Obj_1_data_2A7E0_At3C *value);
extern void fn_1_1540B0(Obj_1_data_2A7E0_At3C *value);
extern void fn_1_9AD88(void);
extern void fn_80008BEC(void *arg0, u32 arg1, u32 arg2);

extern void fn_1_153AF8(u32 *entries);
extern void fn_1_153D48(void *background);
extern void fn_1_9A508(void);
extern u8 lbl_1_rodata_D048[1200];
extern int fn_1_8D690(s16 value);
extern int fn_1_8D72C(s16 value);

// fn_1_153AF4: empty in retail (single blr).
void fn_1_153AF4(void) {
}
/* fzgx:end fn_1_153AF4 */

/* fzgx:begin fn_1_153AF8 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_aur.h"

extern int fn_8003BE1C(void *arg0, void *arg1);
extern int fn_8003C1A4(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4);
extern void fn_8003CE74(void *arg0, void *arg1, int arg2);
extern void fn_8003CBB0(void *arg0, void *arg1, void *arg2, void *arg3);
extern void fn_8003C6D0(void *arg0, void *arg1, void *arg2, void *arg3);
extern u16 lbl_1_bss_8ED8C;
extern u16 lbl_1_bss_8ED8E;
extern void fn_1_151C9C(void);
extern void fn_80074A7C(void (*callback)(void));
extern void fn_1_153AF8(u32 *entries);
extern void fn_1_153D48(void *background);
extern void fn_1_9A508(void);
extern int fn_1_58C4(void);
extern void fn_1_5948(int);
extern void fn_1_627C(int);
extern void fn_1_9D260(void);
extern void fn_1_9AD54(void);
extern void fn_1_153D74(void *);
extern void fn_1_153B24(void *);
extern void fn_1_153C60(Obj_1_data_2A7E0_At3C *value);
extern void fn_1_1540B0(Obj_1_data_2A7E0_At3C *value);
extern void fn_1_9AD88(void);
extern void fn_80008BEC(void *arg0, u32 arg1, u32 arg2);

extern void fn_1_153AF8(u32 *entries);
extern void fn_1_153D48(void *background);
extern void fn_1_9A508(void);
extern u8 lbl_1_rodata_D048[1200];
extern int fn_1_8D690(s16 value);
extern int fn_1_8D72C(s16 value);

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

/* fzgx:begin fn_1_153B24 noprologue */
#include "types.h"

typedef struct {
    s32 count;
    u8 pad_004[0x100];
    s32 counter[64];
    f32 timer[64];
    f32 progress[64];
    f32 cooldown[64];
} Fn153B24Data;

void fn_1_153B24(Fn153B24Data *data, u32 lab_unused0, u32 lab_unused1, u32 lab_unused2) {
    f32 base;
    f32 prod;
    s32 i;

    for (i = 0; i < data->count; i++) {
        data->timer[i] -= 0.15f;
        if (data->timer[i] <= -0.95f) {
            data->counter[i]++;
            data->timer[i] = 0.031f;
        }

        base = 0.005f;
        prod = -0.032f * (f32)data->counter[i];
        data->progress[i] = base + prod;

        if (data->progress[i] <= -0.923f) {
            data->timer[i] = -0.95f;
            data->progress[i] = -0.923f;
            data->counter[i] = (s32)((data->progress[i] - 0.005f) / -0.032f);
        }

        if (data->progress[i] == -0.923f) {
            data->cooldown[i] -= -0.032f;
            if (data->cooldown[i] > 1.0f) {
                data->cooldown[i] = 0.0f;
                data->timer[i] = 0.031f;
                data->progress[i] = 0.005f;
                data->counter[i] = (s32)((data->progress[i] - 0.005f) / -0.032f);
            }
        }
    }
}
/* fzgx:end fn_1_153B24 */

/* fzgx:begin fn_1_153C60 noprologue */
#include "types.h"

extern u32 lbl_1_data_2A7E0[];
extern void lbl_8006DFE8(void *);
extern void lbl_8006E13C(void *);
extern void lbl_8006E0A4(void *);
extern void fn_80072558(void);
extern void lbl_8006D784(void *);
extern void fn_1_560F0(s32, void *);
extern void fn_1_55210(void *);

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

            if ((value + 0x10000) == 0xffff || (value & lbl_1_data_2A7E0[20]) != 0) {
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

/* fzgx:begin fn_1_153D48 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_aur.h"

extern int fn_8003BE1C(void *arg0, void *arg1);
extern int fn_8003C1A4(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4);
extern void fn_8003CE74(void *arg0, void *arg1, int arg2);
extern void fn_8003CBB0(void *arg0, void *arg1, void *arg2, void *arg3);
extern void fn_8003C6D0(void *arg0, void *arg1, void *arg2, void *arg3);
extern u16 lbl_1_bss_8ED8C;
extern u16 lbl_1_bss_8ED8E;
extern void fn_1_151C9C(void);
extern void fn_80074A7C(void (*callback)(void));
extern void fn_1_153AF8(u32 *entries);
extern void fn_1_153D48(void *background);
extern void fn_1_9A508(void);
extern int fn_1_58C4(void);
extern void fn_1_5948(int);
extern void fn_1_627C(int);
extern void fn_1_9D260(void);
extern void fn_1_9AD54(void);
extern void fn_1_153D74(void *);
extern void fn_1_153B24(void *);
extern void fn_1_153C60(Obj_1_data_2A7E0_At3C *value);
extern void fn_1_1540B0(Obj_1_data_2A7E0_At3C *value);
extern void fn_1_9AD88(void);
extern void fn_80008BEC(void *arg0, u32 arg1, u32 arg2);

extern void fn_1_153AF8(u32 *entries);
extern void fn_1_153D48(void *background);
extern void fn_1_9A508(void);
extern u8 lbl_1_rodata_D048[1200];
extern int fn_1_8D690(s16 value);
extern int fn_1_8D72C(s16 value);

// Clears the Aurora background data region.
void fn_1_153D48(void *background) {
    fn_80008BEC((u8 *)background + 0x1108, 0, 0x5fc);
}
/* fzgx:end fn_1_153D48 */

/* fzgx:begin fn_1_1540B0 noprologue */
#include "types.h"

extern s32 fn_1_5910(void);
extern void fn_1_154164(u32 value, u32 *arg1, u32 *arg2, u32 arg3);
extern u32 lbl_1_rodata_D57C[7];

void fn_1_1540B0(u32 value) {
    u32 *table;
    s32 i;
    u32 *base;
    u32 *entry;
    u32 args[3];

    base = (u32 *)((u8 *)value + 0x1108);
    {
        s32 slot;
        slot = fn_1_5910();
        fn_1_154164(value, (u32 *)((u8 *)base + slot * 0xc + 0x8c),
                    (u32 *)((u8 *)base + slot * 0x30 + 0x23c), 0);
    }

    entry = lbl_1_rodata_D57C;
    table = base;
    i = 0;
    while (i < (s32)base[1]) {
        args[0] = entry[0];
        args[1] = entry[1];
        args[2] = entry[2];
        fn_1_154164(value, args, (u32 *)((u8 *)table + 0x2fc), 1);
        table = (u32 *)((u8 *)table + 0x30);
        i++;
    }
}
/* fzgx:end fn_1_1540B0 */

/* fzgx:begin fn_1_1543E8 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_aur.h"

extern int fn_8003BE1C(void *arg0, void *arg1);
extern int fn_8003C1A4(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4);
extern void fn_8003CE74(void *arg0, void *arg1, int arg2);
extern void fn_8003CBB0(void *arg0, void *arg1, void *arg2, void *arg3);
extern void fn_8003C6D0(void *arg0, void *arg1, void *arg2, void *arg3);
extern u16 lbl_1_bss_8ED8C;
extern u16 lbl_1_bss_8ED8E;
extern void fn_1_151C9C(void);
extern void fn_80074A7C(void (*callback)(void));
extern void fn_1_153AF8(u32 *entries);
extern void fn_1_153D48(void *background);
extern void fn_1_9A508(void);
extern int fn_1_58C4(void);
extern void fn_1_5948(int);
extern void fn_1_627C(int);
extern void fn_1_9D260(void);
extern void fn_1_9AD54(void);
extern void fn_1_153D74(void *);
extern void fn_1_153B24(void *);
extern void fn_1_153C60(Obj_1_data_2A7E0_At3C *value);
extern void fn_1_1540B0(Obj_1_data_2A7E0_At3C *value);
extern void fn_1_9AD88(void);
extern void fn_80008BEC(void *arg0, u32 arg1, u32 arg2);

extern void fn_1_153AF8(u32 *entries);
extern void fn_1_153D48(void *background);
extern void fn_1_9A508(void);
extern u8 lbl_1_rodata_D048[1200];
extern int fn_1_8D690(s16 value);
extern int fn_1_8D72C(s16 value);

u32 fn_1_1543E8(s32 value, u32 *source) {
    Obj_1_data_2A7E0_At3C *obj = lbl_1_data_2A7E0.unk_3C;

    switch (value) {
    case 0:
        obj->unk_1104 = *source;
        break;
    default:
        break;
    }

    return 1;
}
/* fzgx:end fn_1_1543E8 */

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
