%{
#include "calculator.tab.h"
%}

%%

[0-9]+(\.[0-9]+)?  { yylval.fval = atof(yytext); return NUMBER; }
"+"                { return '+'; }
"-"                { return '-'; }
"*"                { return '*'; }
"/"                { return '/'; }
"("                { return '('; }
")"                { return ')'; }
[ \t]+             { /* 忽略空白字符 */ }
\n                 { return '\n'; }
.                  { /* 处理非法字符错误 */ fprintf(stderr, "非法字符: %s\n", yytext); exit(1); }

%%

int yywrap() {
    return 1;
}