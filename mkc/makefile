
OBJS = mkc.o


mkc: $(OBJS)
	gcc -g $(OBJS) -o ../bin/mkc

%.o: %.c
	gcc -g -c $< -o $@

all: mkc

clean:
	rm $(OBJS) 
