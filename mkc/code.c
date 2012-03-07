
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "code.h"
#include "sim.h"


char *realloc_str(char *str){
  
  char *aux;
  aux=(char*)malloc(strlen(str)*2);
  strcpy(aux,str);
  str=aux;

  return str;
}


void proc_fmt(char **out, char *fmt,...){

  va_list ap;
  char *p, *sval;
  int ival;
  int off=0;

  va_start(ap,fmt);
  for (p = fmt; *p; p++){
    if (*p !='%'){
      //fputc(*p,out);
      sprintf(*out,"%c",*p);
      continue;
    }
    switch (*++p){
    case 'd':
      ival=va_arg(ap,int);
      //fprintf(out,"%d",ival);
      sprintf(*out,"%c",*p);
      break;
    case 's':
      //for (sval=va_arg(ap,char*);*sval;sval++)
      //fputc(*sval,out);
      sprintf(*out,"%s",sval);
      break;
    default:
      //fputc(*p,out);
      sprintf(*out,"%c",*p);
      break;
    }
  }
  va_end(ap);

  //  return out;
}



void encode(char *fmt,...){

  char *s,*aux;
  s=(char*)malloc(sizeof(char)*500);

  aux=s;
  proc_fmt(&s,fmt);
  fputs(aux,out);  
}


void push_code(char *fmt,...){

}


char *dump_code(){

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


void load_mod(char *mod){

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
