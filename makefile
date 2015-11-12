#Makefile for a 2048 clone.

PREFIX = /usr/local
TARGET = 2048

CC = gcc
CFLAGS = -Wall -std=c89 -pedantic
LIBS =

all: ${TARGET}

${TARGET}: ${TARGET}.c
	${CC} ${CFLAGS} ${TARGET}.c ${LIBS} -o ${TARGET}

clean:
	rm -rf ${TARGET}

install: all
	mkdir -p ${PREFIX}/bin ${PREFIX}/share/man/man1
	cp ${TARGET} ${PREFIX}/bin
	cp ${TARGET}.1 ${PREFIX}/share/man/man1
	chmod 755 ${PREFIX}/bin/${TARGET}
	chmod 644 ${PREFIX}/share/man/man1/${TARGET}.1

uninstall:
	rm -f ${PREFIX}/bin/${TARGET}
	rm -f ${PREFIX}/share/man/man1/${TARGET}.1
