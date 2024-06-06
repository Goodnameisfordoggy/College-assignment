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
%right POSITIVE // �������ȼ�
%right UMINUS // �������ȼ�
%type <fval> expr

%%

input:
    /* ������ */
    | input expr '\n'  { 
        if (floor($2) == $2) // ������������
            printf("���: %lld\n", (long long int)$2);
        else
            printf("���: %.15g\n", $2); // �Զ�ѡ����ʵĸ�ʽ�����������, ����15λС��
    }
    ;

expr:
    NUMBER            { $$ = $1; }
    | expr '+' expr   { $$ = $1 + $3; }
    | expr '-' expr   { $$ = $1 - $3; }
    | expr '*' expr   { $$ = $1 * $3; }
    | expr '/' expr   { 
        if ($3 == 0) {
            yyerror("��������Ϊ��");
            $$ = 0; // ���Ĭ��ֵ0
        } else {
            $$ = $1 / $3;
        }
    }
    | '+' expr %prec POSITIVE { $$ = $2; } // ���ű��ʽ�Ĺ���
    | '-' expr %prec UMINUS { $$ = -$2; } // ���ű��ʽ�Ĺ���
    | '(' expr ')'    { $$ = $2; }
    ;

%%

int main() {
    printf("��������ʽ:\n");
    return yyparse();
}

void yyerror(const char *s) {
    fprintf(stderr, "����: %s\n", s);
}
