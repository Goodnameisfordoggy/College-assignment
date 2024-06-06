%{
	#include <stdlib.h>
	#include "one.tab.h"

    int yyerror(void); // 显式声明 yyerror 函数，未声明报错。
%}
%%
"hi""\n" {return HELLO;}
. {yyerror();}
%%
int main(){
	yyparse();
	return 0;
}
int yyerror(){
	printf("error\n");
	exit(1);
}
int yywrap(){
	return 0;
}