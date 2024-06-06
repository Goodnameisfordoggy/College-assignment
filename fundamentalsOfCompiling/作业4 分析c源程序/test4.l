/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-06-02 23:14:03
 * @FilePath: \c++c:\Users\HDJ\Desktop\User\作业4 分析c源程序\test4.l
 * @Description: 
 * 
 * 				*		写字楼里写字间，写字间里程序员；
 * 				*		程序人员写程序，又拿程序换酒钱。
 * 				*		酒醒只在网上坐，酒醉还来网下眠；
 * 				*		酒醉酒醒日复日，网上网下年复年。
 * 				*		但愿老死电脑间，不愿鞠躬老板前；
 * 				*		奔驰宝马贵者趣，公交自行程序员。
 * 				*		别人笑我忒疯癫，我笑自己命太贱；
 * 				*		不见满街漂亮妹，哪个归得程序员？    
 * Copyright (c) 2024 by HDJ, All Rights Reserved. 
 */
 
%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int line_num = 1;
int start_of_line = 1;

void convert_exponential(char *exp);
void print_line_num();
%}

KEYWORD "if"|"else"|"int"|"double"|"return"|"float"|"char"|"void"
IDENT   [a-zA-Z_][a-zA-Z0-9_]*

%%

\n                     { if(start_of_line) print_line_num(); printf("\n"); line_num++; start_of_line = 1; } /* 打印行号，增加行号计数，并换行 */
[ \t]+                 { if(start_of_line) print_line_num(); start_of_line = 0; printf(" "); } /* 将每个非空的空白符号序列替换为单个空格 */
{KEYWORD}              { if(start_of_line) print_line_num(); start_of_line = 0; for(int i = 0; i < yyleng; i++) printf("%c", toupper(yytext[i])); }
{IDENT}                { if(start_of_line) print_line_num(); start_of_line = 0; printf("_"); for(int i = 0; i < yyleng; i++) printf("%c", tolower(yytext[i])); }
[0-9]+[eE][-+]?[0-9]+  { if(start_of_line) print_line_num(); start_of_line = 0; convert_exponential(yytext); }
.                      { if(start_of_line) print_line_num(); start_of_line = 0; printf("%s", yytext); } /* 其他字符直接输出 */

%%

void convert_exponential(char *exp) {
    double val = atof(exp);
    printf("%g", val);
}

void print_line_num() {
    printf("%d  ", line_num);
}

int main(int argc, char **argv) {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
