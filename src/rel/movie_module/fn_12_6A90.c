#include "types.h"

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

// Compile-time offset checks verify the parser layout for the target ABI.
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

extern unsigned long lbl_12_bss_4DB8[2];
extern unsigned long lbl_12_bss_4DB0;

// The manager is the first member of the backing object; parser slots follow it.
#define MOVIE_PARSER_SLOTS(manager_ptr) \
    (((MovieParserBacking *)(manager_ptr))->slots)

extern s32 fn_12_6C78(MovieParser *parser);
extern s32 fn_12_6D5C(void *parser, s32 error);

static inline s32 parser_invalid(void *arg)
{
    MovieParser *parser = arg;
    lbl_12_bss_4DB0 = (unsigned long)arg;
    if (parser == 0) return -1;
    if (parser->state == 1) return -1;
    return 0;
}

static inline s32 parser_error(void *arg, s32 error)
{
    MovieParser *parser = arg;
    if (parser == 0) {
        MovieParserManager *system = (MovieParserManager *)lbl_12_bss_4DB8[0];
        system->error = error;
        if (error != 0 && system->callback != 0)
            system->callback(system->context, error);
    } else {
        parser->error = error;
        if (error != 0 && parser->callback != 0)
            parser->callback(parser->context, error);
    }
    return error;
}

// Initializes a parser in the supplied slot.
s32 fn_12_6A90(void *arg)
{
    MovieParser *parser = arg;
    if (parser_invalid(arg) != 0)
        return parser_error(0, (s32)0xFF020103);
    parser->state = 1;
    return 0;
}
