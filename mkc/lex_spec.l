
%{

#include <math.h>
#include "y.tab.h"

int yylineno;

%}

BLANK    [\t ]
DIGITO   [0-9]
ID       [a-z0-9]*


%%

{BLANK}+           /* blank caracter - noting */

{BLANK}+\n         /* blank line - noting */

^\n                /* blank line - noting */

{BLANK}+"#".+      /* comment - noting */

"function"         printf( "[FUNC_DEF]\n");

"return"           printf( "[RET_DEF]\n");

"if"               printf("[IF]\n");

"while"            printf("[WHILE]\n");

"("                printf("[PAR_A]\n");

")"                printf("[PAR_B]\n");

"{"                printf("[BLOCK_START]\n");

"}"                printf("[BLOCK_END]\n");

"="                {return ASIG_OP;}


{DIGITO}+                   {yylval.ival=atoi(yytext); return INT;}

{DIGITO}+.{DIGITO}+         printf( "[FLOAT] (%s)\n", yytext);

{ID}               {yylval.sval=addsim(yytext); return ID;}

"+"                printf( "[ADD]\n");

"-"                printf( "[SUB]\n"); 

"*"                printf( "[MUL]\n"); 

"/"                printf( "[DIV]\n"); 
              
"'".+[^']"'"       printf("[STRING] (%s)\n",yytext);

\n                 printf("[END_SENT]\n");

.                  printf( "[UNKNOW] value:%s\n", yytext );
     
   
%%

int yywrap()
{
   return(1);
}




/*
   main is in mkc.
*/