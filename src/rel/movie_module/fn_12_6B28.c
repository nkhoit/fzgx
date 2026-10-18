#include "types.h"
// --- from fzgx/movie_parser.h ---

// --- from fzgx/movie_parser_layout.h ---

/* Builtin spellings intentionally match game s32/u32 without importing them
 * into the Dolphin BSS owner (whose u32 is unsigned long). */
typedef signed int (*MovieErrorCallback)(void *, signed int);
typedef struct MovieParserRecord { unsigned int words[8]; } MovieParserRecord;
typedef struct MovieParser {
    signed int state;
    MovieErrorCallback callback;
    void *context;
    signed int error;
    signed int kind;
    signed int timing[3];
    MovieParserRecord header;
    MovieParserRecord streams[3];
    MovieParserRecord summary;
} MovieParser;
typedef struct MovieParserManager {
    MovieErrorCallback callback;
    void *context;
    signed int error;
    signed int count;
} MovieParserManager;
typedef struct MovieParserBacking {
    MovieParserManager manager;
    MovieParser slots[32];
    unsigned char spare[4];
} MovieParserBacking;
extern MovieParserBacking lbl_12_bss_7E8C;

/* MWCC freestanding constant offsetof idiom; no evaluated null access. */
#define MOVIE_OFFSETOF(type, member) ((unsigned long)&(((type *)0)->member))
#define MOVIE_ABI_ASSERT(name, condition) typedef char name[(condition) ? 1 : -1]
MOVIE_ABI_ASSERT(movie_long_is_4, sizeof(unsigned long) == 4);
MOVIE_ABI_ASSERT(movie_pointer_is_4, sizeof(void *) == 4);
MOVIE_ABI_ASSERT(movie_s32_is_4, sizeof(signed int) == 4);
MOVIE_ABI_ASSERT(movie_u32_is_4, sizeof(unsigned int) == 4);
MOVIE_ABI_ASSERT(movie_callback_is_4, sizeof(MovieErrorCallback) == 4);
MOVIE_ABI_ASSERT(movie_record_is_20, sizeof(MovieParserRecord) == 0x20);
MOVIE_ABI_ASSERT(movie_parser_is_c0, sizeof(MovieParser) == 0xC0);
MOVIE_ABI_ASSERT(movie_manager_is_10, sizeof(MovieParserManager) == 0x10);
MOVIE_ABI_ASSERT(movie_state_at_00, MOVIE_OFFSETOF(MovieParser, state) == 0x00);
MOVIE_ABI_ASSERT(movie_callback_at_04, MOVIE_OFFSETOF(MovieParser, callback) == 0x04);
MOVIE_ABI_ASSERT(movie_context_at_08, MOVIE_OFFSETOF(MovieParser, context) == 0x08);
MOVIE_ABI_ASSERT(movie_error_at_0c, MOVIE_OFFSETOF(MovieParser, error) == 0x0C);
MOVIE_ABI_ASSERT(movie_kind_at_10, MOVIE_OFFSETOF(MovieParser, kind) == 0x10);
MOVIE_ABI_ASSERT(movie_timing_at_14, MOVIE_OFFSETOF(MovieParser, timing) == 0x14);
MOVIE_ABI_ASSERT(movie_header_at_20, MOVIE_OFFSETOF(MovieParser, header) == 0x20);
MOVIE_ABI_ASSERT(movie_streams_at_40, MOVIE_OFFSETOF(MovieParser, streams) == 0x40);
MOVIE_ABI_ASSERT(movie_summary_at_a0, MOVIE_OFFSETOF(MovieParser, summary) == 0xA0);
MOVIE_ABI_ASSERT(movie_manager_callback_at_00, MOVIE_OFFSETOF(MovieParserManager, callback) == 0);
MOVIE_ABI_ASSERT(movie_manager_context_at_04, MOVIE_OFFSETOF(MovieParserManager, context) == 4);
MOVIE_ABI_ASSERT(movie_manager_error_at_08, MOVIE_OFFSETOF(MovieParserManager, error) == 8);
MOVIE_ABI_ASSERT(movie_manager_count_at_0c, MOVIE_OFFSETOF(MovieParserManager, count) == 0xC);
MOVIE_ABI_ASSERT(movie_backing_manager_at_00, MOVIE_OFFSETOF(MovieParserBacking, manager) == 0);
MOVIE_ABI_ASSERT(movie_backing_slots_at_10, MOVIE_OFFSETOF(MovieParserBacking, slots) == 0x10);
MOVIE_ABI_ASSERT(movie_backing_spare_at_1810, MOVIE_OFFSETOF(MovieParserBacking, spare) == 0x1810);
MOVIE_ABI_ASSERT(movie_backing_is_1814, sizeof(MovieParserBacking) == 0x1814);
#undef MOVIE_ABI_ASSERT
#undef MOVIE_OFFSETOF

// --- from fzgx/movie_parser_storage.h ---

/* Matches dolphin/types.h u32 definitions in movie_module_bss.c exactly. */
extern unsigned long lbl_12_bss_4DB8[2];
extern unsigned long lbl_12_bss_4DB0;

/* Retail fn_12_266A8 passes &lbl_12_bss_7E8C and count 32 to fn_12_6ECC.
 * That symbol is a real MovieParserBacking, not a character-array overlay.
 * The saved integer address uses the target's 32-bit Gekko address ABI.
 * It designates the backing's first member, a MovieParserManager. Converting
 * that first-member pointer back to MovieParserBacking recovers the enclosing
 * object; selecting slots then derives a pointer into its actual 32-element
 * array. No byte traversal past the manager subobject is involved.
 * Initialization requires a MovieParserBacking and 0 <= count <= 32. The
 * observed caller uses the full capacity; an arbitrary byte buffer does not
 * satisfy this contract. Slot pointers remain within that actual array.
 */
#define MOVIE_PARSER_SLOTS(manager_ptr) \
    (((MovieParserBacking *)(manager_ptr))->slots)

extern s32 fn_12_6C78(MovieParser *parser);
extern s32 fn_12_6D5C(void *parser, s32 error);

/* Retail fn_12_33428 writes r5 words of r4 backwards into r3 storage. */
extern void fn_12_33428(void *storage, u32 value, u32 word_count);

static inline MovieParser *find_free_slot(void)
{
    MovieParser *slot;
    s32 i;
    MovieParserManager *manager = (MovieParserManager *)lbl_12_bss_4DB8[0];
    slot = MOVIE_PARSER_SLOTS(manager);
    for (i = 0; i < manager->count; i++, slot++) {
        if (slot->state == 1) {
            return slot;
        }
    }
    return 0;
}

void *fn_12_6B28(void)
{
    MovieParser *slot = find_free_slot();
    if (slot == 0) {
        return 0;
    }
    fn_12_33428(slot, 0, 0x30);
    slot->state = 2;
    slot->callback = 0;
    slot->context = 0;
    slot->error = 0;
    slot->kind = 2;
    slot->timing[0] = -1;
    slot->timing[1] = -1;
    slot->timing[2] = -1;
    slot->header.words[0] = -1;
    slot->header.words[1] = -1;
    slot->header.words[2] = -1;
    slot->header.words[3] = -1;
    slot->header.words[4] = -1;
    slot->header.words[5] = -1;
    slot->header.words[6] = -1;
    slot->header.words[7] = -1;
    slot->streams[0].words[0] = -1;
    slot->streams[0].words[1] = -1;
    slot->streams[0].words[2] = -1;
    slot->streams[0].words[3] = -1;
    slot->streams[0].words[4] = -1;
    slot->streams[0].words[5] = -1;
    slot->streams[0].words[6] = -1;
    slot->streams[0].words[7] = -1;
    slot->streams[1].words[0] = -1;
    slot->streams[1].words[1] = -1;
    slot->streams[1].words[2] = -1;
    slot->streams[1].words[3] = -1;
    slot->streams[1].words[4] = -1;
    slot->streams[1].words[5] = -1;
    slot->streams[1].words[6] = -1;
    slot->streams[1].words[7] = -1;
    slot->streams[2].words[0] = -1;
    slot->streams[2].words[1] = -1;
    slot->streams[2].words[2] = -1;
    slot->streams[2].words[3] = -1;
    slot->streams[2].words[4] = -1;
    slot->streams[2].words[5] = -1;
    slot->streams[2].words[6] = -1;
    slot->streams[2].words[7] = -1;
    slot->summary.words[0] = -1;
    slot->summary.words[1] = -1;
    slot->summary.words[2] = -1;
    slot->summary.words[3] = -1;
    slot->summary.words[4] = -1;
    slot->summary.words[5] = -1;
    slot->summary.words[6] = -1;
    slot->summary.words[7] = -1;
    return slot;
}
