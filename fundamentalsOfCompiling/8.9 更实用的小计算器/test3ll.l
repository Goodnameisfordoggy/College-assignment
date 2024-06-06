%{
  #include <stdlib.h>
  #include "test3yy.h"
  int yyerror(char *);
%}
 
 
%%
[0-9]+        {
                yylval.fv = strtod(yytext,0);
                return Number;
              }
              
[0-9]+\.[0-9]+ {
                 yylval.fv = strtod(yytext,0);
                 return Number;
               }
               
[-+()?:<>=/*\n]      { return *yytext; }
[ \t]          ;
[a-zA-Z]          { yylval.cv = *yytext;
                 return CHAR;
               }
"set"          { return SET; }
"ans"          { return ANS; }               
%%
int yywrap()
{
	return 1;
}