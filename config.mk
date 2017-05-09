PREFIX=/usr/local

CC=cc
AR=ar
RANLIB=ranlib

CFLAGS=-Wall -Wextra -std=c89 -pedantic -O2
LDFLAGS=-s

BIN=2048
OBJ=$(BIN:=.o)
MAN=$(BIN:=.1)
CONF=config.mk config.h
