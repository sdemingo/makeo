%{
#include <stdlib.h>
#include <stdio.h>

extern int yylineno;

void yyerror(const char *str)
{
  fprintf(stderr,"line %d: %s\n",yylineno,str);
}
 

%}

%union {
  int ival;
  int sval;  //simbol index
};


%token <sval> ID
%token ASIG_OP
%token <ival> INT


%type <ival> EXP


%%

SENT : ASIG | SENT ASIG
;

ASIG: ID ASIG_OP EXP        {printf("%s=%d\n",getsim($1),$3);}
;

EXP: INT                    {$$=$1;}
;


%% 


