%option noyywrap
%{
	#include <iostream>
	using namespace std;
%}
%%
[0-9]+	cout<<"number "; 
[a-zA-Z]+ cout<<"word ";
[ \t] /* ignore whitespace */
%%
int main(){
	yylex();
}