#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

void yy_load_buffer_state YY_PROTO(( void ));

void yy_init_buffer YY_PROTO(( YY_BUFFER_STATE b, FILE *file ));

void yy_flush_buffer YY_PROTO(( YY_BUFFER_STATE b ));

static void *yy_flex_alloc YY_PROTO(( yy_size_t ));

static void *yy_flex_realloc YY_PROTO(( void *, yy_size_t ));

#define YY_USES_REJECT

#define yywrap() 1
#define YY_SKIP_YYWRAP
typedef unsigned char YY_CHAR;
FILE *yyin = (FILE *) 0, *yyout = (FILE *) 0;
typedef int yy_state_type;
extern char *yytext;

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
extern "C" int yywrap YY_PROTO(( void ));
#endif

#ifdef YY_MALLOC_DECL
YY_MALLOC_DECL
#else
#if __STDC__
#include <stdlib.h>
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

void yy_load_buffer_state(void)
{
    yy_n_chars = yy_current_buffer->yy_n_chars;
    yytext = yy_c_buf_p = yy_current_buffer->yy_buf_pos;
    yyin = yy_current_buffer->yy_input_file;
    yy_hold_char = *yy_c_buf_p;
}

#ifndef YY_ALWAYS_INTERACTIVE
#ifndef YY_NEVER_INTERACTIVE
extern int isatty YY_PROTO(( int ));
#endif
#endif

void yy_init_buffer(YY_BUFFER_STATE b, FILE *file)
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


void yy_flush_buffer(YY_BUFFER_STATE b)
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

static void yy_fatal_error(yyconst char msg[])
{
    (void) fprintf(stderr, "%s\n", msg);
    exit(YY_EXIT_FAILURE);
}

static void *yy_flex_alloc(yy_size_t size)
{
    return (void *) malloc(size);
}

static void *yy_flex_realloc(void *ptr, yy_size_t size)
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
