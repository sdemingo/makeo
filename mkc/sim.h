
enum Stype {S_INT,
	    S_FLOAT,
	    S_STRING};


struct Sim{
  char *name;
  int stype;  
  int ival;
};


typedef struct Sim Sim;

 /* Simbols table */

int addsim(char *sim);

Sim *getsim(int id);

void dump();

 
/* Simbols queue */

void push_sim(int id);

int pull_sim();

