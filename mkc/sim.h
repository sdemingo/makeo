
enum Stype {S_NULL,
            S_INT,
	    S_FLOAT,
	    S_STRING,
            S_FCALL,
	    S_PARAM,
};


struct Sim{
  char *name;
  int stype;  
  int ival;
};


typedef struct Sim Sim;

 /* Simbols table */

int addsim(char *sim);
Sim *getsim(int id);
int cmptypes(int t1,int t2);
void dump();

 
/* Simbols queue */

void push_sim(int id);
int pull_sim();

