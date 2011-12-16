all:	
	make -C mkm/
	make -C mkc/

clean:
	make clean -C mkm
	make clean -C mkc

purge:
	make purge -C mkm
	make purge -C mkc
