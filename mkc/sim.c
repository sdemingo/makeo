
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



int cmptypes(int t1,int t2){

  if ((t1==S_PARAM) || (t2==S_PARAM))
    return 1;
  else
    return t1==t2;
}




void init_sim(){
  
  nullsim=(Sim*)malloc(sizeof(Sim));
  nullsim->name=(char*)malloc(sizeof(char)*50);
  nullsim->stype=S_NULL;
  strcpy(nullsim->name,"unknow sim");  
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
    simtab[id].stype=S_NULL;
    tlast++;
    return id;
  }
  return -1;
  //error
}

Sim *getsim(int id)
{ 
  if ((id<0) || (id>=MAX_SIM)){
    printf ("Acceso a simbolo inexistente\n");
    return nullsim;
  }
  
  return &simtab[id];
}


void text(Sim si){

  char *s;
  
  s=(char*)malloc(strlen(si.name)+20);
  strcpy(s,si.name);
  switch(si.stype){
  case S_INT:
    strcat(s," [INT]");
    break;
  case S_FLOAT:
    strcat(s," [FLOAT]");
    break;
  case S_STRING:
    strcat(s," [STRING]");
    break;
  case S_FCALL:
    strcat(s," [FCALL]");
    break;
 case S_BOOLEAN:
    strcat(s," [BOOL]");
    break;
  case S_PARAM:
    strcat(s," [PARAM]");
    break;
  case S_NULL:
    strcat(s," [NULL]");
    break;
  }
  printf("%s",s);
}


void dump(){
  
  int i;
  
  printf (" - TABLA DE SIMBOLOS - \n");
  for (i=0;i<tlast;i++){
    printf ("\t");
    text(simtab[i]);
    printf ("\n");
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


