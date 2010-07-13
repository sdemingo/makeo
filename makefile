all:	
	make -C mkm/
	make -C mkc/

clean:
	make clean -C mkm
	make clean -C mkc
