%{
    #include <stdio.h>
%}
%%
"color" { printf("color"); }
"flavour" { printf("flavor......."); }
"clever" { printf("smart"); }
"smart" { printf("elegant"); }
"liberal" { printf("conservative"); }
. { printf("%s", yytext); }
%%
//main()
int main()
{
  yylex();
}
int yywrap() {
 return 1;
}