
OBJS = mkc.o lex.yy.o y.tab.o


mkc: $(OBJS)
	gcc -g $(OBJS) -o ../bin/mkc

lex.yy.c: lex_spec.l y.tab.c
	flex lex_spec.l

y.tab.c: yacc_spec.y
	yacc -d yacc_spec.y 

%.o: %.c
	gcc -g -c $< -o $@

all: mkc

clean:
	rm $(OBJS) 
