#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "core.h"
#include "uval.h"
#include "mem.h"
#include "stack.h"


extern int pcounter;

/*
  Evaluation expresion
 */

void op_add(com *c){
  u_val u1,u2,ures;
  
  u1=pop();
  u2=pop();
  if ((isnull(u1)) || (isnull(u2)))
    error("no enough operators in stack to add\n");
  
  if (u1.type!=u2.type)
    error("operators type are diferents\n");
  
  ures.type=u1.type;
  if (ures.type==INT)
    ures.data.ival=u1.data.ival+u2.data.ival;
  if (ures.type==FLOAT)
    ures.data.fval=u1.data.fval+u2.data.fval;
  /*
    ¿Permitir suma de caracteres y de string?
  */
  push(ures);
}



void op_sub(com *c){
  u_val u1,u2,ures;
  
  u1=pop();
  u2=pop();
  if ((isnull(u1)) || (isnull(u2)))
    error("no enough operators in stack to add\n");
  
  if (u1.type!=u2.type)
    error("operators type are diferents\n");
  
  ures.type=u1.type;
  if (ures.type==INT)
    ures.data.ival=u1.data.ival-u2.data.ival;
  if (ures.type==FLOAT)
    ures.data.fval=u1.data.fval-u2.data.fval;
  push(ures);
}




void eval_op(com *c){
  
  
  if (!strcmp(c->cmd,"add")){
    op_add(c);
  }else if(!strcmp(c->cmd,"sub")){
    op_sub(c);
  }else
    error ("operation %s unknow\n",c->cmd);
}


void push_op(com *c,tab *t){
  u_val u;
  sim* s;
  
  if (!strcmp(c->arg1,"const")){
    u=get_u_val(c->arg2);
    push(u);
  }else if (!strcmp(c->arg1,"sim")){
    s=getsim(t,c->arg2);
    if (s==NULL)
      error("simbol unknow\n");
    u=s->val;
    if (isnull(u))
      error("simbol unknow\n");
    push(u);
  }
}





void error(char *fmt,...){
  
  va_list ap;
  char *p,*sval;
  int ival;

  printf ("error:");

  va_start(ap,fmt);
  for (p=fmt; *p;  p++){
    if (*p!='%'){
      putchar(*p);
      continue;
    }

    switch(*++p){
    case 'd':
      ival=va_arg(ap,int);
      printf ("%d",ival);
      break;

    case 's':
      for (sval = va_arg(ap,char*); *sval; sval++)
	putchar(*sval);
      break;

    default:
      putchar(*p);
      break;
    }
    
  }
  va_end(ap);
}



void panic(com *c,char *fmt,...){
  if (c==NULL)
    printf ("Panic at unknow line:");
  else
    printf ("Panic at line %d:",c->nline);
  error(fmt);
  exit(0);
}



void proccom(com *c,tab **t){
  
  u_val u;
  sim *s;
  char istr[4];


  switch (c->type){
    
  case C_PUSH:
    if (!isvalidcom(c,2))
      panic(c,"bad command");
    push_op(c,*t);
    break;
    
  case C_POP:
    if (!isvalidcom(c,1))
      panic(c,"bad command");
    u=pop();
    if (isnull(u))
      panic(c,"empty stack\n");
    addsim(*t,c->arg1,u);
    break;


  case C_ATH:
   if (!isvalidcom(c,0))
      panic(c,"bad command");
    eval_op(c);
    break;


  case C_LABEL:
   if (!isvalidcom(c,1))
      panic(c,"bad command");
    sprintf(istr,"%d",c->nline);
    u=get_u_val(istr);
    addsim(*t,c->arg1,u);
    break;


  case C_GOTO:
   if (!isvalidcom(c,1))
      panic(c,"bad command");
    s=getsim(*t,c->arg1);
    pcounter=s->val.data.ival;
    break;



  case C_GOTO_IFNZ:
   if (!isvalidcom(c,1))
      panic(c,"bad command");
    /*
      Si la cima de la pila no es cero salta
      a la etiqueta.
      Si el valor es igual cero continua
     */
    u=pop();
    if (isnull(u))
      panic(c,"empty stack\n");

    if ((u.type==INT) && (u.data.ival!=0)){
      s=getsim(*t,c->arg1);
      pcounter=s->val.data.ival;
    }
    break;


  case C_FUNCTION:
   if (!isvalidcom(c,1))
      panic(c,"bad command");
    u=pop();  // Guardo la direccion de retorno para volver al llamante
    if (isnull(u))
      panic(c,"empty stack");
    /*
      Aqui hemos de crear un nuevo entorno en la tabla
      de simbolos antes de incluir ret, en la nueva tabla.
      Debemos pasar un doble puntero de tab a proctoken
      porque en su interior esta tabla puede actualizarse.
    */
    newcontext(t,c->arg1);
    addsim(*t,"ret",u);
    printf ("Creo la tabla de simbolos %s\n",c->arg1);
    break;

    
  case C_CALL:
   if (!isvalidcom(c,1))
      panic(c,"bad command");
    //Meto en la pila la dir de retorno
    sprintf(istr,"%d",pcounter);
    u=get_u_val(istr);
    push(u);

    //Salto a la funcion
    s=getsim(*t,c->arg1);
    if (s==NULL){
      error("Not function %s defined\n",c->arg1);
      break;
    }
    if (isnull(u))
      panic(c,"bad function call");
    pcounter=s->val.data.ival;
    break;


  case C_RETURN:
    if (!isvalidcom(c,1))
      panic(c,"bad command");

    //Meter en la cima de la pila el simbolo que le precede a return
    push_op(c,*t);

    //Saltar a la direccion apuntada por el simbolo 'ret'
    s=getsim(*t,"ret");
    if (isnull(u))
      panic(c,"Return address not defined\n");
    pcounter=s->val.data.ival;
    // Borrar el contexto de la funcion y volver al padre
    delcontext(t);
    break;

  default:
    break;
  }
}


