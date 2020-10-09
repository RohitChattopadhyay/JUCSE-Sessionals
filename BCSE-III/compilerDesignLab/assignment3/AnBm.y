%{
	#include<stdio.h>
	#include<stdlib.h>
%}
%token A B
%%
str: s '\n'	{return 0;}
s : T U ;
T : T A
| ;
U : B U
| ;
%%
main()
{
	printf("\nPlease Enter String to parse: ");
	yyparse();
	printf("You provided a Valid String.\n");
} 
int yyerror()
{
	printf("You provided an Invalid String.\n");
	exit(0);
}