%{
#include <iostream>
int yylex();
int yyerror(const char *);
using namespace std;
float vars[128]={0};
float last=0;
%}
%token <cv> CHAR
%token SET ANS
%token <fv> Number
%type <fv> exp
%type <iv> cond
%union
{
  char iv;
  float fv;
  char cv;
}
%left '<' '>' '='
%left '+' '-'
%left '*' '/'
%left '?' ':'
%right '(' ')'
%%
program:
        program exp '\n' { cout << "Result: " << $2 << endl; last = $2; }
        | program stat '\n'
        | 
        ;
        
stat   :
        SET CHAR '=' exp { vars[$2] = $4; }
 
 
cond   :
        exp '<' exp     { $1<$3?$$=1:$$=0; }
        | exp '>' exp     { $1>$3?$$=1:$$=0; }
        | exp '<' '=' exp { $1<=$4?$$=1:$$=0; }
        | exp '>' '=' exp { $1>=$4?$$=1:$$=0; }
        | exp '=' exp     { $1==$3?$$=1:$$=0; }
        
exp    :
        Number        { $$ = $1; }
        | ANS          { $$ = last; }
        | CHAR         { $$ = vars[$1]; }
        | exp '+' exp  { $$ = $1 + $3; }
        | exp '-' exp  { $$ = $1 - $3; }
        | '(' exp ')'  { $$ = $2; }
        | exp '*' exp  { $$ = $1 * $3; }
        | exp '/' exp  { $$ = $1 / $3; }
        | cond '?' exp ':' exp { $1?$$=$3:$$=$5; }
        ;
%%
int yyerror(const char *s)
{
  cout<<s<<endl;
  exit(1); // 缺失返回值，示例未给出
}
int main(int argc,char **argv)
{
  yyparse();
}