#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/avline.h"

extern u32 lbl_801A6410;
extern u32 fn_1_45D0(u32, u32, unsigned char *, u32);
extern void fn_1_46B4(u32, u32, void *, u32);
extern void fn_80008BA8(void*, void*, u32);
extern void *lbl_801A6D00;
extern void lbl_8006DCA4(void);
extern void fn_80074918(u32, u32, u32);
extern void fn_800746A8(u8, u32);
extern void fn_8007245C(u32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_800720B0(u32);
extern void fn_800747D0(u32, u32, u32, u32, u32, u32, u32);
extern void fn_800734A8(u32, u32, u32, u32);
extern void fn_80072EDC(u32, u32);
extern void fn_80073C6C(u32);
extern void fn_80073678(u32);
extern void fn_80074660(u32);
extern void fn_80073898(u32);
extern void fn_80074788(u32);
extern void GXLoadPosMtxImm(void *, u32);
extern void fn_8003462C(u32, u32, u32);

/* fzgx:begin fn_1_58114 */
void fn_1_58114(void) {
    lbl_1_bss_6C840 = fn_1_45D0(lbl_801A6410, 0x6590, lbl_1_data_1C68C, 0x39f);
}
/* fzgx:end fn_1_58114 */

/* fzgx:begin fn_1_58158 */
// fn_1_58158: loads global values and calls fn_1_46B4.
void fn_1_58158(void) {
    u32 v1 = lbl_801A6410;
    u32 v2 = lbl_1_bss_6C840;
    fn_1_46B4(v1, v2, &lbl_1_data_1C68C, 0x3a6);
}
/* fzgx:end fn_1_58158 */

/* fzgx:begin fn_1_5819C */
void fn_1_5819C(void) {
    lbl_1_bss_6C844 = 0;
}
/* fzgx:end fn_1_5819C */

/* fzgx:begin fn_1_581AC */
typedef struct AvLineEntry {
    u16 unk_00;
    u16 unk_02;
    u8 unk_04[0x100];
} AvLineEntry;

#pragma opt_propagation off
s32 fn_1_581AC(u16 value, u16 type, void* data) {
    AvLineEntry *entry;
    u8 *p;

    if (lbl_1_bss_6C844 == 0x64) {
        return 0;
    }

    ((AvLineEntry*)lbl_1_bss_6C840)[lbl_1_bss_6C844].unk_00 = value;
    p = (u8*)lbl_1_bss_6C840 + lbl_1_bss_6C844 * 0x104;
    entry = (AvLineEntry*)p;
    entry->unk_02 = type;
    fn_80008BA8(((AvLineEntry*)lbl_1_bss_6C840)[lbl_1_bss_6C844].unk_04, data, 0x100);
    lbl_1_bss_6C844++;
    return 1;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_581AC */

/* fzgx:begin fn_1_58248 */
#include "dolphin/hw_regs.h"

typedef struct AvLineVtx {
    f32 x;
    f32 y;
    f32 z;
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} AvLineVtx;

typedef struct AvLineList {
    u16 unk_00;
    u16 count;
    AvLineVtx vtx[16];
} AvLineList;

typedef struct AvLineState {
    u8 unk_00;
    u8 pad_01[3];
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    u32 unk_14;
    u8 pad_18[4];
} AvLineState;

extern AvLineState lbl_1_data_1C670;

/* fzgx-allow: A1 GX FIFO write port; retail materialises it as lis 0xcc01/stfs -0x8000 */
#define GX_WG_F32(v) (*(volatile f32 *)GX_FIFO_BASE = (v)) /* Hardware access must remain ordered. */
#define GX_WG_U8(v) (*(volatile u8 *)GX_FIFO_BASE = (v)) /* Hardware access must remain ordered. */

static inline void avline_pos3f32(const f32 x, const f32 y, const f32 z) {
    GX_WG_F32(x);
    GX_WG_F32(y);
    GX_WG_F32(z);
}

static inline void avline_clr4u8(const u8 r, const u8 g, const u8 b, const u8 a) {
    GX_WG_U8(r);
    GX_WG_U8(g);
    GX_WG_U8(b);
    GX_WG_U8(a);
}

void fn_1_58248(void) {
    AvLineState *state;
    AvLineList *list;
    AvLineVtx *v;
    u16 count;
    s32 j;
    s32 off;
    s32 i;

    state = &lbl_1_data_1C670;
    state->unk_04 = 1;
    state->unk_08 = 1;
    state->unk_0C = 1;
    state->unk_10 = 0;
    lbl_8006DCA4();
    fn_80074918(1, 3, 1);
    fn_800746A8(lbl_1_data_1C670.unk_00, lbl_1_data_1C670.unk_14);
    fn_8007245C(0xa00);
    fn_800728A8(state->unk_04, state->unk_08, state->unk_0C, state->unk_10);
    fn_800720B0(0);
    fn_800747D0(4, 0, 1, 1, 0, 2, 1);
    fn_800734A8(0, 0xff, 0xff, 4);
    fn_80072EDC(0, 4);
    fn_80073C6C(0);
    fn_80073678(1);
    fn_80074660(0);
    fn_80073898(0);
    fn_80074788(1);
    GXLoadPosMtxImm(lbl_801A6D00, 0);

    for (i = 0, off = 0; i < lbl_1_bss_6C844; off += sizeof(AvLineList), i++) {
        list = (AvLineList *)(lbl_1_bss_6C840 + off);
        v = list->vtx;
        lbl_1_data_1C670.unk_00 = list->unk_00;
        if (list->count >= 2) {
            fn_8003462C(0xb0, 0, count = list->count);
            for (j = 0; j < count; j++) {
                avline_pos3f32(v->x, v->y, v->z);
                avline_clr4u8(v->r, v->g, v->b, v->a);
                v++;
            }
        }
    }
    lbl_1_bss_6C844 = 0;
}
/* fzgx:end fn_1_58248 */

/* fzgx:begin fn_1_584AC */
// fn_1_584AC: linear congruential generator.
u32 fn_1_584AC(void) {
    u32 state = lbl_1_data_1D628;
    u32 next = state * 0x41c64e6du + 0x3039u;
    lbl_1_data_1D628 = next;
    return (next >> 16) & 0x7FFFu;
}
/* fzgx:end fn_1_584AC */
