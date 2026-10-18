#include "types.h"
#include "rel/sel/globals.h"
#include "rel/sel/name_entry.h"


extern u8 lbl_10_bss_55CDC;
extern s16 lbl_1_bss_960;
extern u32 lbl_801A6410;
extern void fn_1_435C(u32 value);
extern void fn_1_426C(u32 value);
extern void fn_1_A8F78(void);
extern void fn_1_48140(int value);
extern void fn_1_412A0(int value);
extern u8 fn_1_B7C00(void);
extern u8 fn_10_26434(void);
extern void fn_10_26554(void);
extern void fn_1_14BD94(void *);
extern void fn_10_26424(void);
extern u16 lbl_1_bss_9F8[5];
extern u8 lbl_1_bss_8B3A0[0x9f];
extern void fn_1_A2D84(void *);
extern void fn_1_14BCBC(void *, u8);
extern u8 lbl_1_bss_8E51D;
extern u8 lbl_1_data_2B0D4[];
extern u8 lbl_1_data_2B144[];
extern s16 fn_1_12EF24(s16, s16);
extern s32 fn_1_F89E4(u8);
extern void fn_1_14A1AC(u8);
extern void fn_1_14BC40(void);
extern void fn_1_1554D0(void);
extern void fn_1_1555B0(u8);
extern void fn_1_47F74(s32);
extern void fn_1_15555C(void);
extern void fn_1_14BD74(void);

/* fzgx:begin fn_10_25BC8 */
typedef struct fn_10_25BC8_NameEntryState {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u8 _pad0c[0x0c];
    u32 unk18;
    u32 unk1c;
} fn_10_25BC8_NameEntryState;

extern void fn_1_46B4(u32 arg0, fn_10_25BC8_NameEntryState *arg1, u8 *arg2, int arg3);

void fn_10_25BC8(void) {
    lbl_10_bss_55CDC = 1;
    fn_1_435C(((fn_10_25BC8_NameEntryState *)lbl_10_bss_55CD8)->unk04);
    fn_1_426C(((fn_10_25BC8_NameEntryState *)lbl_10_bss_55CD8)->unk18);
    fn_1_A8F78();
    fn_1_48140(0x8f);

    if (lbl_1_bss_960 != 1) {
        if (lbl_1_bss_960 != 3) {
            fn_1_412A0(1);
            fn_1_48140(0x9a);
        }
        fn_1_48140(0x9e);
    }

    fn_1_435C(((fn_10_25BC8_NameEntryState *)lbl_10_bss_55CD8)->unk08);
    fn_1_426C(((fn_10_25BC8_NameEntryState *)lbl_10_bss_55CD8)->unk1c);
    fn_1_46B4(lbl_801A6410, (fn_10_25BC8_NameEntryState *)lbl_10_bss_55CD8,
              lbl_10_data_6980, 0x562);
    lbl_10_bss_55CD8 = 0;
}
/* fzgx:end fn_10_25BC8 */

/* fzgx:begin fn_10_25E1C */
#include "types.h"

typedef struct {
    u8 pad[0x8c];
    s16 value;
} fn_10_25E1C_NameEntryState;

typedef struct {
    s16 v[14];
} fn_10_25E1C_SndTable;

extern fn_10_25E1C_SndTable lbl_10_rodata_1D70;
extern u8 lbl_10_bss_55CE0;
extern u8 lbl_10_bss_55CE1;

void fn_10_25E1C(void) {
    fn_10_25E1C_NameEntryState *state = &(*(fn_10_25E1C_NameEntryState *)&lbl_1_bss_8B3A0);
    s32 i;
    s16 result;

    for (i = 0; i < 6; i++) {
        result = fn_1_12EF24(state->value, i);
        if (state->value == 5) {
            if (i == 5) {
                if (fn_1_F89E4(0) == 0) {
                    goto set_neg; // Both failure cases share the same return path.
                }
            }
            if (i != 5) {
                if (fn_1_F89E4((u8)(i + 1)) == 0) {
                    goto set_neg; // Both failure cases share the same return path.
                }
            }
            goto after_neg; // Preserve the shared failure return path.
        set_neg:
            result = -1;
        after_neg: ;
        }
        if (result != -1) {
            break;
        }
    }

    if (result != -1) {
        lbl_10_bss_55CE0 = (u8)result;
    } else {
        lbl_10_bss_55CE0 = (u8)fn_1_12EF24(state->value, 0);
    }

    fn_1_14A1AC(lbl_1_bss_8E51D);
    fn_1_14BC40();
    fn_1_1554D0();
    fn_1_1555B0(lbl_10_bss_55CE0);
    fn_1_47F74(0x91);
    fn_1_47F74(0x97);
    fn_1_47F74(0x99);

    for (i = 0; i < 6; i++) {
        result = fn_1_12EF24(state->value, i);
        if (result != -1) {
            u8 key = lbl_1_data_2B0D4[result];
            fn_10_25E1C_SndTable table = lbl_10_rodata_1D70;
            s16 index = lbl_1_data_2B144[key] - 1;

            if ((((u32)index > 13) ? 0 : (index >= 0)) && table.v[index] != -1) {
                fn_1_47F74(table.v[index]);
            }
        }
    }
    lbl_10_bss_55CE1 = 0;
}
/* fzgx:end fn_10_25E1C */

/* fzgx:begin fn_10_26000 */
u8 fn_10_26000(void) {
    u8 result;
    u16 flags;

    if (fn_1_B7C00()) {
        return 0;
    }

    if (lbl_10_bss_55CE1 != 0) {
        result = fn_10_26434();
        if (result == 1) {
            fn_10_26554();
            fn_1_14BD94(&lbl_10_bss_55CE0);
        }
        if (result != 0) {
            lbl_10_bss_55CE1 = 0;
        }
        return result;
    }

    flags = lbl_1_bss_9F8[4];
    if (((flags >> 11) & 1) != 0) {
        // fzgx-allow: A1 target hardware address
        fn_1_A2D84((void *)0xA9011100); // fzgx-allow: A2 target hardware address
        fn_10_26424();
        lbl_10_bss_55CE1 = 1;
    }
    fn_1_14BCBC(&lbl_10_bss_55CE0, lbl_1_bss_8B3A0[0x9e]);
    return 0;
}
/* fzgx:end fn_10_26000 */

/* fzgx:begin fn_10_260D4 */
#include "types.h"

typedef struct {
    u8 pad[0x8c];
    s16 value;
} fn_10_260D4_NameEntryState;

typedef struct {
    s16 v[14];
} fn_10_260D4_SndTable;

extern fn_10_260D4_SndTable lbl_10_rodata_1D8C;

extern void fn_1_48140(int);

void fn_10_260D4(void) {
    fn_10_260D4_NameEntryState *state = &(*(fn_10_260D4_NameEntryState *)&lbl_1_bss_8B3A0);
    s32 i;

    for (i = 5; i >= 0; i--) {
        s16 result = fn_1_12EF24(state->value, i);
        if (result != -1) {
            u8 key = lbl_1_data_2B0D4[result];
            fn_10_260D4_SndTable table = lbl_10_rodata_1D8C;
            s16 index = lbl_1_data_2B144[key] - 1;

            if ((((u32)index > 13) ? 0 : (index >= 0)) && table.v[index] != -1) {
                fn_1_48140(table.v[index]);
            }
        }
    }
    fn_1_48140(0x99);
    fn_1_48140(0x97);
    fn_1_48140(0x91);
    fn_1_15555C();
    fn_1_14BD74();
}
/* fzgx:end fn_10_260D4 */

/* fzgx:begin fn_10_26424 */
void fn_10_26424(void) {
    lbl_10_bss_55CE2 = 1;
}
/* fzgx:end fn_10_26424 */

/* fzgx:begin fn_10_26434 noprologue */
#include "types.h"

extern u16 lbl_1_bss_9F8[5];

typedef struct SelState {
    u8 pad0[8];
    u16 flags8;
    u8 padA[6];
    u16 flags10;
    u16 flags12;
} SelState;


extern u8 lbl_10_bss_55CE2;
extern void fn_1_A2D84(int arg);

int fn_10_26434(void) {
    if (((*(SelState *)&lbl_1_bss_9F8).flags10 & 1) ||
        ((*(SelState *)&lbl_1_bss_9F8).flags12 & 1)) {
        if (lbl_10_bss_55CE2 == 1) {
            lbl_10_bss_55CE2 = 0;
            fn_1_A2D84(0xA9011300);
        }
    }

    if (((((*(SelState *)&lbl_1_bss_9F8).flags10 >> 1) & 1)) ||
        ((((*(SelState *)&lbl_1_bss_9F8).flags12 >> 1) & 1))) {
        if (lbl_10_bss_55CE2 == 0) {
            lbl_10_bss_55CE2 = 1;
            fn_1_A2D84(0xA9011300);
        }
    }

    if ((((*(SelState *)&lbl_1_bss_9F8).flags8 >> 8) & 1)) {
        fn_1_A2D84(0xA9011100);
        if (lbl_10_bss_55CE2 == 0) {
            return 1;
        }
        if (lbl_10_bss_55CE2 == 1) {
            return 2;
        }
    }

    if ((((*(SelState *)&lbl_1_bss_9F8).flags8 >> 9) & 1)) {
        fn_1_A2D84(0xA9011000);
        return 2;
    }

    return 0;
}
/* fzgx:end fn_10_26434 */

/* fzgx:begin fn_10_266AC noprologue */
#include "types.h"

typedef struct {
    u32 id;
    f32 f04;
    f32 f08;
    f32 f0c;
    u8 _10[0x20];
    s32 mode;
    u8 _34[0x24];
} Cfg;

// volatile: the GX write-gather pipe is a hardware FIFO.
typedef volatile union {
    u8 u8;
    u16 u16;
    u32 u32;
    f32 f32;
} WGPipe;

#define WGPIPE (*(WGPipe *)0xCC008000) /* fzgx-allow: A1,A2 GX write-gather FIFO port */
#define RF32(base, off) (*(f32*)((base) + (off)))
#define RU32(base, off) (*(const u32*)((base) + (off)))

extern u8 lbl_10_bss_55CE1;
extern u8 lbl_10_bss_55CE2;
extern u8 lbl_10_rodata_1D70[];
extern const Cfg lbl_1_rodata_26F8;
extern s32 lbl_10_data_6B2C[];
extern s32 lbl_801A66B4;

extern u8 fn_1_B7C00(void);
extern void fn_1_4FD64(void);
extern void fn_80074918(s32, s32, s32);
extern void fn_80074788(s32);
extern void fn_80074660(s32);
extern void fn_80073678(s32);
extern void fn_80073C6C(s32);
extern void fn_800747D0(s32, s32, s32, s32, s32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_800734A8(s32, s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, s32, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072E20(s32, s32, s32, s32, s32, s32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_80072864(s32);
extern void fn_8007245C(s32);
extern void fn_800371F8(s32, void*);
extern void fn_8003462C(s32, s32, s32);
extern void fn_1_50164(Cfg*, f32, f32, f32, f32);
extern s32 fn_1_4AEC0(s32);
extern void fn_1_4AEB4(f32);
extern void fn_1_49410(void);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_495C8(s32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4966C(f32, f32);
extern void fn_1_4A0D8(s32);
extern void fn_10_261E4(s32, u8);

void fn_10_266AC(void) {
    Cfg cfg;
    s32 gxAttr;
    s32 texture;
    u8* rodata = lbl_10_rodata_1D70;

    if (fn_1_B7C00() || lbl_10_bss_55CE1 != 0) {
        fn_1_4FD64();
        fn_80074918(0, 7, 0);
        fn_80074788(1);
        fn_80074660(0);
        fn_80073678(1);
        fn_80073C6C(0);
        fn_800747D0(4, 0, 0, 0, 0, 2, 2);
        fn_80072AB0(0, 0, 0);
        fn_800734A8(0, 0xff, 0xff, 4);
        fn_80072C24(0, 0xf, 0xf, 0xf, 2);
        fn_80072D64(0, 0, 0, 0, 1, 0);
        fn_80072CC4(0, 7, 7, 7, 1);
        fn_80072E20(0, 0, 0, 0, 1, 0);
        fn_800728A8(1, 4, 5, 0);
        fn_80072864(2);
        fn_8007245C(0x200);

        gxAttr = RU32(rodata, 0xa8);
        fn_800371F8(1, &gxAttr);
        fn_8003462C(0x80, 7, 4);

        WGPIPE.f32 = RF32(rodata, 0x6c);
        WGPIPE.f32 = RF32(rodata, 0x6c);
        WGPIPE.f32 = RF32(rodata, 0x64);
        WGPIPE.f32 = RF32(rodata, 0xac);
        WGPIPE.f32 = RF32(rodata, 0x6c);
        WGPIPE.f32 = RF32(rodata, 0x64);
        WGPIPE.f32 = RF32(rodata, 0xac);
        WGPIPE.f32 = RF32(rodata, 0xb0);
        WGPIPE.f32 = RF32(rodata, 0x64);
        WGPIPE.f32 = RF32(rodata, 0x6c);
        WGPIPE.f32 = RF32(rodata, 0xb0);
        WGPIPE.f32 = RF32(rodata, 0x64);
    }

    if (lbl_10_bss_55CE1 != 0) {
        cfg = lbl_1_rodata_26F8;
        cfg.id = 2;
        cfg.f04 = RF32(rodata, 0x38);
        cfg.f08 = RF32(rodata, 0x3c);
        cfg.f0c = RF32(rodata, 0x40);
        cfg.mode = 0xa;
        fn_1_50164(&cfg, RF32(rodata, 0x44), RF32(rodata, 0x48),
                   RF32(rodata, 0x4c), RF32(rodata, 0x50));

        texture = lbl_10_data_6B2C[lbl_801A66B4];
        fn_1_4AEC0(1);
        fn_1_4AEB4(RF32(rodata, 0x54));
        fn_1_49410();
        fn_1_4955C(RF32(rodata, 0x58), RF32(rodata, 0x58));
        fn_1_4954C(RF32(rodata, 0x5c));
        fn_1_495B0(0x80000000);  // fzgx-allow: A1 flag value, not an address
        fn_1_49590(RF32(rodata, 0x60));
        fn_1_495C8(9);
        fn_1_496FC(RF32(rodata, 0x38), RF32(rodata, 0xb4));
        fn_1_4966C(RF32(rodata, 0x64), RF32(rodata, 0x68));
        fn_1_4A0D8(texture);
        fn_1_4AEC0(0);
        fn_1_4AEB4(RF32(rodata, 0x6c));
        fn_10_261E4(0x118, lbl_10_bss_55CE2);
    }
}
/* fzgx:end fn_10_266AC */
