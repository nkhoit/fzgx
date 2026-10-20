#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/custom_memcard.h"

extern u32 lbl_801A6410;
extern u8 fn_1_B7C00(void);
extern s32 fn_1_B7CD4(void);
extern s32 fn_1_B7C5C(void);
extern void OSReport(const char* format, ...);
extern void fn_1_46B4(u32 arg0, void* arg1, u8* arg2, s32 arg3);
extern void fn_80008BA8(void*, void*, s32);
extern u32 lbl_1_bss_8CA6C[1605];
extern void fn_1_1324C4(void *arg0);
extern void fn_1_132774(void *arg0);

extern u32 lbl_801A6410;
extern u8 fn_1_B7C00(void);
extern s32 fn_1_B7CD4(void);
extern s32 fn_1_B7C5C(void);
extern void OSReport(const char* format, ...);
extern void fn_80008BA8(void*, void*, s32);
extern void fn_1_46B4(u32 arg0, void* arg1, u8* arg2, s32 arg3);

/* fzgx:begin fn_1_1312F0 */
// Reset the memcard state after reporting an unavailable card.

void fn_1_1312F0(void) {
    u8* state = (u8*)&lbl_1_bss_8CA40;
    void* memcard;

    if (fn_1_B7C00() == 0) {
        if (fn_1_B7CD4() == 0) {
            OSReport((const char*)lbl_1_data_40EF8, fn_1_B7C5C());
        }

        memcard = *(void**)(state + 0x18);
        *(s32*)(state + 0x00) = -1;
        *(s32*)(state + 0x08) = -1;
        *(s32*)(state + 0x0c) = 0;
        if (memcard != 0) {
            fn_1_46B4(lbl_801A6410, memcard, lbl_1_data_40EA4, 0x136);
            *(void**)(state + 0x18) = 0;
        }
    }
}
/* fzgx:end fn_1_1312F0 */

/* fzgx:begin fn_1_131390 noprologue */
#include "types.h"

// Begins a memory-card save by preparing its staging buffer and request.












typedef struct {
    s32 f0;         // 0x00
    s32 f4;         // 0x04
    s32 f8;         // 0x08 handle word
    u8 _c[4];
    u32 f10;        // 0x10 ready word
    u8 _14[4];
    void *f18;      // 0x18 staging buffer
} Blk;

typedef struct {
    u8 f0;          // 0x00
    u8 _1[3];
    u32 f4;         // 0x04
    u32 f8;         // 0x08
    void *fc;       // 0x0c
    u8 _10[0x24 - 0x10];
} Desc;

typedef struct {
    u8 _0[0x28];
} TimeScratch;

extern Blk lbl_1_bss_8CA40;
extern char lbl_1_data_40EA4[];
extern char lbl_1_data_40F0C[];
extern void *lbl_801A6410;

extern void OSPanic(void *file, int line, void *msg, ...);
extern void fn_80008BEC(void *dst, int val, int n);
extern void *fn_1_4630(void *a, int b, void *c, int d);
extern s64 OSGetTime(void);
extern void OSTicksToCalendarTime(s64 t, void *out);
extern void fn_1_AA6D8(int a, int b, void *c);

void fn_1_131390(void) {
    Blk *g = &lbl_1_bss_8CA40;
    TimeScratch scratch;
    Desc desc;

    if (g->f10 == 0) {
        OSPanic(lbl_1_data_40EA4, 0x147, lbl_1_data_40F0C);
        g->f0 = -1;
        g->f8 = -1;
        g->f10 = 0;
        return;
    }
    if (g->f8 == -1) {
        g->f0 = -1;
        return;
    }

    g->f18 = fn_1_4630(lbl_801A6410, 0x20700, lbl_1_data_40EA4, 0x154);
    fn_80008BEC(g->f18, 0, 0x20700);
    OSTicksToCalendarTime(OSGetTime(), &scratch);
    fn_80008BEC(&desc, 0, 0x24);
    desc.f4 = 0x104;
    desc.f0 = 3;
    desc.fc = g->f18;
    desc.f8 = 0;
    fn_1_AA6D8(2, g->f8 & 0xff, &desc);
    g->f4 = 5;
}
/* fzgx:end fn_1_131390 */

/* fzgx:begin fn_1_1314A4 */
// Reset the card state and release the card after an unavailable-card report.
void fn_1_1314A4(void) {
    u8* state = (u8*)&lbl_1_bss_8CA40;
    void* card;

    if (fn_1_B7C00() == 0) {
        if (fn_1_B7CD4() == 0) {
            OSReport((const char*)lbl_1_data_40EF8, fn_1_B7C5C());
        }

        fn_80008BA8(*(void**)(state + 0x10),
                    *(void**)(state + 0x18),
                    0x20700);

        card = *(void**)(state + 0x18);
        *(s32*)(state + 0x00) = -1;
        *(s32*)(state + 0x08) = -1;
        *(void**)(state + 0x10) = 0;

        if (card != 0) {
            fn_1_46B4(lbl_801A6410, card, lbl_1_data_40EA4, 0x188);
            *(void**)(state + 0x18) = 0;
        }
    }
}
/* fzgx:end fn_1_1314A4 */

/* fzgx:begin fn_1_131558 noprologue */
#include "types.h"

typedef struct {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    u8 pad_0C[8];
    u32 unk_14;
    u8 pad_18[0x128];
    u8 unk_140[0x1800];
} CustomMemcardState;

extern CustomMemcardState lbl_1_bss_8CA40;
extern u8 lbl_1_data_40EA4[84];
extern char lbl_1_data_40F30[34];

extern void OSPanic(const char* arg0, s32 arg1, const char* arg2, ...);
extern void fn_80008BEC(void* dst, s32 value, u32 size);
extern void fn_1_AA6D8(s32 arg0, u8 arg1, void* arg2);

void fn_1_131558(void) {
    CustomMemcardState* state = &lbl_1_bss_8CA40;
    u8 request[0x24];

    if (state->unk_14 == 0) {
        OSPanic((const char*)lbl_1_data_40EA4, 0x197, (const char*)lbl_1_data_40F30);
        state->unk_00 = -1;
        state->unk_08 = -1;
    } else if (state->unk_08 == -1) {
        state->unk_00 = -1;
    } else {
        fn_80008BEC(state->unk_140, 0, 0x1800);
        fn_80008BEC(request, 0, 0x24);
        request[0] = 3;
        *(void**)((u8*)request + 0x0C) = state->unk_140;
        fn_1_AA6D8(4, (u8)state->unk_08, request);
        state->unk_04 = 7;
    }
}
/* fzgx:end fn_1_131558 */

/* fzgx:begin fn_1_131620 noprologue */
#include "types.h"

// Reports and releases entries in the custom memory-card table.






typedef struct {
    u8  _00[0x24];
    u32 flag;    // 0x24
    u32 _28;     // 0x28
    u32 value;   // 0x2c
} McEntry;       // 0x30

typedef struct {
    s32  w0;               // 0x00
    u8   _04[4];           // 0x04
    s32  w8;               // 0x08
    u8   _0c[8];           // 0x0c
    u32 *w14;              // 0x14
    u8   _18[0x140 - 0x18];// 0x18
    McEntry ent[128];      // 0x140
} McTable;

extern u8 fn_1_B7C00(void);
extern int fn_1_B7CD4(void);
extern int fn_1_B7C5C(void);
extern void fn_1_46B4(int, u32, void *, int);
extern void OSReport(const char *, ...);
extern McTable lbl_1_bss_8CA40;
extern u8 lbl_1_data_40EA4[];
extern char lbl_1_data_40EF8[];
extern int lbl_801A6410;
void fn_1_131620(void)
{
  McTable *t;
  unsigned i;
  McEntry *e;
  t = &lbl_1_bss_8CA40;
  if (fn_1_B7C00() != 0)
  {
    return;
  }
  if (fn_1_B7CD4() == 0)
  {
    i = fn_1_B7C5C();
    OSReport(lbl_1_data_40EF8, i);
    for (e = t->ent, i = 0; i < 128; i++, e++)
    {
      if (e->flag != 0)
      {
        fn_1_46B4(lbl_801A6410, e->value, lbl_1_data_40EA4, 0x1c9);
      }
    }

    t->w0 = -1;
    return;
  }
  for (e = t->ent, i = 0; i < 128; i++, e++)
  {
    if (e->flag != 0)
    {
      t->w14[i] = e->value;
    }
    else
    {
      t->w14[i] = 0;
    }
  }

  t->w0 = -1;
  t->w8 = -1;
}
/* fzgx:end fn_1_131620 */

/* fzgx:begin fn_1_1317B4 */
u32 fn_1_1317B4(void) {
    return lbl_1_bss_8CA6C[0];
}
/* fzgx:end fn_1_1317B4 */

/* fzgx:begin fn_1_1317C4 */
extern u32 lbl_801A6410;


extern u32 fn_1_4630(u32 arg0, u32 arg1, u8 *arg2, u32 arg3);
extern void fn_80008BEC(void *arg0, u32 arg1, u32 arg2);
extern s32 fn_1_B7E98(s32 arg0);
extern void fn_1_AA6D8(s32 arg0, s32 arg1, void *arg2);

typedef struct {
    u8 unk_0;
    u8 pad_1[3];
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u8 pad_10[0x14];
} MemcardRequest;

void fn_1_1317C4(void) {
    MemcardRequest request;

    lbl_1_bss_8E384.unk_0 = fn_1_4630(
        lbl_801A6410, 0x20700, (*(u8 (*)[84])&lbl_1_data_40EA4), 0x1f3);

    fn_80008BEC(&request, 0, 0x24);
    request.unk_4 = 4;
    request.unk_4 |= 0x4000;
    request.unk_4 |= 0x2000;
    request.unk_0 = 3;
    request.unk_C = lbl_1_bss_8E384.unk_0;
    request.unk_8 = 0;

    if (fn_1_B7E98(0) != 0) {
        fn_1_AA6D8(2, 0, &request);
    } else if (fn_1_B7E98(1) != 0) {
        fn_1_AA6D8(2, 1, &request);
    } else {
        fn_1_AA6D8(2, 0, &request);
    }

    lbl_1_bss_8E380 = 1;
}
/* fzgx:end fn_1_1317C4 */

/* fzgx:begin fn_1_1318B8 */
u8 fn_1_1318B8(void) {
    return lbl_1_bss_8E380 != 0;
}
/* fzgx:end fn_1_1318B8 */

/* fzgx:begin fn_1_1318D4 */
// Completes the pending memory-card operation and clears its active flag.
s32 fn_1_1318D4(void) {
    s32 error;

    if (lbl_1_bss_8E380 == 0) {
        return 0;
    }

    if (fn_1_B7C00() != 0) {
        return 1;
    }

    if (fn_1_B7CD4() == 0) {
        error = fn_1_B7C5C();
        OSReport((const char*)lbl_1_data_40EF8, error);
    }

    if (lbl_1_bss_8E384.unk_0 != 0) {
        fn_1_46B4(lbl_801A6410, (void*)lbl_1_bss_8E384.unk_0,
                   lbl_1_data_40EA4, 0x22b);
        lbl_1_bss_8E384.unk_0 = 0;
    }

    lbl_1_bss_8E380 = 0;
    return 1;
}
/* fzgx:end fn_1_1318D4 */
