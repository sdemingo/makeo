#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "code.h"
#include "y.tab.h"

extern int yylineno;


char *rbuf;
int rbuf_sz = 200;

void error(char *msg){
  //fprintf(stderr,"line %d: %s\n",yylineno,str);
  //char line[200];
  char *line;
  //sprintf(line,"line %d: %s\n",yylineno,msg);
  line=msg;

  printf ("llamo a error con line(%s)\n",msg);

  if (rbuf==NULL){
    rbuf=(char*)malloc(rbuf_sz);
    strcpy(rbuf,""); 
  }

  if ((rbuf_sz-strlen(rbuf))<strlen(line)){
    printf ("Sin sitio en el rbuf\n");
    return;
  }
  strcat(rbuf,line);
}



void iferror(){
  //printf ("ejecuto iferror\n");
  if (rbuf!=NULL){
    printf ("%s",rbuf);
    free(rbuf);
    rbuf=NULL;
    yyerror();
  }
}



