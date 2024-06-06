%option noyywrap
%{
    #include <stdio.h>
    int lines=0;

    void showtitle(); // 声明 showtitle 函数, 示例中未声明报错
%}

%%
title showtitle();
[\n] lines++;
[0-9]+ printf("Int: %s\n",yytext);
[0-9]*\.[0-9]+ printf("Float: %s\n",yytext);
[a-zA-Z][a-zA-Z0-9_]* printf("Var: %s\n",yytext);
[\+\-\*\/\%=;] printf("Op: %s\n",yytext);
[ \t]
. printf("Unknow: %c\n",yytext[0]);
%%

void showtitle() { // 定义 showtitle 函数
    printf("\n-- Lex Example --\n\n");
}

int main() { 
    yylex();
    printf("\nlines = %d\n", lines);
    return 0;
}
