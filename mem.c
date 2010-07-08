#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mem.h"

#define TAG_SIZE 30



void psim(sim *s){
  
  switch (s->val.type){
  case INT:
    printf ("[%s]\t[INT][%d]",s->tag,s->val.data.ival);
    break;
  case CHAR:
    printf ("[%s]\t[CHAR][%c]",s->tag,s->val.data.cval);
    break;
  case STRING:
    printf ("[%s]\t[STRING][%s]",s->tag,s->val.data.sval);
    break;
  case FLOAT:
    printf ("[%s]\t[FLOAT][%f]",s->tag,s->val.data.fval);
    break;
  default:
    printf ("[%s]\t[UnknowType]",s->tag,s->val.data.fval);
  }
}



void ptab(tab* t){
  sim **aux,*n;
  int i=0;
  tab *taux;
  
  if (t==NULL)
    return;
  
  printf ("\n---Table[%s]---",t->name);
  if (t->parent!=NULL)
    printf ("\tparent:%s\n",t->parent->name);
  else
    printf ("\tparent: NULL \n");
  for(aux=t->mem;*aux!=NULL;aux++,i++){
    n=*aux;
    psim(n);
    printf ("\n");
  }
  
  //imprimo las tablas padre
  if (t->parent!=NULL)
    ptab(t->parent);
  
}



sim* addsim(tab* m,char *tag,u_val v){
  sim **aux,*n,*c;

  if (m==NULL)
    return NULL;

  for (aux=m->mem;*aux!=NULL;aux++){
    n=*aux;
    if (!strcmp(n->tag,tag)){
      n->val=v;
      return;
    }
  }

  /*
    Si no existe lo creamos
  */
  c=(sim*)malloc(sizeof(sim));
  if (c==NULL)
    error("No enough memory to simbol %d\n",tag);
  c->tag=(char*)malloc(strlen(tag)+1);
  strcpy(c->tag,tag);
  c->val=v;

  *aux=c;
}


sim* getsim(tab* m,char *tag){
  sim **aux,*n;

  if (m==NULL)
    return NULL;
  
  for(aux=m->mem;*aux!=NULL;aux++){
    n=*aux;
    if (!strcmp(n->tag,tag))
      return n;
  }
  
  //si no existe busco en el contexto padre
  if (m->parent!=NULL)
    return getsim(m->parent,tag);
  else
    return NULL;  //y si no existe, ¿que devuelvo?  
}




void newcontext(tab **m,char *name){
  /*
    Creamos un nuevo contexto que siempre sera
    hijo del main actual
   */

  int i;
  tab *t; //nueva tabla

  t=(tab*)malloc(sizeof(tab));
  if (t==NULL)
    return;
  
  t->name=name;

  for (i=0;i<TAB_SIZE;i++)
    t->mem[i]=NULL;
  t->items=0;
  t->parent=*m;

  *m=t;
}



void delcontext(tab **m){
  /*
    Borra el contexto actual.
    Se llama en return
   */
  
  tab *aux=*m;
  *m=(*m)->parent;
  free(aux);
}
