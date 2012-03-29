#if !defined (UVAL_H)
#define UVAL_H

enum stype{INT,CHAR,FLOAT,STRING,BOOL,NULLVAL};

union tval{
  int ival;
  char cval;
  float fval;
  char *sval;
  int *uxval;
};
typedef union tval tval;


struct u_val{
  int type;
  tval data;
};

typedef struct u_val u_val;


u_val get_u_val(char *arg);
u_val null_u_val();
char* u_val2text(u_val u);
int u_val2bytes(u_val u,char **buf);
int u_valtype(char *str);
int isnull(u_val u);

#endif
