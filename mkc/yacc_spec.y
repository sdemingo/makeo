%{
#include <stdlib.h>
#include <stdio.h>

  //int yylex(void);

void yyerror(const char *str)
{
        fprintf(stderr,"error: %s\n",str);
}
 
/* int yywrap() */
/* { */
/*         return 1; */
/* } */
  
/* main() */
/* { */
/*         yyparse(); */
/* }  */



%}

%token ID
%token ASIG_OP
%token INT

%%

ASIG: ID ASIG_OP INT        {printf (" asignación\n");}


%% 

