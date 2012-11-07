%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.man: %.1
	nroff -man $< > $@

all: bsplit bsplit.man

bsplit: bsplit.o
	$(CC) $(LDFLAGS) -o $@ $^

bsplit.o: bsplit.c

clean:
	rm -f *.o 

distclean: clean
	rm -f bsplit bmerge
