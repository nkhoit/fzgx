#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/som.h"

extern u32 lbl_1_bss_3BBC;
extern void sprintf(char *, const char *, ...);
extern void fn_1_465D0(char *, int);
extern u32 fn_1_45B2C(void *p);
extern int fn_1_458A0(void *src, void *dst, int len, int off);
extern void fn_1_45964(void *a, void *buf, int n, u32 off, void *cb);
extern void fn_1_1383C(void);
extern void DCInvalidateRange(void *addr, u32 len);
extern void fn_8000659C(void);
extern void fn_1_3308(void);
extern void fn_1_D3214(void);
extern void fn_8001AF64(void);

extern volatile u32 lbl_1_bss_3B28;  // volatile: retail reloads it on every access
extern volatile u32 lbl_1_bss_3B2C;  // volatile: retail reloads it on every access
extern volatile u32 lbl_1_data_5180;  // volatile: retail reloads it on every access
extern volatile u32 lbl_1_data_5184;  // volatile: retail reloads it on every access

typedef struct {
    u8 _0[0x2328];
    volatile u32 w2328;   // 0x2328  read cursor (active buffer)
    volatile u32 w232c;   // 0x232c  write offset
    u8 _pad1[0x23b8 - 0x232c - 4];
    volatile u8 b23b8;    // 0x23b8  buffer toggle
    u8 _pad2[3];
    volatile s32 w23bc;   // 0x23bc  DMA-ready flag
} SomRing;

extern SomRing lbl_1_bss_1800;
u8 fn_1_1350C(void *a, u8 *b);
u8 fn_1_1361C(void *a, u32 *b);

/* fzgx:begin fn_1_1350C */
// Reads command data from the loader's single- and double-buffered rings.
// Volatile preserves repeated cursor and readiness reads across ring updates.
u8 fn_1_1350C(void *a, u8 *b) {
    int n;

    if (lbl_1_bss_3B28 == 0) {
        n = lbl_1_data_5180;
        if (lbl_1_bss_3B2C + lbl_1_data_5180 > fn_1_45B2C(a)) {
            n = ((fn_1_45B2C(a) - lbl_1_bss_3B2C) + 0x1f) & ~0x1f;
        }
        if (n > 0) {
            fn_1_458A0(a, b, n, lbl_1_bss_3B2C);
        }
        lbl_1_bss_3B2C += lbl_1_data_5180;
    }

    {
        u8 ret = b[lbl_1_bss_3B28];
        lbl_1_bss_3B28 = lbl_1_bss_3B28 + 1;
        if (lbl_1_bss_3B28 >= lbl_1_data_5180) lbl_1_bss_3B28 = 0;
        return ret;
    }
}
/* fzgx:end fn_1_1350C */

/* fzgx:begin fn_1_1361C */

u8 fn_1_1361C(void *a, u32 *b) {
    SomRing *s = &lbl_1_bss_1800;
    int n;

    if (s->w232c == 0) {
        n = lbl_1_data_5184;
        s->b23b8 = 0;
        if (s->w232c + lbl_1_data_5184 > fn_1_45B2C(a)) {
            n = ((fn_1_45B2C(a) - s->w232c) + 0x1f) & ~0x1f;
        }
        if (n > 0) {
            DCInvalidateRange((void *)b[s->b23b8], lbl_1_data_5184);
            s->w23bc = 0;
            fn_1_45964(a, (void *)b[s->b23b8], n, s->w232c, fn_1_1383C);
        }
        s->w232c += lbl_1_data_5184;
        s->b23b8 = 1 - s->b23b8;
    }

    if (s->w2328 == 0) {
        n = lbl_1_data_5184;
        if (s->w232c + lbl_1_data_5184 > fn_1_45B2C(a)) {
            n = ((fn_1_45B2C(a) - s->w232c) + 0x1f) & ~0x1f;
        }
        while (s->w23bc == 0) {
            fn_8000659C();
            fn_1_3308();
            fn_1_D3214();
            fn_8001AF64();
        }
        if (n > 0) {
            DCInvalidateRange((void *)b[s->b23b8], lbl_1_data_5184);
            s->w23bc = 0;
            fn_1_45964(a, (void *)b[s->b23b8], n, s->w232c, fn_1_1383C);
        }
        s->w232c += lbl_1_data_5184;
        s->b23b8 = 1 - s->b23b8;
    }

    {
        u8 *buf = (u8 *)b[s->b23b8];
        u8 ret = buf[s->w2328];
        s->w2328 = s->w2328 + 1;
        if (s->w2328 >= lbl_1_data_5184) s->w2328 = 0;
        return ret;
    }
}
/* fzgx:end fn_1_1361C */

/* fzgx:begin fn_1_1383C */
void fn_1_1383C(void) {
    lbl_1_bss_3BBC = 1;
}
/* fzgx:end fn_1_1383C */

/* fzgx:begin fn_1_13A28 */
typedef struct Fn1_13A28 Fn1_13A28;

struct Fn1_13A28 {
    u8 unk_00[4];
    Fn1_13A28 *unk_04;
    Fn1_13A28 *unk_08;
    s32 unk_0c;
    Fn1_13A28 *unk_10;
    u8 unk_14[0x10];
    Fn1_13A28 *unk_24;
    Fn1_13A28 *unk_28;
    Fn1_13A28 *unk_2c;
    Fn1_13A28 *unk_30;
    Fn1_13A28 *unk_34;
    Fn1_13A28 *unk_38;
    Fn1_13A28 *unk_3c;
    Fn1_13A28 *unk_40;
    Fn1_13A28 *unk_44;
    u8 unk_48[8];
};

void fn_1_13A28(Fn1_13A28 *arg0, s32 arg1) {
    Fn1_13A28 *child;

    if (arg0->unk_04 != 0) {
        arg0->unk_04 = (Fn1_13A28 *)((u8 *)arg0->unk_04 + arg1);
    }
    if (arg0->unk_08 != 0) {
        arg0->unk_08 = (Fn1_13A28 *)((u8 *)arg0->unk_08 + arg1);
    }
    if (arg0->unk_10 != 0) {
        arg0->unk_10 = (Fn1_13A28 *)((u8 *)arg0->unk_10 + arg1);
    }

    child = arg0->unk_04;
    if (child->unk_24 != 0) {
        child->unk_24 = (Fn1_13A28 *)((u8 *)child->unk_24 + arg1);
    }
    if (child->unk_28 != 0) {
        child->unk_28 = (Fn1_13A28 *)((u8 *)child->unk_28 + arg1);
    }
    if (child->unk_2c != 0) {
        child->unk_2c = (Fn1_13A28 *)((u8 *)child->unk_2c + arg1);
    }
    if (child->unk_30 != 0) {
        child->unk_30 = (Fn1_13A28 *)((u8 *)child->unk_30 + arg1);
    }
    if (child->unk_34 != 0) {
        child->unk_34 = (Fn1_13A28 *)((u8 *)child->unk_34 + arg1);
    }
    if (child->unk_38 != 0) {
        child->unk_38 = (Fn1_13A28 *)((u8 *)child->unk_38 + arg1);
    }
    if (child->unk_3c != 0) {
        child->unk_3c = (Fn1_13A28 *)((u8 *)child->unk_3c + arg1);
    }
    if (child->unk_40 != 0) {
        child->unk_40 = (Fn1_13A28 *)((u8 *)child->unk_40 + arg1);
    }
    if (child->unk_44 != 0) {
        child->unk_44 = (Fn1_13A28 *)((u8 *)child->unk_44 + arg1);
    }

    if (arg0->unk_0c > 0) {
        s32 i;
        Fn1_13A28 *entry = arg0->unk_10;
        for (i = 0; i < arg0->unk_0c; entry += 1) {
            fn_1_13A28(entry, arg1);
            i++;
        }
    }
}
/* fzgx:end fn_1_13A28 */
