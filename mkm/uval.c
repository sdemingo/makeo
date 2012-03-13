#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "uval.h"





void escapes(char **str){

  char *p,*final,*aux;
  int c;

  final=(char*)malloc(strlen(*str));
  aux=final;

  for (p=*str;*p!='\0';p++,aux++){
    if (*p=='\\'){ //escape secuence
      p++;
      if (*p=='n')
	*aux=0x0A;
      if (*p=='t')
	*aux=0x09;
    }else{
      *aux=*p;
    }
    //aux++;
  }
  *aux='\0';
  *str=final;
}



u_val get_u_val(char *arg){

  u_val u;

  if (arg==NULL)  
    return null_u_val();
  
  if (((arg[0]=='\'') && (arg[strlen(arg)-1]=='\'')) 
      ||((arg[0]=='"') && (arg[strlen(arg)-1]=='"')) ){

    u.data.sval=(char*)malloc(strlen(arg));
    strcpy(u.data.sval,arg);
 
    u.type=STRING;
    u.data.sval++;
    u.data.sval[strlen(arg)-2]='\0';

    sprintf(u.data.sval,"%s",u.data.sval);
    //escapes(&u.data.sval);
    

  }else{
    u.type=INT;
    u.data.ival=atoi(arg);
  }

  return u;
}



u_val null_u_val(){
  u_val u;
  u.type=NULLVAL;
  u.data.ival=0;
  return u;
}



char* u_val2text(u_val u){

  //char *str;
  //str=(char*)malloc(50);

  static char str[50];

  if (isnull(u))
    return "null";

  if (u.type==STRING)
    return u.data.sval;

  else if (u.type==INT){
    sprintf(str,"%d",u.data.ival);
  }

  return str;
}


int u_valtype(char *str){

  if (!strcmp(str,"int"))
    return INT;
  else if (!strcmp(str,"string"))
    return STRING;
  else if (!strcmp(str,"float"))
    return FLOAT;
  else
    return NULLVAL;
}


int u_val2bytes(u_val u,char **buf){

  if ( (isnull(u)) || (*buf==NULL))
    return -1;

  if (u.type==STRING){
    strcpy(*buf,u.data.sval);
    return strlen(u.data.sval);
  }
  else if (u.type==INT){
    sprintf (*buf,"%d",u.data.ival);
    return sizeof(u.data.ival);
  }

  return 0;
}


int isnull(u_val u){
  return (u.type==NULLVAL);
}
