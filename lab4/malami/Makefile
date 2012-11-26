%.o: %.asm
    nasm -g -f elf -o $@ $<

all: malami main
 

main:    main.o
    $(CC) $(CFLAGS) -o $@ $^

malami: malami.o
    nasm -g -f elf -w+all -o malami.o malami.asm

main.o: main.c
malami.o: malami.asm


.PHONY: clean

clean:
    rm *.o