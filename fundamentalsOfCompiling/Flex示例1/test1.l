%{
#include <stdio.h>
#include <string.h>
%} 
%%
([1-9]+[0-9]*)|[0]	ECHO;
[0-9]+\.[0-9]+		ECHO;
[a-z A-Z]+    ECHO;
.
%%
//单行注释
int main(int argc, char **argv)
{
  yylex();
  yywrap();
}
int yywrap()
{
	return 1;
}