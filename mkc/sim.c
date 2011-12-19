
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIM 100

struct Sim{
  char *name;
};

struct Sim simtab[MAX_SIM];

int last = 0;


int addsim(char *sim){
  
  int id=last;

  if (last<MAX_SIM){
    simtab[id].name=malloc(strlen(sim));
    simtab[id].name=strcpy(simtab[last].name,sim);
    last++;
    return id;
  }
  return -1;
  //error
}


char *getsim(int id)
{
  if ((id<0) || (id>=MAX_SIM))
    return "";
  
  return simtab[id].name;
}


void dump(){
  
  int i;

  printf (" - TABLA DE SIMBOLOS - \n");
  for (i=0;i<last;i++){
    printf ("     %s\n",simtab[i].name);
  }
  printf ("\n");
}
