#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "core.h"
#include "uval.h"
#include "mem.h"
#include "stack.h"


extern int pcounter;


void op_add(com *c){
  u_val u1,u2,ures;
  
  u1=pop();
  u2=pop();
  if ((isnull(u1)) || (isnull(u2)))
    error(c,"no enough operators in stack to add\n");
  
  if (u1.type!=u2.type)
    error(c,"operators type are diferents\n");
  
  ures.type=u1.type;
  if (ures.type==INT)
    ures.data.ival=u1.data.ival+u2.data.ival;

  if (ures.type==FLOAT)
    ures.data.fval=u1.data.fval+u2.data.fval;

  if (ures.type==STRING){
    int size=strlen(u1.data.sval)+strlen(u2.data.sval)+1;
    ures.data.sval=(char*)malloc(sizeof(char)*size);
    strcpy(ures.data.sval,u2.data.sval);
    strcat(ures.data.sval,u1.data.sval);
    ures.data.sval[size]='\0';
  }
  push(ures);
}



void op_sub(com *c){
  u_val u1,u2,ures;
  
  u1=pop();
  u2=pop();
  if ((isnull(u1)) || (isnull(u2)))
    error(c,"no enough operators in stack to sub\n");
  
  if (u1.type!=u2.type)
    error(c,"operators type are diferents\n");
  
  ures.type=u1.type;
  if (ures.type==INT)
    ures.data.ival=u2.data.ival-u1.data.ival;
  if (ures.type==FLOAT)
    ures.data.fval=u2.data.fval-u1.data.fval;
  if (ures.type==STRING)
    error(c,"sub operation not allowed for string\n");
  push(ures);
}



void op_mul(com *c){
  u_val u1,u2,ures;
  
  u1=pop();
  u2=pop();
  if ((isnull(u1)) || (isnull(u2)))
    error(c,"no enough operators in stack to mul\n");
  
  if (u1.type!=u2.type)
    error(c,"operators type are diferents\n");
  
  ures.type=u1.type;
  if (ures.type==INT)
    ures.data.ival=u1.data.ival*u2.data.ival;
  if (ures.type==FLOAT)
    ures.data.fval=u1.data.fval*u2.data.fval;
  if (ures.type==STRING)
    error(c,"sub operation not allowed for string\n");

  push(ures);
}





void io_op(com *c,tab *t){
  int index,fd;
  u_val u,*pu;
  sim *s;

  
  /* Open file */
  if (!strcmp(c->cmd,"open")){
    if (!isvalidcom(c,1))
      error(c,"bad command");
    
    s=getsim(t,c->arg1);
    if (s==NULL)
      error(c,"simbol not found");
    
    if ((index=io_open(s->val.data.sval))<0)
      error (c,"file %s can be opened\n",s->val.data.sval);
 
    u.type=INT;
    u.data.ival=index;
    push(u);


    /* Close file */
  }else if(!strcmp(c->cmd,"close")){
    if (!isvalidcom(c,1))
      error(c,"bad command");
    s=getsim(t,c->arg1);
    if (s==NULL)
      error(c,"simbol not found");
    fd=s->val.data.ival;
    
    if ((index=io_close(fd))<0)
      error (c,"file %s can be closed\n",s->val.data.ival);



    /* Write file */
  }else if(!strcmp(c->cmd,"write")){
    if (!isvalidcom(c,1))
      error(c,"bad command");
    s=getsim(t,c->arg1);
    if (s==NULL)
      error(c,"simbol not found");
    fd=s->val.data.ival;
    u=pop();
    if ((index=io_write(fd,u))<0)
      error (c,"error at write\n");



    /* Read file */
  }else if(!strcmp(c->cmd,"read")){
    if (!isvalidcom(c,2))
      error(c,"bad command");

    s=getsim(t,c->arg1);
    if (s==NULL)
      error(c,"simbol not found");
    fd=s->val.data.ival;
    u.type=u_valtype(c->arg2);
    if (isnull(u))
      error(c,"bad command");
    
    if ((index=io_read(fd,&u))<0)
      error(c,"error at read\n");
    
    push(u);
    
    
  }else
    error (c,"operation %s unknow\n",c->cmd);
}



void eval_op(com *c){
  
  if (!strcmp(c->cmd,"add")){
    op_add(c);
  }else if(!strcmp(c->cmd,"sub")){
    op_sub(c);
  }else if(!strcmp(c->cmd,"mul")){
    op_mul(c);
  }else
    error (c,"operation %s unknow\n",c->cmd);
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
      error(c,"simbol unknow\n");
    u=s->val;
    if (isnull(u))
      error(c,"simbol unknow\n");
    push(u);
  }
}





void error(com* c,char *fmt,...){
  
  va_list ap;
  char *p,*sval;
  int ival;

  if (c!=NULL){
    printf ("Error on command at line %d\n\t",c->nline);
    printcom(c);
  }else{
    printf ("Error on command at unknow line\n");
  }

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
  exit(-1);
}


void proccom(com *c,tab **t){
  
  u_val u;
  sim *s;
  char istr[4];


  switch (c->type){
    
  case C_PUSH:
    if (!isvalidcom(c,2))
      error(c,"bad command");
    push_op(c,*t);
    break;
    
  case C_POP:
    if (!isvalidcom(c,1))
      error(c,"bad command");
    u=pop();
    if (isnull(u))
      error(c,"empty stack\n");
    addsim(*t,c->arg1,u);
    //printf ("u_val2text: %s\n",u_val2text(u));
    break;


  case C_ATH:
   if (!isvalidcom(c,0))
      error(c,"bad command");
    eval_op(c);
    break;


  case C_LABEL:
   if (!isvalidcom(c,1))
      error(c,"bad command");
    sprintf(istr,"%d",c->nline);
    u=get_u_val(istr);
    addsim(*t,c->arg1,u);
    break;


  case C_GOTO:
   if (!isvalidcom(c,1))
      error(c,"bad command");
    s=getsim(*t,c->arg1);
    pcounter=s->val.data.ival;
    break;



  case C_GOTO_IFNZ:
   if (!isvalidcom(c,1))
      error(c,"bad command");

    u=pop();
    if (isnull(u))
      error(c,"empty stack\n");

    if ((u.type==INT) && (u.data.ival!=0)){
      s=getsim(*t,c->arg1);
      pcounter=s->val.data.ival;
    }
    break;


  case C_FUNCTION:
   if (!isvalidcom(c,1))
      error(c,"bad command");
    u=pop();                     //Save the return address to can back
    if (isnull(u))
      error(c,"empty stack\n");

    newcontext(t,c->arg1);
    addsim(*t,"ret",u);
    break;

    
  case C_CALL:
   if (!isvalidcom(c,1))
      error(c,"bad command");
    sprintf(istr,"%d",pcounter);
    u=get_u_val(istr);
    push(u);                     //push in the stack the return address

    s=getsim(*t,c->arg1);
    if (s==NULL){
      error(c,"Not function %s defined\n",c->arg1);
      break;
    }
    if (isnull(u))
      error(c,"bad function call");
    pcounter=s->val.data.ival;    //jump to the function address
    break;


  case C_RETURN:
    if (!isvalidcom(c,1))
      error(c,"bad command");

    push_op(c,*t);                //Push to stack the return value of the function

    s=getsim(*t,"ret");
    if (isnull(u))
      error(c,"Return address not defined\n");
    pcounter=s->val.data.ival;   //return to the caller
    delcontext(t);
    break;

  case C_IO:
    io_op(c,*t);

  default:
    break;
  }
}


