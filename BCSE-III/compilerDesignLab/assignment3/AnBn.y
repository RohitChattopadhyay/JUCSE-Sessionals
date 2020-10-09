%{
#include<stdio.h>
#include<stdlib.h>
%}

%token A B NL

%%
stmt: S NL {
   	printf("You provided a Valid String.\n");
    exit(0);
}
;
S: A S B |
;
%%

main()
{
    printf("\nPlease Enter String to parse: ");
    yyparse();
}

int yyerror()
{
	printf("You provided an Invalid String.\n");
    exit(0);
}