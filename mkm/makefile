
OBJS = vm.o parser.o stack.o mem.o uval.o core.o io.o


mkm: $(OBJS)
	gcc -g $(OBJS) -o ../bin/mkm

%.o: %.c
	gcc -g -c $< -o $@

all: mkm

clean:
	rm $(OBJS) 
