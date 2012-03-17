#include <stdio.h>

extern FILE *yyin;
extern FILE *out;

int main (int argc, char **argv){
  int sdebug=0;

  ++argv, --argc;
  if (argv[0][0]!='-')
    yyin = fopen(argv[0], "r" );
  else
    yyin = stdin;

  while (argc>1){
    if (argv[1][0]=='-'){
      switch(argv[1][1]){
      case 'o':
	if (argv[2]!=NULL)
	  out=fopen(argv[2],"w");
      case 's':
	printf ("bla");
	sdebug=1;
      }
    }
    ++argv;
    --argc;
  }

  if (out==NULL)
    out=fopen("out.il","w");
 
  yyparse();

  if (sdebug)
    dump();
  
  return 0;
}
