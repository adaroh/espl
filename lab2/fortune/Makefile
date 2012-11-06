 %.o: %.c
	gcc -c -o $@ $<
 
 all: fortune
 
 clean:
	rm -f *.o
 
 invert: fortune.o
	cc -o $@ $^