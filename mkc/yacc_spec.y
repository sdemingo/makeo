%{
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

extern int yylineno;


 void yyerror(const char *str)
 {
   fprintf(stderr,"line %d: %s\n",yylineno,str);
 }
 
 void encode(char *fmt,...){

   FILE *out = stdout;

   va_list ap;
   char *p, *sval;
   int ival;

   va_start(ap,fmt);
   for (p = fmt; *p; p++){
     if (*p !='%'){
       fputc(*p,out);
       continue;
     }
     switch (*++p){
     case 'd':
       ival=va_arg(ap,int);
       fprintf(out,"%d",ival);
       break;
     case 's':
       for (sval=va_arg(ap,char*);*sval;sval++)
	 fputc(*sval,out);
       break;
     default:
       fputc(*p,out);
       break;
     }
   }
   va_end(ap);
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

PROGRAM : BLOCK_CODE           
;

BLOCK_CODE: INIT_STRUCT BLOCK_START BLOCK_SENT BLOCK_END 
| INIT_STRUCT SENT
;

INIT_STRUCT: FUNCTION ID       {encode("function main\n");} 
/* Para este no terminal añadiremos más producciones para cada bloque
con inicio especial como while, for, ifs, ...  */
;

BLOCK_SENT: BLOCK_SENT SENT 
| /* vacio */
;

SENT : ASIG       
;

ASIG: ID ASIG_OP EXP          {encode("pop %s\n",getsim($1));}
;

EXP:   INT                    {$$=$1; encode("push const %d\n",$1);}
| ID                     {encode("push sim %s\n",getsim($1));}
| ID ADD EXP             {encode("push sim %s\n",getsim($1)); encode("add\n"); }
| INT ADD EXP            {encode("push const %d\n",$1); encode("add\n"); }
;


%% 
