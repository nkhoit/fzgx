// Amusement Vision ".lz" decompressor: stock Okumura LZSS (4096-byte ring,
// 18-byte maximum match, ring cleared to zero). The header is two little-endian
// words: compressed size (excluding the 8-byte header) and decompressed size.
// Decompresses args->src into args->dst, reports the decompressed size through
// the optional callback, and returns a pointer to that size.
#include "types.h"

typedef struct {
    const u8 *src;
    u8 *dst;
    void (*callback)(u32 size);
} LzDecompressArgs;

#define LZ_RING_SIZE 4096
#define LZ_MAX_MATCH 18

u32 *fn_18_444(LzDecompressArgs *args) {
    int k;
    long clear_count;
    int r;
    const u8 *ip;
    u8 *op;
    unsigned int flags;
    u32 total;
    const u8 *src;
    int i;
    int j;
    int c;
    u32 size;
    const u8 *base;
    void (*callback)(u32);
    u8 *dst;
    u8 ring[LZ_RING_SIZE + LZ_MAX_MATCH - 1];

    src = args->src;
    base = src;
    callback = args->callback;
    dst = args->dst;
    total = (u32)__lwbrx((void *)src, 0) + 8;
    size = (u32)__lwbrx((void *)base, 4);
    if (total == 0 || size == 0) {
        return NULL;
    }
    op = dst;
    // Holding the clear count in a local gives the zero-trip guard retail has.
    clear_count = LZ_RING_SIZE - LZ_MAX_MATCH;
    ip = base + 8;
    for (i = 0; i < clear_count; i++) {
        ring[i] = 0;
    }

    r = LZ_RING_SIZE - LZ_MAX_MATCH;
    flags = 0;
    for (;;) {
        if (((flags >>= 1) & 0x100) == 0) {
            if ((u32)(ip - base) >= total) {
                break;
            }
            c = *ip++;
            flags = c | 0xFF00;
        }
        if (flags & 1) {
            if ((u32)(ip - src) >= total) {
                break;
            }
            c = *ip++;
            *op++ = c;
            ring[r++] = c;
            r &= LZ_RING_SIZE - 1;
        } else {
            if ((u32)(ip - base) >= total) {
                break;
            }
            i = *ip;
            if ((u32)(ip + 1 - base) >= total) {
                break;
            }
            j = *(ip + 1);
            ip += 2;
            i |= (j & 0xF0) << 4;
            j = (j & 0x0F) + 2;
            for (k = 0; k <= j; k++) {
                c = ring[(i + k) & (LZ_RING_SIZE - 1)];
                *op++ = c;
                ring[r++] = c;
                r &= LZ_RING_SIZE - 1;
            }
        }
    }

    if (callback != NULL) {
        callback(size);
    }
    // Retail returns the address of this stack slot; the caller reads it at once.
    return &size;
}
