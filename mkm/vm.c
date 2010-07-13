#include <stdio.h>
#include "mem.h"
#include "stack.h"
#include "uval.h"
#include "parser.h"
#include "core.h"

#define MINARGS 2


int main (int argc, char **argv){

  com *c;
  u_val u;
  int n;
  tab *mtab;

  if (argc<MINARGS){
    fprintf(stderr,"Faltan argumentos\n");
    exit(-1);
  }
    
  mtab=NULL;

  newcontext(&mtab,"global");
  initparser(argv[1],mtab);
  initstack();

  do{
    c=nextcom();
    if (c==NULL)
      break;
    printcom(c);
    proccom(c,&mtab);
  }while (c!=NULL);
  
  ptab(mtab);
  
  return 0;
}
