#if !defined (IO_H)
#define IO_H

#include "parser.h"


int io_open(char* file);
int io_close(int fd);
int io_read(int fd,u_val *u);
int io_write(int fd,u_val u);
int io_seek(int fd,int off);

#endif
