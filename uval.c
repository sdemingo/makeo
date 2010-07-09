#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "uval.h"

u_val get_u_val(char *arg){

  u_val u;

  if (arg==NULL)  
    return null_u_val();
  
  if ((arg[0]=='"') && (arg[strlen(arg)-1]=='"')){
    u.type=STRING;
    u.data.sval=(char*)malloc(sizeof(char)*strlen(arg));
    arg++;
    strcpy(u.data.sval,arg);
    u.data.sval[strlen(u.data.sval)-1]='\0';
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

  char *str;

 
  str=(char*)malloc(50);

  if (isnull(u))
    return "null";

  if (u.type==STRING)
    strcpy(str,u.data.sval);
  else if (u.type==INT)
    sprintf (str,"%d",u.data.ival);
  
  return str;
}



int isnull(u_val u){
  return (u.type==NULLVAL);
}
