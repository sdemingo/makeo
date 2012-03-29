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
    //printf ("llamo a yyerror con str(%s)\n",str);
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
%token SUB
%token MUL
%token DIV
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
%token IF
%token EQ
%token NQ
%token LT
%token GT
%token AND
%token OR

%type <ival> EXP
%type <ival> EXP2
%type <ival> LEXP
%type <ival> LEXP2
%type <ival> RETURN_SENT
%type <ival> FUNC_HDR
%type <literal> STRING
%type <ival> PARAM_DEF
%type <ival> PARAM_CALL
%type <ival> IF_HDR


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


FUNC_MAIN_HDR: FUNCTION MAIN_ID PAR_A PAR_C      
{
  built_in();encode("function main\n");
} 
;


FUNCS : FUNC_CODE | FUNCS FUNC_CODE              
;








/* 
   --------- Declaración de funciones --------- 
*/

FUNC_CODE : FUNC_HDR BLOCK_START BLOCK_SENT RETURN_SENT 
{
  getsim($4)->stype=$4;
}
;

FUNC_HDR: FUNCTION ID PAR_A PAR_C      
{
  $$=$2;    //index of func name simbol
  //generar #header si es necesario
  encode("function %s\n",getsim($2)->name);
} 


| FUNCTION ID PAR_A PARAM_DEF PAR_C    
{
  $$=$2;    //index of func name simbol
  getsim($2)->ival=$4; //num of params
  encode("function %s\n",getsim($2)->name);
  while ((sim_i=pull_sim())>=0)
    {
      encode ("pop %s\n",getsim(sim_i)->name);
    }
} 
;


PARAM_DEF: ID                            
{
  $$=1;
  push_sim($1);
  getsim($1)->stype=S_PARAM;
}

| ID COMA PARAM_DEF                      
{
  $$=1+$3;
  push_sim($1);
  getsim($1)->stype=S_PARAM;
}
;


RETURN_SENT: RETURN EXP BLOCK_END        
{
  encode("return sim %s\n",getsim($2)->name); 
  $$=getsim($2)->stype;
}

| RETURN BLOCK_END                       
{ error("Return without a value or simbol");}


| BLOCK_END                              
{ 
  encode("return const 0\n");
  $$=S_NULL;
}
;




/* Para estructuras como while, ifs, fors, etc usaremos producciones
similares a las que hemos usado con las funciones, separando la
cabecera de la estructura y luego el bloque de código*/


BLOCK_SENT: BLOCK_SENT SENT     
| /* vacio */


SENT : ASIG 
| FUNC_CALL 
| IF_SENT
;







/*
  --------- Expresiones --------- 
*/

ASIG: ID ASIG_OP EXP          
{
  getsim($1)->stype=$3;
  encode("pop %s\n",getsim($1)->name);
}

| ID ASIG_OP LEXP
{
  getsim($1)->stype=S_BOOLEAN;
  encode("pop %s\n",getsim($1)->name);
}
;


EXP: EXP2 ID
{
  if (!cmptypes($1,getsim($2)->stype))
    error("Type error");
  $$=$1;
  encode("push sim %s\n",getsim($2)->name);
  dumpcode();               //codigo apilado desde EXP2
}

| EXP2 INT
{  
  if (!cmptypes($1,S_INT))
    error("Type error. Integer expected");
  $$=S_INT;
  encode("push const %d\n",$2);
  dumpcode();               //codigo apilado desde EXP2
}


| EXP2 STRING
{
  if (!cmptypes($1,S_STRING))
    error("Type error. String expected");
  $$=S_STRING;
  encode("push const %s\n",$2);
  dumpcode();               //codigo apilado desde EXP2
}

| ID
{
  //1if (getsim($1)->stype==S_NULL)
  //  error("a id must be incializated before using it");
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
  $$=S_PARAM;
}


| PAR_A EXP PAR_C
{
  $$=$2;

}

| EXP2 PAR_A EXP PAR_C
{
  $$=$3;
}
;


/* 
   --------- Math expresions --------- 
*/

EXP2: EXP SUB
{
  if (cmptypes($1,S_STRING))
    error("Operation not allowed with strings");
  else
    pushcode("sub\n");
  $$=$1;
} 

| EXP MUL
{
  if (cmptypes($1,S_STRING))
    error("Operation not allowed with strings");
  else
    pushcode("mul\n");
  $$=$1;
} 

| EXP ADD
{
  pushcode("add\n");
  $$=$1;
}

;


/* 
   --------- Booleans expresions --------- 
*/

LEXP: LEXP2 ID
{
  encode("push sim %s\n",getsim($2)->name);
  dumpcode();
}

| LEXP2 INT
{
  encode("push const %d\n",$2);
  dumpcode();
}

| LEXP2 STRING
{
  encode("push const %s\n",$2);
  dumpcode();
}

| LEXP2 PAR_A LEXP PAR_C
;


LEXP2: ID LOP
{
  pushcode("push sim %s\n",getsim($1)->name);
}

| INT LOP
{
  pushcode("push const %d\n",$1);
}

| STRING LOP
{
  pushcode("push const %s\n",$1);
}

| PAR_A LEXP PAR_C LOP
{
}
;


LOP: EQ
{
  pushcode("eq\n");
}

| AND
{
  pushcode("and\n");
}

| OR
{
  pushcode("or\n");
}








/*
  --------- Llamadas a función ---------   
*/

FUNC_CALL: ID PAR_A PARAM_CALL PAR_C       
{
  if (getsim($1)->ival != $3)
    error("Function bad called. Wrong parametres number");
  encode("call %s\n",getsim($1)->name);   
}

| ID PAR_A PAR_C                      
{
  encode("call %s\n",getsim($1)->name); 
}
;


PARAM_CALL: ID                              
{
  $$=1; 
  encode("push sim %s\n",getsim($1)->name); 
}

| ID COMA PARAM_CALL                        
{
  $$=1+$3; 
  encode("push sim %s\n",getsim($1)->name); 
}

| INT                                       
{
  $$=1; 
  encode("push const %d\n",$1); 
}

| INT COMA PARAM_CALL                       
{
  $$=1+$3; 
  encode("push const %d\n",$1); 
}

| STRING                                    
{
  $$=1; 
  encode("push const %s\n",$1); 
}

| STRING COMA PARAM_CALL                    
{
  $$=1+$3; 
  encode("push const %s\n",$1); 
}




/*
  ---------  Sentencias IF --------- 
*/

IF_SENT: IF_HDR BLOCK_START BLOCK_SENT BLOCK_END
{
  encode ("label %s\n",getsim($1)->name);
}
;

IF_HDR: IF PAR_A LEXP PAR_C
{
  /* 
     we create the if label to jump it and we add
     the label to the simtable
  */

  char iflabel[15];   
  sprintf(iflabel,"fi-%d",yylineno);
  int li=addsim(iflabel);
  encode ("goto-ifz %s\n",getsim(li)->name);
  $$=li;
}
;



%% 

