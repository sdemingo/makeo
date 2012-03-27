#if !defined (PARSER_H)
#define PARSER_H


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include "mem.h"


enum Type{C_ATH = 1,
	  C_PUSH,
	  C_POP,
	  C_LABEL,
	  C_GOTO,
	  C_GOTO_IFZ,
	  C_FUNCTION,
	  C_RETURN,
	  C_CALL,
	  C_IO,
	  NULLTYPE
};
typedef enum Type Type;


struct com{
  Type type;
  int nline;
  char *cmd;
  char *arg1;
  char *arg2;
};

typedef struct com com;


int initparser (char *file,tab *main);
com* nextcom (void);
int isvalidcom(com *c,int nargs);
void printcom (com *c);


#endif
