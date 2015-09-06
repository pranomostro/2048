#Makefile for a 2048 clone.

PREFIX = /usr/local
TARGET = 2048
SRC = ${TARGET}.c

CC = gcc
CFLAGS = -Wall -Wextra -fexpensive-optimizations\
-funroll-loops -fno-builtin -s -std=c89 -Os -O3 -static

all: ${TARGET}

${TARGET}: ${SRC} config.h
	${CC} ${CFLAGS} ${SRC} -o ${TARGET}

clean:
	rm -rf ${TARGET}

install: all
	cp ${TARGET} ${PREFIX}/bin
	cp ${TARGET}.1 ${PREFIX}/share/man/man1

uninstall:
	rm -f ${PREFIX}/bin/${TARGET}
	rm -f ${PREFIX}/share/man/man1/${TARGET}.1
