%{
	#include <stdio.h>
	#include <stdlib.h>

	// ��ʽ���� yylex ������δ��������
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