#if !defined (MEM_H)
#define MEM_H

#include "uval.h"

#define TAB_SIZE 20

struct sim{
  char *tag;
  u_val val;
};
typedef struct sim sim;



struct tab{
  char *name;
  sim *mem[TAB_SIZE];
  int items;
  struct tab* parent;
}; 
typedef struct tab tab;


void newcontext(tab **m,char *name);
void delcontext(tab **m);
sim *addsim(tab* m,char *tag,u_val v);
sim *getsim(tab* m,char *tag);
void ptab(tab* m);


#endif
