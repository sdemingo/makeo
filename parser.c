
#include "parser.h"
#include "uval.h"
#include "mem.h"

#define BUFSIZE 1024
#define BRKLINE "\n"
#define DELIM   " "
#define ARG_LEN 25
#define NULL_TOKEN " "
#define LINES 500


com *commands[LINES];
int pcounter;



char *trim(char **line){
  char *s;
  char *start,*end;
  
  s=(char*)malloc(strlen(*line));
  start=*line;
  while ((*start==' ') || (*start=='\t'))
    start++;
  
  end=*line+strlen(*line)-1;
  while ((*end==' ') || (*end=='\t'))
    end--;
  
  strncpy(s,start,(end-start)+1);
  *line=s;   
}




char *readtxt (char *file)
{
  int fd;
  long n;
  char *buf;
  char *txt=NULL,*aux=NULL;
  int c=0,off=0;
  
  if ((fd=open(file, O_RDONLY)) <0){
    perror("open error");
    return NULL;
  }
  
  buf=(char*)malloc(BUFSIZE*sizeof(char));
  if (buf==NULL){
    perror("no memory to buffer");
    return NULL;
  }
  
  while ((n=read(fd, buf,BUFSIZE))>0){
      c+=n;
      txt=(char*)realloc(txt,c*sizeof(char));
      aux=txt+off;
      aux=memcpy(aux,buf,n);
      off+=n;
  }
  txt[c]='\0';
  free(buf);
  close(fd);
  
  return txt;	
}



com *getcom(char *tok)
{
  com *c;
  char *cs=NULL,*a1=NULL,*a2=NULL;
  char *save;

  if (tok==NULL)
    return NULL;
  
  c=(com*)malloc(sizeof(com));
  if (c==NULL){
    perror("no memory for token");
    return NULL;
  }

  cs=strtok_r(tok,DELIM,&save);
  c->cmd=(char*)malloc(sizeof(char)*ARG_LEN);
  c->arg1=NULL;
  c->arg2=NULL;

  if (cs!=NULL)
    strcpy(c->cmd,cs);
  else
    strcpy(c->cmd,tok);
  c->type=gettype(cs);
  
  
  if (cs!=NULL){
    a1=strtok_r(NULL,DELIM,&save);
    if (a1!=NULL){
      c->arg1=(char*)malloc(sizeof(char)*ARG_LEN);
      strcpy(c->arg1,a1);
    }
  }

  if (a1!=NULL){
    a2=strtok_r(NULL,DELIM,&save);
    if (a2!=NULL){
      c->arg2=(char*)malloc(sizeof(char)*ARG_LEN);
      strcpy(c->arg2,a2);
    }
  }

  return c;
}



void loadlabels(int nlines,tab *t){
  int i;
  u_val u;
  char nline[6];
  sim *s;
  
  for (i=0;i<nlines;i++){
    if (commands[i]!=NULL){
      if((!strcmp(commands[i]->cmd,"label"))
	 || (!strcmp(commands[i]->cmd,"function"))){
	sprintf(nline,"%d",i);
	u=get_u_val(nline);
	if ((s=addsim(t,commands[i]->arg1,u))==NULL)
	  error("Symbol %d not created\n",commands[i]->arg1);
      }
    }
  }
}



int initparser(char *file,tab *t)
{
  int i=0;
  char *pbuf,*line;
  com* c;
  u_val u;
  sim *s;

  pcounter=0;

  pbuf=readtxt(file);

  for (line=pbuf;line!=NULL;pbuf=NULL){
    line=strtok(pbuf,BRKLINE);
    //trim(&line);
    c=getcom(line);
    if ((c!=NULL) && (c->type!=NULLTYPE)){
      c->nline=i;
      commands[i++]=c;
    }
  }

  loadlabels(i,t);
  
  
  s=getsim(t,"main");
  if (s==NULL)
    error("Function main not defined\n");
  if (isnull(s->val))
    error("Function main not defined\n");

  pcounter=s->val.data.ival;
  

  return i;
}


int gettype(char *cs){

  if (cs==NULL)
    return NULLTYPE;
  
  if (!strcmp(cs,"pop"))
    return C_POP;
  else if (!strcmp(cs,"push"))
    return C_PUSH;
  else if (!strcmp(cs,"label"))
    return C_LABEL;
  else if (!strcmp(cs,"goto"))
    return C_GOTO;
  else if (!strcmp(cs,"goto-ifnz"))
    return C_GOTO_IFNZ;
  else if (!strcmp(cs,"function"))
    return C_FUNCTION;
  else if (!strcmp(cs,"return"))
    return C_RETURN;
  else if (!strcmp(cs,"call"))
    return C_CALL;
  else if ((!strcmp(cs,"add")) || (!strcmp(cs,"sub"))) 
    return C_ATH;
  else
    return NULLTYPE;
}




com *nextcom(){
  
  com *c;
  
  c=commands[pcounter];
  pcounter++;

  return c;
}

int isvalidcom(com *c,int nargs){

  if (c==NULL)
    return 0;

  if (nargs==0)
    return 1;

  if ((nargs==1) && (c->arg1!=NULL))
    return 1;
  
  if ((nargs==2) && (c->arg1!=NULL) && (c->arg2!=NULL))
    return 1;

  return 0;
}



void printcom(com *c){

  if ((c==NULL) || (c->type==NULLTYPE))
    return;

  printf ("%d\t- ",c->nline);

  if (c->cmd!=NULL)
    printf ("[%s] ",c->cmd,c->type);

  if (c->arg1!=NULL)
    printf ("[%s]",c->arg1);
  
  if (c->arg2!=NULL)
    printf ("[%s]",c->arg2);

  printf ("\n");
}
