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


char* path(char *mod){

  char *modpath;

  modpath=(char*)malloc(sizeof(char)*512);
  strcpy(modpath,getenv("MKPATH"));
  if (modpath!=NULL){
    modpath=strcat(modpath,"/module/");
    modpath=strcat(modpath,mod);
    return modpath;
  }else{
    yyerror("Environment variable MKPATH not defined");
    return NULL;
  }
}


/* Con este metodo realizamos el linkado de los diferentes archivos */
/* referenciados en la cabecera de nuestro programa */

void link_mod(char *mod){

  FILE *fd;
  char buf[512];
  char *modpath;
  int n;
  char rc;

  fd=fopen(path(mod),"r");

  if (fd==NULL){
    yyerror("Module file not found");
  }else{
    fputc('\n',out);
    for (; (rc = getc(fd)) != EOF;)
      fputc(rc,out);
    fputc('\n',out);
    close(fd);
  }
}



void load_hdr_mod(char *mod){

  FILE *fd;
  char buf[512];
  int n;
  char rc;
  char lin[512];
  char *token;
  int n_token=0,in;

  fd=fopen(path(mod),"r");

  if (fd==NULL){
    yyerror("Module file not found");
  }else{
    while (fgets(lin, 512, fd) != NULL){
      if (strstr(lin,"#header")){
	token = strtok(lin, " ");
	while (token) {
	  n_token++;
	  if (n_token==2)
	    in=addsim(token);
	  if (n_token==3)
	    getsim(in)->ival=atoi(token);
	  token = strtok(NULL, " ");
	}
      }
    }
    close(fd);
  }
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

%token IMPORT
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
%type <ival> PARAM_DEF
%type <ival> PARAM_CALL

%%

PROGRAM : IMPORTS FUNC_MAIN_CODE  |  IMPORTS FUNCS FUNC_MAIN_CODE   
;

IMPORTS: IMPORTS IMPORT_DEF | ;


IMPORT_DEF: IMPORT ID                     {load_hdr_mod(getsim($2)->name);}
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
| FUNC_HDR BLOCK_START BLOCK_SENT BLOCK_END 
| FUNC_HDR SENT RETURN_SENT
| FUNC_HDR SENT    
;

FUNC_HDR: FUNCTION ID PAR_A PAR_C      {
                                         //generar #header
                                         encode("function %s\n",getsim($2)->name);
                                       } 

| FUNCTION ID PAR_A PARAM_DEF PAR_C    
					{
					  getsim($2)->ival=$4;
					  encode("function %s\n",getsim($2)->name);
					  while ((sim_i=pull_sim())>=0)
					    {
					      encode ("pop %s\n",getsim(sim_i)->name);
					    }
					} 
;

PARAM_DEF: ID                            {$$=1;push_sim($1);}
| ID COMA PARAM_DEF                      {$$=1+$3;push_sim($1);}
;

RETURN_SENT: RETURN ID                   {encode("return sim %s\n",getsim($2)->name); }
| RETURN                                 {encode("return const 0\n");}
;




/* Para estructuras como while, ifs, fors, etc usaremos producciones
similares a las que hemos usado con las funciones, separando la
cabecera de la estructura y luego el bloque de código*/


BLOCK_SENT: BLOCK_SENT SENT 
| /* vacio */


SENT : ASIG 
| FUNC_CALL 
;

ASIG: ID ASIG_OP EXP          {getsim($1)->stype=$3;encode("pop %s\n",getsim($1)->name);}
;

EXP:   INT               { 
                          $$=S_INT;
                          getsim($1)->stype=S_INT;
			  encode("push const %d\n",$1);
                         }
| ID                     {
                          $$=getsim($1)->stype;
                          encode("push sim %s\n",getsim($1)->name);
                         }
| ID ADD EXP             {
                          if (getsim($1)->stype!=$3)
			    yyerror("Type error");
			  else
			    encode("push sim %s\n",getsim($1)->name); encode("add\n"); 
                         }
| INT ADD EXP            {
                           encode("push const %d\n",$1); encode("add\n"); 
                         }
| FUNC_CALL 

| STRING                 {
                          $$=S_STRING;
			  encode("push const %s\n",$1); 
                         } 
;


/* Reglas para la llamada a funciones */

FUNC_CALL: ID PAR_A PARAM_CALL PAR_C       {
					     if (getsim($1)->ival != $3)
					       yyerror("Function bad called. Wrong parametres number");
                                             encode("call %s\n",getsim($1)->name); 
                                           }

| ID PAR_A PAR_C                      {encode("call %s\n",getsim($1)->name); }
;


PARAM_CALL: ID                              {$$=1; encode("push sim %s\n",getsim($1)->name); }
| ID COMA PARAM_CALL                        {$$=1+$3; encode("push sim %s\n",getsim($1)->name); }
| INT                                       {$$=1; encode("push const %d\n",$1); }
| INT COMA PARAM_CALL                       {$$=1+$3; encode("push const %d\n",$1); }
| STRING                                    {$$=1; encode("push const %s\n",$1); }
| STRING COMA PARAM_CALL                    {$$=1+$3; encode("push const %s\n",$1); }



%% 


