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
  int flags=O_RDWR;
  struct stat st;
  
  for (i=0;i<FTAB_SIZE;i++)
    if (ftab[i]==NULL){

      if (stat(file,&st)<0)
	fd=creat(file,mode);
      else
	fd=open(file,flags, mode);

      if (fd<0)
	return -1;
      
      ftab[i]=(fnode*)malloc(sizeof(fnode));
      ftab[i]->path=file;
      ftab[i]->fd=fd;
      return i;
    }
  
  return -1;
}



int io_close(int i){

  if (i<FTAB_SIZE){
    close(ftab[i]->fd);
    free(ftab[i]);
    ftab[i]=NULL;
    return 0;
  }else
    return -1;
}




int io_read(int i,u_val *u){

  int sz,n;
  char *buf;

  sz=sizeof(int);

  if (isnull(*u))
    return -1;

  if (ftab[i]==NULL)
    return -1;

  if (u->type==INT){
    buf=(char*)malloc(sizeof(sz));
    n=read(ftab[i]->fd,buf,sz);
    u->data.ival=atoi(buf);

  }else if (u->type==STRING)
    return -1;

  else if (u->type==NULLVAL)
    return -1;
    
  return n;
}




int io_write(int i,u_val u){
  int n;
  char *buf;

  buf=(char*)malloc(sizeof(char)*512);
  n=u_val2bytes(u,&buf);
  if (n<0)
    return n;
  
  return write(ftab[i]->fd,buf,n);
}




int io_seek(int index,int off){

  return 0;
}
