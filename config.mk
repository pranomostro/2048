#configure your installation

PREFIX=/usr/local

CC=gcc

CFLAGS=-Wall -Wextra -std=c89 -pedantic -O2
LDFLAGS=-s

TARGET=2048
OBJS=2048.o
