#if !defined (CORE_H)
#define CORE_H

#include "parser.h"

void error(char *fmt,...);
void panic(com *c,char *fmt,...);
void proccom(com* token,tab **simtab);

#endif
