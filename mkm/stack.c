#include <stdio.h>
#include "stack.h"
#include "uval.h"

#define MAX_SIZE 50


u_val stack[MAX_SIZE];
int sp;


void initstack(){
  sp=0;
  int i;
  for (i=0;i<MAX_SIZE;i++)
    stack[i]=null_u_val();
}


void push(u_val a){
  if (sp<MAX_SIZE)
    stack[sp++]=a;
  else
    error(NULL,"stack is full");
}


u_val pop(){
  if (sp<0)
    return null_u_val();
  else
    return stack[--sp];
}


void pstack(){
  int i;
  printf ("------stack-----\n");
  for (i=0;i<sp;i++){
    printf ("%d\t%s\n",i,u_val2text(stack[i]));
  }
  printf ("----------------\n");
}


void pstack_line(){
  int i;
  printf ("|");
  if (sp>=0){
    for (i=0;i<sp;i++){
      printf ("%s ",u_val2text(stack[i]));
    }
  }
  printf ("|sp:%d",sp);
}
