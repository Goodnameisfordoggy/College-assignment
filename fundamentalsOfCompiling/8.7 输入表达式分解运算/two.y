%{
	#include <iostream>	
	using namespace std;
	int yylex();
	int yyerror(const char *);
%}
%token <iv> Number
%token <sv> Word
%union{
	int iv;
	char *sv;
}
%%
main:
main Number Word Word Number '\n' 
{cout<<$2+$5<<$3<<$4<<endl;free($3);free($4);}
|
;
%%
int yyerror(const char *s){	
	cout<<"Error: "<<s<<endl;
    exit(1); // 缺失返回值，示例未给出
}
int main(){
	yyparse();
	return 0;
}