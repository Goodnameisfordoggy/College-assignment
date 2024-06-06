%{
  #include <iostream>
  #include "calculate.h"  //由bison生成
  extern int yyerror(const char *);
  using namespace std;
%}
%%
[0-9]+         { yylval.dv = strtod(yytext,0); return Number; }  //无小数点
[0-9]+\.[0-9]+ { yylval.dv = strtod(yytext,0); return Number; }  //有小数点
[)(+*-/\n]       { return *yytext; } //直接返回字符为符号
[ \t]          ; //忽略空格         
%%
int yywrap()
{
  return 1;
}