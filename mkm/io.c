#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "io.h"

#define FTAB_SIZE 10
#define MAXBUF 512
#define IOERROR -1

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
  int flags=O_RDWR | O_TRUNC;
  struct stat st;
  
  for (i=0;i<FTAB_SIZE;i++){
    if (ftab[i]==NULL){
      if (!strcmp(file,"in"))
	fd=0;
      else if (!strcmp(file,"out"))
	fd=1;
      else 
	if (stat(file,&st)<0)
	  fd=creat(file,mode);
	else
	  fd=open(file,flags, mode);

      if (fd<0)
	return IOERROR;
      
      ftab[i]=(fnode*)malloc(sizeof(fnode));
      ftab[i]->path=file;
      ftab[i]->fd=fd;
      return i;
    }
  }
  return IOERROR;
}



int io_close(int i){

  if (i<FTAB_SIZE){
    if ((strcmp(ftab[i]->path,"out")) &&
	(strcmp(ftab[i]->path,"in")))
      close(ftab[i]->fd);
    free(ftab[i]);
    ftab[i]=NULL;
    return 0;
  }else
    return IOERROR;
}




int io_read(int i,u_val *u){

  int sz,n,c;
  char *buf;

  sz=sizeof(int);

  if (isnull(*u))
    return IOERROR;

  if (ftab[i]==NULL)
    return IOERROR;

  if (u->type==INT){
    buf=(char*)malloc(sizeof(int));
    n=read(ftab[i]->fd,buf,sz);
    u->data.ival=atoi(buf);

  }else if (u->type==STRING){
    buf=(char*)malloc(sizeof(char)*MAXBUF);
    n=read(ftab[i]->fd,buf,MAXBUF);
    for (c=0;c<MAXBUF;c++)
      if (buf[c]=='\n')
	break;
    u->data.sval=(char*)malloc(sizeof(char)*(c+1));
    strncpy(u->data.sval,buf,c);
    u->data.sval[c+1]='\0';
    return c;

  }else if (u->type==NULLVAL)
    return IOERROR;
    
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
