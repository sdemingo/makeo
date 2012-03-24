
%{
#include <math.h>
#include "y.tab.h"

void strtokens(char **str);
void yylex2str(char *out,char *lex);

%}

%option yylineno

BLANK    [ \t]
DIGITO   [0-9]
LETTER   [a-z0-9.]*

%%

{BLANK}+           /* blank caracter - noting */

{BLANK}+\n         /* blank line - noting */

^\n                /* blank line - noting */

{BLANK}*"#".+      /* comment - noting */

"import"           return IMPORT;

"function"         return FUNCTION;

"return"           return RETURN;

"if"               return IF;

"while"            //printf("[WHILE]\n");

"("                return PAR_A;

")"                return PAR_C;

"{"                return BLOCK_START;

"}"                return BLOCK_END;

"="                {return ASIG_OP;}

","                return COMA;

    
"'"[^\']*"'"       {
                    yylex2str(yylval.literal,yytext);
                    return STRING;
                   }   

{DIGITO}+                   {
                             yylval.ival=atoi(yytext); 
                             return INT;
                            }

{DIGITO}+"."{DIGITO}+         printf( "[FLOAT] (%s)\n", yytext);

{LETTER}+          {if (!strcmp(yytext,"main")) 
                        return MAIN_ID;
                    else
                    {
                        yylval.sval=addsim(yytext);
                        return ID;
                    }
                   }

"+"                return ADD;

"-"                return SUB; 

"*"                return MUL; 

"/"                return DIV; 

"=="               return EQ; 

\n                 //return END_SENT;

.                  //printf( "[UNKNOW] value:%s\n", yytext );
     
   
%%

int yywrap()
{
   return(1);
}

void yylex2str(char *out,char *lex)
{
  char *s;
  out=(char*)malloc(strlen(lex));
  yylval.literal=strcpy(out,lex);
  s=lex;
  while(*s){
    if (*s=='\'')
      *out='"';
    *s++;
    *out++;
  }
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