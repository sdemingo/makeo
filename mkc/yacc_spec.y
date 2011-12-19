%{
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

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

%token ADD
%token END_SENT

%token FUNCTION
%token BLOCK_START
%token BLOCK_END

%type <ival> EXP


%%

PROGRAM : FUNC             
;

FUNC: FUNCTION ID BLOCK_START SENT BLOCK_END  {printf("function main\n");}
;

SENT : ASIG | SENT ASIG       
;

ASIG: ID ASIG_OP EXP          {printf("pop %s\n",getsim($1));}
;

EXP:   INT                    {$$=$1; printf ("push const %d\n",$1);}
| ID                     {printf ("push sim %s\n",getsim($1));}
| ID ADD EXP             {printf ("push sim %s\n",getsim($1)); printf ("add\n"); }
| INT ADD EXP             {printf ("push const %d\n",$1); printf ("add\n"); }
;


%% 



