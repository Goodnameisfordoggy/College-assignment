%{
  #include <iostream>
  using namespace std;
  int yylex();  //只是一个声明
  int yyerror(const char *); //必须要有
%}
%token <dv> Number
%type <dv> exp
%union {
  double dv;
}
%left '+' '-'
%left '*' '/'
%%
 
main : main exp '\n' { cout << "Result : " << $2 << endl; }
     | 
     ;
 
exp  : exp '+' exp  { $$ = $1 + $3; } // 示例缺失';'
     | exp '-' exp  { $$ = $1 - $3; }
     | exp '*' exp  { $$ = $1 * $3; }
     | exp '/' exp  { $$ = $1 / $3; }
     | '(' exp ')'  { $$ = $2; }
     | Number       { $$ = $1; }
     ;
  
%%
 
int yyerror(const char *emseg)
{
	cout << "Error: " << emseg << endl;
    exit(1); // 缺失返回值，示例未给出
}
 
int main()
{
  yyparse();
}