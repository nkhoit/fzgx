#include "types.h"
#include "rel/main_rel/globals.h"

// Scene lights: a pool of light objects, the slots made active from it, and staged
// requests that pick a slot and a set of up to eight channels (one bit per channel).

typedef struct {
    u8 _[0x40];
} LightObj;

typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
} LightSlot;  // 0xC

typedef struct {
    u16 frame;
    u16 slot;
    u16 chan[8];
} LightRequest;  // 0x14

extern void OSPanic(const char *file, int line, const char *msg, ...);
extern void fn_800356B8(LightObj *obj, int mask);
extern void fn_80074D28(LightSlot *slot);
extern int fn_80074D08(int frame);
extern void fn_800793D4(void *dst, int value, int size);

// "light.c" and the assertion messages; the TU's .data starts with the light descriptors.
extern u8 lbl_1_data_1E558[];
extern char lbl_1_data_1EE44[];
extern char lbl_1_data_1EE70[];

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u16 fzgx_obj_lbl_1_bss_6D7A8;          /* pool capacity */
u16 lbl_1_bss_6D7A8__fzgx_offset_2;    /* slot capacity */
u16 lbl_1_bss_6D7A8__fzgx_offset_4;    /* request capacity */
s32 lbl_1_bss_6D7A8__fzgx_offset_8;    /* pool bytes */
s32 lbl_1_bss_6D7A8__fzgx_offset_C;    /* slot bytes */
s32 lbl_1_bss_6D7A8__fzgx_offset_10;   /* request bytes */
u16 lbl_1_bss_6D7A8__fzgx_offset_14;   /* pool count */
u16 lbl_1_bss_6D7A8__fzgx_offset_16;   /* slot count */
u16 fzgx_obj_lbl_1_bss_6D7C0;          /* request count */
LightObj *lbl_1_bss_6D7C0__fzgx_offset_4;
LightSlot *lbl_1_bss_6D7C0__fzgx_offset_8;
LightRequest *lbl_1_bss_6D7C0__fzgx_offset_C;
u16 lbl_1_bss_6D7C0__fzgx_offset_10[8]; /* pool index bound to each channel */
s32 lbl_1_bss_6D7C0__fzgx_offset_20;    /* current frame */

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D7A8;
    s = *(u8 *)&lbl_1_bss_6D7A8__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_6D7A8__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_6D7A8__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_6D7A8__fzgx_offset_C;
    s = *(u8 *)&lbl_1_bss_6D7A8__fzgx_offset_10;
    s = *(u8 *)&lbl_1_bss_6D7A8__fzgx_offset_14;
    s = *(u8 *)&lbl_1_bss_6D7A8__fzgx_offset_16;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D7C0;
    s = *(u8 *)&lbl_1_bss_6D7C0__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_6D7C0__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_6D7C0__fzgx_offset_C;
    s = *(u8 *)&lbl_1_bss_6D7C0__fzgx_offset_10;
    s = *(u8 *)&lbl_1_bss_6D7C0__fzgx_offset_20;
}
#pragma section code_type ".text"

#define sPoolMax fzgx_obj_lbl_1_bss_6D7A8
#define sSlotMax lbl_1_bss_6D7A8__fzgx_offset_2
#define sRequestMax lbl_1_bss_6D7A8__fzgx_offset_4
#define sPoolBytes lbl_1_bss_6D7A8__fzgx_offset_8
#define sSlotBytes lbl_1_bss_6D7A8__fzgx_offset_C
#define sRequestBytes lbl_1_bss_6D7A8__fzgx_offset_10
#define sPoolCount lbl_1_bss_6D7A8__fzgx_offset_14
#define sSlotCount lbl_1_bss_6D7A8__fzgx_offset_16
#define sRequestCount fzgx_obj_lbl_1_bss_6D7C0
#define sPool lbl_1_bss_6D7C0__fzgx_offset_4
#define sSlots lbl_1_bss_6D7C0__fzgx_offset_8
#define sRequests lbl_1_bss_6D7C0__fzgx_offset_C
#define sChanObj lbl_1_bss_6D7C0__fzgx_offset_10
#define sFrame lbl_1_bss_6D7C0__fzgx_offset_20

// The objects above as one block. Two functions keep its address in a local, which
// retail's register order needs.
typedef struct {
    u16 pool_max;
    u16 slot_max;
    u16 request_max;
    s32 pool_bytes;
    s32 slot_bytes;
    s32 request_bytes;
    u16 pool_count;
    u16 slot_count;
    u16 request_count;
    LightObj *pool;
    LightSlot *slots;
    LightRequest *requests;
    u16 chan_obj[8];
    s32 frame;
} LightWork;

static inline u16 *light_chan_ids(LightWork *w) { return w->chan_obj; }

static inline int light_top_chan(u8 *pool, int mask) {
    int bit = 0x1F - __cntlzw(mask);
    if (bit > 7 || bit < 0)
        OSPanic((char *)(pool + 0x8EC), 0x30, (char *)(pool + 0x904));
    return bit;
}

/* fzgx:begin fn_1_7BA08 */
// Sets the capacities and returns the bytes the three arrays need.
int fn_1_7BA08(u16 pool, u16 slots, u16 requests) {
    sSlotMax = slots;
    sRequestMax = requests;
    sPoolMax = pool;
    sPoolBytes = pool << 6;
    sSlotBytes = slots * 12;
    sRequestBytes = requests * 20;
    return sPoolBytes + sSlotBytes + sRequestBytes;
}
/* fzgx:end fn_1_7BA08 */

/* fzgx:begin fn_1_7BA48 */
// Carves the arrays out of `buf` and clears everything.
void fn_1_7BA48(u8 *buf) {
    int i;

    fn_800793D4(buf, 0, sPoolBytes + sSlotBytes + sRequestBytes);
    sRequestCount = 0;
    sSlotCount = 0;
    sPoolCount = 0;
    sPool = (LightObj *)buf;
    sSlots = (LightSlot *)(buf + sPoolBytes);
    sRequests = (LightRequest *)((u8 *)sSlots + sSlotBytes);
    for (i = 0; i < 8; i++) {
        sChanObj[i] = 0xFFFF;
    }
    sFrame = 0;
}
/* fzgx:end fn_1_7BA48 */

/* fzgx:begin fn_1_7BAF8 */
// Clears the arrays already carved from `buf`.
void fn_1_7BAF8(u8 *buf) {
    int i;

    fn_800793D4(buf, 0, sPoolBytes + sSlotBytes + sRequestBytes);
    sRequestCount = 0;
    sSlotCount = 0;
    sPoolCount = 0;
    for (i = 0; i < 8; i++) {
        sChanObj[i] = 0xFFFF;
    }
    sFrame = 0;
}
/* fzgx:end fn_1_7BAF8 */

/* fzgx:begin fn_1_7BB80 */
// Adds a light object to the pool and binds it to the highest channel in `mask`.
#pragma opt_propagation off
void fn_1_7BB80(LightObj *src, int mask) {
    u8 *pool = lbl_1_data_1E558;
    LightWork *w = (LightWork *)&sPoolMax;
    u16 *ids;
    int bit;

    if (w->pool_count >= w->pool_max)
        OSPanic((char *)(lbl_1_data_1E558 + 0x8EC), 0x79, (char *)(pool + 0x8F4));
    w->pool[w->pool_count] = *src;
    bit = light_top_chan(pool, mask);
    {
        int off = bit * 2;
        u16 c = w->pool_count;
        ids = w->chan_obj;
        *(u16 *)((u8 *)ids + off) = c;
    }
    fn_800356B8(src, mask);
    w->pool_count++;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_7BB80 */

/* fzgx:begin fn_1_7BCCC */
// Appends a slot and makes it current.
void fn_1_7BCCC(LightSlot *src) {
    if (sSlotCount >= sSlotMax)
        OSPanic(lbl_1_data_1EE44, 143, lbl_1_data_1EE70);
    sSlots[sSlotCount] = *src;
    fn_80074D28(src);
    sSlotCount++;
}
/* fzgx:end fn_1_7BCCC */

/* fzgx:begin fn_1_7BD6C */
// Stages a request for the current slot and the channels in `mask`.
int fn_1_7BD6C(int mask) {
    u8 *pool = lbl_1_data_1E558;
    LightWork *w = (LightWork *)&sPoolMax;
    u16 *ids;
    int i;
    LightRequest *req;
    int result;

    if (w->request_count >= w->request_max)
        OSPanic((char *)(pool + 0x8EC), 0xA5, (char *)(pool + 0x92C));
    req = &w->requests[w->request_count];
    req->frame = mask;
    req->slot = w->slot_count - 1;
    w->frame = mask;
    result = fn_80074D08(mask);
    i = light_top_chan(pool, mask);
    // re-read after the call: retail reloads the channel table address here
    ids = light_chan_ids(w);
    while (i >= 0) {
        if (ids[i] == 0xFFFF)
            OSPanic((char *)(pool + 0x8EC), 0xB1, (char *)(pool + 0x940));
        req->chan[i] = ids[i];
        mask &= ~(1 << i);
        i = 0x1F - __cntlzw(mask);
    }
    w->request_count++;
    return result;
}
/* fzgx:end fn_1_7BD6C */

/* fzgx:begin fn_1_7BE94 */
// Returns the index of the last staged request.
u16 fn_1_7BE94(void) {
    return sRequestCount - 1;
}
/* fzgx:end fn_1_7BE94 */

/* fzgx:begin fn_1_7BEAC */
// Applies staged request `index`: rebinds changed channels, the slot and the frame.
void fn_1_7BEAC(u16 index) {
    u16 *ids, *hw;
    u32 i;
    LightRequest *req = &sRequests[index];
    int changed = 0;

    // `hw` walks the request as halfwords: hw[2] is chan[i]
    for (i = 0, ids = sChanObj, hw = (u16 *)req; i < 8; i++, ids++, hw++) {
        if (hw[2] != *ids) {
            fn_800356B8(&sPool[hw[2]], 1 << i);
            *ids = hw[2];
            changed = 1;
        }
    }
    if (sSlotCount != req->slot && sSlotCount != 0) {
        fn_80074D28(&sSlots[req->slot]);
        sSlotCount = req->slot;
    }
    if (sFrame != req->frame || changed != 0) {
        fn_80074D08(req->frame);
        sFrame = req->frame;
    }
}
/* fzgx:end fn_1_7BEAC */
