%{
int chars = 0;
int words = 0;
int lines = 0;
#include <string.h>
%}
%%
[a-zA-Z]+ {words++; chars += strlen(yytext);}
\n  { chars++; lines++; }
.  { chars++; }
%%
int main(int argc, char **argv){
   yylex();
   printf("行数：%d，单词数：%d，字符数：%d\n", lines, words, chars);
}
int yywrap(){
return 1;
}