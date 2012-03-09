
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "code.h"
#include "sim.h"



char *codebuf;
int codebuf_sz = 400;


void encode(const char* fmt, ...)
{
  va_list args;
  char buffer[100];
 
  va_start(args,fmt);
  vsprintf (buffer, fmt, args);
  /*
    Usar vsnprintf para controlar los limites 
    y el valor de retorno para saber si se ha truncado
    el fmt al meterlo en el buffer
   */
   
  fprintf(out,"%s",buffer);
  va_end(args);
}



void pushcode(const char* fmt, ...)
{
  va_list args;
  char line[100];

  va_start(args,fmt);
  vsprintf (line, fmt, args);
  va_end(args);

  if (codebuf==NULL){
    codebuf=(char*)malloc(codebuf_sz);
    strcpy(codebuf,""); 
  }

  if ((codebuf_sz-strlen(codebuf))<strlen(line)){
    printf ("Sin sitio en el codebuf\n");
    return;
  }
  
  /*
    Append line on the front of codebuf
  */
  char *aux=(char*)malloc(codebuf_sz);
  strcpy(aux,line);
  strcat(aux,codebuf);
  strcpy(codebuf,aux);
  free(aux);
}



void dumpcode(){
  if (codebuf==NULL)
    return;
  fprintf(out,"%s",codebuf);
  free(codebuf);
  codebuf=NULL;
}



char* path(char *mod){

  char *modpath;

  modpath=(char*)malloc(sizeof(char)*512);
  strcpy(modpath,getenv("MKPATH"));
  if (modpath!=NULL){
    modpath=strcat(modpath,"/mkc/il/");
    modpath=strcat(modpath,mod);
    return modpath;
  }else{
    yyerror("Environment variable MKPATH not defined");
    return NULL;
  }
}


/* Con este metodo realizamos el linkado de los diferentes archivos */
/* referenciados en la cabecera de nuestro programa */

void link_il(char *mod){

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


void load_il(char *mod){

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
