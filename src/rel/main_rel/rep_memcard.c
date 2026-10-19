#include "types.h"
#include "rel/main_rel/globals.h"

typedef struct {
    u32 unk_0;
    u8 unk_4;
    u8 pad_5[0x3];
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u8 unk_14;
    u8 pad_15[0x37];
} RepMemcardReplay;

typedef struct {
    u8 unk_0;
    u8 unk_1;
} Obj_1_bss_8EDF0_At10;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    Obj_1_bss_8EDF0_At10 *unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    u32 unk_30;
    u8 unk_34;
    u8 unk_35;
    u8 pad_36[0xFA];
} Obj_1_bss_8EDF0;

extern u32 lbl_801A6410;
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern f64 fn_80083E84(u8 *text);
extern s32 atoi(u8 *text);
extern void *memset(void *dest, int value, u32 size);
extern u32 fn_1_3F8C(char *name, void (*func)(void), u32 arg2, u32 arg3);
extern u32 fn_1_426C(u32 arg0);
extern u32 fn_1_435C(u32 arg0);
extern u32 fn_1_4630(u32 arg0, u32 arg1, char *file, s32 line);
extern void fn_1_46B4(u32 arg0, u32 arg1, char *file, s32 line);
extern void fn_1_48418(s32 arg0);
extern void fn_1_484CC(s32 arg0);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495FC(void);
extern void fn_1_49614(void);
extern void fn_1_4966C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AF64(void *, ...);
extern f32 fn_1_4B090(void *);
extern int fn_1_4B16C(void *);
extern void fn_1_A8EB0(s32 arg0, s32 arg1);
extern u8 fn_1_B7C00(void);
extern void fn_1_B9BE0(void);
extern void fn_1_B9C0C(void);
extern void fn_1_B9DE8(RepMemcardReplay *arg0);
extern s32 fn_1_BA144(RepMemcardReplay *arg0);
extern void fn_1_BC29C(RepMemcardReplay *arg0);
extern void fn_1_BC310(RepMemcardReplay *arg0);
extern void fn_1_C0510(RepMemcardReplay *arg0, u32 size, u32 buf);
extern void fn_1_C1394(RepMemcardReplay *arg0);
extern int fn_1_FA638(void);
extern void fn_1_1596DC(s32);
extern void fn_1_159440(s32 arg0, s32 arg1);

void fn_1_154798(void);
void fn_1_1548A8(void);
void fn_1_154930(void);
void fn_1_1549B8(void);
void fn_1_154A08(void);
void fn_1_154BE4(void);
void fn_1_154F1C(void);
void fn_1_154FA8(void);
void fn_1_155120(void);
u8 *fn_1_15530C(u8 *text);

/* the replay memory-card state machine: one handler per state */
void (*lbl_1_data_49A18[5])(void) = {
    fn_1_1548A8, fn_1_154930, fn_1_1549B8, fn_1_154A08, fn_1_154BE4,
};
char *lbl_1_data_49A94[5] = {
    "REP_MEMCARD_INIT", "REP_MEMCARD_WAIT", "REP_MEMCARD_ACTION_INIT", "REP_MEMCARD_ACTION", "REP_MEMCARD_FINISH",
};
s32 lbl_1_data_49AA8 = -1;  /* event id */
s32 lbl_1_data_49AAC = -1;  /* previous state */
s32 lbl_1_data_49AB0 = -1;  /* current state */
s32 lbl_1_data_49AB4 = -1;  /* requested state */

u32 lbl_1_bss_8ED90 = 0;  /* saved replay data */
u32 lbl_1_bss_8ED94 = 0;  /* its size */
u32 lbl_1_bss_8ED98 = 0;
u32 lbl_1_bss_8ED9C = 0;
u8 lbl_1_bss_8EDA0 = 0;
RepMemcardReplay lbl_1_bss_8EDA4;
Obj_1_bss_8EDF0 lbl_1_bss_8EDF0;

/* fzgx:begin fn_1_154708 */
void fn_1_154708(u32 arg0) {
    lbl_1_bss_8ED9C = arg0;
    lbl_1_data_49AA8 = -1;
    fn_1_435C(arg0);
    lbl_1_data_49AA8 = fn_1_3F8C("RepMemcardEvent", fn_1_154798, 0, 18);
    lbl_1_data_49AAC = -1;
    lbl_1_data_49AB0 = -1;
    lbl_1_data_49AB4 = -1;
    lbl_1_bss_8EDA0 = 0;
    lbl_1_bss_8ED98 = 0;
    lbl_1_bss_8ED90 = 0;
    lbl_1_bss_8ED94 = 0;
    fn_1_B9BE0();
}
/* fzgx:end fn_1_154708 */

/* fzgx:begin fn_1_154798 */
void fn_1_154798(void) {
    if (lbl_1_data_49AB4 >= 0) {
        lbl_1_data_49AAC = lbl_1_data_49AB0;
        lbl_1_data_49AB0 = lbl_1_data_49AB4;
        lbl_1_data_49AB4 = -1;
    }
    if (lbl_1_data_49AB0 >= 0) {
        lbl_1_data_49A18[lbl_1_data_49AB0]();
    }
}
/* fzgx:end fn_1_154798 */

/* fzgx:begin fn_1_1547FC */
void fn_1_1547FC(void) {
    fn_1_B9C0C();
    if (lbl_1_bss_8ED90 != 0) {
        fn_1_46B4(lbl_801A6410, lbl_1_bss_8ED90, "rep_memcard.c", 115);
        lbl_1_bss_8ED90 = 0;
        lbl_1_bss_8ED94 = 0;
    }
    lbl_1_data_49AAC = -1;
    lbl_1_data_49AB0 = -1;
    lbl_1_data_49AB4 = -1;
    if (lbl_1_data_49AA8 != -1) {
        fn_1_435C(lbl_1_bss_8ED9C);
        fn_1_426C(lbl_1_data_49AA8);
        lbl_1_bss_8ED9C = 0;
        lbl_1_data_49AA8 = -1;
    }
}
/* fzgx:end fn_1_1547FC */

/* fzgx:begin fn_1_1548A8 */
void fn_1_1548A8(void) {
    s16 mode;
    s16 *mode_ptr;
    RepMemcardReplay *replay;

    fn_1_B9BE0();
    fn_1_B9DE8(&lbl_1_bss_8EDA4);
    mode_ptr = (s16 *)&lbl_1_bss_960;
    replay = &lbl_1_bss_8EDA4;
    mode = *mode_ptr;
    replay->unk_0 = 0x20;
    if (mode == 12) {
        replay->unk_4 = 10;
    } else {
        replay->unk_4 = 9;
    }
    if (mode != 2) {
        fn_1_48418(2);
        fn_1_159440(2, 0);
    }
    lbl_1_data_49AB4 = 1;
}
/* fzgx:end fn_1_1548A8 */

/* fzgx:begin fn_1_154930 */
void fn_1_154930(void) {
    s8 result;

    result = fn_1_BA144(&lbl_1_bss_8EDA4);
    if (result == 0) {
        lbl_1_data_49AB4 = 2;
    } else if (result == 1) {
        lbl_1_data_49AB4 = 4;
        lbl_1_bss_8EDA0 = 1;
        fn_1_1596DC(2);
        fn_1_484CC(2);
    } else {
        fn_1_BC310(&lbl_1_bss_8EDA4);
    }
}
/* fzgx:end fn_1_154930 */

/* fzgx:begin fn_1_1549B8 */
void fn_1_1549B8(void) {
    lbl_1_bss_8EDA4.unk_8 = lbl_1_bss_8ED90;
    lbl_1_bss_8EDA4.unk_C = lbl_1_bss_8ED94;
    lbl_1_bss_8EDA4.unk_10 = 5;
    fn_1_C0510(&lbl_1_bss_8EDA4, lbl_1_bss_8ED94, lbl_1_bss_8ED90);
    lbl_1_data_49AB4 = 3;
}
/* fzgx:end fn_1_1549B8 */

/* fzgx:begin fn_1_154A08 */
void fn_1_154A08(void) {
    RepMemcardReplay *replay;
    RepMemcardReplay *saved;
    u32 buf;
    s8 state;

    if (fn_1_B7C00()) {
        return;
    }
    if (lbl_1_bss_8ED98 != 0) {
        fn_1_46B4(lbl_801A6410, lbl_1_bss_8ED98, "rep_memcard.c", 0xcd);
    }
    state = lbl_1_bss_8EDA4.unk_14;
    if (state == 1) {
        fn_1_B9C0C();
        fn_1_BC29C(&lbl_1_bss_8EDA4);
        lbl_1_data_49AB4 = 4;
    } else if (state == 2) {
        if (lbl_1_bss_8ED90 != 0) {
            fn_1_46B4(lbl_801A6410, lbl_1_bss_8ED90, "rep_memcard.c", 0xda);
        }
        replay = &lbl_1_bss_8EDA4;
        if ((s32)replay->unk_C != 0) {
            buf = fn_1_4630(lbl_801A6410, replay->unk_C, "rep_memcard.c", 0xdf);
            fn_80008BA8(buf, (saved = &lbl_1_bss_8EDA4)->unk_8, replay->unk_C);
            fn_1_B9C0C();
            if (saved->unk_8 != 0) {
                fn_1_46B4(lbl_801A6410, saved->unk_8, "rep_memcard.c", 0xe9);
                saved->unk_8 = 0;
            }
            lbl_1_bss_8ED90 = fn_1_4630(lbl_801A6410, replay->unk_C, "rep_memcard.c", 0xee);
            lbl_1_bss_8ED94 = replay->unk_C;
            replay->unk_C = 0;
            fn_80008BA8(lbl_1_bss_8ED90, buf, lbl_1_bss_8ED94);
            fn_1_46B4(lbl_801A6410, buf, "rep_memcard.c", 0xf9);
        }
        lbl_1_data_49AB4 = 4;
        fn_1_BC29C(&lbl_1_bss_8EDA4);
    } else if (state == 8) {
        fn_1_C1394(&lbl_1_bss_8EDA4);
        lbl_1_data_49AB4 = 1;
    }
}
/* fzgx:end fn_1_154A08 */

/* fzgx:begin fn_1_154BE4 */
void fn_1_154BE4(void) {
    if ((s32)lbl_1_bss_8EDA4.unk_14 != 2 && lbl_1_bss_8ED90 != 0) {
        fn_1_46B4(lbl_801A6410, lbl_1_bss_8ED90, "rep_memcard.c", 0x10d);
        lbl_1_bss_8ED90 = 0;
        lbl_1_bss_8ED94 = 0;
    }
    fn_1_B9C0C();
    fn_1_1596DC(2);
    fn_1_484CC(2);
    lbl_1_data_49AAC = -1;
    lbl_1_data_49AB0 = -1;
    lbl_1_data_49AB4 = -1;
}
/* fzgx:end fn_1_154BE4 */

/* fzgx:begin fn_1_154C84 */
BOOL fn_1_154C84(void) {
    if (lbl_1_data_49AB0 == 4) {
        return FALSE;
    }
    if (lbl_1_data_49AB0 != -1 || lbl_1_data_49AB4 != -1) {
        return TRUE;
    }
    return FALSE;
}
/* fzgx:end fn_1_154C84 */

/* fzgx:begin fn_1_154CC4 */
void fn_1_154CC4(u32 arg0) {
    lbl_1_data_49AB4 = arg0;
}
/* fzgx:end fn_1_154CC4 */

/* fzgx:begin fn_1_154CD0 */
void fn_1_154CD0(u32 arg0, u32 arg1) {
    if (lbl_1_bss_8ED90 != 0) {
        fn_1_46B4(lbl_801A6410, lbl_1_bss_8ED90, "rep_memcard.c", 0x12f);
        lbl_1_bss_8ED90 = 0;
        lbl_1_bss_8ED94 = 0;
    }

    lbl_1_bss_8ED90 = fn_1_4630(lbl_801A6410, arg1, "rep_memcard.c", 0x133);
    fn_80008BA8(lbl_1_bss_8ED90, arg0, arg1);
    lbl_1_bss_8ED94 = arg1;
}
/* fzgx:end fn_1_154CD0 */

/* fzgx:begin fn_1_154D84 */
// Saves the pending memory-card data and clears the pending state.
u32 fn_1_154D84(u32 arg0) {
    if (lbl_1_bss_8ED90 == 0) {
        return 0;
    }
    if (arg0 == 0) {
        return 0;
    }

    fn_80008BA8(arg0, lbl_1_bss_8ED90, lbl_1_bss_8ED94);
    fn_1_46B4(lbl_801A6410, lbl_1_bss_8ED90, "rep_memcard.c", 0x13f);
    lbl_1_bss_8ED90 = 0;
    lbl_1_bss_8ED94 = 0;
    return 1;
}
/* fzgx:end fn_1_154D84 */

/* fzgx:begin fn_1_154E24 */
u8 fn_1_154E24(void) {
    return lbl_1_bss_8EDA0;
}
/* fzgx:end fn_1_154E24 */

/* fzgx:begin fn_1_154E34 */
u32 fn_1_154E34(u32 *arg0) {
    *arg0 = lbl_1_bss_8ED94;
    return lbl_1_bss_8ED90;
}
/* fzgx:end fn_1_154E34 */

/* fzgx:begin fn_1_154E4C */
// Clear the replay memory-card message state and set its default layout.
void fn_1_154E4C(void) {
    memset(&lbl_1_bss_8EDF0, 0, sizeof(lbl_1_bss_8EDF0));
    lbl_1_bss_8EDF0.unk_C = 0;
    lbl_1_bss_8EDF0.unk_28 = 1.0f;
    lbl_1_bss_8EDF0.unk_30 = 2;
    lbl_1_bss_8EDF0.unk_8 &= ~2;
    lbl_1_bss_8EDF0.unk_10 = 0;
    lbl_1_bss_8EDF0.unk_20 = 80;
    lbl_1_bss_8EDF0.unk_24 = 385;
    lbl_1_bss_8EDF0.unk_2C = 0.5f;
    fn_1_154FA8();
}
/* fzgx:end fn_1_154E4C */

/* fzgx:begin fn_1_154ED0 */
typedef struct {
    u8 pad_0[0x134];
    Obj_1_bss_8EDF0_At10 *unk_134;
} Fn_1_154ED0_Arg;

void fn_1_154ED0(Fn_1_154ED0_Arg *arg0) {
    fn_1_154F1C();
    lbl_1_bss_8EDF0.unk_C = (u32)arg0;
    lbl_1_bss_8EDF0.unk_10 = arg0->unk_134;
    lbl_1_bss_8EDF0.unk_0 = 0;
    lbl_1_bss_8EDF0.unk_4 = 0;
}
/* fzgx:end fn_1_154ED0 */

/* fzgx:begin fn_1_154F1C */
// Reset the memory-card state and clear its backing buffer.
void fn_1_154F1C(void) {
    lbl_1_bss_8EDF0.unk_1C = 0;
    lbl_1_bss_8EDF0.unk_14 = 0;
    lbl_1_bss_8EDF0.unk_18 = 0;
    memset(&lbl_1_bss_8EDF0.unk_34, 0, 250);
    lbl_1_bss_8EDF0.unk_34 = 0;
}
/* fzgx:end fn_1_154F1C */

/* fzgx:begin fn_1_154F74 */
// Stores the two memory-card state values used by the replication subsystem.
void fn_1_154F74(u32 arg0, u32 arg1) {
    lbl_1_bss_8EDF0.unk_20 = arg0;
    lbl_1_bss_8EDF0.unk_24 = arg1;
}
/* fzgx:end fn_1_154F74 */

/* fzgx:begin fn_1_154F88 */
// Stores the current float value in the memory-card state.
void fn_1_154F88(f32 value) {
    lbl_1_bss_8EDF0.unk_2C = value;
}
/* fzgx:end fn_1_154F88 */

/* fzgx:begin fn_1_154F98 */
void fn_1_154F98(u32 value) {
    lbl_1_bss_8EDF0.unk_30 = value;
}
/* fzgx:end fn_1_154F98 */

/* fzgx:begin fn_1_154FA8 */
void fn_1_154FA8(void) {
    lbl_1_bss_8EDF0.unk_8 |= 4;
}
/* fzgx:end fn_1_154FA8 */

/* fzgx:begin fn_1_154FC0 */
void fn_1_154FC0(void) {
    lbl_1_bss_8EDF0.unk_8 &= ~4;
}
/* fzgx:end fn_1_154FC0 */

/* fzgx:begin fn_1_154FD8 */
void fn_1_154FD8(void) {
    Obj_1_bss_8EDF0 *obj;
    f32 value;
    f32 ratio;
    int count;

    obj = &lbl_1_bss_8EDF0;
    if ((obj->unk_8 & 1) == 0) {
        obj->unk_0++;
        if ((s32)obj->unk_4 != 0) {
            obj->unk_4--;
        }
    }

    if ((s32)obj->unk_4 <= 0) {
        if (((s32)obj->unk_0 % (s32)obj->unk_30) == 0) {
            fn_1_155120();
        }
    }

    fn_1_496FC((f32)(s32)obj->unk_20, (f32)(s32)obj->unk_24);
    fn_1_4955C(obj->unk_28, obj->unk_28);
    fn_1_495FC();

    value = fn_1_4B090(&obj->unk_34);
    ratio = value / (f32)(fn_1_4B16C(&obj->unk_34));
    fn_1_4966C(0.0f, ratio * obj->unk_2C);

    if (fn_1_FA638() != 0) {
        fn_1_4AF64(&obj->unk_34);
    }

    fn_1_49614();
}
/* fzgx:end fn_1_154FD8 */

/* fzgx:begin fn_1_155120 */
#define TEXT(obj) ((u8 *)(obj)->unk_10)
#define SET_TEXT(obj, p) ((obj)->unk_10 = (Obj_1_bss_8EDF0_At10 *)(p))

// Emit the next character (or bracketed group, or escape command) of the replay
// memory-card message into the text buffer.
void fn_1_155120(void) {
    Obj_1_bss_8EDF0 *obj = &lbl_1_bss_8EDF0;
    u8 *text = TEXT(obj);
    u8 c = *text;
    u8 next;

    if (c == 0) {
        return;
    }
    switch (c) {
    case '\\':
        SET_TEXT(obj, fn_1_15530C(text + 1));
        break;
    case '[':
        fn_1_A8EB0(20, 20);
        while (*TEXT(obj) != ']') {
            /* read through the global, not obj: retail reloads the cursor here */
            u8 *p = (u8 *)lbl_1_bss_8EDF0.unk_10;
            u8 ch = *p;
            if ((ch & 0x80) == 0) {
                SET_TEXT(obj, p + 1);
                obj->unk_14++;
                (&obj->unk_34)[obj->unk_1C] = ch;
            } else {
                next = TEXT(obj)[1];
                SET_TEXT(obj, p + 2);
                obj->unk_14 += 2;
                (&obj->unk_34)[obj->unk_1C] = ch;
                (&obj->unk_34)[obj->unk_1C + 1] = next;
            }
            obj->unk_1C = obj->unk_14 + obj->unk_18 * 30;
        }
        c = *TEXT(obj);
        SET_TEXT(obj, TEXT(obj) + 1);
        obj->unk_14++;
        (&obj->unk_34)[obj->unk_1C] = c;
        obj->unk_1C = obj->unk_14 + obj->unk_18 * 30;
        break;
    case '\n':
        obj->unk_14++;
        SET_TEXT(obj, text + 1);
        (&obj->unk_34)[obj->unk_1C] = '\n';
        break;
    case '\0':
        break;
    default:
        if ((c & 0x80) == 0) {
            SET_TEXT(obj, TEXT(obj) + 1);
            obj->unk_14++;
            (&obj->unk_34)[obj->unk_1C] = c;
        } else {
            next = TEXT(obj)[1];
            SET_TEXT(obj, TEXT(obj) + 2);
            obj->unk_14 += 2;
            (&obj->unk_34)[obj->unk_1C] = c;
            (&obj->unk_34)[obj->unk_1C + 1] = next;
        }
        break;
    }
    obj->unk_1C = obj->unk_14 + obj->unk_18 * 30;
}
/* fzgx:end fn_1_155120 */

/* fzgx:begin fn_1_15530C */
u8 *fn_1_15530C(u8 *text) {
    Obj_1_bss_8EDF0 *obj = &lbl_1_bss_8EDF0;

    switch (*text) {
    case 'l':
    {
        u8 *dest;
        obj->unk_1C = 0;
        dest = &obj->unk_34;
        obj->unk_14 = 0;
        text++;
        obj->unk_18 = 0;
        memset(dest, 0, 0xFA);
        *dest = 0;
        break;
    }
    case 'w':
    {
        f32 value;
        text++;
        value = (f32)fn_80083E84(text);
        while ((*text >= '0' && *text <= '9') || *text == '.') {
            text++;
        }
        obj->unk_4 = (s16)(60.0f * value);
        break;
    }
    case 't':
    {
        s32 value;
        text++;
        value = atoi(text);
        while ((*text >= '0' && *text <= '9') || *text == '.') {
            text++;
        }
        value = value - obj->unk_0;
        if (value >= 0) {
            obj->unk_4 = value;
        } else {
            obj->unk_4 = 0;
        }
        break;
    }
    case 'p':
    {
        s32 value = 0;
        text++;
        while ((*text >= '0') && (*text <= '9')) {
            if (value != 0) {
                value *= 10;
            }
            value = *text + value;
            text++;
            value -= 0x30;
        }
        break;
    }
    case 's':
    {
        f32 value;
        text++;
        value = (f32)fn_80083E84(text);
        while ((*text >= '0' && *text <= '9') || *text == '.') {
            text++;
        }
        obj->unk_28 = value;
        break;
    }
    default:
        text++;
        break;
    }

    return text;
}
/* fzgx:end fn_1_15530C */
