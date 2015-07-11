#Makefile for the 2048 clone.

CC = tcc
CFLAGS = -Wall -static -Os
all : 2048

2048 : 2048.c
	$(CC) $(CCFLAGS) 2048.c -o 2048

clean : 2048
	rm -rf 2048