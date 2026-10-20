#include "types.h"

// Car color-change test mode (fze.car_colchg.rel): a small state machine of debug menus that
// pick a machine, step through its color entries and edit their RGB channels on a live preview.

typedef struct {
    u16 held;  // 0x0
    u8 pad_2[0x6];
    volatile u16 hold;  // 0x8  volatile: retail re-reads the pad for every test
    u8 pad_A[0x6];
    volatile u16 trig;  // 0x10 volatile: retail re-reads the pad for every test
    volatile u16 rep;   // 0x12 volatile: retail re-reads the pad for every test
} PadState;

typedef struct {
    u8 pad_0[0x4];
    u8 frame;  // 0x4
} ColchgFrame;

// One machine's color entries in lbl_1_data_1FB6C: a list ended by id -1.
typedef struct {
    s16 id;
    s16 pad_2;
    s32 unk_4;
    u32 color;  // 0xRRGGBBAA
} ColorEntry;  // 0xC

typedef struct {
    s16 car;      // 0x0
    s16 color_id; // 0x2
    s16 entry;    // 0x4
    s16 channel;  // 0x6
    u8 pad_8[0x4];
    s16 unk_C;    // 0xC
} ColchgSel;  // 0x10

typedef struct {
    u8 pad_0[0x324];
    s32 unk_324;
    u8 pad_328[0x90];
    s16 unk_3B8;
    u8 pad_3BA[0x86];
} ColchgCar;  // 0x440

typedef struct {
    char name[0x20];
    void (*init)(void);
    void (*update)(void);
    void (*exit)(void);
} ColchgModeEntry;  // 0x2C

typedef struct {
    u8 pad_0[0x8];
    f32 value_8;
    f32 value_c;
    u8 pad_10[0x48];
} ColchgView;  // 0x58

typedef struct {
    u8 _[0x64];
} ColchgPreview;

typedef struct {
    s16 id;
    u16 unk_2;
    u32 enabled;
    u8 pad_8[0x18];
} ColchgCarInfo;  // 0x20

extern PadState lbl_1_bss_D58;
extern ColchgFrame lbl_1_bss_970;
extern s16 lbl_1_bss_962;
extern u16 lbl_1_bss_968;
extern u16 lbl_1_bss_96A;
extern u32 lbl_1_bss_7167C;
extern u32 lbl_1_bss_71680;
extern u32 lbl_1_bss_71684;
extern u32 lbl_1_bss_71688;
extern u32 lbl_1_bss_7168C;
extern ColorEntry *lbl_1_data_1FB6C[];
extern const ColchgView lbl_1_rodata_26F8;
extern u32 lbl_801A6410;
extern u32 lbl_801A66A0;

extern u32 fn_1_4630(u32, u32, const char *, u32);
extern u32 fn_1_45D0(u32, u32, const char *, u32);
extern void fn_1_46B4(u32, u32, const char *, u32);
extern u32 fn_1_7BA08(u32, u32, u32);
extern void fn_1_7BA48(u32);
extern void fn_1_7BAF8(void);
extern void fn_1_7BB80(void *, s32);
extern void fn_1_7BCCC(void *);
extern void fn_1_7BD6C(s32);
extern void fn_1_3CC4(void);
extern void fn_1_3CF0(u32, u32);
extern u16 fn_1_3F8C(const char *, void *, u32, u32);
extern void fn_1_407C(void);
extern void fn_1_41A8(void);
extern void fn_1_426C(s16);
extern u32 fn_1_435C(u32);
extern void fn_1_4A00(s32, s32, u32);
extern s32 fn_1_4C10(void);
extern void fn_1_5124(u32, u32);
extern void fn_1_6400(void);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern f32 fn_1_4B040(const char *);
extern void fn_1_4B83C(char *, const char *, char *, char *);
extern s32 fn_1_7F49C(s16, s16, char *);
extern void fn_1_7FA04(u32);
extern void fn_1_80058(s8, ColchgCarInfo *);
extern void fn_1_80C18(u32, ColchgCarInfo *, s32);
extern void fn_1_870BC(ColchgCar *, s8, ColchgCar *, s32, u8, f32);
extern void fn_1_8CED0(void *, u32, u32);
extern void fn_1_8D0A4(void *);
extern void fn_1_8D168(void *);
extern void fn_1_8D3F8(void *, ColchgView *, void *, void *);
extern void fn_1_A8DD4(const char *, ...);
extern void fn_1_A8EB0(s32, s32);
extern void fn_8006CE1C(f32);
extern void lbl_8006D7F4(f32, f32, f32);
extern void lbl_8006DCA4(void);
extern void lbl_8006E14C(f32);
extern void lbl_8006E1D8(void *, f32, f32, f32);
extern void fn_80072558(void);
extern void fn_80074CF4(f32, f32, f32);
extern void fn_80035420(void *, f32, s32);
extern void fn_80035680(void *, f32, f32, f32);
extern void fn_80035690(void *, f32, f32, f32);
extern void fn_800356AC(void *, void *);
extern void fn_80083DB0(char *, char *);
extern void GXInitLightDistAttn(void *, s32, f32, f32);
extern void mathutil_mtxA_rotate_x(s32);
extern void mathutil_mtxA_rotate_y(s32);
extern s32 sprintf(char *, const char *, ...);
extern s32 strlen(const char *);
extern void fn_1_12B4(void);
extern void fn_1_12FC(void);
extern void fn_1_1300(void);

void fn_9_298(void);
void fn_9_2E0(void);
void colchg_menu_init(void);
void fn_9_454(void);
void fn_9_534(void);
void colchg_selcar_init(void);
void fn_9_5D8(void);
void fn_9_6F0(void);
void colchg_selmate_init(void);
void fn_9_7DC(void);
void fn_9_A18(void);
void colchg_chgcol_init(void);
void fn_9_AF0(void);
void fn_9_DC0(void);
void colchg_ezsel_init(void);
void fn_9_E4C(void);
void fn_9_F38(void);
void colchg_save_init(void);
void fn_9_FD0(void);
void fn_9_1018(void);
void fn_9_1054(void);
void fn_9_10BC(void);
void fn_9_1124(void);
void colchg_menu_disp(void);
s32 fn_9_120C(ColchgCar *car);
s32 fn_9_1310(ColchgCar *car);
void colchg_selcar_disp(ColchgCar *cars);
void colchg_selmate_disp(ColchgCar *cars);
void colchg_chgcol_disp(ColchgCar *cars);
void colchg_ezsel_disp(void);
void colchg_save_disp(void);
void fn_9_1AC4(void);
void fn_9_1AFC(void);
void fn_9_1BCC(void);
void fn_9_1C54(void);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
s16 fzgx_obj_lbl_9_data_0 = 5;

u32 fzgx_obj_lbl_9_bss_0;            /* heap */
ColchgCar *fzgx_obj_lbl_9_bss_4;     /* machines */
ColchgSel *fzgx_obj_lbl_9_bss_8;     /* selection */
u32 fzgx_obj_lbl_9_bss_C;            /* menu heap */
u32 fzgx_obj_lbl_9_bss_10;           /* preview heap */
ColchgPreview fzgx_obj_lbl_9_bss_14[2];   /* preview views */
s16 fzgx_obj_lbl_9_bss_DC;           /* current task */
u32 fzgx_obj_lbl_9_bss_E0[2];        /* color saved while editing */

#define sHeap fzgx_obj_lbl_9_bss_0
#define sCars fzgx_obj_lbl_9_bss_4
#define sSel fzgx_obj_lbl_9_bss_8
#define sMenuHeap fzgx_obj_lbl_9_bss_C
#define sPreviewHeap fzgx_obj_lbl_9_bss_10
#define sViews fzgx_obj_lbl_9_bss_14
#define sTask fzgx_obj_lbl_9_bss_DC
#define sSavedColor fzgx_obj_lbl_9_bss_E0[0]

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_9_bss_0;
    s = *(u8 *)&fzgx_obj_lbl_9_bss_4;
    s = *(u8 *)&fzgx_obj_lbl_9_bss_8;
    s = *(u8 *)&fzgx_obj_lbl_9_bss_C;
    s = *(u8 *)&fzgx_obj_lbl_9_bss_10;
    s = *(u8 *)&fzgx_obj_lbl_9_bss_14;
    s = *(u8 *)&fzgx_obj_lbl_9_bss_DC;
    s = *(u8 *)&fzgx_obj_lbl_9_bss_E0;
}
#pragma section code_type ".text"

void _prolog(void) {
    s16 i;

    sSel = (ColchgSel *)fn_1_4630(lbl_801A6410, 0x10, "car_colchg.c", 0x93);
    sCars = (ColchgCar *)fn_1_4630(lbl_801A6410, 0xAE40, "car_colchg.c", 0x94);
    for (i = 0; i < 0x29; i++) {
        sCars[i].unk_324 = -1;
    }
    sHeap = fn_1_45D0(lbl_801A6410, fn_1_7BA08(0x20, 0x20, 0x40), "car_colchg.c", 0x96);
    fn_1_7BA48(sHeap);
    sMenuHeap = fn_1_45D0(lbl_801A6410, 0x173C, "car_colchg.c", 0x97);
    fn_1_3CF0(sMenuHeap, 0x80);
    sPreviewHeap = fn_1_45D0(lbl_801A6410, 0x173C, "car_colchg.c", 0x98);
    fn_1_3CF0(sPreviewHeap, 0x80);
    fn_1_5124(sMenuHeap, sPreviewHeap);
    *(u32 *)&lbl_1_bss_970 = 0;
    lbl_1_bss_970.frame = 0x72;
    lbl_1_bss_96A = 0x72;
    fn_8006CE1C(0.0f);
    fn_80074CF4(0.25f, 0.25f, 0.25f);
    fn_1_435C(sPreviewHeap);
    fn_1_3F8C("LightMain", fn_1_7BAF8, sHeap, 2);
    fn_1_3F8C("light_calc", fn_9_1AFC, 0, 3);
    for (i = 0; i < 2; i++) {
        fn_1_8CED0(&sViews[i], 0x200, 0x200);
        fn_1_8D0A4(&sViews[i]);
    }
    lbl_1_bss_7167C = (u32)fn_9_298;
    lbl_1_bss_71680 = (u32)fn_9_2E0;
    lbl_1_bss_71684 = (u32)fn_9_1C54;
}

void fn_9_298(void) {
    if (fn_1_4C10() == 0) {
        if ((lbl_1_bss_D58.hold >> 12) & 1) {
            lbl_1_bss_96A = 0x75;
        }
    }
}

void fn_9_2E0(void) {
    fn_1_435C(sMenuHeap);
    fn_1_407C();
    fn_1_3CC4();
    fn_1_435C(sPreviewHeap);
    fn_1_407C();
}

/* Tear down the color-change state and release its two preview views. */
void _epilog(void) {
    s16 i;

    fn_1_7FA04((u32)sCars);
    for (i = 0; i < 2; i++) {
        fn_1_8D168(&sViews[i]);
    }
    fn_1_435C(sMenuHeap);
    fn_1_41A8();
    fn_1_435C(sPreviewHeap);
    fn_1_41A8();
    fn_1_46B4(lbl_801A6410, sHeap, "car_colchg.c", 0xDA);
    fn_1_6400();
    fn_1_46B4(lbl_801A6410, (u32)sSel, "car_colchg.c", 0xDC);
}

void colchg_menu_init(void) {
    fn_1_435C(sPreviewHeap);
    sTask = fn_1_3F8C("colchg_menu_disp", colchg_menu_disp, 0, 8);
    fn_1_4A00(1, 15, sPreviewHeap);
}

void fn_9_454(void) {
    s32 value;
    s8 delta;

    if (fn_1_4C10() == 0) {
        delta = 0;
        if (((lbl_1_bss_D58.trig >> 3) & 1) || ((lbl_1_bss_D58.rep >> 3) & 1)) {
            delta = -1;
        }
        if (((lbl_1_bss_D58.trig >> 2) & 1) || ((lbl_1_bss_D58.rep >> 2) & 1)) {
            delta++;
        }
        value = lbl_1_bss_970.frame + delta;
        value = lbl_1_bss_970.frame = value > 0x73 ? 0x73 : value < 0x73 ? 0x73 : value;
        if ((lbl_1_bss_D58.hold >> 8) & 1) {
            lbl_1_bss_96A = value;
        }
        if ((lbl_1_bss_D58.hold >> 9) & 1) {
            lbl_1_bss_96A = 0x75;
        }
    }
}

void fn_9_534(void) {
    fn_1_435C(sPreviewHeap);
    fn_1_426C(sTask);
}

void colchg_selcar_init(void) {
    fn_9_1BCC();
    fn_1_435C(sPreviewHeap);
    sTask = fn_1_3F8C("colchg_selcar_disp", colchg_selcar_disp, (u32)sCars, 8);
    fn_1_4A00(1, 15, sPreviewHeap);
}

void fn_9_5D8(void) {
    ColorEntry *entries;
    s32 value;
    s8 delta;

    if (fn_1_4C10() == 0) {
        if ((lbl_1_bss_D58.hold >> 9) & 1) {
            lbl_1_bss_96A = 0x72;
        }
        delta = 0;
        if ((lbl_1_bss_D58.trig & 1) || (lbl_1_bss_D58.rep & 1)) {
            delta = -1;
        }
        if (((lbl_1_bss_D58.trig >> 1) & 1) || ((lbl_1_bss_D58.rep >> 1) & 1)) {
            delta++;
        }
        if (delta != 0) {
            value = sSel->car + delta;
            sSel->car = value > 40 ? 0 : value < 0 ? 40 : value;
        }
        entries = lbl_1_data_1FB6C[sSel->car];
        if (((lbl_1_bss_D58.hold >> 8) & 1) && entries->id != -1) {
            lbl_1_bss_96A = 0x76;
        }
    }
}

void fn_9_6F0(void) {
    fn_1_435C(sPreviewHeap);
    fn_1_426C(sTask);
}

void colchg_selmate_init(void) {
    ColorEntry *entries = lbl_1_data_1FB6C[sSel->car];

    fn_1_435C(sPreviewHeap);
    sTask = fn_1_3F8C("colchg_selmate_disp", colchg_selmate_disp, (u32)sCars, 8);
    fn_1_4A00(1, 15, sPreviewHeap);
    sSel->color_id = entries[sSel->entry].id;
    sSavedColor = entries[sSel->entry].color;
}

void fn_9_7DC(void) {
    ColorEntry *entries;
    s8 delta;
    s16 count;
    s32 index;

    entries = lbl_1_data_1FB6C[sSel->car];
    if (fn_1_4C10() == 0) {
        if ((lbl_1_bss_D58.hold >> 8) & 1) {
            lbl_1_bss_96A = 0x77;
        }
        if ((lbl_1_bss_D58.hold >> 9) & 1) {
            lbl_1_bss_96A = 0x73;
        }
        delta = 0;
        if ((lbl_1_bss_D58.trig & 1) || (lbl_1_bss_D58.rep & 1)) {
            delta = -1;
        }
        if (((lbl_1_bss_D58.trig >> 1) & 1) || ((lbl_1_bss_D58.rep >> 1) & 1)) {
            delta++;
        }
        if (delta != 0) {
            count = 0;
            while (lbl_1_data_1FB6C[sSel->car][count].id != -1) {
                count++;
            }
            entries[sSel->entry].color = sSavedColor;
            index = sSel->entry + delta;
            if (index > count - 1) {
                index = 0;
            } else if (index < 0) {
                index = count - 1;
            }
            sSel->entry = index;
            if (entries[sSel->entry].id == -1) {
                index = sSel->entry - delta;
                if (index > count - 1) {
                    index = 0;
                } else if (index < 0) {
                    index = count - 1;
                }
                sSel->entry = index;
            }
            sSel->color_id = entries[sSel->entry].id;
            sSavedColor = entries[sSel->entry].color;
        }
        if (lbl_801A66A0 & 1) {
            entries[sSel->entry].color = 0;
        } else {
            entries[sSel->entry].color = -1;
        }
    }
}

void fn_9_A18(void) {
    ColorEntry *entries = lbl_1_data_1FB6C[sSel->car];

    fn_1_435C(sPreviewHeap);
    fn_1_426C(sTask);
    entries[sSel->entry].color = sSavedColor;
}

void colchg_chgcol_init(void) {
    fn_1_435C(sPreviewHeap);
    sTask = fn_1_3F8C("colchg_chgcol_disp", colchg_chgcol_disp, (u32)sCars, 8);
    fn_1_4A00(1, 15, sPreviewHeap);
}

void fn_9_AF0(void) {
    s16 rgb[3];
    s16 *chan;
    ColorEntry *entries;
    u32 color;
    s8 delta;
    s8 step;
    s8 i;
    s32 value;
    u8 shift;

    if (fn_1_4C10() == 0) {
        if ((lbl_1_bss_D58.hold >> 9) & 1) {
            lbl_1_bss_96A = 0x76;
        }
        delta = 0;
        step = 0;
        entries = lbl_1_data_1FB6C[sSel->car];
        if (((lbl_1_bss_D58.trig >> 3) & 1) || ((lbl_1_bss_D58.rep >> 3) & 1)) {
            delta = -1;
        }
        if (((lbl_1_bss_D58.trig >> 2) & 1) || ((lbl_1_bss_D58.rep >> 2) & 1)) {
            delta++;
        }
        if (delta != 0) {
            value = (*(ColchgSel **)&sSel)->channel + delta;
            (*(ColchgSel **)&sSel)->channel = value > 2 ? 0 : value < 0 ? 2 : value;
        }
        color = entries[sSel->entry].color;
        chan = rgb;
        rgb[0] = color >> 24;
        rgb[1] = (color >> 16) & 0xFF;
        rgb[2] = (color >> 8) & 0xFF;
        if ((lbl_1_bss_D58.trig & 1) || (lbl_1_bss_D58.rep & 1)) {
            step = -1;
        }
        if (((lbl_1_bss_D58.trig >> 1) & 1) || ((lbl_1_bss_D58.rep >> 1) & 1)) {
            step++;
        }
        if (step != 0) {
            value = rgb[(*(ColchgSel **)&sSel)->channel] + step;
            rgb[(*(ColchgSel **)&sSel)->channel] = value > 255 ? 0 : value < 0 ? 255 : value;
        }
        shift = (3 - (*(ColchgSel **)&sSel)->channel) * 8;
        entries[(*(ColchgSel **)&sSel)->entry].color &= ~(0xFF << shift);
        entries[sSel->entry].color |= rgb[sSel->channel] << shift;
        {
            char *names[3] = {"R", "G", "B"};

            fn_1_A8EB0(2, 0x14);
            for (i = 0; i < 3; chan++, i++) {
                fn_1_A8DD4("%s%s:%d\n", i == sSel->channel ? ">" : " ", names[i], *chan);
            }
        }
    }
}

void fn_9_DC0(void) {
    fn_1_435C(sPreviewHeap);
    fn_1_426C(sTask);
}

void colchg_ezsel_init(void) {
    fn_1_435C(sPreviewHeap);
    sTask = fn_1_3F8C("colchg_ezsel_disp", colchg_ezsel_disp, 0, 8);
}

void fn_9_E4C(void) {
    s32 value;
    s8 delta;

    if (fn_1_4C10() == 0) {
        if ((lbl_1_bss_D58.hold >> 9) & 1) {
            lbl_1_bss_96A = 0x72;
        }
        delta = 0;
        if ((lbl_1_bss_D58.trig & 1) || (lbl_1_bss_D58.rep & 1)) {
            delta = -1;
        }
        if (((lbl_1_bss_D58.trig >> 1) & 1) || ((lbl_1_bss_D58.rep >> 1) & 1)) {
            delta++;
        }
        if (delta != 0) {
            value = sSel->car + delta;
            sSel->car = value > 40 ? 0 : value < 0 ? 40 : value;
        }
        if ((lbl_1_bss_D58.hold >> 8) & 1) {
            lbl_1_bss_96A = 0x76;
        }
    }
}

void fn_9_F38(void) {
    fn_1_435C(sPreviewHeap);
    fn_1_426C(sTask);
}

void colchg_save_init(void) {
    fn_1_435C(sPreviewHeap);
    sTask = fn_1_3F8C("colchg_save_disp", colchg_save_disp, 0, 8);
    lbl_1_bss_968 = 10;
}

void fn_9_FD0(void) {
    if (fn_1_4C10() == 0) {
        if ((lbl_1_bss_D58.hold >> 9) & 1) {
            lbl_1_bss_968 = 10;
        }
    }
}

void fn_9_1018(void) {
    fn_1_435C(sPreviewHeap);
    fn_1_426C(sTask);
}

void fn_9_1054(void) {
    fn_9_1BCC();
    fn_1_435C(sPreviewHeap);
    sTask = fn_1_3F8C("colchg_load_disp", fn_9_1AC4, 0, 8);
    fn_1_4A00(1, 15, sPreviewHeap);
}

void fn_9_10BC(void) {
    if (fn_1_4C10() == 0) {
        lbl_1_bss_96A = 0x73;
        if ((lbl_1_bss_D58.hold >> 9) & 1) {
            lbl_1_bss_96A = 0x72;
        }
        if ((lbl_1_bss_D58.hold >> 8) & 1) {
            lbl_1_bss_96A = 0x76;
        }
    }
}

void fn_9_1124(void) {
    fn_1_435C(sPreviewHeap);
    fn_1_426C(sTask);
}

void colchg_menu_disp(void) {
    s8 i;

    fn_1_496FC(160.0f, 50.0f);
    fn_1_4AE0C("[ \x83\x81\x83j\x83\x85\x81[ ]\n\n");  // "[ メニュー ]"
    for (i = 0x72; i < 0x79; i++) {
        switch (i) {
        case 0x73:
            // "%sマシンセレクト"
            fn_1_4AE0C("%s\x83}\x83V\x83\x93\x83Z\x83\x8C\x83N\x83g\n", lbl_1_bss_970.frame == i ? "*" : " ");
            break;
        }
    }
}

s32 fn_9_120C(ColchgCar *car) {
    s16 pose = sSel->unk_C;

    lbl_8006D7F4(0.0f, 0.0f, -10.0f);
    mathutil_mtxA_rotate_y(-0x8000);
    mathutil_mtxA_rotate_x(0x10000 - 0x2000);
    mathutil_mtxA_rotate_y((s32)((f32)(lbl_801A66A0 % 360) * 182.04444885253906f));
    lbl_8006E14C(2.0f);
    fn_80072558();
    fn_1_870BC(car, pose, car, 0, car->unk_3B8, 1.0f);
    return 0;
}

s32 fn_9_1310(ColchgCar *car) {
    s16 pose = sSel->unk_C;

    lbl_8006D7F4(0.0f, 0.0f, -10.0f);
    mathutil_mtxA_rotate_y(-0x8000);
    mathutil_mtxA_rotate_x(0x2000);
    mathutil_mtxA_rotate_y((s32)((f32)(lbl_801A66A0 % 360) * 182.04444885253906f));
    lbl_8006E14C(2.0f);
    fn_80072558();
    fn_1_870BC(car, pose, car, 0, car->unk_3B8, 1.0f);
    return 0;
}

void colchg_selcar_disp(ColchgCar *cars) {
    ColchgView view;
    char format[0x20];
    char widest[0x20];
    char line[0x20];
    char name[0x20];
    s32 len;
    f32 half;
    s16 i;
    ColorEntry *entries;
    f32 width;
    s16 j;
    s32 maxlen;
    ColchgCar *car;
    s16 index;
    f32 color;

    index = sSel->car;
    entries = lbl_1_data_1FB6C[index];
    fn_1_496FC(160.0f, 50.0f);
    fn_1_4AE0C("[ \x83}\x83V\x83\x93\x83Z\x83\x8C\x83N\x83g ]\n\n");  // "[ マシンセレクト ]"
    maxlen = 0;
    fn_1_7F49C(sSel->car, fzgx_obj_lbl_9_data_0, name);
    for (i = 0; i < 0x29; i++) {
        len = strlen(name);
        if (len > maxlen) {
            maxlen = len;
            fn_80083DB0(widest, name);
        }
    }
    fn_1_4B83C(format, "%%-%ds", widest, name);
    sprintf(line, format, name);
    fn_1_4955C(250.0f / fn_1_4B040(line), 1.0f);
    fn_1_4AE0C(line);
    fn_1_4955C(1.0f, 1.0f);
    fn_1_4955C(1.0f, 1.0f);
    fn_1_4AE0C("(%2d)\n", sSel->car);
    if (((lbl_1_bss_D58.held >> 8) & 1) && entries->id == -1) {
        // "このくるまはカラーチェンジできません" (this machine cannot change color)
        fn_1_4AE0C("\x82\xB1\x82\xCC\x82\xAD\x82\xE9\x82\xDC\x82\xCD\x83J\x83\x89\x81[\x83`\x83" "F\x83\x93\x83W\x82\xC5\x82\xAB\x82\xDC\x82\xB9\x82\xF1\n");
    }
    color = 255.0f;
    half = 0.5f;
    width = 480.0f;
    car = &cars[index];
    for (j = 0; j < 2; j++) {
        view = lbl_1_rodata_26F8;
        view.value_c = color;
        view.value_8 = width * (j % 2) * half;
        switch (j) {
        case 0:
            fn_1_8D3F8(&sViews[j], &view, fn_9_120C, car);
            break;
        case 1:
            fn_1_8D3F8(&sViews[j], &view, fn_9_1310, car);
            break;
        }
    }
}

static inline s16 colchg_count(ColorEntry *entry) {
    s16 count = 0;

    while (entry->id != -1) {
        entry++;
        count++;
    }
    return count;
}

void colchg_selmate_disp(ColchgCar *cars) {
    ColchgView view;
    ColorEntry *entry;
    ColchgCar *car;
    s16 count;
    s16 i;
    f32 color;
    f32 half;
    f32 width;
    s16 index;

    index = sSel->car;
    fn_1_496FC(160.0f, 50.0f);
    count = colchg_count(lbl_1_data_1FB6C[sSel->car]);
    // "[ マテリアルセレクト ]"
    fn_1_4AE0C("[ \x83}\x83" "e\x83\x8A\x83" "A\x83\x8B\x83Z\x83\x8C\x83N\x83g ]\n\n%2d(ID%d/%d))\n", sSel->color_id, sSel->entry, count - 1);
    color = 255.0f;
    half = 0.5f;
    width = 480.0f;
    car = &cars[index];
    for (i = 0; i < 2; i++) {
        view = lbl_1_rodata_26F8;
        view.value_c = color;
        view.value_8 = width * (i % 2) * half;
        switch (i) {
        case 0:
            fn_1_8D3F8(&sViews[i], &view, fn_9_120C, car);
            break;
        case 1:
            fn_1_8D3F8(&sViews[i], &view, fn_9_1310, car);
            break;
        }
    }
}

void colchg_chgcol_disp(ColchgCar *cars) {
    ColchgView view;
    ColchgCar *car;
    s16 i;
    f32 color;
    f32 half;
    f32 width;
    s16 index;

    index = sSel->car;
    fn_1_496FC(160.0f, 50.0f);
    fn_1_4AE0C("[ \x83J\x83\x89\x81[\x83`\x83" "F\x83\x93\x83W ]\n");  // "[ カラーチェンジ ]"
    color = 255.0f;
    half = 0.5f;
    width = 480.0f;
    car = &cars[index];
    for (i = 0; i < 2; i++) {
        view = lbl_1_rodata_26F8;
        view.value_c = color;
        view.value_8 = width * (i % 2) * half;
        switch (i) {
        case 0:
            fn_1_8D3F8(&sViews[i], &view, fn_9_120C, car);
            break;
        case 1:
            fn_1_8D3F8(&sViews[i], &view, fn_9_1310, car);
            break;
        }
    }
}

void colchg_ezsel_disp(void) {
    char name[0x20];
    s32 count;

    fn_1_A8EB0(0x14, 0x14);
    count = fn_1_7F49C(sSel->car, 0, name);
    fn_1_A8DD4("%2d/%2d [%-16s]", sSel->car, 0x29, count);
}

void colchg_save_disp(void) {
    fn_1_A8EB0(0x14, 0x14);
    fn_1_A8DD4("Save?\n");
}

void fn_9_1AC4(void) {
    fn_1_A8EB0(0x14, 0xA);
    fn_1_A8DD4("Select Load Data\n");
}

typedef struct {
    u8 r, g, b, a;
} GXColor;

typedef struct {
    f32 x, y, z;
} Vec;

typedef struct {
    u8 _[0x40];
} GXLightObj;

void fn_9_1AFC(void) {
    Vec pos;
    GXLightObj light;

    lbl_8006DCA4();
    lbl_8006E1D8(&pos, 200.0f, 200.0f, 200.0f);
    fn_1_7BCCC(&pos);
    fn_80035680(&light, pos.x, pos.y, pos.z);
    fn_80035690(&light, pos.x, pos.y, pos.z);
    fn_80035420(&light, 0.0f, 0);
    {
        GXColor white = {0xFF, 0xFF, 0xFF, 0xFF};

        fn_800356AC(&light, &white);
    }
    GXInitLightDistAttn(&light, 0, 0.0f, 0.0f);
    fn_1_7BB80(&light, 1);
    fn_1_7BD6C(1);
    fn_80074CF4(0.6f, 0.6f, 0.6f);
}

void fn_9_1BCC(void) {
    ColchgCarInfo info[0x29];
    s8 i;

    for (i = 0; i < 0x29; i++) {
        fn_1_80058(i, &info[i]);
        info[i].enabled = 1;
        info[i].id = i;
    }
    fn_1_80C18((u32)sCars, info, 0x29);
}

// One entry per color-change mode, indexed by the mode id (0x71 + n).
ColchgModeEntry fzgx_obj_lbl_9_data_1B8[9] = {
    {"SMD_CARCOLCHG_TOP", fn_1_12B4, fn_1_12FC, fn_1_1300},
    {"SMD_CARCOLCHG_MENU", colchg_menu_init, fn_9_454, fn_9_534},
    {"SMD_CARCOLCHG_SELCAR", colchg_selcar_init, fn_9_5D8, fn_9_6F0},
    {"SMD_CARCOLCHG_LOAD", fn_9_1054, fn_9_10BC, fn_9_1124},
    {"SMD_CARCOLCHG_SAVE", colchg_save_init, fn_9_FD0, fn_9_1018},
    {"SMD_CARCOLCHG_SELTEX", colchg_selmate_init, fn_9_7DC, fn_9_A18},
    {"SMD_CARCOLCHG_CHGCOL", colchg_chgcol_init, fn_9_AF0, fn_9_DC0},
    {"SMD_CARCOLCHG_EZSEL", colchg_ezsel_init, fn_9_E4C, fn_9_F38},
    {"SMD_CARCOLCHG_BOTTOM", fn_1_12B4, fn_1_12FC, fn_1_1300},
};

void fn_9_1C54(void) {
    ColchgModeEntry *mode = fzgx_obj_lbl_9_data_1B8;

    mode += lbl_1_bss_962 - 0x71;

    lbl_1_bss_71688 = (u32)mode->update;
    lbl_1_bss_7168C = (u32)mode->exit;
    mode->init();
}
