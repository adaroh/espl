all: encbc decbc test

CC=gcc
CFLAGS=-g -m32 -O0 -Wall

%.o: %.asm
	nasm -g -f elf -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<


test: encbc decbc testbc
	./testbc
	if [ "`./encbc shalom olam|./decbc`" != "shalom olam" ]; then\
		exit 1;\
	fi

encbc: encbc.o encbc2.o bclib.o
	$(CC) $(CFLAGS) -o $@ $^

decbc: decbc.o bclib.o
	$(CC) $(CFLAGS) -o $@ $^

testbc: bclib.c
	$(CC) $(CFLAGS) -o $@ -DTESTBC=1 $^

encbc.o: encbc.c bclib.h
encbc2.o: encbc2.asm
decbc.o: decbc.c bclib.h
bclib.o: bclib.c bclib.h

clean:
	rm -f *.o encbc decbc testbc
