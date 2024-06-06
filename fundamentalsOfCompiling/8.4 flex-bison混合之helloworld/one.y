%{
	#include <stdio.h>
	#include <stdlib.h>

	// 显式声明 yylex 函数，未声明报错。
    int yylex(void);
    int yyerror(const char *s);
%}
%token HELLO
%%
program:
myhi;
myhi:
HELLO {printf("hello,world!\n");exit(1);}
;
%%