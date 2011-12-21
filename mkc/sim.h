
struct Sim{
  char *name;
};

typedef struct Sim Sim;

int addsim(char *sim);

char *getsim_name(int id);

Sim *getsim(int id);

void dump();





void push_sim(int id);

int pull_sim();

