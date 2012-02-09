#include <stdio.h>
#include "mem.h"
#include "stack.h"
#include "uval.h"
#include "parser.h"
#include "core.h"

#define MINARGS 2



void usage(){
  printf ("Usage: mkm [-v|-m] file.vm\n");
  exit(1);
}



int main (int argc, char **argv){

  com *c;
  u_val u;
  int n;
  tab *mtab;
  int v_opt = 0;
  int m_opt = 0;

  if (argc<MINARGS)
    usage();

    
  while ((argc > 1) && (argv[1][0] == '-')){
    switch (argv[1][1]){
    case 'v':
      v_opt = 1;
      break;
    case 'm':
      m_opt = 1;
      break;

    default:
      printf("Wrong Argument: %s\n", argv[1]);
      usage();
    }
    ++argv;
    --argc;
  }


  mtab=NULL;

  newcontext(&mtab,"global");
  initparser(argv[1],mtab);
  initstack();

  do{
    c=nextcom();
    if (c==NULL)
      break;
    if (v_opt){
      printcom(c);
      printf("\t\t");
      pstack_line();
      printf("\n");
    }
    proccom(c,&mtab);
  }while (c!=NULL);
  
  if (m_opt)
    ptab(mtab);
  
  return EXIT_SUCCESS;
}
