#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/light.h"

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

/* fzgx:begin fn_1_7BCCC */
typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
} Triple_80074D28;

typedef struct {
    u8 pad_0[0x2];
    u16 unk_2;
    u8 pad_4[0x12];
    u16 unk_16;
    u8 pad_18[0x8];
    u32 unk_20;
} Fn17BCCCState;

extern void fn_80074D28(Triple_80074D28 *);

void fn_1_7BCCC(Triple_80074D28 *arg0) {
    Fn17BCCCState *state;

    state = (Fn17BCCCState *)&lbl_1_bss_6D7A8;
    if (state->unk_16 >= state->unk_2) {
        OSPanic((const char *)lbl_1_data_1EE44, 143, (const char *)lbl_1_data_1EE70);
    }
    *(Triple_80074D28 *)((u8 *)state->unk_20 + state->unk_16 * 12) = *arg0;
    fn_80074D28(arg0);
    state->unk_16++;
    return;
}
/* fzgx:end fn_1_7BCCC */

/* fzgx:begin fn_1_7BE94 */
u16 fn_1_7BE94(void) {
    return lbl_1_bss_6D7C0[0] - 1;
}
/* fzgx:end fn_1_7BE94 */

/* fzgx:begin fn_1_7BEAC noprologue */
#include "types.h"

// Scene-light routines manage descriptor tables and staged requests.
// Literal assertion strings preserve their shared data-pool layout.

typedef struct {
    u8 _[0x40];
} LightPoolEntry;

typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
} SfxElem;  // 0xC

typedef struct {
    u16 f0;
    u16 f2;
    u16 arr[8];
} LightRequest;  // 0x14

typedef struct {
    u16 h0;              /* 0x00 pool capacity */
    u16 h2;              /* 0x02 slot capacity */
    u16 h4;              /* 0x04 request capacity */
    u8 _6[0x14 - 0x6];
    u16 h14;             /* 0x14 pool count */
    u16 h16;             /* 0x16 active-slot count */
    u16 h18;             /* 0x18 request count */
    u8 _1a[0x1c - 0x1a];
    LightPoolEntry *w1c; /* 0x1c channel pool base (0x40 stride) */
    SfxElem *w20;        /* 0x20 slot array base (0xC stride) */
    LightRequest *w24;   /* 0x24 request array base (0x14 stride) */
    u16 arr28[8];        /* 0x28 cached channel ids */
    s32 w38;             /* 0x38 cached frame id */
} SfxRecord;

// Light-source descriptors and link triples.
extern u32 lbl_1_data_1E558[13];
extern u32 lbl_1_data_1E58C[13];
extern u32 lbl_1_data_1E5C0[13];
extern u32 lbl_1_data_1E5F4[13];
extern u32 lbl_1_data_1E628[13];
extern u32 lbl_1_data_1E65C[13];
extern u32 lbl_1_data_1E690[13];
extern u32 lbl_1_data_1E6C4[13];
extern u32 lbl_1_data_1E6F8[13];
extern u32 lbl_1_data_1E72C[13];
extern u32 lbl_1_data_1E760[13];
extern u32 lbl_1_data_1E794[13];
extern u32 lbl_1_data_1E7C8[13];
extern u32 lbl_1_data_1E7FC[13];
extern u32 lbl_1_data_1E830[13];
extern u32 lbl_1_data_1E864[13];
extern u32 lbl_1_data_1E898[13];
extern u32 lbl_1_data_1E8CC[13];
extern u32 lbl_1_data_1E900[13];
extern u32 lbl_1_data_1E934[13];
extern u32 lbl_1_data_1E968[3];
extern u32 lbl_1_data_1E974[3];
extern u32 lbl_1_data_1E980[3];
extern u32 lbl_1_data_1E98C[3];
extern u32 lbl_1_data_1E998[3];
extern u32 lbl_1_data_1E9A4[3];
extern u32 lbl_1_data_1E9B0[3];
extern u32 lbl_1_data_1E9BC[3];
extern u32 lbl_1_data_1E9C8[3];
extern u32 lbl_1_data_1E9D4[3];
extern u32 lbl_1_data_1E9E0[3];
extern u32 lbl_1_data_1E9EC[3];
extern u32 lbl_1_data_1E9F8[3];
extern u32 lbl_1_data_1EA04[3];
extern u32 lbl_1_data_1EA10[3];
extern u32 lbl_1_data_1EA1C[3];
extern u32 lbl_1_data_1EA28[3];
extern u32 lbl_1_data_1EA34[3];
extern u32 lbl_1_data_1EA40[3];
extern u32 lbl_1_data_1EA4C[3];
extern u32 lbl_1_data_1EA58[3];
extern u32 lbl_1_data_1EA64[3];
extern u32 lbl_1_data_1EA70[13];
extern u32 lbl_1_data_1EAA4[13];
extern u32 lbl_1_data_1EAD8[13];
extern u32 lbl_1_data_1EB0C[13];
extern u32 lbl_1_data_1EB40[13];
extern u32 lbl_1_data_1EB74[13];
extern u32 lbl_1_data_1EBA8[13];
extern u32 lbl_1_data_1EBDC[13];
extern u32 lbl_1_data_1EC10[13];
extern u32 lbl_1_data_1EC44[13];
extern u32 lbl_1_data_1EC78[13];
extern u32 lbl_1_data_1ECAC[13];
extern u32 lbl_1_data_1ECE0[13];
extern u32 lbl_1_data_1ED14[13];
extern u32 lbl_1_data_1ED48[3];
extern u32 lbl_1_data_1ED54[3];
extern u32 lbl_1_data_1ED60[3];
extern u32 lbl_1_data_1ED6C[3];
extern u32 lbl_1_data_1ED78[3];
extern u32 lbl_1_data_1ED84[3];
extern u32 lbl_1_data_1ED90[3];
extern u32 lbl_1_data_1ED9C[3];
extern u32 lbl_1_data_1EDA8[3];
extern u32 lbl_1_data_1EDB4[3];
extern u32 lbl_1_data_1EDC0[3];
extern u32 lbl_1_data_1EDCC[3];
extern u32 lbl_1_data_1EDD8[3];
extern u32 lbl_1_data_1EDE4[3];
extern u32 lbl_1_data_1EDF0[3];
extern u32 lbl_1_data_1EDFC[3];
extern u32 lbl_1_data_1EE08[3];
extern u32 lbl_1_data_1EE14[3];
extern u32 lbl_1_data_1EE20[3];
extern u32 lbl_1_data_1EE2C[3];
extern u32 lbl_1_data_1EE38[3];

extern SfxRecord lbl_1_bss_6D7A8;
extern char lbl_1_data_1EE44[];
extern char lbl_1_data_1EE70[];

extern u16 lbl_1_bss_6D7C0;

extern void OSPanic(const char *file, int line, const char *msg, ...);
extern void fn_800356B8(LightPoolEntry *, int);
extern void fn_80074D28(SfxElem *);
extern int fn_80074D08(int);

// Adds a light-source descriptor to the pool and records its channel index.
#pragma opt_propagation off

void fn_1_7BB80(LightPoolEntry *src, int mask);
#pragma opt_propagation reset

// Appends a source entry to the active slot array.
// The structure copy preserves the required field access sequence.
void fn_1_7BCCC(SfxElem *src);

// Stages a light-set request for the selected channel.
// The channel list is read again after the callback, preserving the required reload.
static inline u16 *light_chan_ids(SfxRecord *r) { return r->arr28; }

static inline int light_top_chan(u8 *pool, int m) {
    int bit = 0x1F - __cntlzw(m);
    if (bit > 7 || bit < 0)
        OSPanic((char *)(pool + 0x8EC), 0x30, (char *)(pool + 0x904));
    return bit;
}
int fn_1_7BD6C(int mask);
// Returns the current light count.
u16 fn_1_7BE94(void);

// Reconciles one active slot with its requested light set.
// Separate halfword cursors preserve the required indexed access order.
void fn_1_7BEAC(u16 arg0) {
    SfxRecord *g = &lbl_1_bss_6D7A8;
    u16 *ap, *ew;
    u32 i;
    LightRequest *elem = &lbl_1_bss_6D7A8.w24[arg0];
    int flag = 0;

    for (i = 0, ap = g->arr28, ew = (u16 *)elem; i < 8; i++, ap++, ew++) {
        if (ew[2] != *ap) {
            fn_800356B8(&g->w1c[ew[2]], 1 << i);
            *ap = ew[2];
            flag = 1;
        }
    }
    if (g->h16 != elem->f2 && g->h16 != 0) {
        fn_80074D28(&g->w20[elem->f2]);
        g->h16 = elem->f2;
    }
    if (g->w38 != elem->f0 || flag != 0) {
        fn_80074D08(elem->f0);
        g->w38 = elem->f0;
    }
}
/* fzgx:end fn_1_7BEAC */

/* fzgx:begin fn_1_7BF9C */
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
