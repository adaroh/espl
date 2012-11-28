.PHONY: all clean

CC=gcc
CFLAGS=-O -g

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: scmp 

scmp: scmp.o cmpstr.o
	$(CC) $(CFLAGS) -o $@ $^

scmp.o: scmp.c
cmpstr.o: cmpstr.c