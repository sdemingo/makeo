#if !defined (UVAL_H)
#define UVAL_H

enum stype{INT,CHAR,FLOAT,STRING,NULLVAL};

union tval{
    int ival;
    char cval;
    float fval;
    char *sval;
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
int isnull(u_val u);

#endif
