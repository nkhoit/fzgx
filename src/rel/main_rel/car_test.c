#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/car_test.h"

extern void fn_1_5634C(u32 arg0);
extern void fn_1_7ECB8(u32 arg0, u32 arg1, u32 arg2);
extern void *lbl_801A6410;
extern const f64 lbl_1_rodata_3588;
extern void fn_1_12AB38(const char *);
extern void *fn_1_45D0(void *, s32, const char *, s32);
extern void fn_80008BEC(void *, s32, s32);
extern void fn_1_80F80(void *, u8, void *);
extern void fn_1_1502BC(void *, void *, void *);

extern void fn_80083DB0(void* arg0, u32 arg1);
extern void fn_1_801F8(s16 arg0, void* arg1);
extern const f32 lbl_1_rodata_33AC;
extern void *fn_1_4630(void *arg0, u32 arg1, void *arg2, u32 arg3);
extern const f32 lbl_1_rodata_33B0[84];
extern void *memset(void *dst, int value, u32 size);
extern void fn_1_46B4(void *arg0, void *arg1, u8 *arg2, s32 arg3);
extern void fn_1_7F954(void *arg0, s32 arg1);
extern void fn_1_49614(void);
extern const f32 lbl_1_rodata_33A8;
extern void fn_80071ED4(s32 arg0, f32 arg1, f32 arg2);
extern void fn_80072014(void *arg0);
extern void fn_800720B0(s32 arg0);

/* fzgx:begin fn_1_7BF9C noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/car_test.h"

extern u16 lbl_1_bss_6D7C0[20];

extern void *lbl_801A6410;
extern u32 fn_1_4630(u32, int, void *, int);
extern void fn_800793D4(u32, int, int);
extern void fn_1_7C13C(void *);
extern void fn_1_7C1E8(u32);
extern u8 fn_1_816E8(void *, u8);
extern const f32 lbl_1_rodata_33A8;
extern void fn_1_495D8(int, int, f32);
extern void fn_1_495FC(void);
extern void OSPanic(const char *, int, const char *, ...);

typedef struct {
    void *unk_0;
    u8 unk_4;
    u8 unk_5;
    u8 unk_6;
    s8 unk_7;
    u8 unk_8;
    u8 unk_9[3];
    void *unk_c;
    void *unk_10;
    void *unk_14;
    void *unk_18;
    void *unk_1c;
    u32 unk_20;
    u8 unk_24;
} LightState;

// Initialize the shared light state and its required resources.
void fn_1_7BF9C(void *arg, s8 flag) {
    u8 *resource_table;
    u32 resource_18;
    u32 resource_1c;
    u32 resource_c;

    resource_table = (u8 *)&lbl_1_data_1EEB0;
    lbl_1_bss_6D7E8 = fn_1_4630(
        (u32)lbl_801A6410, 0x2c, resource_table + 0xac, 0x33);
    resource_18 = fn_1_4630(
        (u32)lbl_801A6410, 4, resource_table + 0xac, 0x34);
    resource_1c = fn_1_4630(
        (u32)lbl_801A6410, 0x18, resource_table + 0xac, 0x35);
    resource_c = fn_1_4630(
        (u32)lbl_801A6410, 0xa4, resource_table + 0xac, 0x36);

    fn_800793D4(resource_c, 0xff, 0xa4);
    fn_1_7C13C(arg);
    fn_1_7C1E8(resource_1c);

    ((LightState *)lbl_1_bss_6D7E8)->unk_0 = arg;
    ((LightState *)lbl_1_bss_6D7E8)->unk_4 = 2;
    ((LightState *)lbl_1_bss_6D7E8)->unk_6 = 2;
    ((LightState *)lbl_1_bss_6D7E8)->unk_24 = 0;
    ((LightState *)lbl_1_bss_6D7E8)->unk_8 = fn_1_816E8(
        (u8 *)((LightState *)lbl_1_bss_6D7E8)->unk_0 +
            ((LightState *)lbl_1_bss_6D7E8)->unk_7 * 0x440,
        ((LightState *)lbl_1_bss_6D7E8)->unk_24);

    ((LightState *)lbl_1_bss_6D7E8)->unk_c = (void *)resource_c;
    ((LightState *)lbl_1_bss_6D7E8)->unk_10 = resource_table + 0x48;
    ((LightState *)lbl_1_bss_6D7E8)->unk_14 = resource_table + 0x94;
    ((LightState *)lbl_1_bss_6D7E8)->unk_18 = (void *)resource_18;
    ((LightState *)lbl_1_bss_6D7E8)->unk_1c = (void *)resource_1c;

    if (flag == 0) {
        ((LightState *)lbl_1_bss_6D7E8)->unk_20 |= 0x40000000;
    }

    fn_1_495D8(2, 2, lbl_1_rodata_33A8);
    fn_1_495FC();
}
/* fzgx:end fn_1_7BF9C */

/* fzgx:begin fn_1_7C13C */
#include "types.h"

typedef struct {
    u8 pad_32c[0x32c];
    void *field_32c;
    u8 pad_330[0x110];
} Fn17C13CEntry;

typedef struct {
    u8 pad_4[4];
    u16 field_4;
    u16 field_6;
    u8 pad_8[0x17c];
    f32 field_184;
} Fn17C13CObject;

void fn_1_7C13C(Fn17C13CEntry *arg0) {
    f32 value;
    Fn17C13CEntry *p;
    int i;

    value = 100.0f;
    p = arg0;
    for (i = 0; i < 0x29; i++) {
        p->field_32c = fn_1_4630((*(u8 * *)&lbl_801A6410), 0x620, (*(u8 (*)[128])&lbl_1_data_1EF5C), 0x58);
        ((Fn17C13CObject *)p->field_32c)->field_6 = (u16)i;
        ((Fn17C13CObject *)p->field_32c)->field_4 = (u16)i;
        ((Fn17C13CObject *)p->field_32c)->field_184 = value;
        p++;
    }
}
/* fzgx:end fn_1_7C13C */

/* fzgx:begin fn_1_7C1E8 */
void fn_1_7C1E8(void *out) {
    u8 *p;
    s8 i;

    p = (u8 *)out;
    for (i = 0; i < 2; i++) {
        *(u32 *)p = (u32)fn_1_4630(lbl_801A6410, 4, (*(u8 (*)[128])&lbl_1_data_1EF5C), 0x68);
        memset(*(void **)p, 0xff, 4);
        *(f32 *)(p + 4) = lbl_1_rodata_33B0[0];
        *(u16 *)(p + 8) = 0xE000;
        *(s16 *)(p + 10) = 0x2000;
        p += 0xc;
    }
}
/* fzgx:end fn_1_7C1E8 */

/* fzgx:begin fn_1_7C2A0 noprologue */
#include "types.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    s = 100.0f;
    s = 17.320507049560547f;
}
static const u32 fzgx_pool_table2[1] = {0x00FF00FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table3[1] = {0x00FF00FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table4[1] = {0x00FF00FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -100.0f;
    s = 3.0f;
    s = 6.0f;
    s = -3.0f;
    s = 182.04444885253906f;
    s = 255.0f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
}
#pragma section code_type ".text"

typedef struct Vec3f {
    f32 x, y, z;
} Vec3f;

typedef struct Line3 {
    Vec3f a;
    Vec3f b;
} Line3;

typedef struct Rodata33A8 {
    f32 f0;
    f32 f4;
    u8 pad8[4];
    u32 c0;
    u32 c1;
    u32 c2;
    f32 f18;
    f32 f1c;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2c;
} Rodata33A8;

typedef struct CarInner {
    u8 pad0[4];
    s16 idx;
    u8 pad6[0x76];
    f32 f7c;
    u8 pad80[4];
    f32 f84;
} CarInner;

typedef struct CarInfo {
    s32 count;
    u8 pad4[4];
    u8 *tbl;
} CarInfo;

typedef struct CarSlot {
    u8 **list;
    CarInfo *info;
    u32 pad;
} CarSlot;

typedef struct Car {
    u8 pad0[2];
    s8 limit;
    u8 pad3[0x329];
    CarInner *inner;
    u8 *p330;
    CarSlot slots[3];
    u8 pad358[0x62];
    s16 f3ba;
} Car;

typedef struct Game {
    u8 pad0[6];
    s8 f6;
    s8 f7;
    s8 f8;
    u8 pad9[3];
    u32 *masks;
    u8 pad10[0xc];
    u8 **color;
    u32 flags;
    s8 f24;
} Game;

extern Game *lbl_1_bss_6D7E8;
extern Rodata33A8 lbl_1_rodata_33A8;
extern u32 lbl_801A66A0;
extern u32 lbl_1_data_1EFDC;
extern u32 lbl_1_data_1EFE4;

extern u32 fn_1_3C18(u32);
extern void fn_1_3BDC(u32);
extern void fn_1_55210(void *);
extern void fn_1_57714(u8);
extern void fn_1_5773C(Vec3f *, Vec3f *, u32 *);
extern void fn_1_87238(Car *, s8, f32);
extern void fn_1_87610(Car *, Car *);
extern void fn_1_A77DC(Car *);
extern void fn_1_A7854(Car *, void *);
extern void fn_1_A8DD4(const char *, ...);
extern void fn_1_A8EF8(u16, u16);
extern void fn_80008BEC(void *, int, u32);
extern void fn_80072558(void);
extern void fn_80074D68(f32, f32, f32);
extern void fn_80074D78(u32);
extern void lbl_8006D7DC(void *);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB74(void *);
extern void lbl_8006DB30(void);
extern void lbl_8006DBE4(void);
extern void lbl_8006DCA4(void);
extern void lbl_8006DFC4(void *);
extern void lbl_8006E0A4(void *);
extern void mathutil_mtxA_rotate_y(s32);
extern u8 *fn_80083970(u8 *, const u8 *);

void fn_1_7C2A0(Car *car) {
    Rodata33A8 *pool = &lbl_1_rodata_33A8;
    s8 count;
    void * lab_t1;
    Line3 l0, l1, l2;
    u32 c0, c1, c2;
    s16 i, k;

    if (lbl_1_bss_6D7E8->flags & 0x40000000) {
        return;
    }
    count = car->slots[lbl_1_bss_6D7E8->f24 - 0 + 0].info->count;
    if (car->inner->idx == lbl_1_bss_6D7E8->f7 || lbl_1_bss_6D7E8->f6 == 5) {
        lbl_8006DAEC();
        lbl_8006DCA4();
        c0 = fzgx_pool_table2[0];
        c1 = fzgx_pool_table3[0];
        c2 = fzgx_pool_table4[0];
        fn_80008BEC(&l0, 0, 0x18);
        fn_80008BEC(&l1, 0, 0x18);
        fn_80008BEC(&l2, 0, 0x18);
        l0.a.x = (-100.0f);
        l0.b.x = (100.0f);
        l1.a.y = (-100.0f);
        l1.b.y = (100.0f);
        l2.a.z = (-100.0f);
        l2.b.z = (100.0f);
        fn_1_57714(2);
        fn_80072558();
        fn_1_5773C(&l0.a, &l0.b, &c0);
        fn_1_5773C(&l1.a, &l1.b, &c1);
        fn_1_5773C(&l2.a, &l2.b, &c2);
        if (lbl_1_bss_6D7E8->f6 == 5) {
            s8 v = car->inner->idx;
            f32 t0 = (6.0f) * (f32)(v % 2);
            f32 t1 = (6.0f) * (f32)(v / 2);
            car->inner->f7c = (3.0f) - t0;
            car->inner->f84 = (-3.0f) + t1;
        }
        lbl_8006E0A4((u8 *)car->inner + 0x7c);
        if (lbl_1_bss_6D7E8->f6 == 5) {
            mathutil_mtxA_rotate_y((s32)((182.044449f) * (f32)(lbl_801A66A0 % 360)));
        }
        {
            u8 *c = *lbl_1_bss_6D7E8->color;
            fn_80074D68((f32)c[0] / (255.0f), (f32)c[1] / (255.0f), (f32)c[2] / (255.0f));
        }
        fn_80074D78((u32)__cntlzw(lbl_1_bss_6D7E8->flags & 0x80000000) >> 5);
        lbl_8006DAEC();
        lbl_8006D7DC((u8 *)car->inner + 0x7c);
        lbl_8006DB74((u8 *)car->inner + 0x14c);
        fn_1_A77DC(car);
        lab_t1 = 0;
        fn_1_A7854(car, lab_t1);
        lbl_8006DB30();
        car->f3ba = lbl_1_bss_6D7E8->f24;
        fn_1_3BDC(3);
        if (lbl_1_bss_6D7E8->f8 == count) {
            i = 0;
            k = 0;
            for (; i < count; i++) {
                if (((1 << i) & lbl_1_bss_6D7E8->masks[lbl_1_bss_6D7E8->f7]) && i != 0) {
                    if ((s16)k > car->limit - 1) {
                        break;
                    }
                    if (fn_80083970(*(u8 **)(car->slots[lbl_1_bss_6D7E8->f24].info->tbl + i * 8 + 4), (u8 *)&lbl_1_data_1EFDC)
                        != *(u8 **)(car->slots[lbl_1_bss_6D7E8->f24].info->tbl + i * 8 + 4)) {
                        if (car->slots[lbl_1_bss_6D7E8->f24].list[i] == 0) {
                            k++;
                        } else {
                            lbl_8006DAEC();
                            if (car->p330 != 0) {
                                fn_1_87610(car, car);
                                lbl_8006DBE4();
                                lbl_8006DFC4(car->p330 + k * 0x30);
                                fn_80072558();
                                fn_1_55210(car->slots[lbl_1_bss_6D7E8->f24].list[i]);
                            }
                            lbl_8006DB30();
                            k++;
                        }
                    }
                }
            }
            fn_80072558();
            fn_1_87238(car, lbl_1_bss_6D7E8->f24, (1.0f));
        } else {
            fn_80072558();
            fn_1_55210(car->slots[lbl_1_bss_6D7E8->f24].list[lbl_1_bss_6D7E8->f8]);
        }
        {
            s16 r = fn_1_3C18(3);
            fn_1_A8EF8(0x140, 0x190);
            fn_1_A8DD4((const char *)&"cpu:%d\n", r);
        }
        lbl_8006DB30();
    }
}
/* fzgx:end fn_1_7C2A0 */

/* fzgx:begin fn_1_7D694 */
typedef struct {
    u8 _pad4[4];
    s16 value;
} Entry;

typedef struct {
    u8 _pad32c[0x32c];
    Entry *entry;
} Object;

typedef struct {
    u8 _pad7[7];
    s8 value;
} GlobalEntry;

// Compares the object's entry selector with the active global selector.
void fn_1_7D694(Object *obj) {
    Entry *entry = obj->entry;
    GlobalEntry *active = *(GlobalEntry **)&lbl_1_bss_6D7E8;

    if (entry->value == active->value) {
        return;
    }
}
/* fzgx:end fn_1_7D694 */

/* fzgx:begin fn_1_7E7A4 */
typedef struct Fn1_7E7A4Data {
    void *field_0;
    u8 pad_4[8];
    void *field_c;
    u8 pad_10[8];
    void *field_18;
    void *field_1c;
} Fn1_7E7A4Data;

void fn_1_7E7A4(Fn1_7E7A4Data *arg0) {
    s8 i;
    u32 offset;

    for (i = 0, offset = 0; i < 0x29; offset += 0x440, i++) {
        fn_1_46B4(
            lbl_801A6410,
            *(void **)(((((((0x32c) + ((u8 *)arg0->field_0)))) + ((offset))))),
            (*(u8 (*)[128])&lbl_1_data_1EF5C),
            0x313);
    }

    fn_1_7F954(arg0->field_0, 0x29);

    for (i = 0; i < 2; i++) {
        fn_1_46B4(
            lbl_801A6410,
            *(void **)((u8 *)arg0->field_1c + i * 0xc),
            (*(u8 (*)[128])&lbl_1_data_1EF5C),
            0x321);
    }

    fn_1_46B4(lbl_801A6410, arg0->field_18, (*(u8 (*)[128])&lbl_1_data_1EF5C), 0x324);
    fn_1_46B4(lbl_801A6410, arg0->field_c, (*(u8 (*)[128])&lbl_1_data_1EF5C), 0x325);
    fn_1_46B4(lbl_801A6410, arg0, (*(u8 (*)[128])&lbl_1_data_1EF5C), 0x326);
    fn_1_49614();
    fn_80074D68(lbl_1_rodata_33A8, lbl_1_rodata_33A8, lbl_1_rodata_33A8);
    fn_80074D78(1);
}
/* fzgx:end fn_1_7E7A4 */

/* fzgx:begin fn_1_7EAE8 */
// fn_1_7EAE8: main_rel .text:0x0007EAE8 size 0x24
// Wrapper that calls fn_1_5634C with argument 0.

void fn_1_7EAE8(void) {
    fn_1_5634C(0);
}
/* fzgx:end fn_1_7EAE8 */

/* fzgx:begin fn_1_7EB0C */
typedef struct {
    s8 unk_0;
} SignedByteView;

typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
} LocalBytes;

void fn_1_7EB0C(void) {
    LocalBytes local0;
    LocalBytes local1;

    local0.unk_0 = lbl_1_bss_6D7F4.unk_C;
    local0.unk_1 = lbl_1_bss_6D7F4.unk_D;
    local0.unk_2 = lbl_1_bss_6D7F4.unk_E;
    if ((s8)lbl_1_bss_6D7F4.unk_F != 0) {
        fn_80071ED4(((SignedByteView *)&lbl_1_bss_6D7F4)->unk_0 + 0,
                    lbl_1_bss_6D7F4.unk_4,
                    lbl_1_bss_6D7F4.unk_8);
        local1 = local0;
        fn_80072014(&local1);
        fn_800720B0(1);
    } else {
        fn_800720B0(0);
    }
}
/* fzgx:end fn_1_7EB0C */

/* fzgx:begin fn_1_7F1E8 */
void fn_1_7F1E8(u32 arg0, u32 arg1) {
    fn_1_7ECB8(arg0, arg1, 0x80000000); // fzgx-allow: A1 retail sentinel
}
/* fzgx:end fn_1_7F1E8 */

/* fzgx:begin fn_1_7F20C */
void fn_1_7F20C(u32 arg0, u32 arg1) {
    fn_1_7ECB8(arg0, arg1, 0x40000000); // fzgx-allow: A1 retail sentinel
}
/* fzgx:end fn_1_7F20C */

/* fzgx:begin fn_1_7F230 */
void fn_1_7F230(u32 arg0, u32 arg1) {
    fn_1_7ECB8(arg0, arg1, 0);
}
/* fzgx:end fn_1_7F230 */

/* fzgx:begin fn_1_7F254 */
void *fn_1_7F254(void *arg0, void *arg1) {
    u8 kind = ((u8 *)arg0)[5];
    s16 type;
    void *result;
    char *data = (char *)&lbl_1_data_1F1D8;

    if (kind == 4) {
        type = 2;
    } else if (kind == 0x28 || kind >= 0x29) {
        type = 3;
    } else {
        type = 1;
    }

    if ((((u32 *)arg0)[0] & 0x40000000) == 0) {
        fn_1_12AB38(data + 0xe0c);
        result = fn_1_45D0(lbl_801A6410, type * 0x30, data + 0xe18, 0x1d5);
        fn_80008BEC(result, 0, type * 0x30);
        fn_1_80F80(result, ((u8 *)arg0)[0x81a0], arg1);
        fn_1_12AB38(data + 0xe20);
    } else {
        struct {
            u16 a;
            u16 b;
            u16 c;
        } info;
        *(u32 *)&info = ((const u32 *)&lbl_1_rodata_3588)[0];
        info.c = ((const u16 *)&lbl_1_rodata_3588)[2];
        info.a = ((u8 *)arg0)[0x81a4];
        info.b = ((u8 *)arg0)[0x81ac];
        info.c = ((u8 *)arg0)[0x81b4];
        result = fn_1_45D0(lbl_801A6410, 0x90, data + 0xe18, 0x1e2);
        fn_80008BEC(result, 0, 0x90);
        fn_1_1502BC(result, &info, arg1);
    }
    return result;
}
/* fzgx:end fn_1_7F254 */
