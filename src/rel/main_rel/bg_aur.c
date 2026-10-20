#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_aur.h"

extern int fn_8003BE1C(void *arg0, void *arg1);
extern int fn_8003C1A4(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4);
extern void fn_8003CE74(void *arg0, void *arg1, int arg2);
extern void fn_8003CBB0(void *arg0, void *arg1, void *arg2, void *arg3);
extern void fn_8003C6D0(void *arg0, void *arg1, void *arg2, void *arg3);
extern u16 lbl_1_bss_8ED8C;
extern u16 lbl_1_bss_8ED8E;
extern void fn_1_151C9C(void);
extern void fn_80074A7C(void (*callback)(void));
extern void fn_1_153AF8(u32 *entries);
extern void fn_1_153D48(void *background);
extern void fn_1_9A508(void);
extern int fn_1_58C4(void);
extern void fn_1_5948(int);
extern void fn_1_627C(int);
extern void fn_1_9D260(void);
extern void fn_1_9AD54(void);
extern void fn_1_153D74(void *);
extern void fn_1_153B24(void *);
extern void fn_1_153C60(Obj_1_data_2A7E0_At3C *value);
extern void fn_1_1540B0(Obj_1_data_2A7E0_At3C *value);
extern void fn_1_9AD88(void);
extern void fn_80008BEC(void *arg0, u32 arg1, u32 arg2);

extern void fn_1_153AF8(u32 *entries);
extern void fn_1_153D48(void *background);
extern void fn_1_9A508(void);
extern u8 lbl_1_rodata_D048[1200];
extern int fn_1_8D690(s16 value);
extern int fn_1_8D72C(s16 value);

/* fzgx:begin fn_1_151AF0 */
int fn_1_151AF0(void *arg0, int mode, void *arg2, void *arg3, void *arg4, void *arg5) {
    u8 local_8[4];
    u8 local_c[8];
    u8 local_14[12];

    if (fn_8003BE1C(arg0, local_c) == 0) {
        return 0;
    }
    if (fn_8003C1A4(local_14, local_8, arg5, arg0, local_c) == 0) {
        return 0;
    }
    switch (mode) {
    case 0:
        fn_8003CE74(local_14, arg2, 0xff);
        break;
    case 1:
        fn_8003CBB0(local_14, arg2, arg3, arg4);
        break;
    case 2:
        fn_8003C6D0(local_14, arg2, arg3, arg4);
        break;
    }
    return 1;
}
/* fzgx:end fn_1_151AF0 */

/* fzgx:begin fn_1_151BDC */
void fn_1_151BDC(u32 value) {
    lbl_1_bss_8ED88 = value;
}
/* fzgx:end fn_1_151BDC */

/* fzgx:begin fn_1_151BE8 */
struct fn_1_151BE8_Copy1200 { u32 a[75][4]; };

u32 fn_1_151BE8(s16 arg0, s16 arg1) {
    struct fn_1_151BE8_Copy1200 loc_8;
    loc_8 = *(struct fn_1_151BE8_Copy1200 *)&lbl_1_rodata_D048;
    {
        s16 row = arg0;
        s16 col = arg1;
        return loc_8.a[row][col];
    }
}
/* fzgx:end fn_1_151BE8 */

/* fzgx:begin fn_1_151C3C */
void fn_1_151C3C(u16 value1, u16 value2) {
    lbl_1_bss_8ED8C = value1;
    lbl_1_bss_8ED8E = value2;
    fn_80074A7C(fn_1_151C9C);
}
/* fzgx:end fn_1_151C3C */

/* fzgx:begin fn_1_151C78 */
void fn_1_151C78(void) {
    fn_80074A7C(0);
}
/* fzgx:end fn_1_151C78 */

/* fzgx:begin fn_1_151C9C noprologue */
#include "types.h"

struct fn_1_151C9C_lbl_1_bss_8ED88 {
    u32 unk_0;
    s16 unk_4;
    s16 unk_6;
};
struct fn_1_151C9C_lbl_1_rodata_D500 {
    f64 unk_0;
};
struct fn_1_151C9C_lbl_1_rodata_D4F8 {
    f32 unk_0;
};
extern struct fn_1_151C9C_lbl_1_bss_8ED88 lbl_1_bss_8ED88;
extern struct fn_1_151C9C_lbl_1_rodata_D4F8 lbl_1_rodata_D4F8;
extern struct fn_1_151C9C_lbl_1_rodata_D500 lbl_1_rodata_D500;
extern u32 fn_1_151BE8(s16, s16);
extern void fn_80008BA8(void *, void *, u32);

struct FzgxCopy_4 { u32 words[1]; };
#pragma opt_propagation off
void fn_1_151C9C(void *arg0, s32 arg_sp0) {
    struct FzgxCopy_4 loc_8;
    void *temp_r7;
    u32 var_r3;
    s32 temp_r3;
    void *var_r30;
    u32 temp_r29;
    s16 var_r28;

    var_r28 = 0;
    temp_r29 = lbl_1_bss_8ED88.unk_0;
    var_r30 = (void *)(temp_r29 + (lbl_1_bss_8ED88.unk_4 * 8));
    while (var_r28 < 1) {
        if ((temp_r29 == 0) || (temp_r3 = *(s32 *)((u8 *)(temp_r29) + 0), (((temp_r3 & 0x80000000) == 0) != 0)) || !(temp_r3 & 0x40000000)) {
            var_r3 = fn_1_151BE8((s16)(lbl_1_bss_8ED88.unk_6), var_r28);
        } else {
            var_r3 = *(u32 *)((u8 *)(var_r30) + 33192);
        }
        temp_r7 = (void *)(*(void **)((u8 *)(arg0) + 4));
        if ((u8) (*(u8 *)((u8 *)(temp_r7) + 21)) == (u8) var_r3) {
            (*(s8 *)((u8 *)(&loc_8) + 0)) = (s8) (var_r3 >> 0x18U);
            (*(u8 *)((u8 *)(&loc_8) + 1)) = (u8) (var_r3 >> 0x10U);
            (*(u8 *)((u8 *)(&loc_8) + 2)) = (u8) (var_r3 >> 8U);
            (*(u8 *)((u8 *)(&loc_8) + 3)) = 0xFF;
            fn_80008BA8((void *)((u8 *)(temp_r7) + 8), (void *)(&loc_8), (u32)(4U));
            (*(s8 *)((u8 *)(&loc_8) + 0)) = (s8) ((f32) (*(u8 *)((u8 *)(&loc_8) + 0)) * lbl_1_rodata_D4F8.unk_0);
            (*(s8 *)((u8 *)(&loc_8) + 1)) = (s8) ((f32) (*(u8 *)((u8 *)(&loc_8) + 1)) * lbl_1_rodata_D4F8.unk_0);
            (*(s8 *)((u8 *)(&loc_8) + 2)) = (s8) ((f32) (*(u8 *)((u8 *)(&loc_8) + 2)) * lbl_1_rodata_D4F8.unk_0);
            fn_80008BA8((void *)((u8 *)((*(void **)((u8 *)(arg0) + 4))) + 4), (void *)(&loc_8), (u32)(4U));
        }
        var_r30 = (void *)((u8 *)(var_r30) + 4);
        var_r28 += 1;
            }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_151C9C */

/* fzgx:begin fn_1_151E20 */
u32 fn_1_151E20(u32 value, s16 index) {
    u32 result = (u32)-1;

    switch (index) {
    case 0:
        result = value >> 24;
        break;
    case 1:
        result = (value >> 16) & 0xff;
        break;
    case 2:
        result = (value >> 8) & 0xff;
        break;
    case 3:
        result = value & 0xff;
        break;
    }

    return result;
}
/* fzgx:end fn_1_151E20 */

/* fzgx:begin fn_1_151E74 */
void fn_1_151E74(u32 *value, s16 index, int byte) {
    switch (index) {
    case 0:
        *value = (*value & 0x00FFFFFF) | ((u32)byte << 24);
        break;
    case 1:
        *value = (*value & 0xFF00FFFF) | ((u32)byte << 16);
        break;
    case 2:
        *value = (*value & 0xFFFF00FF) | ((u32)byte << 8);
        break;
    case 3:
        *value = (*value & 0xFFFFFF00) | byte;
        break;
    default:
        break;
    }
}
/* fzgx:end fn_1_151E74 */

/* fzgx:begin fn_1_151EF8 */
typedef struct {
    s16 unk_0;
    u8 pad_2[0x2];
    u32 unk_4;
} Entry_151EF8;

void fn_1_151EF8(s16 *values, s16 value_count, Entry_151EF8 *entries,
                 s16 group_count, s16 group_size) {
    s16 i;
    s16 j;
    s16 group_index;
    s16 local_index;
    Entry_151EF8 *entry;

    for (i = 0; i < group_count; i++) {
        for (j = 0; j < group_size; j++) {
            entries[i * group_size + j].unk_4 |= (1u << 30);
            entries[i * group_size + j].unk_0 = -1;
        }
    }

    for (i = 0; i < value_count; i++) {

        if (values[i] == -1) {
            continue;
        }

        group_index = i / group_size;
        local_index = i % group_size;

        entries[group_index * group_size + local_index].unk_0 = values[i];
        entries[group_index * group_size + local_index].unk_4 = 0;

        if (entries[group_index * group_size + local_index].unk_0 >= 0x29) {
            entries[group_index * group_size + local_index].unk_4 |= (1u << 29);
            entries[group_index * group_size + local_index].unk_4 |= (1u << 30);
            continue;
        }

        if (!fn_1_8D690(entries[group_index * group_size + local_index].unk_0)) {
            entries[group_index * group_size + local_index].unk_4 |= (1u << 31);
        }
        if (!fn_1_8D72C(entries[group_index * group_size + local_index].unk_0)) {
            entries[group_index * group_size + local_index].unk_4 |= (1u << 30);
        }
        if ((lbl_1_bss_8B3A0.unk_94 & 0x40000000) != 0 &&
            !fn_1_8D690(entries[group_index * group_size + local_index].unk_0)) {
            entries[group_index * group_size + local_index].unk_4 |= (1u << 30);
        }
        if ((lbl_1_bss_8B3A0.unk_94 & 0x02000000) != 0 &&
            entries[group_index * group_size + local_index].unk_0 != 6 &&
            (entries[group_index * group_size + local_index].unk_4 & 0x80000000) == 0) {
            entries[group_index * group_size + local_index].unk_4 |= (1u << 31);
        }
    }
}
/* fzgx:end fn_1_151EF8 */

/* fzgx:begin fn_1_152840 */
typedef struct Entry {
    s16 id;
    u8 pad[2];
    u32 flags;
} Entry;

int fn_1_152840(s16 id, Entry *entries, s16 outer_count, s16 inner_count) {
    s16 count;
    s16 i;
    s16 j;

    if (id == -1) {
        return 0;
    }

    count = inner_count;
    for (i = 0; i < outer_count; i++) {
        for (j = 0; j < count; j++) {
            if ((entries[(i * count) + j].flags & (3u << 30)) == 0 &&
                id == entries[(i * count) + j].id) {
                return 1;
            }
        }
    }

    return 0;
}
/* fzgx:end fn_1_152840 */

/* fzgx:begin fn_1_1528D0 */
typedef struct Cell {
    s16 id;
    u8 pad[2];
    u32 flags;
} Cell;

s32 fn_1_1528D0(s16 x, s16 y, Cell *table, s16 unused, s16 multiplier) {
    s32 value;

    if (lbl_1_bss_8B3A0.unk_94 & 0x00020000) {
        if (table[(x * multiplier) + y].flags & ~0x3FFFFFFF)
            return -1;
    } else {
        if (table[(x * multiplier) + y].flags & 0x40000000)
            return -1;
    }

    value = table[(x * multiplier) + y].id;
    if (value != -1)
        return value;
    return -1;
}
/* fzgx:end fn_1_1528D0 */

/* fzgx:begin fn_1_152970 */
typedef struct {
    s16 key;
    u16 pad;
    u32 mask;
} Fn152970Entry;

s32 fn_1_152970(s16 *out_group, s16 *out_entry, s16 key, u32 mask,
                 Fn152970Entry *entries, s16 group_count, s16 entry_count) {
    s16 count;
    s16 group;
    s16 entry;

    if (key == -1) {
        return 0;
    }

    count = entry_count;
    for (group = 0; group < group_count; group++) {
        for (entry = 0; entry < count; entry++) {
            if ((entries[(group * count) + entry].mask & mask) == 0 &&
                key == entries[(group * count) + entry].key) {
                *out_group = group;
                *out_entry = entry;
                return 1;
            }
        }
    }
    return 0;
}
/* fzgx:end fn_1_152970 */
