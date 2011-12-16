%{
#include <stdlib.h>
#include <stdio.h>

extern int yylineno;

void yyerror(const char *str)
{
  fprintf(stderr,"line %d: %s\n",yylineno,str);
}
 

%}

%token ID
%token ASIG_OP
%token INT

%%

SENT : ASIG
;

ASIG: ID ASIG_OP EXP        { }
;

EXP: INT                    {printf ("int:%d\n",yyval);}
;


%% 


