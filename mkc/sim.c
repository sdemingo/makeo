
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIM 100

struct Sim{
  char *name;
};

struct Sim simtab[MAX_SIM];

int last = 0;


void addsim(char *sim){
  
  if (last<MAX_SIM){
    simtab[last].name=malloc(strlen(sim));
    simtab[last].name=strcpy(simtab[last].name,sim);
    last++;
    printf ("Simbolo añadido\n");
  }

 

  //error
}


char *getsim(int id)
{

  return "";
}


void dump(){
  
  int i;

  printf (" - TABLA DE SIMBOLOS - \n");
  for (i=0;i<last;i++){
    printf ("     %s\n",simtab[i].name);
  }
  printf ("\n");
}
