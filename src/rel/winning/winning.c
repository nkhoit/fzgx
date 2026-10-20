#include "types.h"

/* fzgx:begin _prolog */
struct _prolog_lbl_15_bss_0 {
    u8 pad_0[0xC];
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u8 unk_20;
    u8 unk_21;
    u8 unk_22;
    u8 unk_23;
};
struct _prolog_lbl_801A6410 {
    u32 unk_0;
};
struct _prolog_lbl_1_bss_96A {
    u16 unk_0;
};

extern u32 fn_1_45D0(u32, u32, void *, u32);
extern struct _prolog_lbl_15_bss_0 lbl_15_bss_0;
extern struct _prolog_lbl_1_bss_96A lbl_1_bss_96A;
extern struct _prolog_lbl_801A6410 lbl_801A6410;
extern u32 fn_1_3CF0(void *, u32);
extern u32 fn_1_479F0(u32);
extern u32 fn_1_47F74(u32);
extern u32 fn_1_4A00(u32, u32, void *);
extern u32 lbl_15_data_A4;
extern u32 lbl_1_bss_7167C;
extern u32 lbl_1_bss_71680;
extern u32 lbl_1_bss_71684;
extern void fn_15_1F4(void);
extern void fn_15_260(void);
extern void fn_15_350(void);
extern void fn_1_C2454(void);

void _prolog(void) {
    struct _prolog_lbl_15_bss_0 *p_lbl_15_bss_0;
    u32 v0;
    u32 zero;
    s32 t0;
    s32 t1;
    p_lbl_15_bss_0 = (struct _prolog_lbl_15_bss_0 *)&lbl_15_bss_0;
    t0 = fn_1_45D0(lbl_801A6410.unk_0, 5948, &lbl_15_data_A4, 0x158);
    p_lbl_15_bss_0->unk_C = t0;
    t1 = fn_1_45D0(lbl_801A6410.unk_0, 5948, &lbl_15_data_A4, 0x159);
    p_lbl_15_bss_0->unk_10 = t1;
    fn_1_3CF0((void *)p_lbl_15_bss_0->unk_C, 128);
    fn_1_3CF0((void *)p_lbl_15_bss_0->unk_10, 128);
    fn_1_479F0(14);
    fn_1_47F74(140);
    fn_1_47F74(187);
    p_lbl_15_bss_0->unk_14 = 0;
    p_lbl_15_bss_0->unk_14 = p_lbl_15_bss_0->unk_14 | 0x40000000;
    v0 = p_lbl_15_bss_0->unk_10;
    p_lbl_15_bss_0->unk_18 = 0;
    p_lbl_15_bss_0->unk_1C = 30;
    p_lbl_15_bss_0->unk_20 = 1;
    p_lbl_15_bss_0->unk_21 = 0;
    p_lbl_15_bss_0->unk_22 = 0;
    p_lbl_15_bss_0->unk_23 = 0;
    lbl_1_bss_96A.unk_0 = 183;
    fn_1_4A00(1, 30, (void *)v0);
    fn_1_C2454();
    lbl_1_bss_7167C = (u32)(fn_15_1F4);
    lbl_1_bss_71680 = (u32)(fn_15_260);
    lbl_1_bss_71684 = (u32)(fn_15_350);
}
/* fzgx:end _prolog */

/* fzgx:begin _epilog */
extern f32 lbl_15_rodata_0[25];
extern u32 lbl_15_bss_C;
extern u32 lbl_15_bss_10;
extern u32 lbl_1_bss_6EAB4;
extern u8 lbl_15_data_A4[176];
extern u32 lbl_801A6410;

extern void fn_8006CE1C(f32);
extern void fn_1_435C(u32);
extern void fn_1_41A8(void);
extern void fn_1_47A60(u32);
extern void fn_1_48140(u32);
extern void fn_1_46B4(u32, u32, u8 *, u32);

void _epilog(void) {
    fn_8006CE1C(lbl_15_rodata_0[0]);
    lbl_1_bss_6EAB4 &= (u32)-0x29;
    fn_1_435C(lbl_15_bss_C);
    fn_1_41A8();
    fn_1_435C(lbl_15_bss_10);
    fn_1_41A8();
    fn_1_47A60(0xe);
    fn_1_48140(0x8c);
    fn_1_48140(0xbb);
    fn_1_46B4(lbl_801A6410, lbl_15_bss_C, lbl_15_data_A4, 0x192);
    fn_1_46B4(lbl_801A6410, lbl_15_bss_10, lbl_15_data_A4, 0x193);
}
/* fzgx:end _epilog */

/* fzgx:begin fn_15_1F4 */
extern s32 lbl_15_bss_14;
extern s32 lbl_15_bss_1C;
extern void fn_15_B90(void);

void fn_15_1F4(void) {
    if ((lbl_15_bss_14 & 0x10000000) != 0) {
        if (lbl_15_bss_1C != 0) {
            lbl_15_bss_1C -= 1;
        }
        if (lbl_15_bss_1C == 0) {
            lbl_15_bss_14 &= ~0x10000000;
            fn_15_B90();
        }
    }
}
/* fzgx:end fn_15_1F4 */

/* fzgx:begin fn_15_260 */
extern struct fn_15_260_lbl_15_bss_0 lbl_15_bss_0;
extern u32 fn_1_435C(u32);
extern void fn_1_407C(void);
extern void fn_1_3CC4(void);
extern s32 fn_1_8DB94(void);
extern void fn_1_86254(u32);
extern void fn_1_106EB0(void);
extern s32 camera_get_flags(void);
extern void camera_update(void);
extern u32 fn_1_58C4(void);
extern void fn_1_5948(s32);
extern void fn_1_9A770(void);
extern void fn_1_627C(s32);

struct fn_15_260_lbl_15_bss_0 {
    u8 pad_0[0xC];
    u32 unk_C;
    u32 unk_10;
    u8 pad_14[0xD];
    u8 unk_21;
    u8 pad_22[2];
    u32 unk_24;
    u32 unk_28;
};

void fn_15_260(void) {
    struct fn_15_260_lbl_15_bss_0 *p_lbl_15_bss_0;
    u32 count;
    s32 i;
    s16 index;

    p_lbl_15_bss_0 = (struct fn_15_260_lbl_15_bss_0 *)&lbl_15_bss_0;
    if (p_lbl_15_bss_0->unk_21 != 0) {
        fn_1_435C(p_lbl_15_bss_0->unk_24);
        fn_1_407C();
    }
    fn_1_435C(p_lbl_15_bss_0->unk_C);
    fn_1_407C();
    fn_1_3CC4();
    if (fn_1_8DB94() != 0) {
        fn_1_86254(0);
        fn_1_106EB0();
    }
    if (camera_get_flags() != 0) {
        camera_update();
    }
    count = fn_1_58C4();
    i = 0;
    while ((s16)i < count) {
        index = (s16)i;
        fn_1_5948(index);
        fn_1_9A770();
        if (p_lbl_15_bss_0->unk_21 != 0) {
            fn_1_435C(p_lbl_15_bss_0->unk_28);
            fn_1_407C();
        }
        fn_1_435C(p_lbl_15_bss_0->unk_10);
        fn_1_407C();
        fn_1_627C(index);
        i++;
    }
}
/* fzgx:end fn_15_260 */

/* fzgx:begin fn_15_350 */
typedef void (*fn_15_350_Fn0)(void);
struct fn_15_350_lbl_15_data_70_0_E16 {
    u8 pad_0[0x4];
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
};

extern s16 lbl_1_bss_962;
extern u8 lbl_15_data_70[32];
extern u32 lbl_1_bss_71688;
extern u32 lbl_1_bss_7168C;

void fn_15_350(void) {
    u32 v0;
    struct fn_15_350_lbl_15_data_70_0_E16 *p;
    p = (struct fn_15_350_lbl_15_data_70_0_E16 *)&lbl_15_data_70;
    p += lbl_1_bss_962 - 183;
    lbl_1_bss_71688 = p->unk_8;
    v0 = p->unk_C;
    lbl_1_bss_7168C = v0;
    ((fn_15_350_Fn0)p->unk_4)();
}
/* fzgx:end fn_15_350 */

/* fzgx:begin fn_15_B8C */
// fn_15_B8C: empty in retail (single blr).
void fn_15_B8C(void) {
}
/* fzgx:end fn_15_B8C */

/* fzgx:begin fn_15_B90 */
struct fn_15_B90_Copy160 { u32 a[40]; };
struct fn_15_B90_lbl_15_bss_0 {
    u8 pad_0[0x10];
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u8 pad_1C[0x10];
    u32 unk_2C;
    u8 pad_30[0xE];
    u8 unk_3E;
    u8 pad_3F[0x1];
    u16 unk_40;
};
struct fn_15_B90_lbl_15_rodata_0 {
    u8 pad_0[0x10];
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
    u32 unk_30;
    u32 unk_34;
    u32 unk_38;
    u32 unk_3C;
    u32 unk_40;
    u32 unk_44;
    u32 unk_48;
    u32 unk_4C;
    u32 unk_50;
    u32 unk_54;
};

extern struct fn_15_B90_lbl_15_rodata_0 lbl_15_rodata_0;
extern struct fn_15_B90_lbl_15_bss_0 lbl_15_bss_0;
extern u32 lbl_1_bss_6EAB4;
extern u16 lbl_1_bss_968;
extern u16 lbl_1_bss_96A;
extern u32 lbl_15_data_90[5];
extern u32 fn_1_4A00(u32, u32, u32);
extern u32 fn_1_5370(u32, u32);
extern void fn_1_DCF54(void *, void *, void *);
extern void camera_disable_flags(void);

void fn_15_B90(void) {
    struct fn_15_B90_lbl_15_rodata_0 *p_lbl_15_rodata_0;
    struct fn_15_B90_lbl_15_bss_0 *p_lbl_15_bss_0;
    struct fn_15_B90_Copy160 loc_50;
    u32 loc_44[3];
    u32 loc_38[3];
    u32 loc_2C[3];
    u32 loc_20[3];
    u32 loc_14[3];
    u32 loc_8[3];
    u32 v0;
    u32 v3;

    p_lbl_15_rodata_0 = (struct fn_15_B90_lbl_15_rodata_0 *)&lbl_15_rodata_0;
    p_lbl_15_bss_0 = (struct fn_15_B90_lbl_15_bss_0 *)&lbl_15_bss_0;
    v0 = p_lbl_15_bss_0->unk_14;
    lbl_1_bss_6EAB4 = lbl_1_bss_6EAB4 & 0xFFFFFFD7u;
    if ((v0 & 0x20000000) == 0) {
        if ((v0 & 0x80) != 0) {
            lbl_1_bss_968 = *(u8 *)((u8 *)p_lbl_15_bss_0->unk_2C + 0x190);
        } else {
            v3 = p_lbl_15_bss_0->unk_2C;
            loc_50 = *(struct fn_15_B90_Copy160 *)((u8 *)v3 + 0xF0);
            if (((u8 *)&loc_50)[8] == 0 && p_lbl_15_bss_0->unk_3E == 0) {
                lbl_1_bss_968 = 0x10;
            } else {
                if (p_lbl_15_bss_0->unk_40 < 1) {
                    p_lbl_15_bss_0->unk_40 = 1;
                    p_lbl_15_bss_0->unk_18 = lbl_15_data_90[1];
                    camera_disable_flags();
                    fn_1_5370(3, 0);
                    loc_44[0] = p_lbl_15_rodata_0->unk_10;
                    loc_44[1] = p_lbl_15_rodata_0->unk_14;
                    loc_44[2] = p_lbl_15_rodata_0->unk_18;
                    loc_38[0] = p_lbl_15_rodata_0->unk_1C;
                    loc_38[1] = p_lbl_15_rodata_0->unk_20;
                    loc_38[2] = p_lbl_15_rodata_0->unk_24;
                    loc_2C[0] = p_lbl_15_rodata_0->unk_28;
                    loc_2C[1] = p_lbl_15_rodata_0->unk_2C;
                    loc_2C[2] = p_lbl_15_rodata_0->unk_30;
                    fn_1_DCF54(loc_44, loc_38, loc_2C);
                    fn_1_4A00(1, 30, p_lbl_15_bss_0->unk_10);
                } else {
                    lbl_1_bss_968 = *(u8 *)((u8 *)v3 + 0x190);
                }
            }
        }
    } else {
        if ((v0 & 0x80) != 0) {
            lbl_1_bss_96A = 183;
        } else {
            if (p_lbl_15_bss_0->unk_40 < 1) {
                p_lbl_15_bss_0->unk_40 = 1;
                p_lbl_15_bss_0->unk_18 = lbl_15_data_90[1];
                camera_disable_flags();
                fn_1_5370(3, 0);
                loc_20[0] = p_lbl_15_rodata_0->unk_34;
                loc_20[1] = p_lbl_15_rodata_0->unk_38;
                loc_20[2] = p_lbl_15_rodata_0->unk_3C;
                loc_14[0] = p_lbl_15_rodata_0->unk_40;
                loc_14[1] = p_lbl_15_rodata_0->unk_44;
                loc_14[2] = p_lbl_15_rodata_0->unk_48;
                loc_8[0] = p_lbl_15_rodata_0->unk_4C;
                loc_8[1] = p_lbl_15_rodata_0->unk_50;
                loc_8[2] = p_lbl_15_rodata_0->unk_54;
                fn_1_DCF54(loc_20, loc_14, loc_8);
                fn_1_4A00(1, 30, p_lbl_15_bss_0->unk_10);
            } else {
                lbl_1_bss_96A = 183;
            }
        }
    }
}
/* fzgx:end fn_15_B90 */

/* fzgx:begin fn_15_DD8 */
struct fn_15_DD8_Copy160 { u32 a[40]; };

struct fn_15_DD8_lbl_15_bss_0 {
    u8 pad_0[0xC];
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    u8 pad_20[0x2];
    u8 unk_22;
    u8 unk_23;
    u8 pad_24[0x8];
    u32 unk_2C;
    u8 pad_30[0x4];
    u8 unk_34;
    u8 unk_35;
    u8 unk_36;
    u8 pad_37[0x7];
    u8 unk_3E;
    u8 pad_3F[0x1];
    u16 unk_40;
};

extern int fn_1_4C10(void);
extern s32 fn_1_C24A4(void);
extern struct fn_15_DD8_lbl_15_bss_0 lbl_15_bss_0;
extern u32 lbl_1_bss_6EAB4;
extern u8 lbl_1_bss_5138[];
extern u32 fn_1_4A00(u32, u32, void *);
extern u32 fn_1_A2A70(u32, s16);
extern u8 fn_1_B7C00(void);
extern void fn_1_3FDA8(void *, void *);

void fn_15_DD8(void) {
    s32 v4;
    struct fn_15_DD8_lbl_15_bss_0 *p;
    u32 v1;
    u32 v2;
    struct fn_15_DD8_Copy160 loc;

    p = &lbl_15_bss_0;
    if (fn_1_4C10() != 0) {
        return;
    }
    v1 = p->unk_14;
    v2 = v1 & 0x10000000;
    if (v2 == 0 && ((v1 & 1) == 0 || p->unk_18 >= 60)) {
        if ((p->unk_34 != 0 || p->unk_35 != 0) && p->unk_36 != 0 && p->unk_40 >= 1) {
            return;
        }
        loc = *(struct fn_15_DD8_Copy160 *)((u8 *)p->unk_2C + 0xF0);
        v4 = (p->unk_23 != 0) ? 480 : 30;
        if ((((u8 *)&loc)[8] == 0 && p->unk_3E == 0) || p->unk_40 < 1 || (v1 & 0x80) != 0) {
            if (v2 == 0) {
                p->unk_1C = (s16)v4;
                p->unk_14 |= 0x10000000;
            }
            lbl_1_bss_6EAB4 |= 0xAC;
            fn_1_A2A70(12, (s16)v4);
            fn_1_4A00(0, v4 & 0xFF, (void *)p->unk_10);
        } else {
            if (p->unk_22 == 0) {
                fn_1_3FDA8((void *)p->unk_C, (void *)p->unk_10);
            }
            p->unk_22 = 1;
            if ((s32)lbl_1_bss_5138[0xE2] == 0 && fn_1_C24A4() == 0 && (fn_1_B7C00() & 0xFF) == 0) {
                if ((p->unk_14 & 0x10000000) == 0) {
                    p->unk_1C = (s16)v4;
                    p->unk_14 |= 0x10000000;
                }
                p->unk_14 |= 0x10000000;
                lbl_1_bss_6EAB4 |= 0xAC;
                fn_1_A2A70(12, (s16)v4);
                fn_1_4A00(0, v4 & 0xFF, (void *)p->unk_10);
                p->unk_22 = 0;
            }
        }
    }
}
/* fzgx:end fn_15_DD8 */

/* fzgx:begin fn_15_FCC */
typedef struct Sig_fn_1_22E8C_Fn_1_22E8CInput {
    u8 pad[0xB4];
} Sig_fn_1_22E8C_Fn_1_22E8CInput;

typedef struct Sig_fn_1_22E8C_Fn_1_22E8COutput {
    u32 flags;
    u8 pad04[0x8];
    f32 field0c;
    u8 pad10[0xCC];
    f32 fielddc;
    u8 pade0[0x120];
    f32 field200;
    u8 pad204[0x280];
    void *field484;
} Sig_fn_1_22E8C_Fn_1_22E8COutput;

struct fn_15_FCC_lbl_15_rodata_0 {
    f32 unk_0;
    u8 pad_4[0x54];
    f32 unk_58;
    f32 unk_5C;
};
struct fn_15_FCC_lbl_15_bss_0 {
    u8 pad_0[0xC];
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u8 pad_1C[0x1E];
    s16 unk_3A;
    u8 pad_3C[0x4];
    u16 unk_40;
    u8 pad_42[0x2];
    f32 unk_44;
    f32 unk_48;
    u32 unk_4C;
    u32 unk_50;
    u32 unk_54;
    u32 unk_58;
    u32 unk_5C;
};

typedef struct Obj_1_bss_6EAD0_At0 {
    void *unk_0;
} Obj_1_bss_6EAD0_At0;

typedef struct Obj_1_bss_6EAD0 {
    Obj_1_bss_6EAD0_At0 *unk_0;
    u8 pad_4[0x704];
} Obj_1_bss_6EAD0;

extern struct fn_15_FCC_lbl_15_bss_0 lbl_15_bss_0;
extern struct fn_15_FCC_lbl_15_rodata_0 lbl_15_rodata_0;
extern Obj_1_bss_6EAD0 lbl_1_bss_6EAD0;
extern u32 lbl_15_data_154;
extern u32 lbl_15_data_164;
extern u8 lbl_1_data_28060[];
extern void camera_enable_flags(void);
extern void fn_80008BA8(void *, void *, u32);
extern void fn_1_22E8C(Sig_fn_1_22E8C_Fn_1_22E8COutput *, Sig_fn_1_22E8C_Fn_1_22E8CInput *);
extern f32 fn_1_1577D0(u32, u32, f32);
extern u32 fn_1_435C(u32);
extern s32 fn_1_3F8C(u32, u32, void *, u32);
extern s32 fn_1_5370(s32, s32);
extern void fn_15_4568(void);
extern void fn_1_15B610(void);
extern void ADXT_Pause(void *, s32);
extern s32 fn_80067898(u32);

extern s32 fn_1_157820;
extern s32 fn_1_1578C4;

void fn_15_FCC(void) {
    Sig_fn_1_22E8C_Fn_1_22E8CInput sp8;
    u8 *p_src;
    s16 i;
    Sig_fn_1_22E8C_Fn_1_22E8COutput *p_obj;
    struct fn_15_FCC_lbl_15_rodata_0 *p_rodata;
    struct fn_15_FCC_lbl_15_bss_0 *p_bss;
    f32 val0;
    f32 val200;
    u32 temp_r0;
    u32 v;
    u8 *p_aux;

    p_rodata = &lbl_15_rodata_0;
    p_bss = (struct fn_15_FCC_lbl_15_bss_0 *)&lbl_15_bss_0;
    p_bss->unk_18 = 0;
    p_bss->unk_40 = 0;
    p_bss->unk_44 = p_rodata->unk_0;
    p_bss->unk_48 = p_rodata->unk_0;
    camera_enable_flags();
    temp_r0 = p_bss->unk_14;
    if (temp_r0 & 6) {
        p_obj = (Sig_fn_1_22E8C_Fn_1_22E8COutput *)p_bss->unk_4C;
        val200 = p_rodata->unk_58;
        val0 = p_rodata->unk_0;
        p_src = lbl_1_data_28060 + 0x438;
        i = 0;
        while ((s32)i < p_bss->unk_3A) {
            fn_80008BA8(&sp8, p_src, 0xB4U);
            fn_1_22E8C(p_obj, &sp8);
            p_aux = (u8 *)p_obj->field484;
            i += 1;
            p_obj->field0c = val200;
            p_obj->field200 = val0;
            *(f32 *)(p_aux + 0xC) = val0;
            p_obj->fielddc = val0;
            p_obj->flags = p_obj->flags | 0x100000 | 0x8001;
            p_obj = (Sig_fn_1_22E8C_Fn_1_22E8COutput *)((u8 *)p_obj + 0x620);
        }
    }
    if (p_bss->unk_14 & 2) {
        fn_1_1577D0(1U, 1U, p_rodata->unk_5C);
        fn_1_435C(p_bss->unk_C);
        fn_1_3F8C((u32)&lbl_15_data_154, (u32)&fn_1_157820, 0, 2U);
        fn_1_435C(p_bss->unk_10);
        fn_1_3F8C((u32)&lbl_15_data_164, (u32)&fn_1_1578C4, 0, 2U);
    }
    v = p_bss->unk_14;
    p_bss->unk_50 = 0;
    p_bss->unk_54 = 0;
    p_bss->unk_58 = 0;
    p_bss->unk_5C = 0;
    if (v & 0x78) {
        temp_r0 = p_bss->unk_14 & 0xFBFFFFFF;
        p_bss->unk_14 = temp_r0;
        p_bss->unk_14 = temp_r0 | 0x40000000;
        fn_1_5370(0, 0);
    } else if (v & 0x80) {
        p_bss->unk_14 = v | 0x04000000;
        fn_1_5370(4, 0);
    } else {
        p_bss->unk_14 = v & 0xBBFFFFFF;
        fn_1_5370(0, 0);
    }
    fn_15_4568();
    fn_1_15B610();
    ADXT_Pause(lbl_1_bss_6EAD0.unk_0->unk_0, 0);
    fn_80067898(0xA91A0000U);
    fn_80067898(0xA91A0200U);
}
/* fzgx:end fn_15_FCC */

/* fzgx:begin fn_15_11DC */
#include "font.h"
#include "rel/main_rel/camera.h"
#include "rel/main_rel/sound.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
}
static const u32 fzgx_pool_table2[21] = {0x00FF00FF, 0x808080FF, 0xFFFFFFFF, 0xC3ACEF3B, 0x43FC728F, 0x44241408, 0xC3AD35A2, 0x43FE58B4, 0x44243FBE, 0x00000000, 0x3F800000, 0x00000000, 0xC3ACEF3B, 0x43FC728F, 0x44241408, 0xC3AD35A2, 0x43FE58B4, 0x44243FBE, 0x00000000, 0x3F800000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 200.0f;
    s = 1.0f;
}
static const u32 fzgx_pool_table4[1] = {0xFFC800FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 30.0f;
    d = 0.01;
    s = 2.0f;
    s = 320.0f;
    s = 240.0f;
    s = 20.0f;
    s = 10.0f;
    s = 0.5f;
    s = 3.0f;
    s = 0.03999999910593033f;
    d = 4503601774854144.0;
}
#pragma section code_type ".text"

struct WinningCar {
    u32 flags;
    u8 unknown_4[0xD8];
    f32 motion_dc;
    u8 unknown_e0[0x120];
    f32 motion_200;
    u8 unknown_204[0x41C];
};

struct WinningState {
    u8 unknown_0[0x10];
    void *transition;
    u32 flags;
    s32 frame;
    u8 unknown_1c[4];
    u8 input_enabled;
    u8 unknown_21[2];
    u8 advancing;
    u8 unknown_24[8];
    void *result_source;
    u8 unknown_30[4];
    u8 show_first_result;
    u8 show_second_result;
    u8 result_visible;
    u8 unknown_37;
    s16 active_car_count;
    s16 total_car_count;
    u8 unknown_3c[2];
    u8 result_blocked;
    u8 unknown_3f;
    u16 stage;
    u8 unknown_42[2];
    f32 first_result_alpha;
    f32 second_result_alpha;
    struct WinningCar *cars;
    u32 effect_mode;
    u32 effect_enabled;
    u32 initialized;
    u8 unknown_5c[4];
    f32 result_scale;
};

/* The retail 0xA0-byte result snapshot includes its status byte at +8. */
struct WinningResultSnapshot {
    u32 unknown_0[2];
    u8 status;
    u8 unknown_9[0x97];
};


struct WinningTimeline {
    u32 unknown_0;
    s32 results_start;
    s32 results_end;
    s32 hide_result_at;
    s32 exit_at;
};

struct WinningInputStatus {
    u8 unknown_0[0xE0];
    u8 held_frames;
    u8 unknown_e1;
    u8 skip;
};

extern struct WinningState lbl_15_bss_0;
extern struct WinningTimeline lbl_15_data_90;
extern struct WinningInputStatus lbl_1_bss_5138;
extern FontDrawPacket lbl_1_rodata_26F8;

typedef struct Sig_ADXT_Stop_ADXTHandle Sig_ADXT_Stop_ADXTHandle;
extern u32 fn_8004BF0C(Sig_ADXT_Stop_ADXTHandle *, u32);
extern s32 fn_800674FC(u32, s32, s16);
extern u32 fn_15_4578(void);
extern void fn_15_4060(void);
extern void fn_15_30E8(void);
extern void fn_15_398C(void);
extern void fn_15_B90(void);
extern void fn_15_DD8(void);
extern u32 fn_15_5460(f32);
extern u32 fn_15_5730(f32);
extern void fn_1_4A00(s32, u8, void *);
extern s8 fn_1_5370(s8, s32);
extern u32 fn_1_467F4(void);
extern void fn_1_15B544(void);
extern void fn_1_15B5CC(void);
extern void fn_1_15B588(void);
extern void fn_1_15B654(void);
extern u32 fn_1_A2A70(u32, u32);
extern void fn_1_A2D84(u32);
extern void camera_set_entry_field_0xa8(u8, s16);
extern CameraState *camera_get_state_object(void);
extern BOOL camera_are_flags_enabled(void);
extern LiveCamera *live_camera_get(void);

static inline f32 winning_clamp(f32 value, f32 low, f32 high) {
    if (value < low) {
        return low;
    } else if (value > high) {
        return high;
    } else {
        return value;
    }
}

#pragma opt_propagation off
void fn_15_11DC(void) {
    struct WinningState *state;
    struct WinningTimeline *timeline;
    struct WinningCar *car;
    s32 index;
    s32 first_index;
    struct WinningCar *first_car;
    FontDrawPacket packet;
    struct WinningResultSnapshot result;
    CameraState *camera;
    LiveCamera *live;
    f32 fade;
    f32 value;
    f32 previous_scale;
    f64 scale_step;
    s32 frame;
    u8 skip;

    state = &lbl_15_bss_0;
    if (state->flags & 0x78) {
        camera_set_entry_field_0xa8(0, 2);
    } else {
        camera_set_entry_field_0xa8(0, 2);
    }
    if (state->flags & 0x78) {
        fn_15_4578();
    }
    if (state->flags & 0x10000000) {
        return;
    }

    if (state->flags & 4) {
        for (first_car = state->cars, first_index = 0; (s16)first_index < state->total_car_count; ++first_index, ++first_car) {
            first_car->flags |= 0x100000;
            if (state->frame <= 350) {
                first_car->motion_200 = (0.0f);
                first_car->motion_dc = (0.0f);
            }
        }
        if (state->frame == 1) {
            for (car = state->cars, index = 0; (s16)index < state->active_car_count; ++index, ++car) {
                car->flags |= 0x400;
            }
            state->input_enabled = 1;
        }
        if (state->frame == 350) {
            for (car = state->cars, index = 0; (s16)index < state->total_car_count; ++index, ++car) {
                car->flags &= ~0x8000U;
            }
            state->flags |= 0x40000000;
        }
        if (state->frame == 1029) {
            fn_1_4A00(0, 12, state->transition);
        }
        if (state->frame == 1041) {
            fn_15_4060();
            fn_1_5370(4, 0);
        }
        if (state->frame == 1044) {
            if ((s32)fn_1_467F4() == 0) {
                fn_15_30E8();
            }
            fn_1_5370(4, 0);
            fn_1_4A00(1, 15, state->transition);
            fn_15_398C();
            fn_1_15B544();
            fn_1_15B5CC();
            fn_1_15B588();
            state->initialized = 1;
        }
        if (state->frame == 2280) {
            fn_1_4A00(0, 120, state->transition);
            lbl_1_bss_6EAB4.unk_0 |= 0xAC;
            fn_1_A2A70(12, 120);
        }
        if (state->frame == 2400) {
            fn_15_B90();
        }
        frame = state->frame;
        if (frame == 1219) state->effect_enabled = 1;
        if (frame == 1393) state->effect_mode = 1;
        if (frame == 1586) state->effect_mode = 2;
        if (frame == 1739) state->effect_enabled = 0;
        if (frame == 2087) {
            state->effect_enabled = 1;
            state->effect_mode = 0;
        }
    } else if (state->flags & 2) {
        for (car = state->cars, index = 0; (s16)index < state->total_car_count; ++index, ++car) {
            car->flags |= 0x100000;
            if (state->frame <= 350) {
                car->motion_200 = (0.0f);
                car->motion_dc = (0.0f);
            }
        }
        if (state->frame == 1) {
            for (car = state->cars, index = 0; (s16)index < state->active_car_count; ++index, ++car) {
                car->flags |= 0x400;
            }
        }
        if (state->frame == 350) {
            for (car = state->cars, index = 0; (s16)index < state->total_car_count; ++index, ++car) {
                car->flags &= ~0x8000U;
            }
            state->flags |= 0x40000000;
        }
        frame = state->frame;
        if (frame == 523) state->input_enabled = 1;
        if (frame == 3292) fn_1_4A00(0, 12, state->transition);
        if (state->frame == 3304) {
            fn_15_4060();
            fn_1_5370(4, 0);
        }
        if (state->frame == 3307) {
            if ((s32)fn_1_467F4() == 0) fn_15_30E8();
            fn_1_5370(4, 0);
            fn_1_4A00(1, 15, state->transition);
            fn_15_398C();
            fn_1_15B544();
            fn_1_15B5CC();
            fn_1_15B588();
            state->initialized = 1;
        }
        if (state->frame == 4680) fn_1_15B654();
        if (state->frame == lbl_15_data_90.results_start) fn_15_DD8();
        frame = state->frame;
        if (frame == 3662) state->effect_enabled = 1;
        if (frame == 4011) state->effect_enabled = 0;
    } else if (state->flags & 0x78) {
        state->input_enabled = 1;
        if (state->frame == 15) fn_1_4A00(1, 244, state->transition);
        if (state->frame == 3292) fn_1_4A00(0, 12, state->transition);
        if (state->frame == 3304 && !(state->flags & 0x40)) {
            fn_15_4060();
            fn_1_5370(4, 0);
        }
        if (state->frame == 3307) {
            if (state->flags & 0x40) {
                fn_15_B90();
                return;
            }
            if ((s32)fn_1_467F4() == 0 && !(state->flags & 0x40)) fn_15_30E8();
            fn_1_5370(4, 0);
            fn_1_4A00(1, 15, state->transition);
            fn_15_398C();
            fn_1_15B544();
            fn_1_15B5CC();
            fn_1_15B588();
            state->initialized = 1;
        }
        if (state->frame == 4680) fn_1_15B654();
        timeline = &lbl_15_data_90;
        {
        s32 trigger_frame = timeline->results_start;
        s32 current_frame = state->frame;
        if (current_frame == trigger_frame) {
            result = *(struct WinningResultSnapshot *)((u8 *)state->result_source + 0xF0);
            if (result.status == 0 && state->result_blocked == 0 && !(state->flags & 0x20000000)) {
                state->advancing = 1;
                fn_15_DD8();
            } else {
                state->stage = 1;
            }
        }
        }
        if (state->stage >= 1) {
            camera = camera_get_state_object();
            /* Retail reads this phase counter as signed with lha. */
            *(s16 *)&camera->unk_20 += 2;
            if (camera_are_flags_enabled()) {
                live = live_camera_get();
                *(s16 *)((u8 *)live + 0x5C) += 2;
            }
            frame = state->frame;
            value = (1.0f) - (f32)(timeline->results_start + 30 - frame) / (30.0f);
            fade = winning_clamp(value, (0.0f), (1.0f));
            if (frame >= lbl_15_data_90.results_end && (state->show_first_result || state->show_second_result)) {
                value = (f32)(lbl_15_data_90.results_end + 30 - frame) / (30.0f);
                fade = winning_clamp(value, (0.0f), (1.0f));
            }
            previous_scale = state->result_scale;
            scale_step = (0.01) * (f64)((2.0f) - previous_scale);
            state->result_scale = (f32)((f64)previous_scale + scale_step);
            packet = lbl_1_rodata_26F8;
            packet.x = (320.0f);
            packet.y = (240.0f);
            packet.z = (20.0f);
            packet.image = 0x8C04;
            packet.flags = 0xA;
            packet.alpha = fade;
            fn_1_4F734(&packet);

            packet.image = 0x8C06;
            packet.z = (10.0f);
            if (state->frame > timeline->results_start + 20) {
                packet.scale_x = (2.0f) * state->result_scale;
                packet.scale_y = packet.scale_x;
                if (packet.scale_y > (2.0f)) {
                    value = (2.0f) - (packet.scale_x - (2.0f));
                    packet.scale_y = winning_clamp(value, (0.0f), (2.0f));
                }
            } else {
                packet.scale_x = (0.0f);
                packet.scale_y = (0.0f);
            }
            packet.alpha = packet.scale_y / (2.0f);
            fn_1_4F734(&packet);

            packet.z = (30.0f);
            packet.image = 0x8C06;
            *(u32 *)packet.color = fzgx_pool_table4[0];
            if (state->frame > timeline->results_start + 20) {
                packet.scale_x = (3.0f) * state->result_scale;
                packet.scale_y = packet.scale_x;
                if (packet.scale_y > (3.0f)) {
                    value = (3.0f) - (packet.scale_x - (3.0f));
                    packet.scale_y = winning_clamp(value, (0.0f), (3.0f));
                }
            } else {
                packet.scale_x = (0.0f);
                packet.scale_y = (0.0f);
            }
            packet.alpha = packet.scale_y / (3.0f);
            fn_1_4F734(&packet);
            if (state->frame == timeline->results_start + 60) {
                fn_8004BF0C((Sig_ADXT_Stop_ADXTHandle *)lbl_1_bss_6EAD0.unk_0->unk_4, 0);
                fn_800674FC(3, (s32)0xA0100000U, 0x7F);
                fn_1_A2D84(0xA91A0600);
            }
        } else {
            state->result_scale = (0.0f);
        }
        timeline = &lbl_15_data_90;
        if (state->frame == timeline->results_end + 40 && (state->show_first_result || state->show_second_result)) {
            fn_1_A2D84(0xA91A0700);
        }
        if (state->frame >= timeline->results_end && state->show_first_result) {
            skip = lbl_1_bss_5138.skip;
            if (state->frame >= lbl_15_data_90.hide_result_at) {
                state->result_visible = 0;
            } else {
                value = (1.0f) - (f32)(timeline->results_end + 30 - state->frame) / (30.0f);
                state->first_result_alpha = winning_clamp(value, (0.0f), (1.0f));
            }
            if ((s32)skip != 0) {
                value = state->first_result_alpha - (0.03999999910593033f);
                state->first_result_alpha = winning_clamp(value, (0.0f), (1.0f));
            }
            fn_15_5460(state->first_result_alpha);
        }
        if (state->frame >= timeline->results_end && state->show_second_result && !state->show_first_result) {
            skip = lbl_1_bss_5138.skip;
            if (state->frame >= lbl_15_data_90.hide_result_at) {
                state->result_visible = 0;
            } else {
                value = (1.0f) - (f32)(timeline->results_end + 30 - state->frame) / (30.0f);
                state->second_result_alpha = winning_clamp(value, (0.0f), (1.0f));
            }
            if ((s32)skip != 0) {
                value = state->second_result_alpha - (0.03999999910593033f);
                state->second_result_alpha = winning_clamp(value, (0.0f), (1.0f));
            }
            fn_15_5730(state->second_result_alpha);
        }
        if (state->frame == lbl_15_data_90.exit_at) {
            state->stage = 4;
            state->advancing = 1;
            fn_15_DD8();
        }
        frame = state->frame;
        if (frame == 3517) state->effect_enabled = 1;
        if (frame == 3866) state->effect_enabled = 0;
    } else if (state->flags & 0x80) {
        fn_1_15B544();
        fn_1_15B5CC();
        fn_1_15B588();
        fn_15_398C();
        state->initialized = 1;
    }
    if (state->frame < 18000) {
        ++state->frame;
    }
}

#pragma opt_propagation reset
/* fzgx:end fn_15_11DC */

/* fzgx:begin fn_15_1D7C */
extern struct fn_15_1D7C_lbl_15_bss_0 lbl_15_bss_0;
extern u32 fn_15_1F28(u32, u32);
extern u32 fn_15_FCC(void);
extern u32 fn_1_4A00(u32, u32, u32);

struct fn_15_1D7C_lbl_15_bss_0 {
    u8 pad_0[0xC];
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
};

u32 fn_15_1D7C(u32 arg0, u32 arg1, u32 arg2) {
    struct fn_15_1D7C_lbl_15_bss_0 *p_lbl_15_bss_0;
    u32 v0;
    u32 v1;
    u32 v2;
    u32 t0, t1, t2, t3;
    p_lbl_15_bss_0 = (struct fn_15_1D7C_lbl_15_bss_0 *)&lbl_15_bss_0;
    v0 = arg2;
    v1 = arg0;
    v2 = arg1;
    if ((p_lbl_15_bss_0->unk_14 & 0x78) == 0) {
    v0 = p_lbl_15_bss_0->unk_10;
    v1 = 1;
    v2 = 30;
    t0 = fn_1_4A00(v1, v2, v0);
    v1 = t0;
    } else {
    v0 = p_lbl_15_bss_0->unk_10;
    v1 = 0;
    v2 = 0;
    t1 = fn_1_4A00(v1, v2, v0);
    v1 = t1;
    }
    v1 = p_lbl_15_bss_0->unk_C;
    v2 = p_lbl_15_bss_0->unk_10;
    t2 = fn_15_1F28(v1, v2);
    v1 = t2;
    if ((p_lbl_15_bss_0->unk_14 & 0x1) != 0) {
    t3 = fn_15_FCC();
    v1 = t3;
    }
    return v1;
}
/* fzgx:end fn_15_1D7C */

/* fzgx:begin fn_15_1DF4 */
extern struct fn_15_1DF4_lbl_15_bss_0 lbl_15_bss_0;
extern u8 lbl_1_bss_25E98;
extern u8 lbl_1_bss_9F8;
extern struct fn_15_1DF4_lbl_1_bss_5138 lbl_1_bss_5138;
extern void fn_15_11DC(void);
extern u32 fn_1_B7C00(void);
extern void fn_15_DD8(void);

struct fn_15_1DF4_lbl_15_bss_0 {
    u8 pad_0[0x14];
    u32 unk_14;
    u8 pad_18[0x8];
    u8 unk_20;
    u8 unk_21;
    u8 unk_22;
};

struct fn_15_1DF4_lbl_1_bss_5138 {
    u8 pad_0[0xE0];
    u8 unk_E0;
    u8 unk_E1;
    u8 unk_E2;
};

void fn_15_1DF4(void) {
    struct fn_15_1DF4_lbl_15_bss_0 *p;
    struct fn_15_1DF4_lbl_1_bss_5138 *q;
    u8 *table;
    u32 idx;
    u16 val;
    s32 e2;
    s32 bit;

    p = (struct fn_15_1DF4_lbl_15_bss_0 *)&lbl_15_bss_0;
    if ((p->unk_14 & 0x1) != 0) {
        fn_15_11DC();
    }

    table = (u8 *)&lbl_1_bss_9F8 + 0x8;
    idx = (u32)lbl_1_bss_25E98 * 0x14;
    val = *(u16 *)(table + idx);
    if ((((val >> 8) & 1) != 0 || ((val >> 12) & 1) != 0) &&
        (fn_1_B7C00() & 0xFF) == 0 && p->unk_20 != 0 || p->unk_22 != 0) {
        fn_15_DD8();
    }

    q = (struct fn_15_1DF4_lbl_1_bss_5138 *)&lbl_1_bss_5138;
    e2 = q->unk_E2;
    if (e2 != 0) {
        bit = (*(u16 *)(table + (u32)lbl_1_bss_25E98 * 0x14) >> 8) & 1;
        if (q->unk_E2 != 0 && bit != 0 && q->unk_E0 >= 0xF && q->unk_E0 <= 0x78) {
            q->unk_E0 = 0x78;
        }
    }
}
/* fzgx:end fn_15_1DF4 */

/* fzgx:begin fn_15_1EE0 */
extern struct fn_15_1EE0_lbl_15_bss_0 lbl_15_bss_0;
extern u32 camera_enable_flags(u32);
extern u32 fn_15_236C(u32, u32);

struct fn_15_1EE0_lbl_15_bss_0 {
    u8 pad_0[0xC];
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
};

void fn_15_1EE0(void) {
    struct fn_15_1EE0_lbl_15_bss_0 *p_lbl_15_bss_0;
    u32 t0;
    p_lbl_15_bss_0 = (struct fn_15_1EE0_lbl_15_bss_0 *)&lbl_15_bss_0;
    t0 = fn_15_236C(p_lbl_15_bss_0->unk_C, p_lbl_15_bss_0->unk_10);
    if ((p_lbl_15_bss_0->unk_14 & 0x1) != 0) {
    camera_enable_flags(t0);
    }
}
/* fzgx:end fn_15_1EE0 */

/* fzgx:begin fn_15_1F28 */
struct fn_15_1F28_bss {
    u8 pad_0[0x8];
    void *unk_8;
    u8 pad_C[0x8];
    u32 unk_14;
    u8 pad_18[0x26];
    u8 unk_3E;
    u8 pad_3F[0x25];
    u32 unk_64;
    u32 unk_68;
    u32 unk_6C;
    u32 unk_70;
    u32 unk_74;
    u32 unk_78;
    u32 unk_7C;
    u32 unk_80;
    u32 unk_84;
    u32 unk_88;
    u32 unk_8C;
    u32 unk_90;
    s16 unk_94;
    s16 unk_96;
    u16 unk_98;
};

struct fn_15_1F28_ro3 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
};

struct fn_15_1F28_snd {
    u32 unk_0;
    u32 unk_4;
    u8 pad_8[0x8];
    u8 unk_10[0x4A248];
    u8 unk_4A258[0x4A248];
    u8 unk_944A0[0x3000];
};

struct fn_15_1F28_bss6EAD0 {
    struct fn_15_1F28_snd *unk_0;
};

struct fn_15_1F28_6410 {
    u32 unk_0;
};

extern struct fn_15_1F28_bss lbl_15_bss_0;
extern struct fn_15_1F28_ro3 lbl_15_rodata_98;
extern struct fn_15_1F28_bss6EAD0 lbl_1_bss_6EAD0;
extern struct fn_15_1F28_6410 lbl_801A6410;
extern f32 lbl_15_rodata_A4[];
extern u8 lbl_15_data_0[];

extern u32 fn_1_A0680(void);
extern void fn_1_41048(void);
extern u32 fn_15_2AE4(void);
extern u32 fn_15_2E8C(void);
extern u32 fn_1_7BA08(u32, u32, u32);
extern u32 fn_1_45D0(u32, u32, u32, u32);
extern void *fn_1_435C(void *);
extern s32 fn_1_3F8C(u32, u32, void *, u32);
extern u32 fn_1_7BA48(u32);
extern void fn_15_3A14(void);
extern void lbl_8006D758(void);
extern void mathutil_mtxA_rotate_y(u32);
extern void mathutil_mtxA_rotate_x(u32);
extern void lbl_8006E1B0(void *, void *);
extern void fn_80074CF4(f32, f32, f32);
extern u32 fn_8004CD70(u32, u32, u32);
extern void fn_80051E64(void *, void *, u32);
extern u32 fn_1_A1588(void *, u32);
extern void ADXT_Pause(void *, s32);
extern u32 fn_8004BF0C(void *, u32);
extern void camera_set_state_flag(u8);
extern void fn_1_5124(void *, void *);
extern u32 fn_1_5370(u32, u32);
extern void fn_1_9A578(void);
extern u32 fn_15_3B24(void);

extern s32 fn_15_2228;
extern s32 fn_15_2274;
extern s32 fn_15_537C;
extern s32 fn_15_545C;
extern s32 fn_1_7BAF8;

void fn_15_1F28(u32 arg0, u32 arg1) {
    u8 *d;
    struct fn_15_1F28_bss *p;
    f32 f0;
    u32 buf;

    d = (u8 *)&lbl_15_data_0;
    p = (struct fn_15_1F28_bss *)&lbl_15_bss_0;

    p->unk_64 = 0;
    p->unk_68 = 0;
    p->unk_6C = 0;
    p->unk_70 = 0;
    p->unk_3E = 0;
    fn_1_A0680();
    fn_1_41048();
    p->unk_74 = arg0;
    p->unk_78 = arg1;
    fn_15_2AE4();
    if (!(p->unk_14 & 0x80)) {
        fn_15_2E8C();
    }
    p->unk_8 = (void *)fn_1_45D0(lbl_801A6410.unk_0, fn_1_7BA08(0x20U, 0x20U, 0x40U), (u32)(d + 0xa4), 0x647U);
    fn_1_435C((void *)arg0);
    fn_1_3F8C((u32)(d + 0x174), (u32)(&fn_15_2228), NULL, 5U);
    fn_1_435C((void *)arg1);
    fn_1_7BA48((u32)p->unk_8);
    fn_1_3F8C((u32)(d + 0x180), (u32)(&fn_1_7BAF8), (void *)(p->unk_8), 3U);
    fn_1_3F8C((u32)(d + 0x18C), (u32)(&fn_15_537C), NULL, 5U);
    fn_1_3F8C((u32)(d + 0x19C), (u32)(&fn_15_2274), NULL, 0xAU);
    fn_1_3F8C((u32)(d + 0x1A8), (u32)(&fn_15_545C), NULL, 0xBU);
    fn_15_3A14();

    p->unk_88 = lbl_15_rodata_98.unk_0;
    p->unk_8C = lbl_15_rodata_98.unk_4;
    p->unk_90 = lbl_15_rodata_98.unk_8;
    p->unk_7C = lbl_15_rodata_98.unk_0;
    p->unk_80 = lbl_15_rodata_98.unk_4;
    p->unk_84 = lbl_15_rodata_98.unk_8;
    p->unk_94 = -0x2000;
    p->unk_96 = 0x2000;
    lbl_8006D758();
    mathutil_mtxA_rotate_y((u32)p->unk_96);
    mathutil_mtxA_rotate_x((u32)p->unk_94);
    lbl_8006E1B0(&p->unk_7C, &p->unk_88);
    f0 = lbl_15_rodata_A4[0];
    fn_80074CF4(f0, f0, f0);

    if (lbl_1_bss_6EAD0.unk_0->unk_0 == 0) {
        lbl_1_bss_6EAD0.unk_0->unk_0 = fn_8004CD70(2U, (u32)((u8 *)lbl_1_bss_6EAD0.unk_0 + 0x10), 0x4A248U);
    }
    if (lbl_1_bss_6EAD0.unk_0->unk_4 == 0) {
        lbl_1_bss_6EAD0.unk_0->unk_4 = fn_8004CD70(2U, (u32)((u8 *)lbl_1_bss_6EAD0.unk_0 + 0x4A258), 0x4A248U);
    }
    fn_80051E64((void *)lbl_1_bss_6EAD0.unk_0->unk_4, (void *)((u8 *)lbl_1_bss_6EAD0.unk_0 + 0x944A0), 0x3000U);
    fn_1_A1588((void *)lbl_1_bss_6EAD0.unk_0->unk_0, 0x35U);
    ADXT_Pause((void *)lbl_1_bss_6EAD0.unk_0->unk_0, 1);
    p->unk_98 = 0;
    fn_8004BF0C((void *)lbl_1_bss_6EAD0.unk_0->unk_0, -0x50U);
    fn_8004BF0C((void *)lbl_1_bss_6EAD0.unk_0->unk_4, -0x50U);
    camera_set_state_flag(1U);
    fn_1_5124((void *)arg0, (void *)arg1);
    if (!(p->unk_14 & 1)) {
        fn_1_5370(4U, 0U);
    }
    fn_1_9A578();
    if (!(p->unk_14 & 0x80)) {
        fn_15_3B24();
    }
}
/* fzgx:end fn_15_1F28 */

/* fzgx:begin fn_15_2228 */
extern u32 fn_15_2CEC(void);
extern u32 fn_15_3AFC(void);
extern u32 fn_15_401C(void);
extern u32 fn_15_4124(void);
extern u32 lbl_15_bss_14;
extern u8 lbl_15_bss_21;

void fn_15_2228(void) {
    if ((lbl_15_bss_14 & ~0x7FFFFFFF) != 0) {
    fn_15_4124();
    }
    fn_15_2CEC();
    fn_15_3AFC();
    if (lbl_15_bss_21 != 0) {
    fn_15_401C();
    }
}
/* fzgx:end fn_15_2228 */

/* fzgx:begin fn_15_2274 */
struct fn_15_2274_lbl_15_bss_0 {
    u8 pad_0[0x14];
    u32 unk_14;
    u8 pad_18[0x9];
    u8 unk_21;
    u8 pad_22[0x4E];
    u32 unk_70;
};

struct fn_15_2274_lbl_15_rodata_0 {
    u8 pad_0[0xA8];
    u32 unk_A8;
    u32 unk_AC;
    u32 unk_B0;
    u32 unk_B4;
    u32 unk_B8;
};

extern struct fn_15_2274_lbl_15_bss_0 lbl_15_bss_0;
extern struct fn_15_2274_lbl_15_rodata_0 lbl_15_rodata_0;
extern void fn_15_435C(void);
extern void fn_15_405C(void);
extern void fn_15_2D74(void);
extern void fn_80007AB4(void *);

void fn_15_2274(void) {
    struct fn_15_2274_lbl_15_rodata_0 *p_lbl_15_rodata_0;
    struct fn_15_2274_lbl_15_bss_0 *p_lbl_15_bss_0;
    u32 v0;
    p_lbl_15_rodata_0 = &lbl_15_rodata_0;
    p_lbl_15_bss_0 = &lbl_15_bss_0;
    if ((p_lbl_15_bss_0->unk_14 & 0x80000000) != 0) {
        fn_15_435C();
    }
    v0 = p_lbl_15_bss_0->unk_70;
    switch (v0) {
    case 0: {
        u32 local0;
        local0 = p_lbl_15_rodata_0->unk_A8;
        fn_80007AB4(&local0);
        break;
    }
    case 1: {
        u32 local1;
        local1 = p_lbl_15_rodata_0->unk_AC;
        fn_80007AB4(&local1);
        break;
    }
    case 2: {
        u32 local2;
        local2 = p_lbl_15_rodata_0->unk_B0;
        fn_80007AB4(&local2);
        break;
    }
    case 3: {
        u32 local3;
        local3 = p_lbl_15_rodata_0->unk_B4;
        fn_80007AB4(&local3);
        break;
    }
    default: {
        u32 local4;
        local4 = p_lbl_15_rodata_0->unk_B8;
        fn_80007AB4(&local4);
        break;
    }
    }
    if (p_lbl_15_bss_0->unk_21 != 0) {
        fn_15_405C();
    }
    if ((p_lbl_15_bss_0->unk_14 & 0x80) != 0) {
        fn_15_2D74();
    }
}
/* fzgx:end fn_15_2274 */

/* fzgx:begin fn_15_236C */
struct fn_15_236C_lbl_15_bss_0 {
    u8 pad_0[0x8];
    u32 unk_8;
    u8 pad_C[0x8];
    u32 unk_14;
    u8 pad_18[0x9];
    u8 unk_21;
};
struct fn_15_236C_lbl_1_bss_6EAD0 {
    u32 unk_0;
};

extern struct fn_15_236C_lbl_15_bss_0 lbl_15_bss_0;
extern struct fn_15_236C_lbl_1_bss_6EAD0 lbl_1_bss_6EAD0;
extern u32 fn_15_2CF0(u32);
extern u32 fn_15_38FC(u32);
extern u32 fn_1_435C(u32);
extern u32 fn_1_46B4(u32, u32, u32, u32);
extern u32 fn_1_A0AA4(u32);
extern u32 ADXT_Stop(u32);
extern u32 lbl_15_data_A4;
extern u32 lbl_801A6410;
extern void fn_15_3B00(void);
extern void fn_15_4060(void);
extern void fn_1_410A0(void);
extern void fn_1_41A8(void);
extern void fn_1_469BC(void);
extern void fn_1_6400(void);

void fn_15_236C(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    struct fn_15_236C_lbl_15_bss_0 *p_lbl_15_bss_0;
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 t2, t3, t4, t8;
    p_lbl_15_bss_0 = (struct fn_15_236C_lbl_15_bss_0 *)&lbl_15_bss_0;
    fn_1_469BC();
    ADXT_Stop(*(u32 *)((u8 *)lbl_1_bss_6EAD0.unk_0 + 0));
    t2 = ADXT_Stop(*(u32 *)((u8 *)lbl_1_bss_6EAD0.unk_0 + 4));
    t3 = fn_1_A0AA4(t2);
    t4 = fn_15_2CF0(t3);
    if ((p_lbl_15_bss_0->unk_14 & 0x80) == 0) {
    fn_15_38FC(t4);
    }
    fn_15_3B00();
    if (p_lbl_15_bss_0->unk_21 != 0) {
    fn_15_4060();
    }
    v0 = p_lbl_15_bss_0->unk_8;
    v3 = arg3;
    if (v0 != 0) {
    v3 = (u32)&lbl_801A6410;
    v1 = (u32)&lbl_15_data_A4;
    v2 = *(u32 *)((u8 *)v3 + 0);
    v3 = 1768;
    t8 = fn_1_46B4(v2, v0, (u32)v1, v3);
    v2 = t8;
    p_lbl_15_bss_0->unk_8 = 0;
    }
    fn_1_435C(arg0);
    fn_1_41A8();
    fn_1_435C(arg1);
    fn_1_41A8();
    fn_1_410A0();
    fn_1_6400();
}
/* fzgx:end fn_15_236C */

/* fzgx:begin fn_15_2620 */
struct fn_15_2620_Arg0 {
    u8 pad_0[0x18];
    u32 unk_18;
    u8 pad_1C[0x6C];
    u32 unk_88;
    u32 unk_8C;
    u8 pad_90[0x8];
    u8 unk_98;
    u8 pad_99[0x42B];
    u8 unk_4C4;
};
struct fn_15_2620_Entry {
    u8 pad_0[6];
    u8 unk_6;
    u8 pad_7;
};
struct fn_15_2620_lbl_15_bss_0 {
    u8 pad_0[0x14];
    u32 unk_14;
    u8 pad_18[0x14];
    struct fn_15_2620_Entry *unk_2C;
    u8 pad_30[0x20];
    u32 unk_50;
    u32 unk_54;
    u32 unk_58;
};

extern struct fn_15_2620_lbl_15_bss_0 lbl_15_bss_0;
extern u32 fn_1_8E728(void *, u32);

void fn_15_2620(struct fn_15_2620_Arg0 *arg0) {
    struct fn_15_2620_lbl_15_bss_0 *p_lbl_15_bss_0;
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    p_lbl_15_bss_0 = &lbl_15_bss_0;
    v0 = arg0->unk_88;
    switch ((s32)v0) {
    case 33:
    case 42:
    case 43:
        if ((s32)p_lbl_15_bss_0->unk_54 != 0 && (s32)arg0->unk_4C4 == (s32)p_lbl_15_bss_0->unk_50) {
            arg0->unk_8C = 2;
        } else {
            arg0->unk_8C = 3;
        }
        break;
    case 21:
    case 41:
        if ((s32)p_lbl_15_bss_0->unk_54 != 0 && (s32)arg0->unk_4C4 == (s32)p_lbl_15_bss_0->unk_50) {
            arg0->unk_8C = 2;
        } else {
            arg0->unk_8C = 3;
        }
        break;
    default:
        v1 = p_lbl_15_bss_0->unk_14;
        if ((v1 & 0x4000000) != 0 && (v1 & 0x80) == 0) {
            if ((s32)p_lbl_15_bss_0->unk_54 != 0 && (s32)arg0->unk_4C4 == (s32)p_lbl_15_bss_0->unk_50) {
                arg0->unk_8C = 1;
            } else {
                arg0->unk_8C = 2;
            }
        } else {
            arg0->unk_8C = 1;
        }
        break;
    }
    if ((s32)p_lbl_15_bss_0->unk_58 != 0) {
        arg0->unk_18 = (arg0->unk_18 & 0xDFFFFFFF);
    } else {
        arg0->unk_18 = (arg0->unk_18 | 0x20000000);
    }
    v2 = ((31 - __cntlzw(p_lbl_15_bss_0->unk_2C[arg0->unk_4C4].unk_6)) & 0x3);
    v3 = (u32)(p_lbl_15_bss_0->unk_2C + arg0->unk_4C4);
    switch ((s32)v2) {
    case 0:
        v3 = 0;
        break;
    case 1:
        v3 = 1;
        break;
    case 2:
        v3 = 2;
        break;
    case 3:
        v3 = 3;
        break;
    default:
        v3 = 0;
        break;
    }
    if (arg0->unk_98 != (u32)v3) {
        fn_1_8E728((void *)(u32)arg0, (v3 & 0xFF));
    }
}
/* fzgx:end fn_15_2620 */

/* fzgx:begin fn_15_2CEC */
// fn_15_2CEC: empty in retail (single blr).
void fn_15_2CEC(void) {
}
/* fzgx:end fn_15_2CEC */

/* fzgx:begin fn_15_2CF0 */
extern u32 lbl_15_bss_9C[13];
extern u8 lbl_15_data_A4[176];
extern u32 lbl_801A6410;
extern void fn_1_8F494(void *);
extern u32 fn_1_46B4(u32, u32, const u8 *, int);

void fn_15_2CF0(void) {
    u32 *p;
    s32 i;

    p = lbl_15_bss_9C;
    for (i = 0; i < 12; i++) {
        if (p[i] != 0) {
            fn_1_8F494((void *)p[i]);
            fn_1_46B4(lbl_801A6410, p[i], lbl_15_data_A4, 0x8cf);
            p[i] = 0;
        }
    }
}
/* fzgx:end fn_15_2CF0 */

/* fzgx:begin fn_15_2D74 */
struct fn_15_2D74_D0 {
    u32 unk_0;
    u32 unk_4;
};

struct fn_15_2D74_D8 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
};

struct fn_15_2D74_bss0 {
    u8 pad_0[0x2C];
    u8 *unk_2C;
    u8 pad_30[0x8];
    s16 unk_38;
};

struct fn_15_2D74_rec {
    u32 unk_0;
    u32 unk_4;
};

struct fn_15_2D74_bss1 {
    u8 pad_0[0x8];
    struct fn_15_2D74_rec *unk_8;
};

struct fn_15_2D74_root {
    struct fn_15_2D74_bss1 *unk_0;
};

extern f32 fn_1_A71AC(void);
extern struct fn_15_2D74_D0 lbl_15_rodata_D0;
extern struct fn_15_2D74_D8 lbl_15_rodata_D8;
extern struct fn_15_2D74_bss0 lbl_15_bss_0;
extern struct fn_15_2D74_root lbl_1_bss_38458;
extern u32 fn_1_129D9C(void *, void *, u32, u32, u32, u32, u32, f32);
extern void lbl_8006D7DC(void *);
extern void lbl_8006DB74(void *);
extern void lbl_8006DFC4(void *);

void fn_15_2D74(u32 arg0) {
    u8 *obj;
    u32 *list;
    s16 i;
    u32 tbl[2];
    struct fn_15_2D74_root *q;
    u32 vec[3];
    u32 mtx[13];
    f32 v;
    struct fn_15_2D74_bss0 *p;
    u8 *sub;
    u8 *t;

    p = (struct fn_15_2D74_bss0 *)&lbl_15_bss_0;
    tbl[0] = lbl_15_rodata_D0.unk_0;
    tbl[1] = lbl_15_rodata_D0.unk_4;
    vec[0] = lbl_15_rodata_D8.unk_0;
    vec[1] = lbl_15_rodata_D8.unk_4;
    vec[2] = lbl_15_rodata_D8.unk_8;
    v = fn_1_A71AC();
    list = (u32 *)((u8 *)p + 0x9c);
    i = 0;
    q = (struct fn_15_2D74_root *)&lbl_1_bss_38458;
    while (i < p->unk_38) {
        obj = (u8 *)*list;
        sub = *(u8 **)(obj + 0x150);
        t = *(u8 **)(sub + 8);
        lbl_8006D7DC(obj + 0xa8);
        lbl_8006DFC4(t + 0x214);
        lbl_8006DB74(mtx);
        fn_1_129D9C(mtx, vec, 0,
                    q->unk_0->unk_8[((s16 *)tbl)[p->unk_2C[0x194 + i]]].unk_0,
                    0, 0, 1, v);
        list++;
        i++;
    }
}
/* fzgx:end fn_15_2D74 */

/* fzgx:begin fn_15_2E8C pool */
struct fn_15_2E8C_bss0 {
    u8 pad_0[0x2C];
    u8 *unk_2C;
    u8 pad_30[0x8];
    s16 unk_38;
    u8 pad_3A[0x92];
    u16 unk_CC;
    u16 unk_CE;
    u8 unk_D0;
    u8 pad_D1[0x7B];
    s16 unk_14C;
};

extern u8 jumptable_15_data_1DC[100];
extern s32 fn_1_12CB04(s16);
extern s16 fn_1_12CCB0(s16, s16);
extern u32 fn_1_8E4A4(u32, u32, u32);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u16 lbl_15_bss_0;
u16 fzgx_pool_gap_bss_2;
u32 lbl_15_bss_4[2];
u32 lbl_15_bss_C;
u32 lbl_15_bss_10;
u32 lbl_15_bss_14[2];
u32 lbl_15_bss_1C;
u8 lbl_15_bss_1C__fzgx_offset_4;
u8 lbl_15_bss_21;
u16 lbl_15_bss_21__fzgx_offset_1;
u32 lbl_15_bss_21__fzgx_offset_3[2];
u8 *lbl_15_bss_2C;
u32 lbl_15_bss_2C__fzgx_offset_4;
u8 lbl_15_bss_2C__fzgx_offset_8;
u8 fzgx_obj_lbl_15_bss_35;
u16 lbl_15_bss_35__fzgx_offset_1;
s16 lbl_15_bss_35__fzgx_offset_3;
u16 lbl_15_bss_35__fzgx_offset_5;
u32 lbl_15_bss_35__fzgx_offset_7[14];
u32 lbl_15_bss_74;
u32 lbl_15_bss_78[4];
u32 lbl_15_bss_88[5];
u32 fzgx_obj_lbl_15_bss_9C[12];
u16 lbl_15_bss_9C__fzgx_offset_30;
u16 lbl_15_bss_9C__fzgx_offset_32;
u8 lbl_15_bss_D0;
u8 fzgx_pool_gap_bss_D1;
u16 fzgx_pool_gap_bss_D2;
u8 lbl_15_bss_D4;
u8 lbl_15_bss_D4__fzgx_offset_1;
u16 lbl_15_bss_D4__fzgx_offset_2;
u32 lbl_15_bss_D4__fzgx_offset_4[29];
s16 lbl_15_bss_D4__fzgx_offset_78;
u16 lbl_15_bss_D4__fzgx_offset_7A;
u32 lbl_15_bss_D4__fzgx_offset_7C;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_15_bss_0;
    s = *(u8 *)&fzgx_pool_gap_bss_2;
    s = *(u8 *)&lbl_15_bss_4;
    s = *(u8 *)&lbl_15_bss_C;
    s = *(u8 *)&lbl_15_bss_10;
    s = *(u8 *)&lbl_15_bss_14;
    s = *(u8 *)&lbl_15_bss_1C;
    s = *(u8 *)&lbl_15_bss_1C__fzgx_offset_4;
    s = *(u8 *)&lbl_15_bss_21;
    s = *(u8 *)&lbl_15_bss_21__fzgx_offset_1;
    s = *(u8 *)&lbl_15_bss_21__fzgx_offset_3;
    s = *(u8 *)&lbl_15_bss_2C;
    s = *(u8 *)&lbl_15_bss_2C__fzgx_offset_4;
    s = *(u8 *)&lbl_15_bss_2C__fzgx_offset_8;
    s = *(u8 *)&fzgx_obj_lbl_15_bss_35;
    s = *(u8 *)&lbl_15_bss_35__fzgx_offset_1;
    s = *(u8 *)&lbl_15_bss_35__fzgx_offset_3;
    s = *(u8 *)&lbl_15_bss_35__fzgx_offset_5;
    s = *(u8 *)&lbl_15_bss_35__fzgx_offset_7;
    s = *(u8 *)&lbl_15_bss_74;
    s = *(u8 *)&lbl_15_bss_78;
    s = *(u8 *)&lbl_15_bss_88;
    s = *(u8 *)&fzgx_obj_lbl_15_bss_9C;
    s = *(u8 *)&lbl_15_bss_9C__fzgx_offset_30;
    s = *(u8 *)&lbl_15_bss_9C__fzgx_offset_32;
    s = *(u8 *)&lbl_15_bss_D0;
    s = *(u8 *)&fzgx_pool_gap_bss_D1;
    s = *(u8 *)&fzgx_pool_gap_bss_D2;
    s = *(u8 *)&lbl_15_bss_D4;
    s = *(u8 *)&lbl_15_bss_D4__fzgx_offset_1;
    s = *(u8 *)&lbl_15_bss_D4__fzgx_offset_2;
    s = *(u8 *)&lbl_15_bss_D4__fzgx_offset_4;
    s = *(u8 *)&lbl_15_bss_D4__fzgx_offset_78;
    s = *(u8 *)&lbl_15_bss_D4__fzgx_offset_7A;
    s = *(u8 *)&lbl_15_bss_D4__fzgx_offset_7C;
}
#pragma section code_type ".text"

void fn_15_2E8C(void) {
    u8 *rec;
    s16 k;
    s16 c;
    s16 i;
    u32 *q;
    u8 *e;
    u8 f;
    s16 cnt;
    s16 n;
    s16 r;
    u32 acc;

    
    i = 0;
    q = (u32 *)((u8 *)&lbl_15_bss_D4);
    lbl_15_bss_9C__fzgx_offset_32 = 0;
    rec = lbl_15_bss_2C;
    lbl_15_bss_9C__fzgx_offset_30 = 0;
    lbl_15_bss_D0 = 0;

    for (; i < 0x16; i += 7) {
        q[0] = 0;
        q[1] = 0;
        q[2] = 0;
        q[3] = 0;
        q[4] = 0;
        q[5] = 0;
        q[6] = 0;
        q += 7;
    }
    q = (u32 *)((u8 *)&lbl_15_bss_D4) + i;
    for (; i < 0x1D; i++) {
        *q++ = 0;
    }

    cnt = lbl_15_bss_35__fzgx_offset_3;
    e = rec;
    acc = 0;
    for (n = 0; n < cnt; n++) {
        f = e[5];
        switch (f) {
        case 19:
            acc += 3;
            break;
        case 30:
            acc += 1;
            break;
        case 34:
            if (n == 0) {
                acc += 6;
            } else {
                acc += 3;
            }
            break;
        case 40:
            acc += 1;
            break;
        case 16:
            acc += 2;
            break;
        }
        e += 8;
    }
    lbl_15_bss_D4__fzgx_offset_78 = 26 - (u8)acc;

    for (k = 0; k < lbl_15_bss_D4__fzgx_offset_78; k++) {
        e = rec + ((k + lbl_15_bss_35__fzgx_offset_3) << 3);
        c = e[5];
        if (c >= 41) {
            c = *((u8 *)(*(u8 **)e) + 0x81A0);
        }
        r = fn_1_12CB04(c);
        switch (r) {
        case 2:
            lbl_15_bss_D0 = 1;
            fn_1_8E4A4(c, 0x10000000, 0x80000000);
            fn_1_8E4A4(fn_1_12CCB0(c, 0), 0x10000000, 0x80000000);
            fn_1_8E4A4(fn_1_12CCB0(c, 1), 0x10000000, 0x80000000);
            break;
        case 1:
            fn_1_8E4A4(c, 0x10000000, 0x80000000);
            fn_1_8E4A4(fn_1_12CCB0(c, 0), 0x10000000, 0x80000000);
            break;
        case 0:
            fn_1_8E4A4(c, 0x10000000, 0x80000000);
            break;
        }
    }
}
/* fzgx:end fn_15_2E8C */

/* fzgx:begin fn_15_30E8 */
extern struct fn_15_30E8_lbl_15_bss_0 lbl_15_bss_0;
extern void fn_15_3368(s16);

struct fn_15_30E8_entry {
    u32 unk_0;
    u8 unk_4;
    u8 value;
    u8 unk_6[2];
};

struct fn_15_30E8_object {
    u8 unk_0[0x81a0];
    u8 value;
};

struct fn_15_30E8_lbl_15_bss_0 {
    u8 unk_0[0x2c];
    struct fn_15_30E8_entry *entries;
    u8 unk_30[8];
    s16 entry_offset;
    u8 unk_3a[0x112];
    s16 entry_count;
};

void fn_15_30E8(void) {
    struct fn_15_30E8_lbl_15_bss_0 *state;
    struct fn_15_30E8_entry *entry;
    s32 i;
    s16 value;

    state = &lbl_15_bss_0;
    entry = state->entries;
    i = 0;
    while (i < state->entry_count) {
        value = entry[i + state->entry_offset].value;
        if ((s16)value >= 0x29) {
            value = ((struct fn_15_30E8_object *)entry[i + state->entry_offset].unk_0)->value;
        }
        fn_15_3368((s16)value);
        i++;
    }
}
/* fzgx:end fn_15_30E8 */

/* fzgx:begin fn_15_3174 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
}
static const u32 fzgx_pool_table2[21] = {0x00FF00FF, 0x808080FF, 0xFFFFFFFF, 0xC3ACEF3B, 0x43FC728F, 0x44241408, 0xC3AD35A2, 0x43FE58B4, 0x44243FBE, 0x00000000, 0x3F800000, 0x00000000, 0xC3ACEF3B, 0x43FC728F, 0x44241408, 0xC3AD35A2, 0x43FE58B4, 0x44243FBE, 0x00000000, 0x3F800000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 200.0f;
    s = 1.0f;
}
static const u32 fzgx_pool_table4[1] = {0xFFC800FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 30.0f;
    d = 0.01;
    s = 2.0f;
    s = 320.0f;
    s = 240.0f;
    s = 20.0f;
    s = 10.0f;
    s = 0.5f;
    s = 3.0f;
    s = 0.03999999910593033f;
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table6[3] = {0x00000000, 0x00000000, 0x43480000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.6000000238418579f;
}
static const u32 fzgx_pool_table8[8] = {0x000000FF, 0x404040FF, 0x404088FF, 0xAAAAAAFF, 0xFF0000FF, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.5f;
    s = -0.8999999761581421f;
}
static const u32 fzgx_pool_table10[5] = {0x00000003, 0x00040006, 0x00000000, 0x3F800000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -1.5f;
    s = -2.25f;
    s = -2.0f;
    s = 0.20000000298023224f;
    s = -0.20000000298023224f;
    s = -2.200000047683716f;
    s = 9.0f;
}
#pragma section code_type ".text"

struct fn_15_3174_lbl_15_rodata_0 {
    f32 unk_0;
    u8 pad_4[0x58];
    f32 unk_5C;
    u8 pad_60[0x24];
    f32 unk_84;
    u8 pad_88[0x8];
    f64 unk_90;
    u8 pad_98[0x30];
    f32 unk_C8;
    u8 pad_CC[0x18];
    f32 unk_E4;
    f32 unk_E8;
    f32 unk_EC;
    f32 unk_F0;
    f32 unk_F4;
    f32 unk_F8;
};
struct fn_15_3174_lbl_1_data_2A7E0 {
    u8 pad_0[0x3C];
    u32 unk_3C;
};

extern struct fn_15_3174_lbl_15_rodata_0 lbl_15_rodata_0;
extern struct fn_15_3174_lbl_1_data_2A7E0 lbl_1_data_2A7E0;
extern u8 lbl_15_bss_D0;
extern void lbl_8006D7DC(void *);
extern void lbl_8006E1B0(void *, void *);

#pragma opt_propagation off
#pragma opt_lifetimes off
void fn_15_3174(void * arg0) {
    struct fn_15_3174_lbl_15_rodata_0 *p_lbl_15_rodata_0;
    u8 v0;
    u32 v1;
    s16 v2;
    f32 v3;
    f32 v4;
    f32 v5;
    f32 v6;
    f32 v7;
    f32 v8;
    f32 v9;
    f32 v11;
    f32 v10;
    u32 v12;
    f32 v13;
    f32 v14;
    f32 v15;
    void * v16;
    p_lbl_15_rodata_0 = (struct fn_15_3174_lbl_15_rodata_0 *)&lbl_15_rodata_0;
    v0 = *(u8 *)((u8 *)arg0 + 1220);
    v1 = lbl_1_data_2A7E0.unk_3C;
    v2 = (s16)v0;
    if (v2 < 8) {
    v3 = (0.0f);
    *(f32 *)((u8 *)arg0 + 168) = (f32)((-1.5f) + (f32)((0.5f) * (f32)(s32)v2));
    *(f32 *)((u8 *)arg0 + 172) = v3;
    *(f32 *)((u8 *)arg0 + 176) = v3;
    } else {
    if (v2 < 17) {
    v4 = (0.5f);
    v5 = (0.0f);
    *(f32 *)((u8 *)arg0 + 168) = (f32)((-2.25f) + (f32)(v4 * (f32)(s32)(v2 - 8)));
    *(f32 *)((u8 *)arg0 + 172) = v5;
    *(f32 *)((u8 *)arg0 + 176) = v4;
    } else {
    if (v2 < 26) {
    v6 = (0.0f);
    v7 = (1.0f);
    *(f32 *)((u8 *)arg0 + 168) = (f32)((-2.0f) + (f32)((0.5f) * (f32)(s32)(v2 - 17)));
    *(f32 *)((u8 *)arg0 + 172) = v6;
    *(f32 *)((u8 *)arg0 + 176) = v7;
    } else {
    v8 = (0.5f);
    v9 = (-2.25f);
    v10 = (1.5f);
    v11 = (0.200000003f);
    *(f32 *)((u8 *)arg0 + 168) = (f32)(v9 + (f32)(v8 * (f32)(s32)(v2 - 26)));
    *(f32 *)((u8 *)arg0 + 172) = v11;
    *(f32 *)((u8 *)arg0 + 176) = v10;
    }
    }
    }
    v12 = *(u32 *)((u8 *)arg0 + 136);
    if ((s32)v12 == 33 || (s32)v12 == 42 || (s32)v12 == 43) {
    v13 = (0.0f);
    *(f32 *)((u8 *)arg0 + 168) = (-2.20000005f);
    v14 = (-0.200000003f);
    *(f32 *)((u8 *)arg0 + 172) = v13;
    *(f32 *)((u8 *)arg0 + 176) = v14;
    }
    if ((s16)v0 == 26 && lbl_15_bss_D0 == 0) {
    v15 = (0.0f);
    *(f32 *)((u8 *)arg0 + 168) = (-2.0f);
    *(f32 *)((u8 *)arg0 + 172) = v15;
    *(f32 *)((u8 *)arg0 + 176) = v15;
    }
    lbl_8006D7DC((void *)(v1 + 16));
    v16 = (void *)(((u8 *)arg0 + 168));
    lbl_8006E1B0((void *)v16, (void *)v16);
    *(f32 *)((u8 *)arg0 + 184) = (1.0f);
}
#pragma opt_lifetimes reset

#pragma opt_propagation reset
/* fzgx:end fn_15_3174 */

/* fzgx:begin fn_15_398C */
struct fn_15_398C_entry {
    u8 pad_0[0x18];
    u32 flags;
};

struct fn_15_398C_state {
    u8 pad_0[0x14];
    u32 flags;
    u8 pad_18[0x84];
    struct fn_15_398C_entry *entries_9c[0xd4 / 4 - 0x9c / 4];
    struct fn_15_398C_entry *entries_d4[0x1d];
};

extern struct fn_15_398C_state lbl_15_bss_0;

void fn_15_398C(void) {
    struct fn_15_398C_state *s;
    struct fn_15_398C_entry **p;
    struct fn_15_398C_entry *entry;
    s16 i;

    s = &lbl_15_bss_0;
    s->flags |= 0x04000000;
    p = &s->entries_9c[0];
    for (i = 0; i < 0xc; i++) {
        entry = *p;
        if (entry != 0) {
            entry->flags &= 0x3FFFFFFF;
        }
        p++;
    }
    p = &s->entries_d4[0];
    for (i = 0; i < 0x1d; i++) {
        entry = *p;
        if (entry != 0) {
            entry->flags &= 0x3FFFFFFF;
        }
        p++;
    }
}
/* fzgx:end fn_15_398C */

/* fzgx:begin fn_15_3A14 */
extern struct fn_15_3A14_lbl_15_bss_74 lbl_15_bss_74;
extern struct fn_15_3A14_lbl_15_bss_78 lbl_15_bss_78;
extern u32 fn_1_3F8C(u32, u32, u32, u32);
extern u32 fn_1_435C(u32);
extern u32 fn_1_7ACDC(u32);
extern u32 fn_1_7EAE8(void);
extern u8 lbl_15_data_0[];
extern void fn_1_789E8(void);
extern void fn_1_78EBC(void);
extern void fn_1_7E9C4(void);
extern void fn_1_9A5CC(void);
extern void fn_1_9A7BC(void);

struct fn_15_3A14_lbl_15_bss_74 {
    u32 unk_0;
};
struct fn_15_3A14_lbl_15_bss_78 {
    u32 unk_0;
};

void fn_15_3A14(void) {
    u8 *p_lbl_15_data_0;
    p_lbl_15_data_0 = (u8 *)&lbl_15_data_0;
    fn_1_435C(lbl_15_bss_74.unk_0);
    fn_1_3F8C((u32)((u8 *)p_lbl_15_data_0 + 608), (u32)fn_1_789E8, 0, 21);
    fn_1_3F8C((u32)((u8 *)p_lbl_15_data_0 + 620), (u32)fn_1_9A5CC, 0, 23);
    fn_1_435C(lbl_15_bss_78.unk_0);
    fn_1_3F8C((u32)((u8 *)p_lbl_15_data_0 + 636), (u32)fn_1_7E9C4, 0, 4);
    fn_1_3F8C((u32)((u8 *)p_lbl_15_data_0 + 644), (u32)fn_1_7EAE8, 0, 29);
    fn_1_3F8C((u32)((u8 *)p_lbl_15_data_0 + 652), (u32)fn_1_78EBC, 0, 7);
    fn_1_3F8C((u32)((u8 *)p_lbl_15_data_0 + 664), (u32)fn_1_9A7BC, 0, 10);
    fn_1_7EAE8();
    fn_1_7ACDC(50);
}
/* fzgx:end fn_15_3A14 */

/* fzgx:begin fn_15_3AFC */
// fn_15_3AFC: empty in retail (single blr).
void fn_15_3AFC(void) {
}
/* fzgx:end fn_15_3AFC */

/* fzgx:begin fn_15_3B00 */
extern u32 fn_1_79100(void);
extern u32 fn_1_7EAE8(u32);

void fn_15_3B00(void) {
    u32 t0;
    t0 = fn_1_79100();
    fn_1_7EAE8(t0);
}
/* fzgx:end fn_15_3B00 */

/* fzgx:begin fn_15_401C */
extern u32 fn_1_C6F80(u32);
extern u32 lbl_15_bss_14;

u32 fn_15_401C(u32 arg0) {
    u32 v0;
    u32 t0, t1;
    v0 = arg0;
    if ((lbl_15_bss_14 & 0x40000000) != 0) {
    v0 = 1;
    t0 = fn_1_C6F80(v0);
    v0 = t0;
    } else {
    v0 = 0;
    t1 = fn_1_C6F80(v0);
    v0 = t1;
    }
    return v0;
}
/* fzgx:end fn_15_401C */

/* fzgx:begin fn_15_405C */
// fn_15_405C: empty in retail (single blr).
void fn_15_405C(void) {
}
/* fzgx:end fn_15_405C */

/* fzgx:begin fn_15_4060 */
extern struct fn_15_4060_lbl_15_bss_0 lbl_15_bss_0;
extern struct fn_15_4060_lbl_801A6410 lbl_801A6410;
extern u32 fn_1_41A8(u32);
extern u32 fn_1_435C(u32);
extern u32 fn_1_46B4(u32, u32, void *, u32);
extern u32 fn_1_58854(u32);
extern u32 fn_1_85878(void);
extern u32 fn_1_982C4(u32);
extern u32 fn_1_C47B4(u32);
extern u32 fn_1_C6F80(u32);
extern u32 lbl_15_data_A4;

struct fn_15_4060_lbl_15_bss_0 {
    u8 pad_0[0x21];
    u8 unk_21;
    u8 pad_22[0x2];
    u32 unk_24;
    u32 unk_28;
    u8 pad_2C[0x124];
    u32 unk_150;
};
struct fn_15_4060_lbl_801A6410 {
    u32 unk_0;
};

void fn_15_4060(void) {
    struct fn_15_4060_lbl_15_bss_0 *p_lbl_15_bss_0;
    u32 t0, t1, t2, t6, t8;
    p_lbl_15_bss_0 = (struct fn_15_4060_lbl_15_bss_0 *)&lbl_15_bss_0;
    t0 = fn_1_85878();
    t1 = fn_1_982C4(t0);
    t2 = fn_1_58854(t1);
    fn_1_C47B4(t2);
    fn_1_C6F80(0);
    fn_1_46B4(lbl_801A6410.unk_0, p_lbl_15_bss_0->unk_150, &lbl_15_data_A4, 2849);
    t6 = fn_1_435C(p_lbl_15_bss_0->unk_24);
    fn_1_41A8(t6);
    t8 = fn_1_435C(p_lbl_15_bss_0->unk_28);
    fn_1_41A8(t8);
    fn_1_46B4(lbl_801A6410.unk_0, p_lbl_15_bss_0->unk_24, &lbl_15_data_A4, 2854);
    fn_1_46B4(lbl_801A6410.unk_0, p_lbl_15_bss_0->unk_28, &lbl_15_data_A4, 2855);
    p_lbl_15_bss_0->unk_21 = 0;
}
/* fzgx:end fn_15_4060 */

/* fzgx:begin fn_15_435C */
#include "rel/main_rel/camera.h"

struct fn_15_435C_lbl_15_rodata_0 {
    u8 pad_0[0x70];
    f32 unk_70;
    u8 pad_74[0xC];
    f32 unk_80;
    f32 unk_84;
    u8 pad_88[0x90];
    u32 unk_118;
    u32 unk_11C;
    u32 unk_120;
    f32 unk_124;
};

struct fn_15_435C_lbl_15_bss_0 {
    u8 pad_0[0x38];
    s16 unk_38;
    u8 pad_3A[0x32];
    u32 unk_6C;
    u32 unk_70;
    u8 pad_74[0x24];
    s16 unk_98;
    u8 pad_9A[2];
    u32 unk_9C[1];
};

struct fn_15_435C_lbl_15_data_0 {
    u8 pad_0[0x50];
    u32 unk_50[0x2D];
    u8 pad_104[0x1D0];
    char unk_2D4[0x14];
    char unk_2E8[0x10];
    char unk_2F8[0x10];
    char unk_308[0x10];
    char unk_318[0x20];
    char unk_338[0x2C];
    char unk_364[0x40];
};

struct fn_15_435C_cam {
    u8 pad_0[0x1C];
    f32 unk_1C;
};

struct fn_15_435C_elem {
    u8 pad_0[0x88];
    u32 unk_88;
};

extern struct fn_15_435C_lbl_15_rodata_0 lbl_15_rodata_0;
extern struct fn_15_435C_lbl_15_bss_0 lbl_15_bss_0;
extern struct fn_15_435C_lbl_15_data_0 lbl_15_data_0;
extern u32 lbl_1_data_20B14[];

extern CameraState * camera_get_state_object(void);
extern void fn_1_49410(void);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495FC(void);
extern void fn_1_496FC(f32, f32);
extern void fn_1_49514(u32 *);
extern s16 fn_1_12C930(s16);
extern s16 fn_1_12C710(int);
extern s16 fn_1_7F49C(s16, s16, void *);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_4A0D8(const char *);

#pragma opt_loop_invariants off
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_lifetimes off
void fn_15_435C(void) {
    u32 buf[8];
    u32 v[6];
    struct fn_15_435C_lbl_15_rodata_0 *p_ro = &lbl_15_rodata_0;
    struct fn_15_435C_lbl_15_data_0 *p_data = &lbl_15_data_0;
    struct fn_15_435C_lbl_15_bss_0 *p_bss = &lbl_15_bss_0;
    struct fn_15_435C_cam *p_cam;
    struct fn_15_435C_elem **p_ent;
    u32 *p_tbl;
    s32 i;

    v[3] = p_ro->unk_118;
    v[4] = p_ro->unk_11C;
    v[5] = p_ro->unk_120;
    p_cam = (struct fn_15_435C_cam *)camera_get_state_object();
    fn_1_49410();
    fn_1_4954C(p_ro->unk_70);
    fn_1_4955C(p_ro->unk_84, p_ro->unk_84);
    fn_1_495FC();
    fn_1_496FC(p_ro->unk_80, p_ro->unk_124);
    v[0] = v[5];
    p_ent = (struct fn_15_435C_elem **)((u8 *)p_bss + 0x9C);
    i = 0;

    while (i < (s32)p_bss->unk_38 + 3) {
        if (i == (s32)p_bss->unk_6C) {
            v[2] = v[3];
            fn_1_49514(&v[2]);
        }
        else {
            v[1] = v[0];
            fn_1_49514(&v[1]);
        }

        if (i < (s32)p_bss->unk_38) {
            struct fn_15_435C_elem *p_e = *p_ent;
            u32 v_tbl = lbl_1_data_20B14[(s16)fn_1_12C930((s16)p_e->unk_88)];

            fn_1_7F49C(fn_1_12C710(p_e->unk_88), 5, buf);
            fn_1_4AE0C(p_data->unk_2D4, i + 1, v_tbl, buf);
        }
        else {
            switch (i - (s32)p_bss->unk_38) {
            case 0:
                p_tbl = p_data->unk_50;
                fn_1_4AE0C(p_data->unk_2E8, p_tbl[p_bss->unk_70]);
                break;
            case 1: {
                f32 f_live = p_cam->unk_1C;
                fn_1_4AE0C(p_data->unk_2F8, f_live);
                break;
            }
            case 2:
                switch (p_bss->unk_98 % 3) {
                case 0:
                    fn_1_4A0D8(p_data->unk_308);
                    break;
                case 1:
                    fn_1_4A0D8(p_data->unk_318);
                    break;
                default:
                    fn_1_4A0D8(p_data->unk_338);
                    break;
                }
                break;
            default:
                fn_1_4AE0C(p_data->unk_364);
                break;
            }
        }
        p_ent++;
        i++;
    }
}
#pragma opt_lifetimes reset
#pragma opt_propagation reset
#pragma opt_common_subs reset
#pragma opt_loop_invariants reset
/* fzgx:end fn_15_435C */

/* fzgx:begin fn_15_4568 */
extern u16 lbl_15_bss_154;

void fn_15_4568(void) {
    lbl_15_bss_154 = 0;
}
/* fzgx:end fn_15_4568 */

/* fzgx:begin fn_15_537C */
extern f32 lbl_15_bss_88[5];
extern u8 lbl_15_bss_3F8[136];
extern f32 lbl_15_rodata_0[25];
extern u32 lbl_15_rodata_19C[20];

extern void fn_1_7BCCC(void *);
extern void fn_80035680(void *, f32, f32, f32);
extern void fn_80035690(void *, f32, f32, f32);
extern void fn_80035420(void *, u32, f32);
extern void fn_800356AC(void *, void *);
extern void GXInitLightDistAttn(void *, f32, f32, u32);
extern void fn_1_7BB80(void *, u32);
extern void fn_1_7BD6C(u32);

void fn_15_537C(void) {
    u8 *p_lbl_15_bss_3F8;
    u32 local;
    f32 v;
    p_lbl_15_bss_3F8 = &lbl_15_bss_3F8[0];
    fn_1_7BCCC(&lbl_15_bss_88[0]);
    p_lbl_15_bss_3F8 = &lbl_15_bss_3F8[0];
    fn_80035680(p_lbl_15_bss_3F8, lbl_15_bss_88[0], lbl_15_bss_88[1], lbl_15_bss_88[2]);
    fn_80035690(p_lbl_15_bss_3F8, lbl_15_bss_88[0], lbl_15_bss_88[1], lbl_15_bss_88[2]);
    fn_80035420(&lbl_15_bss_3F8[0], 0, lbl_15_rodata_0[0]);
    local = lbl_15_rodata_19C[0];
    fn_800356AC(&lbl_15_bss_3F8[0], &local);
    GXInitLightDistAttn(&lbl_15_bss_3F8[0], 0.0f, 0.0f, 0);
    fn_1_7BB80(&lbl_15_bss_3F8[0], 1);
    fn_1_7BD6C(1);
}
/* fzgx:end fn_15_537C */

/* fzgx:begin fn_15_545C */
// fn_15_545C: empty in retail (single blr).
void fn_15_545C(void) {
}
/* fzgx:end fn_15_545C */

/* fzgx:begin fn_15_5460 */
#include "font.h"

struct fn_15_5460_Row { u32 a[4]; u32 name; u32 c; };

struct fn_15_5460_lbl_15_data_0 {
    u8 pad_0[0x1C80];
    u32 unk_1C80[36];
    u8 pad_1D10[0x40];
    u32 unk_1D50[24];
    u8 pad_1DB0[0xBC];
    u32 unk_1E6C[6];
    u8 pad_1E84[0x48];
    u32 unk_1ECC[6];
    u8 pad_1EE4[0x18];
    char unk_1EFC[4];
    u8 pad_1F00[0x70];
    char unk_1F70[8];
    char unk_1F78[5];
};

extern struct fn_15_5460_lbl_15_data_0 lbl_15_data_0;
extern u32 lbl_801A66B4[1];
extern u32 lbl_1_rodata_26F8;
extern u8 lbl_15_bss_35;

extern int fn_1_4F734(FontDrawPacket *);
extern u32 fn_1_141360(u32, u32, u32, u32, f32, f32);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_4955C(f32, f32);
extern void fn_1_49590(f32);
extern void fn_1_495A0(f32);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_52070(u32);
extern void fn_1_520A0(void);
extern void fn_1_520CC(void);

extern u8 fn_15_1D7C__fzgx_offset_0[];
extern u8 fn_15_1DF4__fzgx_offset_0[];
extern u8 fn_15_1EE0__fzgx_offset_0[];
extern u8 fn_15_2E8C__fzgx_offset_104[];
extern u8 fn_15_2E8C__fzgx_offset_10C[];
extern u8 fn_15_2E8C__fzgx_offset_110[];
extern u8 fn_15_2E8C__fzgx_offset_DC[];
extern u8 fn_15_2E8C__fzgx_offset_E4[];
extern u8 fn_15_2E8C__fzgx_offset_EC[];
extern u8 fn_15_3AC__fzgx_offset_0[];
extern u8 fn_15_4578__fzgx_offset_864[];
extern u8 fn_15_4578__fzgx_offset_86C[];
extern u8 fn_15_4578__fzgx_offset_874[];
extern u8 fn_15_4578__fzgx_offset_87C[];
extern u8 fn_15_4578__fzgx_offset_884[];
extern u8 fn_15_4578__fzgx_offset_88C[];
extern u8 fn_15_4578__fzgx_offset_894[];
extern u8 fn_15_4578__fzgx_offset_89C[];
extern u8 fn_15_4578__fzgx_offset_8A4[];
extern u8 fn_15_4578__fzgx_offset_8AC[];
extern u8 fn_15_4578__fzgx_offset_8B4[];
extern u8 fn_15_4578__fzgx_offset_8BC[];
extern u8 fn_15_4578__fzgx_offset_8C0[];
extern u8 fn_15_644__fzgx_offset_0[];
extern u8 fn_15_B8C__fzgx_offset_0[];
extern u8 lbl_15_data_0__fzgx_offset_0[];
extern u8 lbl_15_data_10__fzgx_offset_0[];
extern u8 lbl_15_data_18__fzgx_offset_0[];
extern u8 lbl_15_data_1C2C__fzgx_offset_0[];
extern u8 lbl_15_data_1C34__fzgx_offset_0[];
extern u8 lbl_15_data_1C40__fzgx_offset_0[];
extern u8 lbl_15_data_1C50__fzgx_offset_0[];
extern u8 lbl_15_data_1C5C__fzgx_offset_0[];
extern u8 lbl_15_data_1C68__fzgx_offset_0[];
extern u8 lbl_15_data_1C70__fzgx_offset_0[];
extern u8 lbl_15_data_1C74__fzgx_offset_0[];
extern u8 lbl_15_data_1C78__fzgx_offset_0[];
extern u8 lbl_15_data_1C7C__fzgx_offset_0[];
extern u8 lbl_15_data_1D10__fzgx_offset_0[];
extern u8 lbl_15_data_1D20__fzgx_offset_0[];
extern u8 lbl_15_data_1D30__fzgx_offset_0[];
extern u8 lbl_15_data_1D40__fzgx_offset_0[];
extern u8 lbl_15_data_1DB0__fzgx_offset_0[];
extern u8 lbl_15_data_1DCC__fzgx_offset_0[];
extern u8 lbl_15_data_1DF8__fzgx_offset_0[];
extern u8 lbl_15_data_1E0C__fzgx_offset_0[];
extern u8 lbl_15_data_1E24__fzgx_offset_0[];
extern u8 lbl_15_data_1E3C__fzgx_offset_0[];
extern u8 lbl_15_data_1E54__fzgx_offset_0[];
extern u8 lbl_15_data_1E84__fzgx_offset_0[];
extern u8 lbl_15_data_1E8C__fzgx_offset_0[];
extern u8 lbl_15_data_1E9C__fzgx_offset_0[];
extern u8 lbl_15_data_1EAC__fzgx_offset_0[];
extern u8 lbl_15_data_1EBC__fzgx_offset_0[];
extern u8 lbl_15_data_30__fzgx_offset_0[];
extern u8 lbl_15_data_38__fzgx_offset_0[];
extern u8 lbl_15_data_40__fzgx_offset_0[];
extern u8 lbl_15_data_48__fzgx_offset_0[];
extern u8 lbl_15_data_60__fzgx_offset_0[];
extern u8 lbl_15_data_68__fzgx_offset_0[];
extern u8 lbl_15_data_8__fzgx_offset_0[];
static u32 fzgx_pool_native_lbl_15_data_0_gap_0[1824] = {0x57494E5F, 0x31535400, 0x57494E5F, 0x324E4400, 0x57494E5F, 0x33524400, 0x57494E5F, 0x34544800, (u32)lbl_15_data_0__fzgx_offset_0, (u32)lbl_15_data_8__fzgx_offset_0, (u32)lbl_15_data_10__fzgx_offset_0, (u32)lbl_15_data_18__fzgx_offset_0, 0x424C4143, 0x4B000000, 0x47524159, 0x00000000, 0x424C5545, 0x00000000, 0x57484954, 0x453F0000, (u32)lbl_15_data_30__fzgx_offset_0, (u32)lbl_15_data_38__fzgx_offset_0, (u32)lbl_15_data_40__fzgx_offset_0, (u32)lbl_15_data_48__fzgx_offset_0, 0x6D656E75, 0x00000000, 0x77696E6E, 0x696E6700, (u32)lbl_15_data_60__fzgx_offset_0, (u32)fn_15_3AC__fzgx_offset_0, (u32)fn_15_644__fzgx_offset_0, (u32)fn_15_B8C__fzgx_offset_0, (u32)lbl_15_data_68__fzgx_offset_0, (u32)fn_15_1D7C__fzgx_offset_0, (u32)fn_15_1DF4__fzgx_offset_0, (u32)fn_15_1EE0__fzgx_offset_0, 0x00000000, 0x00001248, 0x000012FC, 0x0000137E, 0x000019C8, 0x77696E6E, 0x696E672E, 0x63000000, 0x50757368, 0x203C413E, 0x20746F20, 0x77696E6E, 0x696E6720, 0x72756E20, 0x6D6F6465, 0x210A0000, 0x4341523A, 0x2532642C, 0x20545950, 0x453A2532, 0x64200000, 0x20257328, 0x25732920, 0x0A000000, 0x53454C3A, 0x204F4E0A, 0x00000000, 0x53454C3A, 0x204F4646, 0x0A000000, 0x5345513A, 0x20474320, 0x57494E4E, 0x494E4720, 0x52554E0A, 0x00000000, 0x5345513A, 0x20474320, 0x5653203A, 0x20253164, 0x0A000000, 0x5345513A, 0x20414320, 0x3173740A, 0x00000000, 0x5345513A, 0x20414320, 0x454E440A, 0x00000000, 0x53746166, 0x66526F6C, 0x6C4D6169, 0x6E000000, 0x53746166, 0x66526F6C, 0x6C446973, 0x70000000, 0x57696E6E, 0x696E6743, 0x616C6300, 0x4C696768, 0x744D6169, 0x6E000000, 0x6D6F745F, 0x6C696768, 0x745F6361, 0x6C630000, 0x57696E6E, 0x696E6744, 0x69737000, 0x6D6F745F, 0x6C696768, 0x745F6469, 0x73700000, 0x526F6245, 0x78656300, 0x7365745F, 0x77696E6E, 0x65725F72, 0x616E6B00, 0x526F6244, 0x69737043, 0x6C697000, (u32)fn_15_2E8C__fzgx_offset_10C, (u32)fn_15_2E8C__fzgx_offset_110, (u32)fn_15_2E8C__fzgx_offset_110, (u32)fn_15_2E8C__fzgx_offset_DC, (u32)fn_15_2E8C__fzgx_offset_110, (u32)fn_15_2E8C__fzgx_offset_110, (u32)fn_15_2E8C__fzgx_offset_110, (u32)fn_15_2E8C__fzgx_offset_110, (u32)fn_15_2E8C__fzgx_offset_110, (u32)fn_15_2E8C__fzgx_offset_110, (u32)fn_15_2E8C__fzgx_offset_110, (u32)fn_15_2E8C__fzgx_offset_110, (u32)fn_15_2E8C__fzgx_offset_110, (u32)fn_15_2E8C__fzgx_offset_110, (u32)fn_15_2E8C__fzgx_offset_E4, (u32)fn_15_2E8C__fzgx_offset_110, (u32)fn_15_2E8C__fzgx_offset_110, (u32)fn_15_2E8C__fzgx_offset_110, (u32)fn_15_2E8C__fzgx_offset_EC, (u32)fn_15_2E8C__fzgx_offset_110, (u32)fn_15_2E8C__fzgx_offset_110, (u32)fn_15_2E8C__fzgx_offset_110, (u32)fn_15_2E8C__fzgx_offset_110, (u32)fn_15_2E8C__fzgx_offset_110, (u32)fn_15_2E8C__fzgx_offset_104, 0x57494E5F, 0x57414954, 0x00000000, 0x7365745F, 0x6F746865, 0x725F726F, 0x625F706F, 0x73000000, 0x53746167, 0x6543616C, 0x63000000, 0x4261636B, 0x47726F75, 0x6E644361, 0x6C630000, 0x466F674D, 0x61696E00, 0x466F674F, 0x66660000, 0x53746167, 0x65446973, 0x70000000, 0x4261636B, 0x47726F75, 0x6E644469, 0x73700000, 0x4275726E, 0x65720000, 0x4275726E, 0x65724469, 0x73700000, 0x456E656D, 0x79546F74, 0x616C436F, 0x6E74726F, 0x6C4D6169, 0x6E000000, 0x25316488, 0xCA203A20, 0x25732825, 0x7329200A, 0x00000000, 0x94778C69, 0x20814620, 0x2573200A, 0x00000000, 0x8370815B, 0x83583A20, 0x25352E32, 0x660A0000, 0x42474D3A, 0x2081F495, 0x5C8FB241, 0x43000000, 0x42474D3A, 0x2081F495, 0x5C8FB247, 0x43208345, 0x8343836A, 0x8393834F, 0x83898393, 0x00000000, 0x42474D3A, 0x2081F483, 0x74834083, 0x8B835283, 0x9382CC83, 0x65815B83, 0x7D816941, 0x43834783, 0x93836683, 0x42839383, 0x4F816A00, 0x44554D4D, 0x590A0000, 0x006400C8, 0x3DCCCCCD, 0x3D8F5C29, 0x00000000, 0x442F0000, 0x00000000, 0xFFFF4D55, 0x54454349, 0x54590000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3DB851EC, 0x3DA3D70A, 0x00000000, 0x442F0000, 0x42700000, 0xFFFF5241, 0x4E4B0000, 0x00000000, 0x00000000, 0x00000000, 0x00003100, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3DA3D70A, 0x3DB851EC, 0x00000000, 0x442F0000, 0x42B40000, 0xFFFF5449, 0x4D450000, 0x00000000, 0x00000000, 0x00000000, 0x00003031, 0x27353922, 0x39383000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3D99999A, 0x3DCCCCCD, 0x00000000, 0x442F0000, 0x42F00000, 0xFFFF4245, 0x5354204C, 0x41500000, 0x00000000, 0x00000000, 0x00003030, 0x27313222, 0x38383200, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3D8F5C29, 0x3DE147AE, 0x00000000, 0x442F0000, 0x43160000, 0xFFFF4D41, 0x58205350, 0x45454400, 0x00000000, 0x00000000, 0x00003130, 0x32340000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3D851EB8, 0x3E051EB8, 0x00000000, 0x442F0000, 0x43340000, 0xFFFF504F, 0x494E5453, 0x00000000, 0x00000000, 0x00000000, 0x00003938, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3D75C28F, 0x3E23D70A, 0x00000000, 0x442F0000, 0x43520000, 0xFFFF4154, 0x5441434B, 0x00000000, 0x00000000, 0x00000000, 0x00004E4F, 0x4E450000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x006400C8, 0x3DCCCCCD, 0x3D8F5C29, 0x00000000, 0x442F0000, 0x00000000, 0xFFFF4D55, 0x54454349, 0x54590000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3DB851EC, 0x3DA3D70A, 0x00000000, 0x442F0000, 0x42700000, 0xFFFF5241, 0x4E4B0000, 0x00000000, 0x00000000, 0x00000000, 0x00003100, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3DA3D70A, 0x3DB851EC, 0x00000000, 0x442F0000, 0x42B40000, 0xFFFF5449, 0x4D450000, 0x00000000, 0x00000000, 0x00000000, 0x00003031, 0x27353922, 0x39383000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3D99999A, 0x3DCCCCCD, 0x00000000, 0x442F0000, 0x42F00000, 0xFFFF4245, 0x5354204C, 0x41500000, 0x00000000, 0x00000000, 0x00003030, 0x27313222, 0x38383200, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3D8F5C29, 0x3DE147AE, 0x00000000, 0x442F0000, 0x43160000, 0xFFFF4D41, 0x58205350, 0x45454400, 0x00000000, 0x00000000, 0x00003130, 0x32340000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3D851EB8, 0x3E051EB8, 0x00000000, 0x442F0000, 0x43340000, 0xFFFF504F, 0x494E5453, 0x00000000, 0x00000000, 0x00000000, 0x00003938, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3D75C28F, 0x3E23D70A, 0x00000000, 0x442F0000, 0x43520000, 0xFFFF4154, 0x5441434B, 0x00000000, 0x00000000, 0x00000000, 0x00004E4F, 0x4E450000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x006400C8, 0x3DCCCCCD, 0x3D8F5C29, 0x00000000, 0x442F0000, 0x00000000, 0xFFFF4D55, 0x54454349, 0x54590000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3DB851EC, 0x3DA3D70A, 0x00000000, 0x442F0000, 0x42700000, 0xFFFF5241, 0x4E4B0000, 0x00000000, 0x00000000, 0x00000000, 0x00003100, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3DA3D70A, 0x3DB851EC, 0x00000000, 0x442F0000, 0x42B40000, 0xFFFF5449, 0x4D450000, 0x00000000, 0x00000000, 0x00000000, 0x00003031, 0x27353922, 0x39383000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3D99999A, 0x3DCCCCCD, 0x00000000, 0x442F0000, 0x42F00000, 0xFFFF4245, 0x5354204C, 0x41500000, 0x00000000, 0x00000000, 0x00003030, 0x27313222, 0x38383200, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3D8F5C29, 0x3DE147AE, 0x00000000, 0x442F0000, 0x43160000, 0xFFFF4D41, 0x58205350, 0x45454400, 0x00000000, 0x00000000, 0x00003130, 0x32340000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3D851EB8, 0x3E051EB8, 0x00000000, 0x442F0000, 0x43340000, 0xFFFF504F, 0x494E5453, 0x00000000, 0x00000000, 0x00000000, 0x00003938, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3D75C28F, 0x3E23D70A, 0x00000000, 0x442F0000, 0x43520000, 0xFFFF4154, 0x5441434B, 0x00000000, 0x00000000, 0x00000000, 0x00004E4F, 0x4E450000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x006400C8, 0x3DCCCCCD, 0x3D8F5C29, 0x00000000, 0x442F0000, 0x00000000, 0xFFFF4D55, 0x54454349, 0x54590000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3DB851EC, 0x3DA3D70A, 0x00000000, 0x442F0000, 0x42700000, 0xFFFF5241, 0x4E4B0000, 0x00000000, 0x00000000, 0x00000000, 0x00003100, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3DA3D70A, 0x3DB851EC, 0x00000000, 0x442F0000, 0x42B40000, 0xFFFF5449, 0x4D450000, 0x00000000, 0x00000000, 0x00000000, 0x00003031, 0x27353922, 0x39383000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3D99999A, 0x3DCCCCCD, 0x00000000, 0x442F0000, 0x42F00000, 0xFFFF4245, 0x5354204C, 0x41500000, 0x00000000, 0x00000000, 0x00003030, 0x27313222, 0x38383200, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3D8F5C29, 0x3DE147AE, 0x00000000, 0x442F0000, 0x43160000, 0xFFFF4D41, 0x58205350, 0x45454400, 0x00000000, 0x00000000, 0x00003130, 0x32340000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3D851EB8, 0x3E051EB8, 0x00000000, 0x442F0000, 0x43340000, 0xFFFF504F, 0x494E5453, 0x00000000, 0x00000000, 0x00000000, 0x00003938, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3D75C28F, 0x3E23D70A, 0x00000000, 0x442F0000, 0x43520000, 0xFFFF4154, 0x5441434B, 0x00000000, 0x00000000, 0x00000000, 0x00004E4F, 0x4E450000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x006400C8, 0x3DCCCCCD, 0x3D8F5C29, 0x00000000, 0x442F0000, 0x00000000, 0xFFFF4D55, 0x54454349, 0x54590000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3DB851EC, 0x3DA3D70A, 0x00000000, 0x442F0000, 0x42700000, 0xFFFF5241, 0x4E4B0000, 0x00000000, 0x00000000, 0x00000000, 0x00003100, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3DA3D70A, 0x3DB851EC, 0x00000000, 0x442F0000, 0x42B40000, 0xFFFF5449, 0x4D450000, 0x00000000, 0x00000000, 0x00000000, 0x00003031, 0x27353922, 0x39383000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3D99999A, 0x3DCCCCCD, 0x00000000, 0x442F0000, 0x42F00000, 0xFFFF4245, 0x5354204C, 0x41500000, 0x00000000, 0x00000000, 0x00003030, 0x27313222, 0x38383200, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3D8F5C29, 0x3DE147AE, 0x00000000, 0x442F0000, 0x43160000, 0xFFFF4D41, 0x58205350, 0x45454400, 0x00000000, 0x00000000, 0x00003130, 0x32340000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3D851EB8, 0x3E051EB8, 0x00000000, 0x442F0000, 0x43340000, 0xFFFF504F, 0x494E5453, 0x00000000, 0x00000000, 0x00000000, 0x00003938, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3D75C28F, 0x3E23D70A, 0x00000000, 0x442F0000, 0x43520000, 0xFFFF4154, 0x5441434B, 0x00000000, 0x00000000, 0x00000000, 0x00004E4F, 0x4E450000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x006400C8, 0x3DCCCCCD, 0x3D8F5C29, 0x00000000, 0x442F0000, 0x00000000, 0xFFFF4D55, 0x54454349, 0x54590000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3DB851EC, 0x3DA3D70A, 0x00000000, 0x442F0000, 0x42700000, 0xFFFF5241, 0x4E4B0000, 0x00000000, 0x00000000, 0x00000000, 0x00003100, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3DA3D70A, 0x3DB851EC, 0x00000000, 0x442F0000, 0x42B40000, 0xFFFF5449, 0x4D450000, 0x00000000, 0x00000000, 0x00000000, 0x00003031, 0x27353922, 0x39383000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3D99999A, 0x3DCCCCCD, 0x00000000, 0x442F0000, 0x42F00000, 0xFFFF4245, 0x5354204C, 0x41500000, 0x00000000, 0x00000000, 0x00003030, 0x27313222, 0x38383200, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3D8F5C29, 0x3DE147AE, 0x00000000, 0x442F0000, 0x43160000, 0xFFFF4D41, 0x58205350, 0x45454400, 0x00000000, 0x00000000, 0x00003130, 0x32340000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3D851EB8, 0x3E051EB8, 0x00000000, 0x442F0000, 0x43340000, 0xFFFF504F, 0x494E5453, 0x00000000, 0x00000000, 0x00000000, 0x00003938, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3D75C28F, 0x3E23D70A, 0x00000000, 0x442F0000, 0x43520000, 0xFFFF4154, 0x5441434B, 0x00000000, 0x00000000, 0x00000000, 0x00004E4F, 0x4E450000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x006400C8, 0x3DCCCCCD, 0x3D8F5C29, 0x00000000, 0x442F0000, 0x00000000, 0xFFFF5255, 0x42592043, 0x55500000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3DB851EC, 0x3DA3D70A, 0x00000000, 0x442F0000, 0x42700000, 0xFFFF544F, 0x54414C20, 0x52414E4B, 0x00000000, 0x00000000, 0x00003100, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3DA3D70A, 0x3DB851EC, 0x00000000, 0x442F0000, 0x42B40000, 0xFFFF544F, 0x54414C20, 0x504F494E, 0x54530000, 0x00000000, 0x00003233, 0x30000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3D75C28F, 0x3E23D70A, 0x00000000, 0x442F0000, 0x42F00000, 0xFFFF544F, 0x54414C20, 0x41545441, 0x434B0000, 0x00000000, 0x00004E4F, 0x4E450000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x006400C8, 0x3DCCCCCD, 0x3D8F5C29, 0x00000000, 0x442F0000, 0x00000000, 0xFFFF5255, 0x42592043, 0x55500000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3DB851EC, 0x3DA3D70A, 0x00000000, 0x442F0000, 0x42700000, 0xFFFF544F, 0x54414C20, 0x52414E4B, 0x00000000, 0x00000000, 0x00003100, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3DA3D70A, 0x3DB851EC, 0x00000000, 0x442F0000, 0x42B40000, 0xFFFF544F, 0x54414C20, 0x504F494E, 0x54530000, 0x00000000, 0x00003233, 0x30000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3D75C28F, 0x3E23D70A, 0x00000000, 0x442F0000, 0x42F00000, 0xFFFF544F, 0x54414C20, 0x41545441, 0x434B0000, 0x00000000, 0x00004E4F, 0x4E450000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x006400C8, 0x3DCCCCCD, 0x3D8F5C29, 0x00000000, 0x442F0000, 0x00000000, 0xFFFF5255, 0x42592043, 0x55500000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3DB851EC, 0x3DA3D70A, 0x00000000, 0x442F0000, 0x42700000, 0xFFFF544F, 0x54414C20, 0x52414E4B, 0x00000000, 0x00000000, 0x00003100, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3DA3D70A, 0x3DB851EC, 0x00000000, 0x442F0000, 0x42B40000, 0xFFFF544F, 0x54414C20, 0x504F494E, 0x54530000, 0x00000000, 0x00003233, 0x30000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3D75C28F, 0x3E23D70A, 0x00000000, 0x442F0000, 0x42F00000, 0xFFFF544F, 0x54414C20, 0x41545441, 0x434B0000, 0x00000000, 0x00004E4F, 0x4E450000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x006400C8, 0x3DCCCCCD, 0x3D8F5C29, 0x00000000, 0x442F0000, 0x00000000, 0xFFFF5255, 0x42592043, 0x55500000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3DB851EC, 0x3DA3D70A, 0x00000000, 0x442F0000, 0x42700000, 0xFFFF544F, 0x54414C20, 0x52414E4B, 0x00000000, 0x00000000, 0x00003100, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3DA3D70A, 0x3DB851EC, 0x00000000, 0x442F0000, 0x42B40000, 0xFFFF544F, 0x54414C20, 0x504F494E, 0x54530000, 0x00000000, 0x00003233, 0x30000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3D75C28F, 0x3E23D70A, 0x00000000, 0x442F0000, 0x42F00000, 0xFFFF544F, 0x54414C20, 0x41545441, 0x434B0000, 0x00000000, 0x00004E4F, 0x4E450000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x006400C8, 0x3DCCCCCD, 0x3D8F5C29, 0x00000000, 0x442F0000, 0x00000000, 0xFFFF5255, 0x42592043, 0x55500000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3DB851EC, 0x3DA3D70A, 0x00000000, 0x442F0000, 0x42700000, 0xFFFF544F, 0x54414C20, 0x52414E4B, 0x00000000, 0x00000000, 0x00003100, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3DA3D70A, 0x3DB851EC, 0x00000000, 0x442F0000, 0x42B40000, 0xFFFF544F, 0x54414C20, 0x504F494E, 0x54530000, 0x00000000, 0x00003233, 0x30000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3D75C28F, 0x3E23D70A, 0x00000000, 0x442F0000, 0x42F00000, 0xFFFF544F, 0x54414C20, 0x41545441, 0x434B0000, 0x00000000, 0x00004E4F, 0x4E450000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x006400C8, 0x3DCCCCCD, 0x3D8F5C29, 0x00000000, 0x442F0000, 0x00000000, 0xFFFF5255, 0x42592043, 0x55500000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3DB851EC, 0x3DA3D70A, 0x00000000, 0x442F0000, 0x42700000, 0xFFFF544F, 0x54414C20, 0x52414E4B, 0x00000000, 0x00000000, 0x00003100, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3DA3D70A, 0x3DB851EC, 0x00000000, 0x442F0000, 0x42B40000, 0xFFFF544F, 0x54414C20, 0x504F494E, 0x54530000, 0x00000000, 0x00003233, 0x30000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x3D75C28F, 0x3E23D70A, 0x00000000, 0x442F0000, 0x42F00000, 0xFFFF544F, 0x54414C20, 0x41545441, 0x434B0000, 0x00000000, 0x00004E4F, 0x4E450000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x414C4C20, 0x43555000, 0x52554259, 0x20435550, 0x00000000, 0x53415050, 0x48495245, 0x20435550, 0x00000000, 0x454D4552, 0x414C4420, 0x43555000, 0x4449414D, 0x4F4E4420, 0x43555000, 0x41582043, 0x55500000, 0x47455200, 0x46524100, 0x53504100, 0x49544100}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_15_data_0_unk_1C80[36] = {(u32)lbl_15_data_1C2C__fzgx_offset_0, (u32)lbl_15_data_1C34__fzgx_offset_0, (u32)lbl_15_data_1C40__fzgx_offset_0, (u32)lbl_15_data_1C50__fzgx_offset_0, (u32)lbl_15_data_1C5C__fzgx_offset_0, (u32)lbl_15_data_1C68__fzgx_offset_0, (u32)lbl_15_data_1C70__fzgx_offset_0, (u32)lbl_15_data_1C70__fzgx_offset_0, (u32)lbl_15_data_1C70__fzgx_offset_0, (u32)lbl_15_data_1C70__fzgx_offset_0, (u32)lbl_15_data_1C70__fzgx_offset_0, 0x00000000, (u32)lbl_15_data_1C74__fzgx_offset_0, (u32)lbl_15_data_1C74__fzgx_offset_0, (u32)lbl_15_data_1C74__fzgx_offset_0, (u32)lbl_15_data_1C74__fzgx_offset_0, (u32)lbl_15_data_1C74__fzgx_offset_0, 0x00000000, (u32)lbl_15_data_1C78__fzgx_offset_0, (u32)lbl_15_data_1C78__fzgx_offset_0, (u32)lbl_15_data_1C78__fzgx_offset_0, (u32)lbl_15_data_1C78__fzgx_offset_0, (u32)lbl_15_data_1C78__fzgx_offset_0, 0x00000000, (u32)lbl_15_data_1C7C__fzgx_offset_0, (u32)lbl_15_data_1C7C__fzgx_offset_0, (u32)lbl_15_data_1C7C__fzgx_offset_0, (u32)lbl_15_data_1C7C__fzgx_offset_0, (u32)lbl_15_data_1C7C__fzgx_offset_0, 0x00000000, (u32)lbl_15_data_1C2C__fzgx_offset_0, (u32)lbl_15_data_1C34__fzgx_offset_0, (u32)lbl_15_data_1C40__fzgx_offset_0, (u32)lbl_15_data_1C50__fzgx_offset_0, (u32)lbl_15_data_1C5C__fzgx_offset_0, (u32)lbl_15_data_1C68__fzgx_offset_0}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_15_data_0_gap_1D10[16] = {0x4E4F5649, 0x43452043, 0x4C415353, 0x00000000, 0x5354414E, 0x44415244, 0x20434C41, 0x53530000, 0x45585045, 0x52542043, 0x4C415353, 0x00000000, 0x4D415354, 0x45522043, 0x4C415353, 0x00000000}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_15_data_0_unk_1D50[24] = {(u32)lbl_15_data_1D10__fzgx_offset_0, (u32)lbl_15_data_1D20__fzgx_offset_0, (u32)lbl_15_data_1D30__fzgx_offset_0, (u32)lbl_15_data_1D40__fzgx_offset_0, (u32)lbl_15_data_1C70__fzgx_offset_0, (u32)lbl_15_data_1C70__fzgx_offset_0, (u32)lbl_15_data_1C70__fzgx_offset_0, (u32)lbl_15_data_1C70__fzgx_offset_0, (u32)lbl_15_data_1C74__fzgx_offset_0, (u32)lbl_15_data_1C74__fzgx_offset_0, (u32)lbl_15_data_1C74__fzgx_offset_0, (u32)lbl_15_data_1C74__fzgx_offset_0, (u32)lbl_15_data_1C78__fzgx_offset_0, (u32)lbl_15_data_1C78__fzgx_offset_0, (u32)lbl_15_data_1C78__fzgx_offset_0, (u32)lbl_15_data_1C78__fzgx_offset_0, (u32)lbl_15_data_1C7C__fzgx_offset_0, (u32)lbl_15_data_1C7C__fzgx_offset_0, (u32)lbl_15_data_1C7C__fzgx_offset_0, (u32)lbl_15_data_1C7C__fzgx_offset_0, (u32)lbl_15_data_1D10__fzgx_offset_0, (u32)lbl_15_data_1D20__fzgx_offset_0, (u32)lbl_15_data_1D30__fzgx_offset_0, (u32)lbl_15_data_1D40__fzgx_offset_0}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_15_data_0_gap_1DB0[47] = {0x50545300, (u32)lbl_15_data_1DB0__fzgx_offset_0, (u32)lbl_15_data_1DB0__fzgx_offset_0, (u32)lbl_15_data_1DB0__fzgx_offset_0, (u32)lbl_15_data_1DB0__fzgx_offset_0, (u32)lbl_15_data_1DB0__fzgx_offset_0, (u32)lbl_15_data_1DB0__fzgx_offset_0, 0x4B4D2F48, 0x00000000, (u32)lbl_15_data_1DCC__fzgx_offset_0, (u32)lbl_15_data_1DCC__fzgx_offset_0, (u32)lbl_15_data_1DCC__fzgx_offset_0, (u32)lbl_15_data_1DCC__fzgx_offset_0, (u32)lbl_15_data_1DCC__fzgx_offset_0, (u32)lbl_15_data_1DCC__fzgx_offset_0, 0x02BC044C, 0x05DC076C, 0x08FC0A8C, 0x434F4E47, 0x52415455, 0x4C415449, 0x4F4E5321, 0x21000000, 0x434F4E47, 0x52415455, 0x4C415449, 0x4F4E5321, 0x21284745, 0x52290000, 0x434F4E47, 0x52415455, 0x4C415449, 0x4F4E5321, 0x21284652, 0x41290000, 0x434F4E47, 0x52415455, 0x4C415449, 0x4F4E5321, 0x21285350, 0x41290000, 0x434F4E47, 0x52415455, 0x4C415449, 0x4F4E5321, 0x21284954, 0x41290000}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_15_data_0_unk_1E6C[6] = {(u32)lbl_15_data_1DF8__fzgx_offset_0, (u32)lbl_15_data_1E0C__fzgx_offset_0, (u32)lbl_15_data_1E24__fzgx_offset_0, (u32)lbl_15_data_1E3C__fzgx_offset_0, (u32)lbl_15_data_1E54__fzgx_offset_0, (u32)lbl_15_data_1DF8__fzgx_offset_0}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_15_data_0_gap_1E84[18] = {0x594F5520, 0x474F5400, 0x594F5520, 0x474F5428, 0x47455229, 0x00000000, 0x594F5520, 0x474F5428, 0x46524129, 0x00000000, 0x594F5520, 0x474F5428, 0x53504129, 0x00000000, 0x594F5520, 0x474F5428, 0x49544129, 0x00000000}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_15_data_0_unk_1ECC[6] = {(u32)lbl_15_data_1E84__fzgx_offset_0, (u32)lbl_15_data_1E8C__fzgx_offset_0, (u32)lbl_15_data_1E9C__fzgx_offset_0, (u32)lbl_15_data_1EAC__fzgx_offset_0, (u32)lbl_15_data_1EBC__fzgx_offset_0, (u32)lbl_15_data_1E84__fzgx_offset_0}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_15_data_0_gap_1EE4[6] = {0x462D5A45, 0x524F2047, 0x52414E44, 0x20505249, 0x580A0000, 0x25730A00}; /* fzgx-allow: A1 measured pool bytes and bindings */
static char fzgx_pool_native_lbl_15_data_0_unk_1EFC[4] = {0x25, 0x73, 0x00, 0x00}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_15_data_0_gap_1F00[28] = {0x25640000, 0x25303264, 0x27253032, 0x64222530, 0x33640000, 0x203A2025, 0x73000000, 0x20257300, (u32)fn_15_4578__fzgx_offset_8C0, (u32)fn_15_4578__fzgx_offset_864, (u32)fn_15_4578__fzgx_offset_86C, (u32)fn_15_4578__fzgx_offset_86C, (u32)fn_15_4578__fzgx_offset_874, (u32)fn_15_4578__fzgx_offset_874, (u32)fn_15_4578__fzgx_offset_87C, (u32)fn_15_4578__fzgx_offset_87C, (u32)fn_15_4578__fzgx_offset_884, (u32)fn_15_4578__fzgx_offset_884, (u32)fn_15_4578__fzgx_offset_88C, (u32)fn_15_4578__fzgx_offset_894, (u32)fn_15_4578__fzgx_offset_894, (u32)fn_15_4578__fzgx_offset_89C, (u32)fn_15_4578__fzgx_offset_8A4, (u32)fn_15_4578__fzgx_offset_8AC, (u32)fn_15_4578__fzgx_offset_8B4, (u32)fn_15_4578__fzgx_offset_864, (u32)fn_15_4578__fzgx_offset_864, (u32)fn_15_4578__fzgx_offset_8BC}; /* fzgx-allow: A1 measured pool bytes and bindings */
static char fzgx_pool_native_lbl_15_data_0_unk_1F70[8] = {0x25, 0x73, 0x21, 0x21, 0x0A, 0x00, 0x00, 0x00}; /* fzgx-allow: A1 measured pool bytes and bindings */
static char fzgx_pool_native_lbl_15_data_0_unk_1F78[5] = {0x25, 0x73, 0x21, 0x21, 0x00}; /* fzgx-allow: A1 measured pool bytes and bindings */

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_data_base_prime(void) {
    const void *volatile s;  /* fzgx-allow: S2 data base primer sink: the retail TU addressed .data off its section base before its literal pool; the section is dropped at integration */
    s = fzgx_pool_native_lbl_15_data_0_unk_1C80;
    s = fzgx_pool_native_lbl_15_data_0_unk_1D50;
    s = fzgx_pool_native_lbl_15_data_0_unk_1E6C;
    s = fzgx_pool_native_lbl_15_data_0_unk_1ECC;
    s = fzgx_pool_native_lbl_15_data_0_unk_1EFC;
    s = fzgx_pool_native_lbl_15_data_0_unk_1F70;
    s = fzgx_pool_native_lbl_15_data_0_unk_1F78;
}
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
}
static const u32 fzgx_pool_table2[21] = {0x00FF00FF, 0x808080FF, 0xFFFFFFFF, 0xC3ACEF3B, 0x43FC728F, 0x44241408, 0xC3AD35A2, 0x43FE58B4, 0x44243FBE, 0x00000000, 0x3F800000, 0x00000000, 0xC3ACEF3B, 0x43FC728F, 0x44241408, 0xC3AD35A2, 0x43FE58B4, 0x44243FBE, 0x00000000, 0x3F800000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 200.0f;
    s = 1.0f;
}
static const u32 fzgx_pool_table4[1] = {0xFFC800FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 30.0f;
    d = 0.01;
    s = 2.0f;
    s = 320.0f;
    s = 240.0f;
    s = 20.0f;
    s = 10.0f;
    s = 0.5f;
    s = 3.0f;
    s = 0.03999999910593033f;
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table6[3] = {0x00000000, 0x00000000, 0x43480000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.6000000238418579f;
}
static const u32 fzgx_pool_table8[8] = {0x000000FF, 0x404040FF, 0x404088FF, 0xAAAAAAFF, 0xFF0000FF, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.5f;
    s = -0.8999999761581421f;
}
static const u32 fzgx_pool_table10[5] = {0x00000003, 0x00040006, 0x00000000, 0x3F800000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -1.5f;
    s = -2.25f;
    s = -2.0f;
    s = 0.20000000298023224f;
    s = -0.20000000298023224f;
    s = -2.200000047683716f;
    s = 9.0f;
    s = 1.0399999618530273f;
    s = 1000.0f;
    s = 4.0f;
    s = 5.0f;
    s = -4.0f;
    s = 55.0f;
}
static const u32 fzgx_pool_table12[3] = {0x00FF00FF, 0x808080FF, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 40.0f;
}
static const u32 fzgx_pool_table14[2] = {0x00FFFFFF, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 540.0f;
    s = 60.0f;
    s = 234.0f;
    s = 11.0f;
    s = 142.0f;
    s = 296.0f;
    s = 324.0f;
    s = 0.800000011920929f;
    s = 940.0f;
    s = 103.0f;
    s = 1.440000057220459f;
    s = 160.0f;
    s = 211.0f;
    s = 0.8399999737739563f;
    s = 141.0f;
    s = 180.0f;
    s = 27.0f;
    s = 224.0f;
    s = 117.0f;
    s = 23.0f;
    s = 1.2999999523162842f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 320.0;
    s = 250.0f;
    s = 1.559999942779541f;
    s = 0.4000000059604645f;
}
static const u32 fzgx_pool_table18[2] = {0xFFFFFFFF, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.7000000476837158f;
}
static const u32 fzgx_pool_table20[4] = {0x00000000, 0x00000000, 0x3F99999A, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 6.0f;
    s = -22.0f;
    s = 238.0f;
    s = 1.399999976158142f;
    s = 146.0f;
    s = 303.0f;
    s = 1.2000000476837158f;
    s = 308.0f;
    s = 340.0f;
    s = 330.0f;
}
#pragma section code_type ".text"
void fn_15_5460(f32 arg0) {
    f32 offset;
    FontDrawPacket loc_8;
    struct fn_15_5460_Row *rows;

    
    offset = (lbl_15_bss_35 != 0) ? -22.0f : 0.0f;

    fn_1_520A0();
    fn_1_52070(320);
    loc_8 = *(const FontDrawPacket *)((((s32)(((u8 *)(&lbl_1_rodata_26F8) + -4))) + 4));
    loc_8.image = 0x10000 - 0x5EFB;
    loc_8.x = 320.0f;
    loc_8.y = 238.0f + offset;
    loc_8.z = 3.0f;
    loc_8.scale_x = 1.0f;
    loc_8.scale_y = 1.0f;
    loc_8.alpha = arg0;
    loc_8.flags = 10;
    fn_1_4F734(&loc_8);

    fn_1_141360(4, (s32)loc_8.x, (s32)loc_8.y, 2, 1.0f, arg0);

    fn_1_520CC();
    fn_1_49410();
    fn_1_494DC(6);
    fn_1_495B0(0xC0000000); /* fzgx-allow: A1 bitmask, not an address */
    fn_1_495C8(1);
    fn_1_49590(0.5f);
    fn_1_4955C(1.4f, 1.4f);
    fn_1_496FC(320.0f, 146.0f + offset);
    fn_1_495A0(arg0);
    fn_1_4AE0C(fzgx_pool_native_lbl_15_data_0_unk_1EFC, fzgx_pool_native_lbl_15_data_0_unk_1E6C[lbl_801A66B4[0]]);

    offset = 303.0f + offset;
    fn_1_496FC(320.0f, offset);
    fn_1_4955C(1.2f, 1.2f);
    fn_1_4AE0C(fzgx_pool_native_lbl_15_data_0_unk_1EFC, fzgx_pool_native_lbl_15_data_0_unk_1ECC[lbl_801A66B4[0]]);
    fn_1_496FC(320.0f, offset);
    fn_1_4955C(1.2f, 1.2f);

    if (lbl_15_bss_35 != 0) {
        fn_1_496FC(320.0f, 308.0f);
        fn_1_4955C(1.5f, 1.5f);
        rows = (struct fn_15_5460_Row *)fzgx_pool_native_lbl_15_data_0_unk_1C80;
        fn_1_4AE0C(fzgx_pool_native_lbl_15_data_0_unk_1F70, rows[lbl_801A66B4[0]].name);
        fn_1_496FC(320.0f, 340.0f);
        fn_1_4955C(1.5f, 1.5f);
        fn_1_4AE0C(fzgx_pool_native_lbl_15_data_0_unk_1F78, fzgx_pool_native_lbl_15_data_0_unk_1D50[lbl_801A66B4[0] * 4 + 3]);
    } else {
        fn_1_496FC(320.0f, 330.0f);
        fn_1_4955C(1.5f, 1.5f);
        rows = (struct fn_15_5460_Row *)fzgx_pool_native_lbl_15_data_0_unk_1C80;
        fn_1_4AE0C(fzgx_pool_native_lbl_15_data_0_unk_1F70, rows[lbl_801A66B4[0]].name);
    }
}
/* fzgx:end fn_15_5460 */

/* fzgx:begin fn_15_5864 */
extern s16 lbl_1_bss_960;
extern u8 lbl_15_bss_4[8];

#pragma opt_propagation off
u32 fn_15_5864(u32 unused) {
    s32 value = lbl_1_bss_960;
    u32 mask = ~((value - 14) | (14 - value)) >> 31;
    return ((lbl_15_bss_4[0]) & (mask));
}
#pragma opt_propagation reset
/* fzgx:end fn_15_5864 */
