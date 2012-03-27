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
  for (i=0;t->mem[i]!=NULL;i++){
    n=t->mem[i];
    psim(n);
    printf ("\n");
  }
  
  if (t->parent!=NULL)
    ptab(t->parent);
  
}



sim* addsim(tab* m,char *tag,u_val v){
  sim *n,*c;
  int i;

  if (m==NULL)
    return NULL;

  for (i=0;m->mem[i]!=NULL;i++){
    n=m->mem[i];
    if (!strcmp(n->tag,tag)){
      n->val=v;
      return;
    }
  }

  /*
    If it doesn't exist, we create it
  */
 
  c=(sim*)malloc(sizeof(sim));
  if (c==NULL)
    error("No enough memory to simbol %d\n",tag);

  c->val=v;
  c->tag=(char*)malloc(strlen(tag));
  strcpy(c->tag,tag);

  m->mem[i]=c;
  return m->mem[i];
}


sim* getsim(tab* m,char *tag){
  sim **aux,*n;
  int i;

  if (m==NULL)
    return NULL;
  
  for (i=0;m->mem[i]!=NULL;i++){
    n=m->mem[i];
    if (!strcmp(n->tag,tag))
      return n;
  }

  /* 
     If the sim does not exists here, it looks for in the root table
    */

  if (m->parent!=NULL)
    return getsim(m->root,tag);
  else
    return NULL;
  
}




void newcontext(tab **m,char *name){
  
  int i;
  tab *t; //new table

  t=(tab*)malloc(sizeof(tab));
  if (t==NULL)
    return;
  
  t->name=name;

  for (i=0;i<TAB_SIZE;i++){
    t->mem[i]=NULL;
  }

  t->items=0;
  t->parent=*m;
  if (t->parent==NULL) //is the root table
    t->root=t;
  else
    t->root=(*m)->root;
    
  *m=t;
}


void delcontext(tab **m){

  /* Leak?  */

  tab *aux=*m;
  *m=(*m)->parent;
  free(aux);
}
