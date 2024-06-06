%option noyywrap
%{
//里面的内容会被完整地复制到lex.yy.c 的开头，通常会用来放置include、define的信息
    #include <string.h>
    #include <stdio.h>
   int lines = 0;
   int chars = 0;
   int digits = 0;
   int others = 0;
%}
%%
[a-zA-Z] {chars++;}
[0-9] {digits++;}
\n {lines++; chars++;}
. {others++;}
%%
//下面的多个函数也会被完整的复制到lex.yy.c中
int main(){
    yylex();
	printf("# of lines: %d\n",lines);
	printf("# of chars: %d\n",chars);
	printf("# of digits: %d\n",digits);
	printf("# of others: %d\n",others);
}