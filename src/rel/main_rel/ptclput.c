#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/ptclput.h"

extern u16 lbl_1_bss_6EA94;
extern struct fn_1_9F870_lbl_801A6410 lbl_801A6410;
extern u32 fn_1_46B4(u32, u32, void *, u32);
extern u32 fn_1_45D0(u32, u32, void *, u32);
extern void fn_80008BA8(void *, const void *, u32);
extern u32 lbl_1_bss_6EA90;
extern u32 lbl_801A6D00;
extern void fn_1_9F164(void *);
extern void fn_1_9F4B4(void *);
extern void fn_800720B0(u32);
extern void fn_8007245C(u32);
extern void fn_800724C8(void);
extern void fn_80072864(u32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_800735C8(s32, s32);
extern void fn_80073620(s32, s32);
extern void fn_80073678(u32);
extern void fn_80073778(u32, s32);
extern void fn_80073C6C(s32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void fn_80074660(u32);
extern void fn_80074788(u32);
extern void fn_80074918(u8, s32, u8);
extern void GXLoadPosMtxImm(u32, u32);
extern void lbl_8006D758(void);
extern void lbl_8006D9D8(void *);
extern void lbl_8006D7B0(void);
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006D848(f32);
extern void lbl_8006DFC4(void *);

/* fzgx:begin fn_1_9F7DC */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/ptclput.h"

struct fn_1_9F7DC_lbl_1_bss_6EA88 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
};
struct fn_1_9F7DC_lbl_801A6410 {
    u32 unk_0;
};

void fn_1_9F7DC(void) {
    struct fn_1_9F7DC_lbl_1_bss_6EA88 *p_lbl_1_bss_6EA88;
    p_lbl_1_bss_6EA88 = (struct fn_1_9F7DC_lbl_1_bss_6EA88 *)&lbl_1_bss_6EA88;

    p_lbl_1_bss_6EA88->unk_0 =
        fn_1_45D0((*(struct fn_1_9F7DC_lbl_801A6410 *)&lbl_801A6410).unk_0, 0x4000, &lbl_1_data_2CD20, 0x4c1);
    p_lbl_1_bss_6EA88->unk_4 =
        fn_1_45D0((*(struct fn_1_9F7DC_lbl_801A6410 *)&lbl_801A6410).unk_0, 0x4000, &lbl_1_data_2CD20, 0x4c2);
    p_lbl_1_bss_6EA88->unk_8 =
        fn_1_45D0((*(struct fn_1_9F7DC_lbl_801A6410 *)&lbl_801A6410).unk_0, 0x1800, &lbl_1_data_2CD20, 0x4c3);
}
/* fzgx:end fn_1_9F7DC */

/* fzgx:begin fn_1_9F870 */
#include "types.h"

struct fn_1_9F870_lbl_1_bss_6EA88 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
};
struct fn_1_9F870_lbl_801A6410 {
    u32 unk_0;
};

void fn_1_9F870(void) {
    struct fn_1_9F870_lbl_1_bss_6EA88 *p_lbl_1_bss_6EA88;
    p_lbl_1_bss_6EA88 = (struct fn_1_9F870_lbl_1_bss_6EA88 *)&lbl_1_bss_6EA88;
    fn_1_46B4(lbl_801A6410.unk_0, p_lbl_1_bss_6EA88->unk_0, &lbl_1_data_2CD20, 1226);
    fn_1_46B4(lbl_801A6410.unk_0, p_lbl_1_bss_6EA88->unk_4, &lbl_1_data_2CD20, 1227);
    fn_1_46B4(lbl_801A6410.unk_0, p_lbl_1_bss_6EA88->unk_8, &lbl_1_data_2CD20, 1228);
}
/* fzgx:end fn_1_9F870 */

/* fzgx:begin fn_1_9F8FC */
void fn_1_9F8FC(void) {
    lbl_1_bss_6EA94 = 0;
    lbl_1_bss_6EA96 = 0;
}
/* fzgx:end fn_1_9F8FC */

/* fzgx:begin fn_1_9F914 */
int fn_1_9F914(const void *src0, const void *src1) {
    Obj_1_bss_6EA88 *obj = &lbl_1_bss_6EA88;

    if (*(u16 *)((u8 *)obj + 0xc) == 0x100) {
        return 0;
    }
    fn_80008BA8((u8 *)obj->unk_0 +
                    ((*(u16 *)((u8 *)obj + 0xc) & 0xffff) << 6),
                src0, 0x40);
    fn_80008BA8((u8 *)obj->unk_4 +
                    (*(u16 *)((u8 *)obj + 0xc) << 6),
                src1, 0x40);
    *(u16 *)((u8 *)obj + 0xc) = *(u16 *)((u8 *)obj + 0xc) + 1;
    return 1;
}
/* fzgx:end fn_1_9F914 */

/* fzgx:begin fn_1_9F9A4 */
struct fn_1_9F9A4_Blk {
    u32 w0;
    u32 w1;
    u32 w2;
    u32 w3;
    u32 w4;
    u32 w5;
};

s32 fn_1_9F9A4(u32 arg0) {
    u16 v0;
    u32 v1;
    u32 v2;

    v0 = lbl_1_bss_6EA96;
    v1 = arg0;
    if (v0 == 256) {
        v1 = 0;
        return v1;
    }
    v2 = (lbl_1_bss_6EA90 + (v0 * 24));
    *(struct fn_1_9F9A4_Blk *)v2 = *(struct fn_1_9F9A4_Blk *)v1;
    lbl_1_bss_6EA96++;
    return 1;
}
/* fzgx:end fn_1_9F9A4 */

/* fzgx:begin fn_1_9FA18 */
#include "types.h"
#include "dolphin/hw_regs.h"
#include "psvec.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/ptclput.h"

struct fn_1_9FA18_State {
    u8 *unk_0;
    u8 *unk_4;
    u8 *unk_8;
    u16 unk_C;
    u16 unk_E;
};
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} fn_1_9FA18_Vec;
typedef struct {
    fn_1_9FA18_Vec pos;
    f32 radius;
    u32 unk_10;
    u32 unk_14;
} fn_1_9FA18_Sphere;
typedef struct {
    u8 pad_0[0x8];
    fn_1_9FA18_Vec pos;
} fn_1_9FA18_Obj;
typedef struct {
    u8 pad_0[0xa0];
    fn_1_9FA18_Obj *obj;
} fn_1_9FA18_Inner;

void fn_1_9FA18(void) {
    struct fn_1_9FA18_State *state;
    s32 i;
    s32 off;
    fn_1_9FA18_Obj *obj;
    fn_1_9FA18_Vec v;
    fn_1_9FA18_Sphere sphere;
    u8 mtx[0x30];
    f32 radius;
    f32 len;

    state = (struct fn_1_9FA18_State *)&lbl_1_bss_6EA88;
    fn_80074788(0);
    fn_80072864(0);
    fn_800745A4(0, 1, 4, 60, 0, 125);
    fn_800734A8(0, 0, 0, 255);
    fn_80072AB0(0, 0, 0);
    fn_800735C8(0, 12);
    fn_80073620(0, 28);
    fn_80073C6C(0);
    fn_80072C24(0, 15, 14, 8, 15);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 6, 4, 7);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_80073678(1);
    fn_80074660(1);
    fn_80074918(1, 3, 0);
    fn_800720B0(0);
    fn_800728A8(1, 1, 1, 0);
    lbl_8006D758();
    GXLoadPosMtxImm(lbl_801A6D00, 0);
    fn_800724C8();
    fn_8007245C(0x2200);
    for (i = 0, off = 0; i < state->unk_C; off += 0x40, i++) {
        fn_80073778(*(u32 *)(state->unk_4 + off + 0x24), 0);
        fn_1_9F164(state->unk_0 + off);
    }
    state->unk_C = 0;
    fn_80074788(0);
    fn_80072864(0);
    fn_800745A4(0, 1, 4, 60, 0, 125);
    fn_800734A8(0, 0, 0, 255);
    fn_80072AB0(0, 0, 0);
    fn_800735C8(0, 12);
    fn_80073620(0, 28);
    fn_80073C6C(0);
    fn_80072C24(0, 15, 15, 15, 14);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 6, 4, 7);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_80073678(1);
    fn_80074660(1);
    fn_80074918(1, 3, 0);
    fn_800720B0(0);
    fn_800728A8(1, 4, 1, 0);
    if (state->unk_E != 0) {
        obj = ((fn_1_9FA18_Inner *)lbl_1_bss_38458->unk_8)->obj;
        fn_80073778(*(u32 *)((u8 *)obj + 0x24), 0);
    }
    for (i = 0, off = 0; i < state->unk_E; off += 0x18, i++) {
        sphere = *(fn_1_9FA18_Sphere *)(state->unk_8 + off);
        radius = sphere.radius;
        lbl_8006D9D8(&sphere);
        lbl_8006D7B0();
        psvec_set(&v, *(const f32 *)(LC_BASE + 0x2C), *(const f32 *)(LC_BASE + 0x1C), *(const f32 *)(LC_BASE + 0xC));
        {
            f32 x = v.x;
            f32 y = v.y;
            f32 z = v.z;
            f32 sum = x * x;

            sum = sum + y * y;
            sum = sum + z * z;
            len = lbl_8006D0B4(sum);
        }
        if (len > 0.1f + radius) {
            lbl_8006DB74(mtx);
            lbl_8006D848((len - radius) / len);
            lbl_8006DFC4(mtx);
        }
        sphere.pos = obj->pos;
        sphere.radius = 0.70710677f * radius;
        fn_1_9F4B4(&sphere);
    }
    state->unk_E = 0;
}
/* fzgx:end fn_1_9FA18 */
