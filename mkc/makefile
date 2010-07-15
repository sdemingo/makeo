
OBJS = mkc.o lex.o


mkc: $(OBJS)
	gcc -g $(OBJS) -o ../bin/mkc

lex.c: lex_spec.l
	flex -o lex.c lex_spec.l

%.o: %.c
	gcc -g -c $< -o $@

all: mkc

clean:
	rm $(OBJS) 
