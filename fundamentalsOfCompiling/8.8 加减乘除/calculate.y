%{
  #include <iostream>
  using namespace std;
  int yylex();  //ֻ��һ������
  int yyerror(const char *); //����Ҫ��
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
 
exp  : exp '+' exp  { $$ = $1 + $3; } // ʾ��ȱʧ';'
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
    exit(1); // ȱʧ����ֵ��ʾ��δ����
}
 
int main()
{
  yyparse();
}