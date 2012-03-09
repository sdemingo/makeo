
%{
#include <math.h>
#include "y.tab.h"

void strtokens(char **str);

%}

%option yylineno

BLANK    [\t ]
DIGITO   [0-9]
ID       [a-z0-9.]*


%%

{BLANK}+           /* blank caracter - noting */

{BLANK}+\n         /* blank line - noting */

^\n                /* blank line - noting */

{BLANK}*"#".+      /* comment - noting */

"import"           return IMPORT;

"function"         return FUNCTION;

"return"           return RETURN;

"if"               //printf("[IF]\n");

"while"            //printf("[WHILE]\n");

"("                return PAR_A;

")"                return PAR_C;

"{"                return BLOCK_START;

"}"                return BLOCK_END;

"="                {return ASIG_OP;}

","                return COMA;

"'".+[^']"'"     {
                    strtokens(&yytext);
                    yylval.literal=(char*)malloc(strlen(yytext)+1);
                    yylval.literal=strcpy(yylval.literal,yytext);
                    return STRING;
                   }   

{DIGITO}+                   {yylval.ival=atoi(yytext); return INT;}

{DIGITO}+.{DIGITO}+         printf( "[FLOAT] (%s)\n", yytext);

{ID}               {if (!strcmp(yytext,"main")) 
                        return MAIN_ID;
                    else
                        {yylval.sval=addsim(yytext);return ID;}
                    }

"+"                return ADD;

"-"                //printf( "[SUB]\n"); 

"*"                //printf( "[MUL]\n"); 

"/"                //printf( "[DIV]\n"); 

\n                 //return END_SENT;

.                  //printf( "[UNKNOW] value:%s\n", yytext );
     
   
%%

int yywrap()
{
   return(1);
}


void strtokens(char **str)
{
  char *s;
  s=*str;
  while(*s){
    if (*s=='\'')
      *s='"';
    *s++;
  }
}




/*
   main is in mkc.
*/