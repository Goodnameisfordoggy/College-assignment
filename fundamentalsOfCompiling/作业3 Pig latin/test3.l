/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-06-02 22:18:47
 * @FilePath: \c++c:\Users\HDJ\Desktop\User\作业3 Pig latin\test3.l
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
#include <ctype.h>

void pig_latin(char *word);
%}

%%

[a-zA-Z]+    { pig_latin(yytext); }
[ \t\n]+     { printf("%s", yytext); }
.            { printf("%c", yytext[0]); }

%%

void pig_latin(char *word) {
    if (isalpha(word[0])) {
        char first = word[0];
        if (strchr("AEIOUaeiou", first)) {
            printf("%say ", word);
        } else {
            printf("%s%cay ", word + 1, first);
        }
    } else {
        printf("%s", word);
    }
}

int main(int argc, char **argv) {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
