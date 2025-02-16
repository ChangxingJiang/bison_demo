#include "calculator.h"
#include <stdio.h>

char *yytext;

int yy_cnt = 0;

int yylex(YYSTYPE *lvalp) {
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
