%{
	#include <iostream>	
    #include <cstring>
	#include "twoy.h"	
	extern int yyerror(const char*);
	using namespace std;
%}
%%
[0-9]+ { yylval.iv=strtol(yytext,0,10);return Number;}
[a-zA-Z]+ {yylval.sv=strdup(yytext);return Word;}
[ \t];
\n {return *yytext;}
%%
int yywrap(){
	return 1;
}