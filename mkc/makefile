
OBJS = mkc.o sim.o code.o lex.yy.o y.tab.o

HDR = sim.h y.tab.h

mkc: $(OBJS)
	gcc $(FLAGS) -g $(OBJS) -o ../bin/mkc

lex.yy.c: lex_spec.l y.tab.c $(HDR)
	flex lex_spec.l


y.tab.c: yacc_spec.y $(HDR)
	yacc -d yacc_spec.y 



%.o: %.c
	gcc $(FLAGS) -g -c $< -o $@

all: mkc

clean:
	rm $(OBJS) 

purge: clean
	rm ../bin/mkc

