%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sim.h"
#include "code.h"
  
  
  extern int yylineno;
  int sim_i;


  void yyerror(const char *str)
  {
    printf ("llamo a yyerror con str(%s)\n",str);
    if (str!=NULL)
      fprintf(stderr,"line %d: %s\n",yylineno,str);
  }

 
  
  void built_in(){
    load_il("sys.il");
    link_il("sys.il");
  }
  
  
  %}


%union {
  int ival;
  int sval;       //simbol index
  char *literal;
  char buf_code[64];       // buffer para subir código a través del árbol de no-terminales
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

%type <buf_code> EXP2

%%

PROGRAM : IMPORTS FUNC_MAIN_CODE  |  IMPORTS FUNCS FUNC_MAIN_CODE   
;

IMPORTS: IMPORTS IMPORT_DEF | ;


IMPORT_DEF: IMPORT ID                     {encode("import\n");}
;


FUNC_MAIN_CODE: FUNC_MAIN_HDR BLOCK_START BLOCK_SENT BLOCK_END       
| FUNC_MAIN_HDR SENT       
		/*|  error  {error("Falta funcion main");exit(-1);}  */
;


FUNC_MAIN_HDR: FUNCTION MAIN_ID PAR_A PAR_C      {built_in();encode("function main\n");} 
;


FUNCS : FUNC_CODE | FUNCS FUNC_CODE              
;



/* Reglas para la declaración de funciones */

FUNC_CODE : FUNC_HDR BLOCK_START BLOCK_SENT RETURN_SENT 
;

FUNC_HDR: FUNCTION ID PAR_A PAR_C      {
                                         //generar #header si es necesario
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

RETURN_SENT: RETURN EXP BLOCK_END         {encode("return sim %s\n",getsim($2)->name); }
| RETURN BLOCK_END                       {error("Return without a value or simbol");}
| BLOCK_END                              {encode("return const 0\n");}
;




/* Para estructuras como while, ifs, fors, etc usaremos producciones
similares a las que hemos usado con las funciones, separando la
cabecera de la estructura y luego el bloque de código*/


BLOCK_SENT: BLOCK_SENT SENT     {iferror();}
| /* vacio */



SENT : ASIG 
| FUNC_CALL 
;




ASIG: ID ASIG_OP EXP          
{
  getsim($1)->stype=$3;
  encode("pop %s\n",getsim($1)->name);
}
;


EXP: ID EXP2             
{
  $$=getsim($1)->stype;
  encode("push sim %s\n",getsim($1)->name);
  dumpcode();               //codigo apilado desde EXP2
}

| INT EXP2
{
  $$=S_INT;
  encode("push const %d\n",$1);
  dumpcode();               //codigo apilado desde EXP2
}


| STRING EXP2
{
  $$=S_STRING;
  encode("push const %s\n",$1);
  dumpcode();               //codigo apilado desde EXP2
}


| ID    
{
  $$=getsim($1)->stype;
  encode("push sim %s\n",getsim($1)->name);
}

| INT
{ 
  $$=S_INT;
  getsim($1)->stype=S_INT;
  encode("push const %d\n",$1);
}


| STRING
{
  $$=S_STRING;
  encode("push const %s\n",$1); 
} 

| FUNC_CALL              
{
  $$=S_INT;
}
;


EXP2: ADD EXP           
{
  pushcode("add\n");     //apilo código para descargarlo en EXP
}
;



/* Reglas para la llamada a funciones */

FUNC_CALL: ID PAR_A PARAM_CALL PAR_C       {
					     if (getsim($1)->ival != $3)
					       error("Function bad called. Wrong parametres number");
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


  //void error(const char *str);

