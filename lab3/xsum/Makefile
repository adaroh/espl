 %.o: %.c
	gcc -c -o $@ $<
 
 all: xsum
 
 clean:
	rm -f *.o
 
 invert: xsum.o
	cc -o $@ $^