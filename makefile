
mkm: vm.o parser.o stack.o mem.o uval.o core.o
	gcc -g vm.o parser.o stack.o mem.o uval.o core.o -o mkm

parser.o: parser.c parser.h
	gcc -g -c parser.c -o parser.o

stack.o: stack.c stack.h
	gcc -g -c stack.c -o stack.o

mem.o: mem.c mem.h
	gcc -g -c mem.c -o mem.o

uval.o: uval.c uval.h
	gcc -g -c uval.c -o uval.o

core.o: core.c core.h
	gcc -g -c core.c -o core.o

vm.o: vm.c
	gcc -g -c vm.c -o vm.o

all: mkm


clean:
	rm *~ *.o test
