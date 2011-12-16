#include <stdio.h>

extern FILE *yyin;

int main (int argc, char **argv){
 
  ++argv, --argc; /* se salta el nombre del programa */
  if ( argc > 0 )
    yyin = fopen( argv[0], "r" );
  else
    yyin = stdin;
  
  //yylex();
  yyparse();

  dump();
  
  return 0;
}
