
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sim.h"

#define MAX_SIM 100


/*
  Tabla de Simbolos
 */
struct Sim simtab[MAX_SIM];
int tlast = 0;


/*
  Cola de simbolos
 */
int simstack[MAX_SIM];
int head=0;


Sim *nullsim;


void init_sim(){
  
  nullsim=(Sim*)malloc(sizeof(Sim));
  nullsim->name="unknow sim";
  
  memset(simstack,-1,MAX_SIM);
}

/*
  Funciones de la tabla de simbolos
*/

int addsim(char *sim){
  int i;
  
  if ((i=exists(sim))>=0)
    return i;

  int id=tlast;

  if (tlast<MAX_SIM){
    simtab[id].name=malloc(strlen(sim));
    simtab[id].name=strcpy(simtab[tlast].name,sim);
    tlast++;
    return id;
  }
  return -1;
  //error
}


char *getsim_name(int id)
{
  if ((id<0) || (id>=MAX_SIM))
    return "";
  
  return simtab[id].name;
}

Sim *getsim(int id)
{ 
  if ((id<0) || (id>=MAX_SIM))
    return nullsim;
  
  return &simtab[id];
}


void dump(){
  
  int i;

  printf (" - TABLA DE SIMBOLOS - \n");
  for (i=0;i<tlast;i++){
    printf ("     %s\n",simtab[i].name);
  }
  printf ("\n");
}


int exists(char *simname){
  int i;

  for (i=0;i<tlast;i++){
    if (strcmp(simtab[i].name,simname)==0)
      return i;
  }
  return -1;
}



void copy(Sim *dest,Sim *src){
  if ((dest!=NULL) && (src!=NULL)){
    strcpy(dest->name,src->name);
  }
}








/*  Funciones para el buffer de simbolos. Lo ideal es que guarde
   indice de simbolos, en lugar de simbolos en si mismo */


void push_sim(int id){
  if (head<MAX_SIM){
    simstack[head]=id;
    head++;
  }
    
}


int pull_sim(){
  int id,i;

  head--;
  if (head<0)
    return -1;
  id=simstack[head];

  return id;
}


