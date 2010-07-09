#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "io.h"

#define FTAB_SIZE 10


struct fnode{
  char *path;
  int fd;
};
typedef struct fnode fnode;


fnode *ftab[FTAB_SIZE];


int io_open(char* file){

  int i;
  int fd;
  mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
  int flags=O_WRONLY | O_CREAT | O_TRUNC;
  
  for (i=0;i<FTAB_SIZE;i++)
    if (ftab[i]==NULL){

      fd=open(file,flags, mode);
      if (fd<0){
	perror("error");
	return -2;
      }
      
      ftab[i]=(fnode*)malloc(sizeof(fnode));
      ftab[i]->path=file;
      ftab[i]->fd=fd;
      return i;
    }
  
  return -1;
}



int io_close(int index){

  if (index<FTAB_SIZE){
    free(ftab[index]);
    ftab[index]=NULL;
    return 0;
  }else
    return -1;
}




int io_read(int index,sim **buf){

  return 0;
}




int io_write(int index,sim **buf){

  return 0;
}




int io_seek(int index,int off){

  return 0;
}
