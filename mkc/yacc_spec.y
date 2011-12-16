%{
#include <stdlib.h>
#include <stdio.h>


void yyerror(const char *str)
{
        fprintf(stderr,"error: %s\n",str);
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

