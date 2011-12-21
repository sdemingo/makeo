%{
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "sim.h"

extern int yylineno;
FILE *out;
int sim_i;

void yyerror(const char *str)
{
    fprintf(stderr,"line %d: %s\n",yylineno,str);
}

void encode(char *fmt,...){

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


/* Con este metodo realizamos el linkado de los diferentes archivos */
/* referenciados en la cabecera de nuestro programa */

void link_mod(char *mod){

  FILE *fd;
  char buf[512];
  char *modpath;
  int n;
  char rc;

  modpath=getenv("MKPATH");
  modpath=strcat(modpath,"/module/");
  modpath=strcat(modpath,mod);

  fd=fopen(modpath,"r");

  if (fd==NULL)
    yyerror("Module file not found");

  fputc('\n',out);
  for (; (rc = getc(fd)) != EOF;)
    fputc(rc,out);

  fputc('\n',out);
       
  close(fd);
}

%}
%union {
  int ival;
  int sval;  //simbol index
  int sim_v [10]; //vector de indices de simbols
  char *literal;
};


%token <sval> ID
%token ASIG_OP
%token <ival> INT

%token ADD
%token END_SENT
%token STRING

%token FUNCTION
%token RETURN
%token MAIN_ID
%token BLOCK_START
%token BLOCK_END
%token PAR_A
%token PAR_C
%token COMA

%type <ival> EXP
%type <literal> STRING


%%

PROGRAM : FUNC_MAIN_CODE  |  FUNCS FUNC_MAIN_CODE   
;

FUNC_MAIN_CODE: FUNC_MAIN_HDR BLOCK_START BLOCK_SENT BLOCK_END 
| FUNC_MAIN_HDR SENT       
		/*|  error  {yyerror("Falta funcion main");exit(-1);}  */
;


FUNC_MAIN_HDR: FUNCTION MAIN_ID PAR_A PAR_C      {link_mod("sys.il");encode("function main\n");} 
;


FUNCS : FUNC_CODE | FUNCS FUNC_CODE              
;



/* Reglas para la declaración de funciones */

FUNC_CODE : FUNC_HDR BLOCK_START BLOCK_SENT RETURN_SENT BLOCK_END 
|  FUNC_HDR BLOCK_START BLOCK_SENT BLOCK_END 
| FUNC_HDR SENT RETURN_SENT
| FUNC_HDR SENT    
;

FUNC_HDR: FUNCTION ID PAR_A PAR_C      {encode("function %s\n",getsim($2)->name);} 

| FUNCTION ID PAR_A PARAM_DEF PAR_C    
					{
					  encode("function %s\n",getsim($2)->name);
					  while ((sim_i=pull_sim())>=0)
					    {
					      encode ("pop %s\n",getsim(sim_i)->name);
					    }
					 } 
;

PARAM_DEF: ID                            {push_sim($1);}
| ID COMA PARAM_DEF                      {push_sim($1);}
;

RETURN_SENT: RETURN ID                   {encode("return sim %s\n",getsim($2)->name); }
;







/* Para estructuras como while, ifs, fors, etc usaremos producciones
similares a las que hemos usado con las funciones, separando la
cabecera de la estructura y luego el bloque de código*/


BLOCK_SENT: BLOCK_SENT SENT 
| /* vacio */
;

SENT : ASIG       
;

ASIG: ID ASIG_OP EXP          {encode("pop %s\n",getsim($1)->name);}
;

EXP:   INT               {$$=$1;encode("push const %d\n",$1);}
| ID                     {encode("push sim %s\n",getsim($1)->name);}
| ID ADD EXP             {encode("push sim %s\n",getsim($1)->name); encode("add\n"); }
| INT ADD EXP            {encode("push const %d\n",$1); encode("add\n"); }
| FUNC_CALL              
;


/* Reglas para la llamada a funciones */

FUNC_CALL: ID PAR_A PARAM_CALL PAR_C       {encode("call %s\n",getsim($1)->name); }
| ID PAR_A PAR_C                      {encode("call %s\n",getsim($1)->name); }
;


PARAM_CALL: ID                              {encode("push sim %s\n",getsim($1)->name); }
| ID COMA PARAM_CALL                        {encode("push sim %s\n",getsim($1)->name); }
| INT                                       {encode("push const %d\n",$1); }
| INT COMA PARAM_CALL                       {encode("push const %d\n",$1); }
| STRING                                    {encode("push const %s\n",$1); }
| STRING COMA PARAM_CALL                    {encode("push const %s\n",$1); }



%% 


