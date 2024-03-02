CC = gcc

CFLAGS = -O1 -g -Wall -I .
LDLIBS = -lpthread -lm

PROGS =	producerconsumer_amd_naive\
		producerconsumer_amd

all: $(PROGS)

producerconsumer_amd_naive: producerconsumer_amd_naive.c sbuf.c csapp.c csapp.h
producerconsumer_amd: producerconsumer_amd.c sbuf.c csapp.c csapp.h

clean:
	rm -f $(PROGS) *.o *~