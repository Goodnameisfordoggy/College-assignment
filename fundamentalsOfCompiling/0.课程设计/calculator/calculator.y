%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void yyerror(const char *s);
int yylex(void);

%}

%union {
    double fval;
}

%token <fval> NUMBER
%left '+' '-'
%left '*' '/'
%right POSITIVE // 正号优先级
%right UMINUS // 负号优先级
%type <fval> expr

%%

input:
    /* 空输入 */
    | input expr '\n'  { 
        if (floor($2) == $2) // 如果结果是整数
            printf("结果: %lld\n", (long long int)$2);
        else
            printf("结果: %.15g\n", $2); // 自动选择合适的格式来输出浮点数, 保留15位小数
    }
    ;

expr:
    NUMBER            { $$ = $1; }
    | expr '+' expr   { $$ = $1 + $3; }
    | expr '-' expr   { $$ = $1 - $3; }
    | expr '*' expr   { $$ = $1 * $3; }
    | expr '/' expr   { 
        if ($3 == 0) {
            yyerror("除数不能为零");
            $$ = 0; // 输出默认值0
        } else {
            $$ = $1 / $3;
        }
    }
    | '+' expr %prec POSITIVE { $$ = $2; } // 正号表达式的规则
    | '-' expr %prec UMINUS { $$ = -$2; } // 负号表达式的规则
    | '(' expr ')'    { $$ = $2; }
    ;

%%

int main() {
    printf("请输入表达式:\n");
    return yyparse();
}

void yyerror(const char *s) {
    fprintf(stderr, "错误: %s\n", s);
}
