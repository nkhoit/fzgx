#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/rob.h"

extern void fn_1_12ABB4(void *arg0);
extern void fn_1_96230(void *arg0, void *arg1, void *arg2, void *arg3, int arg4);
extern void fn_1_41850(void *arg0);
extern u32 lbl_1_bss_6E98C;
extern u16 fn_1_96B14(void *base, void *arg1, s32 index);
extern s32 fn_80083BCC(void *arg0, void *arg1);
extern void ADXT_Stop(u32 arg0);
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32, u32, u8 *, u32);
extern void fn_80008BEC(void *, u32, u32);

extern const char *lbl_1_data_20D1C[];
extern void sprintf(char *buffer, u8 *format, ...);
extern s32 fn_1_12A32C(char *buffer);
extern s16 fn_1_98104(void);

/* fzgx:begin fn_1_95EF0 noprologue */
#include "types.h"

struct fn_1_95EF0_Arg0 {
    u8 pad_0[0x14C];
    u32 unk_14C;
};
struct fn_1_95EF0_lbl_801A6410 {
    u32 unk_0;
};
extern struct fn_1_95EF0_lbl_801A6410 lbl_801A6410;
extern u8 lbl_1_data_27C00[];
extern void fn_1_12ABB4(void *);
extern void fn_1_46B4(u32, u32, const char *, int);

void fn_1_95EF0(void *arg0, s32 arg_sp0) {
    void *var_r28;
    void *temp_r3_7;
    void *temp_r3_6;
    void *temp_r3_5;
    void *temp_r3_4;
    void *temp_r3_3;
    void *temp_r3_2;
    void *temp_r3;
    u32 var_r27;
    u32 temp_r4_7;
    u32 temp_r4_6;
    u32 temp_r4_5;
    u32 temp_r4_4;
    u32 temp_r4_3;
    u32 temp_r4_2;
    u32 temp_r4;

    temp_r3 = (void *)(*(void **)((u8 *)(arg0) + 332));
    if (temp_r3 != NULL) {
        fn_1_12ABB4((void *)(temp_r3));
        (*(void **)((u8 *)(arg0) + 332)) = (void *)(NULL);
    }
    temp_r4 = *(u32 *)((u8 *)(arg0) + 336);
    if (temp_r4 != 0) {
        fn_1_46B4(lbl_801A6410.unk_0, temp_r4, (const char *)((s8 *) lbl_1_data_27C00), 0xB44);
        (*(u32 *)((u8 *)(arg0) + 336)) = 0U;
    }
    temp_r3_2 = (void *)(*(void **)((u8 *)(arg0) + 364));
    if (temp_r3_2 != NULL) {
        fn_1_12ABB4((void *)(temp_r3_2));
        (*(void **)((u8 *)(arg0) + 364)) = (void *)(NULL);
    }
    temp_r4_2 = *(u32 *)((u8 *)(arg0) + 368);
    if (temp_r4_2 != 0) {
        fn_1_46B4(lbl_801A6410.unk_0, temp_r4_2, (const char *)((s8 *) lbl_1_data_27C00), 0xB49);
        (*(u32 *)((u8 *)(arg0) + 368)) = 0U;
    }
    temp_r3_3 = (void *)(*(void **)((u8 *)(arg0) + 396));
    if (temp_r3_3 != NULL) {
        fn_1_12ABB4((void *)(temp_r3_3));
        (*(void **)((u8 *)(arg0) + 396)) = (void *)(NULL);
    }
    temp_r4_3 = *(u32 *)((u8 *)(arg0) + 400);
    if (temp_r4_3 != 0) {
        fn_1_46B4(lbl_801A6410.unk_0, temp_r4_3, (const char *)((s8 *) lbl_1_data_27C00), 0xB4B);
        (*(u32 *)((u8 *)(arg0) + 400)) = 0U;
    }
    temp_r3_4 = (void *)(*(void **)((u8 *)(arg0) + 428));
    if (temp_r3_4 != NULL) {
        fn_1_12ABB4((void *)(temp_r3_4));
        (*(void **)((u8 *)(arg0) + 428)) = (void *)(NULL);
    }
    temp_r4_4 = *(u32 *)((u8 *)(arg0) + 432);
    if (temp_r4_4 != 0) {
        fn_1_46B4(lbl_801A6410.unk_0, temp_r4_4, (const char *)((s8 *) lbl_1_data_27C00), 0xB4D);
        (*(u32 *)((u8 *)(arg0) + 432)) = 0U;
    }
    temp_r3_5 = (void *)(*(void **)((u8 *)(arg0) + 460));
    if (temp_r3_5 != NULL) {
        fn_1_12ABB4((void *)(temp_r3_5));
        (*(void **)((u8 *)(arg0) + 460)) = (void *)(NULL);
    }
    temp_r4_5 = *(u32 *)((u8 *)(arg0) + 464);
    if (temp_r4_5 != 0) {
        fn_1_46B4(lbl_801A6410.unk_0, temp_r4_5, (const char *)((s8 *) lbl_1_data_27C00), 0xB4F);
        (*(u32 *)((u8 *)(arg0) + 464)) = 0U;
    }
    temp_r3_6 = (void *)(*(void **)((u8 *)(arg0) + 492));
    if (temp_r3_6 != NULL) {
        fn_1_12ABB4((void *)(temp_r3_6));
        (*(void **)((u8 *)(arg0) + 492)) = (void *)(NULL);
    }
    temp_r4_6 = *(u32 *)((u8 *)(arg0) + 496);
    if (temp_r4_6 != 0) {
        fn_1_46B4(lbl_801A6410.unk_0, temp_r4_6, (const char *)((s8 *) lbl_1_data_27C00), 0xB51);
        (*(u32 *)((u8 *)(arg0) + 496)) = 0U;
    }
    var_r28 = (void *)(arg0);
    var_r27 = 0U;
    do {
        temp_r3_7 = (void *)(*(void **)((u8 *)(var_r28) + 524));
        if (temp_r3_7 != NULL) {
            fn_1_12ABB4((void *)(temp_r3_7));
            (*(void **)((u8 *)(var_r28) + 524)) = (void *)(NULL);
        }
        temp_r4_7 = *(u32 *)((u8 *)(var_r28) + 528);
        if (temp_r4_7 != 0) {
            fn_1_46B4(lbl_801A6410.unk_0, temp_r4_7, (const char *)((s8 *) lbl_1_data_27C00), 0xB54);
            (*(u32 *)((u8 *)(var_r28) + 528)) = 0U;
        }
        var_r27 += 1;
        var_r28 = (void *)((u8 *)(var_r28) + 0x20);
    } while (var_r27 < 0x14U);
}
/* fzgx:end fn_1_95EF0 */

/* fzgx:begin fn_1_96130 */
#include "dolphin/hw_regs.h"
#include "psvec.h"

typedef s32 (*fn_1_8D210_callback)(u32);
extern void fn_1_12AB38(void *arg0);
extern s32 fn_1_465D0(s32 arg0, s32 arg1);
// lbl_1_data_27BA4: .data size 0x5C, 3 refs from car.c (own data block)
extern u8 lbl_1_data_27BA4[0x5C];
// lbl_1_data_278AC: .data size 0x3, 3 refs from car.c (own data block)
extern u32 lbl_1_data_278AC;

void fn_1_96130(void *arg0) {
    fn_1_12AB38(lbl_1_data_27BA4);
    fn_1_465D0( (s32)(void *)(arg0), 1);
    fn_1_12AB38(&lbl_1_data_278AC);
}
/* fzgx:end fn_1_96130 */

/* fzgx:begin fn_1_9617C */
#include "dolphin/hw_regs.h"
#include "psvec.h"

typedef s32 (*fn_1_8D210_callback)(u32);
extern void fn_1_12AB38(void *arg0);
extern s32 fn_1_12A8A4(u32 arg0, void *arg1);
extern void fn_1_41328(void *arg0);
extern void fn_1_426E4(void *arg0, void *arg1);
// lbl_1_data_27BA4: .data size 0x5C, 3 refs from car.c (own data block)
extern u8 lbl_1_data_27BA4[0x5C];
// lbl_1_data_278AC: .data size 0x3, 3 refs from car.c (own data block)
extern u32 lbl_1_data_278AC;

typedef struct CarResourceState CarResourceState;

struct CarResourceState {
    u8 unk_00[0x08];
    void *unk_08;
    void *unk_0C;
};

// Loads the car resource, updates its model data, and restores shared state.
void fn_1_9617C(CarResourceState *car, void *resource) {
    fn_1_12AB38(lbl_1_data_27BA4);
    if (fn_1_12A8A4( (u32)(void *)(resource), &car->unk_0C) != 0) {
        fn_1_41328(car->unk_0C);
        fn_1_426E4(car->unk_08, car->unk_0C);
    }
    fn_1_12AB38(&lbl_1_data_278AC);
}
/* fzgx:end fn_1_9617C */

/* fzgx:begin fn_1_961F0 */
typedef struct Fn1961F0Owner Fn1961F0Owner;

struct Fn1961F0Owner {
    u8 unk_00[0x0C];
    void *resource;
};

void fn_1_961F0(Fn1961F0Owner *owner) {
    if (owner->resource != 0) {
        fn_1_12ABB4(owner->resource);
        owner->resource = 0;
    }
}
/* fzgx:end fn_1_961F0 */

/* fzgx:begin fn_1_96630 */
typedef struct Fn196630Object Fn196630Object;

struct Fn196630Object {
    u8 unk_00[0x88];
    void *value_88;
};

void fn_1_96630(Fn196630Object *object, void *arg1, void *arg2) {
    fn_1_96230(object, object->value_88, arg1, arg2, 0);
}
/* fzgx:end fn_1_96630 */

/* fzgx:begin fn_1_96664 */
void fn_1_96664(void *arg0, void *arg1, void *arg2) {
    fn_1_96230(0, arg0, arg1, arg2, 1);
}
/* fzgx:end fn_1_96664 */

/* fzgx:begin fn_1_966A0 */
typedef struct Fn1966A0Object Fn1966A0Object;
struct Fn1966A0Object {
    u32 entries[0x39];
    u32 resource_e4;
    u8 unk_E8[0x10];
    u32 resource_f8;
};

extern void fn_1_12A2D0(s32 arg0);
extern void fn_80071718(u32 arg0);
extern void fn_800711A8(u32 arg0);

void fn_1_966A0(Fn1966A0Object *object) {
    u8 *slot;
    u8 *group;
    u8 *outer;
    int i;
    int j;
    s32 value;
    u8 *walk;

    group = (u8 *)object;
    outer = (u8 *)object;
    for (i = 0; i < 5; i++) {
        slot = group;
        for (j = 0; j < 4; j++) {
            if (((Fn1966A0Object *)slot)->resource_f8 != 0) {
                if (*(s32 *)(outer + 4) != -1) {
                    fn_1_12A2D0(*(s32 *)(outer + 4));
                }
                fn_80071718(((Fn1966A0Object *)slot)->resource_f8);
                ((Fn1966A0Object *)slot)->resource_f8 = 0;
            }
            slot += 4;
        }
        if (((Fn1966A0Object *)outer)->resource_e4 != 0) {
            if (*(s32 *)(outer + 4) != -1) {
                fn_1_12A2D0(*(s32 *)(outer + 4));
            }
            fn_800711A8(((Fn1966A0Object *)outer)->resource_e4);
            ((Fn1966A0Object *)outer)->resource_e4 = 0;
        }
        group += 0x10;
        outer += 4;
    }

    value = -1;
    walk = (u8 *)object;
    for (i = 0; i < 5; i++) {
        if (*(s32 *)(walk + 4) != -1) {
            value = object->entries[i + 1];
            break;
        }
        walk += 4;
    }
    if (value != -1) {
        fn_1_12A2D0(value);
    }
}
/* fzgx:end fn_1_966A0 */

/* fzgx:begin fn_1_967A8 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/car.h"

extern void fn_1_12AB38(void *arg0);
extern void fn_1_12A8A4(void *arg0, void *arg1);
extern u32 lbl_1_bss_6E98C;
extern void fn_1_96AE8(void);

extern void fn_1_12AB38(void *value);

typedef struct Fn1967A8Resource Fn1967A8Resource;
struct Fn1967A8Resource {
    u8 unk_00;
    u8 unk_01[0x07];
    u32 unk_08;
    u8 unk_0C[0x10];
    u32 unk_1C;
};

typedef struct Fn1967A8Object Fn1967A8Object;
struct Fn1967A8Object {
    u8 unk_00[0x1C];
    Fn1967A8Resource *unk_1C;
    void *unk_20;
    u8 unk_24[0x64];
    u32 unk_88;
    u8 unk_8C[0xC0];
    u32 unk_14C;
    u32 unk_150;
    void *unk_154;
};

extern Fn1967A8Resource *fn_1_41518(void *arg0);
extern void fn_1_41C18(Fn1967A8Resource *arg0, void *arg1);
extern void fn_1_41F58(Fn1967A8Resource *arg0, s32 arg1, void (*arg2)(void), void *arg3);
extern void fn_1_96968(void);
extern void fn_1_969E8(void);
extern void fn_1_96BC0(void);
extern void fn_1_96A68(void);

void fn_1_967A8(Fn1967A8Object *arg0, void *arg1) {
    u32 i;

    fn_1_12AB38(lbl_1_data_27BA4);
    fn_1_12A8A4(arg1, &arg0->unk_20);
    arg0->unk_1C = fn_1_41518(arg0->unk_20);
    arg0->unk_1C->unk_1C = arg0->unk_14C;
    arg0->unk_1C->unk_08 = arg0->unk_150;
    arg0->unk_1C->unk_00 = arg0->unk_88;
    fn_1_41C18(arg0->unk_1C, arg0->unk_154);
    fn_1_41F58(arg0->unk_1C, 0, fn_1_96968, arg0);
    fn_1_41F58(arg0->unk_1C, 1, fn_1_96968, arg0);
    fn_1_41F58(arg0->unk_1C, 2, fn_1_969E8, arg0);
    fn_1_41F58(arg0->unk_1C, 3, fn_1_96BC0, arg0);
    fn_1_41F58(arg0->unk_1C, 4, fn_1_96A68, arg0);
    for (i = 0; i < 0x14; i++) {
        lbl_1_bss_6E98C = i;
        fn_1_41F58(arg0->unk_1C, 5, fn_1_96AE8, arg0);
    }
    fn_1_12AB38(&lbl_1_data_278AC);
}
/* fzgx:end fn_1_967A8 */

/* fzgx:begin fn_1_968FC */
typedef struct Fn1968FCChild Fn1968FCChild;
typedef struct Fn1968FCObject Fn1968FCObject;

struct Fn1968FCChild {
    u8 unk_00[0x08];
    u32 unk_08;
    u8 unk_0c[0x10];
    u32 unk_1c;
};

struct Fn1968FCObject {
    u8 unk_00[0x1c];
    Fn1968FCChild *unk_1c;
    void *unk_20;
};

void fn_1_968FC(Fn1968FCObject *object) {
    if (object->unk_20 != 0) {
        fn_1_12ABB4(object->unk_20);
        object->unk_20 = 0;
    }

    if (object->unk_1c != 0) {
        object->unk_1c->unk_1c = 0;
        object->unk_1c->unk_08 = 0;
        fn_1_41850(object->unk_1c);
        object->unk_1c = 0;
    }
}
/* fzgx:end fn_1_968FC */

/* fzgx:begin fn_1_96968 */
#include "dolphin/hw_regs.h"
#include "psvec.h"

typedef struct Fn196968Object Fn196968Object;
struct Fn196968Object {
    u8 unk_00[0x28];
    u32 unk_28;
    u8 unk_2C[0x144];
    void *unk_170;
    void *unk_174;
};
typedef s32 (*fn_1_8D210_callback)(u32);
extern s32 fn_1_41488(void *arg0, void *arg1);
extern u16 fn_1_96968(Fn196968Object *object, void *arg1);
// lbl_1_data_2785C: .data size 0x10, 1 refs from car.c (own data block)
extern u8 lbl_1_data_2785C[0x10];

// Cache the resource key and return the requested resource sequence number.
u16 fn_1_96968(Fn196968Object *object, void *arg1) {
    if (object->unk_170 != 0 && object->unk_174 != 0) {
        object->unk_28 = fn_1_41488(object->unk_174, lbl_1_data_2785C);
        return (u16)((u32)fn_1_41488(object->unk_174, arg1) + 1);
    }

    object->unk_28 = 0;
    return 0;
}
/* fzgx:end fn_1_96968 */

/* fzgx:begin fn_1_969E8 */
#include "dolphin/hw_regs.h"
#include "psvec.h"

typedef struct Fn1969E8Owner Fn1969E8Owner;
struct Fn1969E8Owner {
    u8 unk_00[0x2C];
    u32 unk_2c;
    u8 unk_30[0x180];
    u32 unk_1b0;
    void *unk_1b4;
};
typedef s32 (*fn_1_8D210_callback)(u32);
extern s32 fn_1_41488(void *arg0, void *arg1);
extern u16 fn_1_969E8(Fn1969E8Owner *owner, void *arg1);
// lbl_1_data_22A24: .data size 0x5, 1 refs from car.c (own data block)
extern u32 lbl_1_data_22A24;

// Resolve the owner's resource values and cache the associated lookup result.
u16 fn_1_969E8(Fn1969E8Owner *owner, void *arg1) {
    if (owner->unk_1b0 != 0 && owner->unk_1b4 != 0) {
        owner->unk_2c = fn_1_41488(owner->unk_1b4, &lbl_1_data_22A24);
        return (u16)(fn_1_41488(owner->unk_1b4, arg1) + 1);
    }

    owner->unk_2c = 0;
    return 0;
}
/* fzgx:end fn_1_969E8 */

/* fzgx:begin fn_1_96A68 */
#include "dolphin/hw_regs.h"
#include "psvec.h"

typedef struct Fn196A68Object Fn196A68Object;
struct Fn196A68Object {
    u8 unk_00[0x34];
    u32 unk_34;
    u8 unk_38[0x1B8];
    void *unk_1F0;
    void *unk_1F4;
};
typedef s32 (*fn_1_8D210_callback)(u32);
extern s32 fn_1_41488(void *arg0, void *arg1);
extern u16 fn_1_96A68(Fn196A68Object *object, void *arg1);
// lbl_1_data_27870: .data size 0x4, 1 refs from car.c (own data block)
extern u32 lbl_1_data_27870;

// Updates the car's resource state and returns the next resource index.
u16 fn_1_96A68(Fn196A68Object *object, void *arg1) {
    if (object->unk_1F0 != 0 && object->unk_1F4 != 0) {
        object->unk_34 = fn_1_41488(object->unk_1F4, &lbl_1_data_27870);
        return (u16)(fn_1_41488(object->unk_1F4, arg1) + 1);
    }
    object->unk_34 = 0;
    return 0;
}
/* fzgx:end fn_1_96A68 */

/* fzgx:begin fn_1_96AE8 */
void fn_1_96AE8(void *base, void *arg1) {
    fn_1_96B14(base, arg1, lbl_1_bss_6E98C);
}
/* fzgx:end fn_1_96AE8 */

/* fzgx:begin fn_1_96B14 */
#include "dolphin/hw_regs.h"
#include "psvec.h"

typedef s32 (*fn_1_8D210_callback)(u32);
extern s32 fn_1_41488(void *arg0, void *arg1);
// lbl_1_data_27874: .data size 0x38, 1 refs from car.c (own data block)
extern u8 lbl_1_data_27874[0x38];

typedef struct Fn196B14Entry Fn196B14Entry;
struct Fn196B14Entry {
    u8 unk_00[0x210];
    void *unk_210;
    void *unk_214;
};

// Computes the indexed entry value when its backing resource is available.
u16 fn_1_96B14(void *base, void *arg1, s32 index) {
    Fn196B14Entry *entry = (Fn196B14Entry *)((u8 *)base + (index << 5));

    if (entry->unk_210 != 0 && entry->unk_214 != 0) {
        ((u32 *)((u8 *)base + 0x38))[index] =
            (u32)fn_1_41488(entry->unk_214, lbl_1_data_27874);
        return (u16)(fn_1_41488(entry->unk_214, arg1) + 1);
    }

    ((u32 *)((u8 *)base + 0x38))[index] = 0;
    return 0;
}
/* fzgx:end fn_1_96B14 */

/* fzgx:begin fn_1_96BC0 */
#include "dolphin/hw_regs.h"
#include "psvec.h"

typedef struct Fn196BC0Object Fn196BC0Object;
struct Fn196BC0Object {
    u8 unk_00[0x30];
    void *value_30;
    u8 unk_34[0x19C];
    void *resource_1D0;
    void *resource_1D4;
};
typedef s32 (*fn_1_8D210_callback)(u32);
extern s32 fn_1_41488(void *arg0, void *arg1);
extern u16 fn_1_96BC0(Fn196BC0Object *object, void *arg1);
// lbl_1_data_2786C: .data size 0x4, 1 refs from car.c (own data block)
extern u32 lbl_1_data_2786C;

// Updates the car's resource-derived value and returns the converted result.
u16 fn_1_96BC0(Fn196BC0Object *object, void *arg1) {
    if (object->resource_1D0 != 0 && object->resource_1D4 != 0) {
        object->value_30 = (void *)fn_1_41488(
            object->resource_1D4, &lbl_1_data_2786C);
        return (u16)(fn_1_41488(object->resource_1D4, arg1) + 1);
    }

    object->value_30 = 0;
    return 0;
}
/* fzgx:end fn_1_96BC0 */

/* fzgx:begin fn_1_96F20 noprologue */
#include "types.h"
#include "rel/main_rel/car.h"

typedef struct Vec3f {
    f32 x, y, z;
} Vec3f;

typedef struct CarR29 {
    u8 unk_00[0x14];
    f32 unk_14;
} CarR29;

typedef struct CarSub2 {
    u8 unk_00[0x88];
    u8 unk_88[1];
} CarSub2;

typedef struct CarSub {
    u8 unk_00[0x8];
    CarSub2 *unk_8;
} CarSub;

typedef struct CarData {
    u8 unk_00[0x8c];
    s32 unk_8c;
    u8 unk_90[0x10];
    s16 unk_a0;
    s16 unk_a2;
    s16 unk_a4;
    u8 unk_a6[2];
    f32 unk_a8;
    f32 unk_ac;
    f32 unk_b0;
    f32 unk_b4;
    f32 unk_b8;
    u8 unk_bc[0x28];
    void *unk_e4[1];
    u8 unk_e8[0x150 - 0xe8];
    CarSub *unk_150;
} CarData;

extern const f32 lbl_1_rodata_3E48[];

extern void *camera_get_state_object(void);
extern void camera_update_state(void *);
extern CarR29 *fn_80071268(void *, void *);
extern void lbl_8006E1F0(Vec3f *, f32, f32, f32);
extern void fn_1_A714C(f32 *, s32, s32, f32 *);
extern f32 lbl_8006D21C(s32);
extern void lbl_8006DAEC(void);
extern void lbl_8006E0B4(f32, f32, f32);
extern void mathutil_mtxA_rotate_z(s16);
extern void mathutil_mtxA_rotate_y(s16);
extern void mathutil_mtxA_rotate_x(s16);
extern void lbl_8006E14C(f32);
extern void lbl_8006DFC4(void *);
extern f32 (*lbl_801A6D00)[4];
extern void lbl_8006DB30(void);
extern void lbl_8006E2C0(Vec3f *, f32, f32, f32);
extern void fn_8006E250(Vec3f *, Vec3f *);
extern void fn_1_B81C(Vec3f *, Vec3f *, s32);

void fn_1_96F20(CarData *car) {
    const f32 *pool = lbl_1_rodata_3E48;
    Vec3f sp40;
    Vec3f sp34;
    Vec3f sp28;
    Vec3f sp1C;
    Vec3f sp10;
    f32 spC;
    f32 sp8;
    CarR29 *r29;
    void *cam;
    CarSub2 *sub2;
    f32 f31_val;
    f32 mtx_x, mtx_y, mtx_z;

    cam = camera_get_state_object();
    r29 = fn_80071268(car->unk_e4[car->unk_8c], &lbl_1_data_22A1C);
    if (!r29) {
        r29 = fn_80071268(car->unk_e4[car->unk_8c], &lbl_1_data_24EF0);
    }
    if (!r29) {
        return;
    }

    camera_update_state(cam);
    lbl_8006E1F0(&sp10, pool[0x49], pool[0x4A], pool[0x49]);
    fn_1_A714C(&spC, 0, 0, &sp8);

    f31_val = lbl_8006D21C((s32)(pool[0x77] * spC * pool[0x66]));

    lbl_8006DAEC();
    sub2 = car->unk_150->unk_8;
    lbl_8006E0B4(car->unk_a8, car->unk_ac + car->unk_b4, car->unk_b0);
    mathutil_mtxA_rotate_z(car->unk_a4);
    mathutil_mtxA_rotate_y(car->unk_a0);
    mathutil_mtxA_rotate_x(car->unk_a2);
    lbl_8006E14C(car->unk_b8);
    lbl_8006DFC4(&sub2->unk_88);

    mtx_x = lbl_801A6D00[0][3];
    mtx_y = lbl_801A6D00[1][3];
    mtx_z = lbl_801A6D00[2][3];
    lbl_8006DB30();

    sp28.x = mtx_x;
    sp28.y = mtx_y;
    sp28.z = mtx_z + (pool[0x8D] * r29->unk_14) / f31_val;
    sp28.x *= pool[0x8E];
    sp28.y *= pool[0x8E];
    sp28.z *= pool[0x8E];
    if (sp28.z > sp8 + (mtx_z - r29->unk_14)) {
        sp28.z = sp8 + (mtx_z - r29->unk_14);
    }

    lbl_8006E2C0(&sp1C, pool[0x49], pool[0x49], mtx_z - sp28.z);
    fn_8006E250(&sp28, &sp40);

    sp34.x = sp40.x + sp1C.x;
    sp34.y = sp40.y + sp1C.y;
    sp34.z = sp40.z + sp1C.z;

    fn_1_B81C(&sp40, &sp34, 0);
}
/* fzgx:end fn_1_96F20 */

/* fzgx:begin fn_1_97174 */
typedef struct Fn197174Owner Fn197174Owner;
typedef struct Fn197174Root Fn197174Root;
typedef struct Fn197174Entry Fn197174Entry;

struct Fn197174Owner {
    u8 unk_00[0x14];
    u8 *base;
};

struct Fn197174Root {
    u8 unk_00[0x08];
    u16 count;
};

struct Fn197174Entry {
    u8 unk_00[0x1C];
    u32 offset;
};

extern Fn197174Root *fn_1_41BDC(void);
extern Fn197174Entry *fn_1_41B18(Fn197174Owner *owner, void *arg1, s32 index);

s32 fn_1_97174(Fn197174Owner *owner, void *arg1, void *arg2) {
    Fn197174Root *root = fn_1_41BDC();
    s32 index = 0;

    while (index < (s32)root->count) {
        Fn197174Entry *entry = fn_1_41B18(owner, arg1, index);
        if (fn_80083BCC(owner->base + entry->offset, arg2) == 0) {
            return index;
        }
        index++;
    }
    return -1;
}
/* fzgx:end fn_1_97174 */

/* fzgx:begin fn_1_97204 */
extern void fn_1_9724C(void *arg0, void *arg1);
extern u8 fn_1_97F80(void *arg0, void *arg1);

void fn_1_97204(void *arg0, void *arg1) {
    fn_1_9724C(arg0, arg1);
    if (fn_1_97F80(arg0, arg1)) {
        return;
    }
}
/* fzgx:end fn_1_97204 */

/* fzgx:begin fn_1_9724C */
// Loads the active resource value when the initialization check has not completed.
void fn_1_9724C(void) {
    if (fn_1_98104() == 0) {
        ADXT_Stop(lbl_1_bss_6EAD0.unk_0->unk_4);
    }
}
/* fzgx:end fn_1_9724C */

/* fzgx:begin fn_1_97F1C */
typedef struct {
    u8 unk_000[0x4A4];
    s32 unk_4A4;
} Fn197F1CObject;

/* Formats the indexed message and stores its parsed value in the object. */
s16 fn_1_97F1C(Fn197F1CObject *object, s16 index) {
    char buffer[0x80];

    sprintf(buffer, lbl_1_data_27D90, lbl_1_data_20D1C[index]);
    object->unk_4A4 = fn_1_12A32C(buffer);
    return (s16)object->unk_4A4;
}
/* fzgx:end fn_1_97F1C */

/* fzgx:begin fn_1_97F80 noprologue */
#include "types.h"

extern u32 lbl_801A6410;

typedef struct Fn197F80Object Fn197F80Object;
struct Fn197F80Object {
    u8 unk_000[0x488];
    u8 unk_488;
    u8 unk_489;
    u8 unk_48A[0x1A];
    void *unk_4A4;
    void *unk_4A8;
    void *unk_4AC;
    void *unk_4B0;
    void *unk_4B4;
};

extern u32 lbl_1_data_209C0;



extern void *fn_80083970(const char *, const char *);
extern void sprintf(char *, const char *, ...);
extern int fn_80083BCC(const char *, const char *);
extern void fn_1_12A2D0(void *);
extern void fn_1_12A2B8(int);
extern void fn_1_12AB38(const char *);
extern int fn_1_12A8A4(const char *, void **);
extern void *fn_1_4630(u32, u32, const char *, u32);
extern void fn_80083DB0(void *, const char *);
extern u32 strlen(const char *);

u32 fn_1_97F80(Fn197F80Object *rob, const char *name) {
    void *resource = 0;
    char path[0x40];
    u8 *data = (u8 *)&lbl_1_data_209C0;
    u32 length;

    if (name == 0 || fn_80083970(name, (const char *)(data + 0x6390)) == 0) {
        return 0;
    }

    sprintf(path, (const char *)(data + 0x73e0), name);
    if (fn_80083BCC(path, (const char *)(data + 0x73e8)) == 0 ||
        fn_80083BCC(path, (const char *)(data + 0x73f4)) == 0 ||
        fn_80083BCC(path, (const char *)(data + 0x7400)) == 0 ||
        fn_80083BCC(path, (const char *)(data + 0x740c)) == 0) {
        return 1;
    }

    fn_1_12A2D0(rob->unk_4A4);
    fn_1_12A2B8(1);
    fn_1_12AB38((const char *)(data + 0x7418));
    if (fn_1_12A8A4(path, &resource) == 0) {
        return 0;
    }

    fn_1_12AB38((const char *)(data + 0x6eec));
    fn_1_12A2B8(0);
    length = strlen(name);
    rob->unk_488 = 1;
    rob->unk_489 = 1;
    rob->unk_4A8 = resource;
    rob->unk_4AC = *(void **)resource;
    rob->unk_4B0 = (u8 *)resource + 4;
    rob->unk_4B4 = fn_1_4630(*(u32 *)&lbl_801A6410,
                            (length + 0x20) & ~0x1f,
                            (const char *)(data + 0x7240), 0xfa9);
    fn_80083DB0(rob->unk_4B4, name);
    return 1;
}
/* fzgx:end fn_1_97F80 */

/* fzgx:begin fn_1_98104 noprologue */
#include "types.h"

extern u8 lbl_1_data_27C00[0xE0];
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32, u32, u8 *, u32);
extern void fn_80008BEC(void *, u32, u32);

typedef struct Fn198104Obj {
    u8 unk_00[0x1C];
    u32 value_1C;
    u8 unk_20[0x0C];
    u32 value_2C;
} Fn198104Obj;

s32 fn_1_98104(Fn198104Obj *obj) {
    Fn198104Obj *ptr = (Fn198104Obj *)((u8 *)obj + 0x488);
    u32 saved;

    if (ptr == 0) {
        return 0;
    }

    saved = ptr->value_1C;
    if (ptr->value_2C != 0) {
        fn_1_46B4(lbl_801A6410, ptr->value_2C, lbl_1_data_27C00, 0xfc0);
        ptr->value_2C = 0;
    }

    fn_80008BEC(ptr, 0, 0x30);
    ptr->value_1C = saved;
    return 1;
}
/* fzgx:end fn_1_98104 */

/* fzgx:begin fn_1_9818C */
extern u32 fn_1_12A734(u32);

s32 fn_1_9818C(u32 arg0) {
    s16 v0;
    s32 v1;
    u32 t0;
    v0 = (s16)arg0;
    v1 = v0;
    if (v0 != -1) {
    t0 = fn_1_12A734(v1);
    v1 = t0;
    v1 = 1;
    } else {
    v1 = 0;
    }
    return v1;
}
/* fzgx:end fn_1_9818C */
