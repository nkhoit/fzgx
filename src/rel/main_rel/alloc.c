#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/alloc.h"

extern char lbl_1_data_2C9C[20];
extern void OSPanic(const char *message, int line, const char *file, ...);
extern void fn_80009AA8(u32 value, u32 count, const char *file, int line);
extern u32 fn_1_435C(u32 value);
extern void fn_1_426C(s16 value);
extern f32 lbl_1_rodata_160;
extern f32 lbl_1_rodata_164[2];
extern u32 lbl_1_bss_F5C;
extern u32 lbl_1_bss_F60[2];
extern s32 fn_8008023C(Obj_1_bss_7AC20 *, u32 *, u32);
extern u32 lbl_801A6410;
extern Obj_1_bss_F68_Target *fn_1_45D0(u32, u32, u8 *, u32);
extern void fn_800793D4(Obj_1_bss_F68_Target *, u32, u32);
extern u16 fn_1_3F8C(u8 *, void (*)(void), u32, u32);
extern void fn_1_6394(void);
extern void fn_1_63D4(void);
extern void fn_1_DF74(void);
extern u8 lbl_1_bss_F76;
extern void fn_1_DA6C(LiveCamera *);
extern void fn_1_DE14(LiveCamera *);
extern void fn_1_E174(void);
extern void fn_1_F3D0(LiveCamera *);
s32 fn_1_3FC28(void);
void fn_1_3EF14(u32 *);
extern f32 lbl_1_rodata_16C;
extern void fn_8006CE1C(f32);

/* fzgx:begin fn_1_4928 */
typedef struct {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
} Fn1_4928Entry;

extern Fn1_4928Entry lbl_1_bss_DCC[32];

void fn_1_4928(void) {
    u32 value;
    u32 count;
    s32 remaining;
    Fn1_4928Entry *entry;

    entry = lbl_1_bss_DCC;
    remaining = 0x20;
    while (remaining > 0) {
        if (entry->unk_08 != 0) {
            entry->unk_04--;
            if (entry->unk_04 == 0) {
                count = entry->unk_08;
                value = entry->unk_00;
                if (count == 0) {
                    OSPanic((const char *)&lbl_1_data_2CD0, 0x15b,
                                lbl_1_data_2C9C);
                }
                fn_80009AA8(value, count, (const char *)&lbl_1_data_2CD0,
                            0x15b);
                entry->unk_08 = 0;
            }
        }
        remaining--;
        entry++;
    }
}
/* fzgx:end fn_1_4928 */

/* fzgx:begin fn_1_49F0 */
void fn_1_49F0(u32 *value) {
    lbl_1_data_2CD8 = *value;
}
/* fzgx:end fn_1_49F0 */

/* fzgx:begin fn_1_4A00 noprologue */
#include "types.h"

// Updates fade colors and transition state using the shared color data.
// Aggregate assignment preserves the source and destination register order.













typedef struct {
    u32 value;
} FadeColor;

typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 flags;
    u16 h4;
    s16 h6;
    FadeColor color;
    void *pc;
} AllocCtl;

extern FadeColor lbl_1_data_2CD8;
extern AllocCtl lbl_1_data_2CDC;
extern char lbl_1_data_2CEC[];

extern void *fn_1_435C(void *scope);
extern s16 fn_1_3F8C(void *name, void *tick, void *ctx, int flag);
extern void fn_1_4010(s16 id, void *teardown);
extern void fn_1_4060(void);
extern void fn_1_426C(s32 h);
extern void fn_8006CDFC(void *arg);
extern void fn_8006CE1C(f32 level);

void fn_1_4BB0(void);
f32 fn_1_4D14(AllocCtl *ctl);
void fn_1_4CD8(void);
void fn_1_4DE0(AllocCtl *ctl, u32 reason);
void fn_1_4E60(AllocCtl *ctl);

void fn_1_4A00(int dir, u8 rate, void *arg) {
    void *prev;

    if (lbl_1_data_2CDC.h6 != -1) {
        fn_1_4BB0();
        lbl_1_data_2CDC.h4 = (u16)(65535.0f * fn_1_4D14(&lbl_1_data_2CDC));
    } else if (dir != 0) {
        lbl_1_data_2CDC.h4 = 0xFFFF;
    } else {
        lbl_1_data_2CDC.h4 = 0;
    }

    lbl_1_data_2CDC.flags = 0;

    if (rate == 0) {
        if (dir != 0) {
            fn_1_4CD8();
        } else {
            fn_8006CE1C(1.0f);
        }
        return;
    }

    if (dir != 0) {
        lbl_1_data_2CDC.flags |= 2;
        if (lbl_1_data_2CDC.h4 < 0x100) {
            fn_1_4CD8();
            lbl_1_data_2CDC.h4 = 0;
            return;
        }
    } else {
        lbl_1_data_2CDC.flags |= 4;
        if (lbl_1_data_2CDC.h4 > 0xff00) {
            fn_8006CE1C(1.0f);
            lbl_1_data_2CDC.h4 = 0xFFFF;
            return;
        }
    }

    lbl_1_data_2CDC.flags |= 1;
    lbl_1_data_2CDC.b1 = 0;
    lbl_1_data_2CDC.b2 = 1;
    lbl_1_data_2CDC.b0 = rate;
    lbl_1_data_2CDC.pc = arg;
    prev = fn_1_435C(arg);
    lbl_1_data_2CDC.h6 = fn_1_3F8C(lbl_1_data_2CEC, fn_1_4E60, &lbl_1_data_2CDC, 0);
    fn_1_4010(lbl_1_data_2CDC.h6, fn_1_4DE0);
    fn_1_435C(prev);
}
void fn_1_4BB0(void);
int fn_1_4C10(void);
f32 fn_1_4C24(void);
int fn_1_4CAC(void);
void fn_1_4CC0(void);
void fn_1_4CD8(void);
f32 fn_1_4D14(AllocCtl *ctl);
void fn_1_4DE0(AllocCtl *ctl, u32 reason);
void fn_1_4E60(AllocCtl *ctl);
/* fzgx:end fn_1_4A00 */

/* fzgx:begin fn_1_4BB0 */
void fn_1_4BB0(void) {
    if (lbl_1_data_2CDC.unk_3 & 1) {
        u32 value = fn_1_435C(lbl_1_data_2CDC.unk_C);
        fn_1_426C(lbl_1_data_2CDC.unk_6);
        fn_1_435C(value);
    }
}
/* fzgx:end fn_1_4BB0 */

/* fzgx:begin fn_1_4C10 */
int fn_1_4C10(void) {
    u8 value = lbl_1_data_2CDC.unk_3;
    return value & 1;
}
/* fzgx:end fn_1_4C10 */

/* fzgx:begin fn_1_4C24 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 65535.0f;
    s = 1.0f;
    s = -1.0f;
    s = 0.0f;
    d = 4503599627370496.0;
}
#pragma section code_type ".text"

extern f32 lbl_1_rodata_160;

f32 fn_1_4C24(void) {
    f32 *rodata;
    f32 ratio;

    rodata = &lbl_1_rodata_160;

    if ((lbl_1_data_2CDC.unk_3 & 1) == 0) {
        return (-1.0f);
    }

    ratio = (f32)lbl_1_data_2CDC.unk_1 / (f32)lbl_1_data_2CDC.unk_0;
    if (ratio < (0.0f)) {
        return (0.0f);
    }
    if (ratio > (1.0f)) {
        return (1.0f);
    }
    return ratio;
}
/* fzgx:end fn_1_4C24 */

/* fzgx:begin fn_1_4CAC */
u32 fn_1_4CAC(void) {
    return (lbl_1_data_2CDC.unk_3 >> 1) & 1;
}
/* fzgx:end fn_1_4CAC */

/* fzgx:begin fn_1_4CC0 */
void fn_1_4CC0(void) {
    lbl_1_data_2CDC.unk_3 &= 0xfe;
}
/* fzgx:end fn_1_4CC0 */

/* fzgx:begin fn_1_4CD8 */
#include "types.h"

struct fn_1_4CD8_lbl_1_data_2CDC {
    u8 pad_0[0x8];
    u32 unk_8;
};

#pragma opt_dead_assignments off
void fn_1_4CD8(void) {
    u32 *fzgx_value;
    fn_8006CE1C((0.0f));
    fzgx_value = &((*(struct fn_1_4CD8_lbl_1_data_2CDC *)&lbl_1_data_2CDC).unk_8);
    *fzgx_value = lbl_1_data_2CD8;
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_4CD8 */

/* fzgx:begin fn_1_4D14 pool */
typedef struct Fn14D14Data {
    u8 value0;
    u8 value1;
    u8 unk2;
    u8 flags;
    u16 value4;
} Fn14D14Data;

f32 fn_1_4D14(Fn14D14Data *data) {
    f32 value3;
    u8 value;
    f32 value1;
    f32 temp;

    value3 = ((f32)data->value4) / lbl_1_rodata_160;
    value = 0x0f;
    if (data->value0 != 0x3c) {
        value = data->value0;
    }
    if (data->value1 > value) {
        value1 = lbl_1_rodata_164[0];
    } else {
        value1 = ((f32)data->value1) / (f32)value;
    }

    if (data->flags & 2) {
        value1 = value3 * (lbl_1_rodata_164[0] - value1);
    } else {
        temp = lbl_1_rodata_164[0] - value3;
        temp = temp * value1;
        value1 = value3 + temp;
    }
    return value1;
}
/* fzgx:end fn_1_4D14 */

/* fzgx:begin fn_1_4DE0 */
extern f32 lbl_1_rodata_16C;
extern f32 lbl_1_rodata_164[2];

void fn_8006CE1C(f32);

#pragma opt_dead_assignments off
void fn_1_4DE0(Obj_1_data_2CDC *obj, u32 arg1) {
    if (arg1 == 1) {
        obj->unk_3 &= 0xFE;
        if (obj->unk_3 & 2) {
            Obj_1_data_2CDC *p;
            fn_8006CE1C(lbl_1_rodata_16C);
            p = &lbl_1_data_2CDC;
            p->unk_8 = lbl_1_data_2CD8;
        } else {
            fn_8006CE1C((*((0) + (lbl_1_rodata_164))));
        }
        obj->unk_6 = -1;
    }
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_4DE0 */

/* fzgx:begin fn_1_4E60 noprologue */
#include "types.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 65535.0f;
    s = 1.0f;
    s = -1.0f;
    s = 0.0f;
    d = 4503599627370496.0;
}
#pragma section code_type ".text"

typedef struct {
    u32 value;
} FadeColor;

typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 flags;
    u16 h4;
    s16 h6;
    FadeColor color;
    void *pc;
} AllocCtl;

extern FadeColor lbl_1_data_2CD8;
extern AllocCtl lbl_1_data_2CDC;

extern void fn_1_4060(void);
extern void fn_8006CDFC(FadeColor *arg);
extern void fn_8006CE1C(f32 level);

static inline f32 fade_level(AllocCtl *data) {
    f32 value3;
    u8 value;
    f32 value1;
    f32 temp;

    value3 = ((f32)data->h4) / 65535.0f;
    value = (data->b0 == 0x3c) ? 0x0f : data->b0;
    if (data->b1 > value) {
        value1 = 1.0f;
    } else {
        value1 = ((f32)data->b1) / (f32)value;
    }

    if (data->flags & 2) {
        value1 = value3 * (1.0f - value1);
    } else {
        temp = 1.0f - value3;
        temp = temp * value1;
        value1 = value3 + temp;
    }
    return value1;
}

static inline void fade_finish(void) {
    fn_8006CE1C(0.0f);
    lbl_1_data_2CDC.color = lbl_1_data_2CD8;
}

void fn_1_4E60(AllocCtl *ctl) {
    f32 level;
    FadeColor color;

    level = fade_level(ctl);
    if (0.0f == level) {
        fade_finish();
    } else {
        color = ctl->color;
        fn_8006CDFC(&color);
        fn_8006CE1C(level);
    }
    ctl->b1 += ctl->b2;
    if (ctl->b1 > ctl->b0) {
        ctl->flags &= ~1;
    }
    if (!(ctl->flags & 1)) {
        ctl->h6 = -1;
        ctl->h4 = (u16)(65535.0f * level);
        fn_1_4060();
    }
}
/* fzgx:end fn_1_4E60 */

/* fzgx:begin fn_1_4FEC */
void fn_1_4FEC(void) {
    lbl_1_bss_F58 = 0;
}
/* fzgx:end fn_1_4FEC */

/* fzgx:begin fn_1_4FFC */
void fn_1_4FFC(void) {
    u8 value[0x14ac];
    u32 result;

    lbl_1_bss_F5C &= ~0x20000000;
    lbl_1_bss_F5C &= ~0x08000000;
    lbl_1_bss_F5C &= 0x3fffffff;

    if (lbl_1_bss_F60[0] != 0) {
        lbl_1_bss_F60[0]--;
    }

    if (fn_1_3FC28() != 0) {
        fn_1_3EF14((u32 *)value);
        result = *(u32 *)value;
        if ((result & 0x2) != 0) {
            lbl_1_bss_7EFD8.unk_19 = 1;
        } else {
            lbl_1_bss_7EFD8.unk_19 = 0;
        }
    }
}
/* fzgx:end fn_1_4FFC */

/* fzgx:begin fn_1_509C */
// Initialize the allocation state and report whether initialization succeeded.
s32 fn_1_509C(void) {
    lbl_1_bss_7AC40 = lbl_1_bss_F58;
    if (fn_8008023C(&lbl_1_bss_7AC20, &lbl_1_bss_7AC40, 4) == 0) {
        return 0;
    }

    lbl_1_bss_7AC20.unk_0 = lbl_1_bss_7AC40;
    return 1;
}
/* fzgx:end fn_1_509C */

/* fzgx:begin fn_1_5104 */
void fn_1_5104(void) {
    lbl_1_bss_F58 = lbl_1_bss_7AC40;
    lbl_1_bss_7AC20.unk_0 = lbl_1_bss_7AC40;
}
/* fzgx:end fn_1_5104 */
