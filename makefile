#Makefile for a 2048 clone.

PREFIX = /usr
TARGET = 2048
SRC = ${TARGET}.c

CC = gcc
CFLAGS = -Wall -W -Wextra -fexpensive-optimizations\
-funroll-loops -fno-builtin -s -std=c89 -Os -O3

all: ${TARGET}

${TARGET}: ${SRC}
	${CC} ${CCFLAGS} ${SRC} -o ${TARGET}

clean:
	rm -rf ${TARGET}

install: all
	cp ${TARGET} ${PREFIX}/bin
	cp ${TARGET}.1 ${PREFIX}/share/man/man1

uninstall:
	rm -f ${PREFIX}/bin/${TARGET}
	rm -f ${PREFIX/share/man/man1/${TARGET}.1
