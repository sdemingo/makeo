
%{

#include <math.h>
%}

DIGITO   [0-9]
ID       [a-z][a-z0-9]*


%%

[\t ]+             /* noting */

^\n                /* noting */

\n                 printf("[END_SENT]\n");

"function"         printf( "[FUNC_DEF]\n");

"return"           printf( "[RET_DEF]\n");

"if"               printf("[IF]\n");

"while"            printf("[WHILE]\n");

"("                printf("[PAR_A]\n");

")"                printf("[PAR_B]\n");

"{"                printf("[BLOCK_START]\n");

"}"                printf("[BLOCK_END]\n");

"="                printf("[ASIG]\n");


{DIGITO}+                   printf( "[INT] (%s)\n", yytext);

{DIGITO}+.{DIGITO}+         printf( "[FLOAT] (%s)\n", yytext);

{ID}               printf( "[ID] (%s)\n", yytext);

"+"                printf( "[ADD]\n");

"-"                printf( "[SUB]\n"); 

"*"                printf( "[MUL]\n"); 

"/"                printf( "[DIV]\n"); 
              
"'".+[^']"'"       printf("[STRING] (%s)\n",yytext);

.                  printf( "[UNKNOW] value:%s\n", yytext );
     
   
%%

int yywrap()
{
   return(1);
}


/*
   main is in mkc.
*/