#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define YY_USE_PROTOS
#define YY_USE_CONST

#define yyconst const

#define YY_PROTO(proto) proto

#define YY_END_OF_BUFFER_CHAR 0

#define YY_BUF_SIZE 16384

typedef struct yy_buffer_state *YY_BUFFER_STATE;

extern int yyleng;
extern FILE *yyin, *yyout;

#define EOB_ACT_CONTINUE_SCAN 0
#define EOB_ACT_END_OF_FILE 1
#define EOB_ACT_LAST_MATCH 2

/* Return all but the first 'n' matched characters back to the input stream. */

#define yyless(n) \
	do \
		{ \
		/* Undo effects of setting up yytext. */ \
		*yy_cp = yy_hold_char; \
		YY_RESTORE_YY_MORE_OFFSET \
		yy_c_buf_p = yy_cp = yy_bp + n - YY_MORE_ADJ; \
		YY_DO_BEFORE_ACTION; /* set up yytext again */ \
		} \
	while ( 0 )

/* The following is because we cannot portably get our hands on size_t
 * (without autoconf's help, which isn't available because we want
 * flex-generated scanners to compile on their own).
 */
typedef unsigned int yy_size_t;


struct yy_buffer_state {
    FILE *yy_input_file;

    char *yy_ch_buf; /* input buffer */
    char *yy_buf_pos; /* current position in input buffer */

    /* Size of input buffer in bytes, not including room for EOB
     * characters.
     */
    yy_size_t yy_buf_size;

    /* Number of characters read into yy_ch_buf, not including EOB
     * characters.
     */
    int yy_n_chars;

    /* Whether we "own" the buffer - i.e., we know we created it,
     * and can realloc() it to grow it, and should free() it to
     * delete it.
     */
    int yy_is_our_buffer;

    /* Whether this is an "interactive" input source; if so, and
     * if we're using stdio for input, then we want to use getc()
     * instead of fread(), to make sure we stop fetching input after
     * each newline.
     */
    int yy_is_interactive;

    /* Whether we're considered to be at the beginning of a line.
     * If so, '^' rules will be active on the next match, otherwise
     * not.
     */
    int yy_at_bol;

    /* Whether to try to fill the input buffer when we reach the
     * end of it.
     */
    int yy_fill_buffer;

    int yy_buffer_status;
#define YY_BUFFER_NEW 0
#define YY_BUFFER_NORMAL 1
#define YY_BUFFER_EOF_PENDING 2
};

static YY_BUFFER_STATE yy_current_buffer = 0;

/* yy_hold_char holds the character lost when yytext is formed. */
static char yy_hold_char;

static int yy_n_chars; /* number of characters read into yy_ch_buf */


int yyleng;

static char *yy_c_buf_p = (char *) 0;

void yyrestart YY_PROTO(( FILE *input_file ));

void yy_load_buffer_state YY_PROTO(( void ));

YY_BUFFER_STATE yy_create_buffer YY_PROTO(( FILE *file, int size ));

void yy_init_buffer YY_PROTO(( YY_BUFFER_STATE b, FILE *file ));

void yy_flush_buffer YY_PROTO(( YY_BUFFER_STATE b ));

#define YY_FLUSH_BUFFER yy_flush_buffer( yy_current_buffer )

static void *yy_flex_alloc YY_PROTO(( yy_size_t ));

static void *yy_flex_realloc YY_PROTO(( void *, yy_size_t ));

#define YY_USES_REJECT

#define yywrap() 1
#define YY_SKIP_YYWRAP
typedef unsigned char YY_CHAR;
FILE *yyin = (FILE *) 0, *yyout = (FILE *) 0;
typedef int yy_state_type;
extern char *yytext;

static int yy_get_next_buffer YY_PROTO(( void ));

static void yy_fatal_error YY_PROTO(( yyconst char msg[] ));

/* Done after the current pattern has been matched and before the
 * corresponding action - sets up yytext.
 */
#define YY_DO_BEFORE_ACTION \
	yytext = yy_bp; \
	yyleng = (int) (yy_cp - yy_bp); \
	yy_hold_char = *yy_cp; \
	*yy_cp = '\0'; \
	yy_c_buf_p = yy_cp;

static yy_state_type yy_state_buf[YY_BUF_SIZE + 2], *yy_state_ptr;
static char *yy_full_match;
static int yy_lp;
#define REJECT \
{ \
*yy_cp = yy_hold_char; /* undo effects of setting up yytext */ \
yy_cp = yy_full_match; /* restore poss. backed-over text */ \
++yy_lp; \
goto find_rule; \
}
#define YY_MORE_ADJ 0
#define YY_RESTORE_YY_MORE_OFFSET
char *yytext;
#include "calculator.h"


/* Macros after this point can all be overridden by user definitions in
 * section 1.
 */

#ifndef YY_SKIP_YYWRAP
#ifdef __cplusplus
extern "C" int yywrap YY_PROTO(( void ));
#else
extern int yywrap YY_PROTO(( void ));
#endif
#endif

#ifndef YY_NO_UNPUT
static void yyunput YY_PROTO(( int c, char *buf_ptr ));
#endif

#ifndef YY_NO_INPUT
#ifdef __cplusplus
static int yyinput YY_PROTO(( void ));
#else
static int input YY_PROTO(( void ));
#endif
#endif

#if YY_STACK_USED
static int yy_start_stack_ptr = 0;
static int yy_start_stack_depth = 0;
static int *yy_start_stack = 0;

#else
#endif

#ifdef YY_MALLOC_DECL
YY_MALLOC_DECL
#else
#if __STDC__
#ifndef __cplusplus
#include <stdlib.h>
#endif
#else
/* Just try to get by without declaring the routines.  This will fail
 * miserably on non-ANSI systems for which sizeof(size_t) != sizeof(int)
 * or sizeof(void*) != sizeof(int).
 */
#endif
#endif

/* Amount of stuff to slurp up with each read. */
#ifndef YY_READ_BUF_SIZE
#define YY_READ_BUF_SIZE 8192
#endif

/* Gets input and stuffs it into "buf".  number of characters read, or YY_NULL,
 * is returned in "result".
 */
#ifndef YY_INPUT
#define YY_INPUT(buf,result,max_size) \
	if ( yy_current_buffer->yy_is_interactive ) \
		{ \
		int c = '*', n; \
		for ( n = 0; n < max_size && \
			     (c = getc( yyin )) != EOF && c != '\n'; ++n ) \
			buf[n] = (char) c; \
		if ( c == '\n' ) \
			buf[n++] = (char) c; \
		if ( c == EOF && ferror( yyin ) ) \
			YY_FATAL_ERROR( "input in flex scanner failed" ); \
		result = n; \
		} \
	else if ( ((result = fread( buf, 1, max_size, yyin )) == 0) \
		  && ferror( yyin ) ) \
		YY_FATAL_ERROR( "input in flex scanner failed" );
#endif

/* Report a fatal error. */
#ifndef YY_FATAL_ERROR
#define YY_FATAL_ERROR(msg) yy_fatal_error( msg )
#endif

int yy_cnt = 0;

int yylex(void) {
    if (yy_cnt == 0) {
        yy_cnt++;
        yytext = "3";
        printf(yytext);
        return NUM;
    }
    if (yy_cnt == 1) {
        printf("+");
        yy_cnt++;
        return ADD;
    }
    if (yy_cnt == 2) {
        yy_cnt++;
        yytext = "5";
        printf(yytext);
        return NUM;
    }
    if (yy_cnt == 3) {
        yy_cnt++;
        return BR;
    }
    return EOF;
}


/* yy_get_next_buffer - try to read in a new buffer
 *
 * Returns a code representing an action:
 *	EOB_ACT_LAST_MATCH -
 *	EOB_ACT_CONTINUE_SCAN - continue scanning from current position
 *	EOB_ACT_END_OF_FILE - end of file
 */

static int yy_get_next_buffer() {
    register char *dest = yy_current_buffer->yy_ch_buf;
    register char *source = yytext;
    register int number_to_move, i;
    int ret_val;

    if (yy_c_buf_p > &yy_current_buffer->yy_ch_buf[yy_n_chars + 1])
        YY_FATAL_ERROR(
        "fatal flex scanner internal error--end of buffer missed");

    if (yy_current_buffer->yy_fill_buffer == 0) {
        /* Don't try to fill the buffer, so this is an EOF. */
        if (yy_c_buf_p - yytext - YY_MORE_ADJ == 1) {
            /* We matched a single character, the EOB, so
             * treat this as a final EOF.
             */
            return EOB_ACT_END_OF_FILE;
        } else {
            /* We matched some text prior to the EOB, first
             * process it.
             */
            return EOB_ACT_LAST_MATCH;
        }
    }

    /* Try to read more data. */

    /* First move last chars to start of buffer. */
    number_to_move = (int) (yy_c_buf_p - yytext) - 1;

    for (i = 0; i < number_to_move; ++i)
        *(dest++) = *(source++);

    if (yy_current_buffer->yy_buffer_status == YY_BUFFER_EOF_PENDING)
    /* don't do the read, it's not guaranteed to return an EOF,
     * just force an EOF
     */
        yy_current_buffer->yy_n_chars = yy_n_chars = 0;

    else {
        int num_to_read =
                yy_current_buffer->yy_buf_size - number_to_move - 1;

        while (num_to_read <= 0) {
            /* Not enough room in the buffer - grow it. */
#ifdef YY_USES_REJECT
            YY_FATAL_ERROR(
                "input buffer overflow, can't enlarge buffer because scanner uses REJECT");
#else

			/* just a shorter name for the current buffer */
			YY_BUFFER_STATE b = yy_current_buffer;

			int yy_c_buf_p_offset =
				(int) (yy_c_buf_p - b->yy_ch_buf);

			if ( b->yy_is_our_buffer )
				{
				int new_size = b->yy_buf_size * 2;

				if ( new_size <= 0 )
					b->yy_buf_size += b->yy_buf_size / 8;
				else
					b->yy_buf_size *= 2;

				b->yy_ch_buf = (char *)
					/* Include room in for 2 EOB chars. */
					yy_flex_realloc( (void *) b->yy_ch_buf,
							 b->yy_buf_size + 2 );
				}
			else
				/* Can't grow it, we don't own it. */
				b->yy_ch_buf = 0;

			if ( ! b->yy_ch_buf )
				YY_FATAL_ERROR(
				"fatal error - scanner input buffer overflow" );

			yy_c_buf_p = &b->yy_ch_buf[yy_c_buf_p_offset];

			num_to_read = yy_current_buffer->yy_buf_size -
						number_to_move - 1;
#endif
        }

        if (num_to_read > YY_READ_BUF_SIZE)
            num_to_read = YY_READ_BUF_SIZE;

        /* Read in more data. */
        YY_INPUT((&yy_current_buffer->yy_ch_buf[number_to_move]),
                 yy_n_chars, num_to_read);

        yy_current_buffer->yy_n_chars = yy_n_chars;
    }

    if (yy_n_chars == 0) {
        if (number_to_move == YY_MORE_ADJ) {
            ret_val = EOB_ACT_END_OF_FILE;
            yyrestart(yyin);
        } else {
            ret_val = EOB_ACT_LAST_MATCH;
            yy_current_buffer->yy_buffer_status =
                    YY_BUFFER_EOF_PENDING;
        }
    } else
        ret_val = EOB_ACT_CONTINUE_SCAN;

    yy_n_chars += number_to_move;
    yy_current_buffer->yy_ch_buf[yy_n_chars] = YY_END_OF_BUFFER_CHAR;
    yy_current_buffer->yy_ch_buf[yy_n_chars + 1] = YY_END_OF_BUFFER_CHAR;

    yytext = &yy_current_buffer->yy_ch_buf[0];

    return ret_val;
}

#ifndef YY_NO_UNPUT
#ifdef YY_USE_PROTOS
static void yyunput(int c, register char *yy_bp)
#else
static void yyunput( c, yy_bp )
int c;
register char *yy_bp;
#endif
{
    register char *yy_cp = yy_c_buf_p;

    /* undo effects of setting up yytext */
    *yy_cp = yy_hold_char;

    if (yy_cp < yy_current_buffer->yy_ch_buf + 2) {
        /* need to shift things up to make room */
        /* +2 for EOB chars. */
        register int number_to_move = yy_n_chars + 2;
        register char *dest = &yy_current_buffer->yy_ch_buf[
            yy_current_buffer->yy_buf_size + 2];
        register char *source =
                &yy_current_buffer->yy_ch_buf[number_to_move];

        while (source > yy_current_buffer->yy_ch_buf)
            *--dest = *--source;

        yy_cp += (int) (dest - source);
        yy_bp += (int) (dest - source);
        yy_current_buffer->yy_n_chars =
                yy_n_chars = yy_current_buffer->yy_buf_size;

        if (yy_cp < yy_current_buffer->yy_ch_buf + 2)
            YY_FATAL_ERROR("flex scanner push-back overflow");
    }

    *--yy_cp = (char) c;

    yytext = yy_bp;
    yy_hold_char = *yy_cp;
    yy_c_buf_p = yy_cp;
}
#endif	/* ifndef YY_NO_UNPUT */


#ifdef __cplusplus
static int yyinput()
#else
static int input()
#endif
{
    int c;

    *yy_c_buf_p = yy_hold_char;

    if (*yy_c_buf_p == YY_END_OF_BUFFER_CHAR) {
        /* yy_c_buf_p now points to the character we want to return.
         * If this occurs *before* the EOB characters, then it's a
         * valid NUL; if not, then we've hit the end of the buffer.
         */
        if (yy_c_buf_p < &yy_current_buffer->yy_ch_buf[yy_n_chars])
        /* This was really a NUL. */
            *yy_c_buf_p = '\0';

        else {
            /* need more input */
            int offset = yy_c_buf_p - yytext;
            ++yy_c_buf_p;

            switch (yy_get_next_buffer()) {
                case EOB_ACT_LAST_MATCH:
                    /* This happens because yy_g_n_b()
                     * sees that we've accumulated a
                     * token and flags that we need to
                     * try matching the token before
                     * proceeding.  But for input(),
                     * there's no matching to consider.
                     * So convert the EOB_ACT_LAST_MATCH
                     * to EOB_ACT_END_OF_FILE.
                     */

                    /* Reset buffer status. */
                    yyrestart(yyin);

                /* fall through */

                case EOB_ACT_END_OF_FILE: {
                    if (yywrap())
                        return EOF;

#ifdef __cplusplus
					return yyinput();
#else
                    return input();
#endif
                }

                case EOB_ACT_CONTINUE_SCAN:
                    yy_c_buf_p = yytext + offset;
                    break;
            }
        }
    }

    c = *(unsigned char *) yy_c_buf_p; /* cast for 8-bit char's */
    *yy_c_buf_p = '\0'; /* preserve yytext */
    yy_hold_char = *++yy_c_buf_p;

    return c;
}


void yyrestart(FILE *input_file)
{
    if (!yy_current_buffer)
        yy_current_buffer = yy_create_buffer(yyin, YY_BUF_SIZE);

    yy_init_buffer(yy_current_buffer, input_file);
    yy_load_buffer_state();
}

#ifdef YY_USE_PROTOS
void yy_load_buffer_state(void)
#else
void yy_load_buffer_state()
#endif
{
    yy_n_chars = yy_current_buffer->yy_n_chars;
    yytext = yy_c_buf_p = yy_current_buffer->yy_buf_pos;
    yyin = yy_current_buffer->yy_input_file;
    yy_hold_char = *yy_c_buf_p;
}


#ifdef YY_USE_PROTOS
YY_BUFFER_STATE yy_create_buffer(FILE *file, int size)
#else
YY_BUFFER_STATE yy_create_buffer( file, size )
FILE *file;
int size;
#endif
{
    YY_BUFFER_STATE b;

    b = (YY_BUFFER_STATE) yy_flex_alloc(sizeof(struct yy_buffer_state));
    if (!b)
        YY_FATAL_ERROR("out of dynamic memory in yy_create_buffer()");

    b->yy_buf_size = size;

    /* yy_ch_buf has to be 2 characters longer than the size given because
     * we need to put in 2 end-of-buffer characters.
     */
    b->yy_ch_buf = (char *) yy_flex_alloc(b->yy_buf_size + 2);
    if (!b->yy_ch_buf)
        YY_FATAL_ERROR("out of dynamic memory in yy_create_buffer()");

    b->yy_is_our_buffer = 1;

    yy_init_buffer(b, file);

    return b;
}


#ifndef YY_ALWAYS_INTERACTIVE
#ifndef YY_NEVER_INTERACTIVE
extern int isatty YY_PROTO(( int ));
#endif
#endif

#ifdef YY_USE_PROTOS
void yy_init_buffer(YY_BUFFER_STATE b, FILE *file)
#else
void yy_init_buffer( b, file )
YY_BUFFER_STATE b;
FILE *file;
#endif


{
    yy_flush_buffer(b);

    b->yy_input_file = file;
    b->yy_fill_buffer = 1;

#if YY_ALWAYS_INTERACTIVE
	b->yy_is_interactive = 1;
#else
#if YY_NEVER_INTERACTIVE
	b->yy_is_interactive = 0;
#else
    b->yy_is_interactive = file ? (isatty(fileno(file)) > 0) : 0;
#endif
#endif
}


#ifdef YY_USE_PROTOS
void yy_flush_buffer(YY_BUFFER_STATE b)
#else
void yy_flush_buffer( b )
YY_BUFFER_STATE b;
#endif

{
    if (!b)
        return;

    b->yy_n_chars = 0;

    /* We always need two end-of-buffer characters.  The first causes
     * a transition to the end-of-buffer state.  The second causes
     * a jam in that state.
     */
    b->yy_ch_buf[0] = YY_END_OF_BUFFER_CHAR;
    b->yy_ch_buf[1] = YY_END_OF_BUFFER_CHAR;

    b->yy_buf_pos = &b->yy_ch_buf[0];

    b->yy_at_bol = 1;
    b->yy_buffer_status = YY_BUFFER_NEW;

    if (b == yy_current_buffer)
        yy_load_buffer_state();
}


#ifndef YY_EXIT_FAILURE
#define YY_EXIT_FAILURE 2
#endif

#ifdef YY_USE_PROTOS
static void yy_fatal_error(yyconst char msg[])
#else
static void yy_fatal_error( msg )
char msg[];
#endif
{
    (void) fprintf(stderr, "%s\n", msg);
    exit(YY_EXIT_FAILURE);
}


/* Redefine yyless() so it works in section 3 code. */

#undef yyless
#define yyless(n) \
	do \
		{ \
		/* Undo effects of setting up yytext. */ \
		yytext[yyleng] = yy_hold_char; \
		yy_c_buf_p = yytext + n; \
		yy_hold_char = *yy_c_buf_p; \
		*yy_c_buf_p = '\0'; \
		yyleng = n; \
		} \
	while ( 0 )

#ifdef YY_USE_PROTOS
static void *yy_flex_alloc(yy_size_t size)
#else
static void *yy_flex_alloc( size )
yy_size_t size;
#endif
{
    return (void *) malloc(size);
}

#ifdef YY_USE_PROTOS
static void *yy_flex_realloc(void *ptr, yy_size_t size)
#else
static void *yy_flex_realloc( ptr, size )
void *ptr;
yy_size_t size;
#endif
{
    /* The cast to (char *) in the following accommodates both
     * implementations that use char* generic pointers, and those
     * that use void* generic pointers.  It works with the latter
     * because both ANSI C and C++ allow castless assignment from
     * any pointer type to void*, and deal with argument conversions
     * as though doing an assignment.
     */
    return (void *) realloc((char *) ptr, size);
}
