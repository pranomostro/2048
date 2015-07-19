#Makefile for the ${TARGET} clone.

PREFIX = /usr
TARGET = 2048
SRC = ${TARGET}.c

CC = gcc
CFLAGS = -Wall -W -Wextra -fexpensive-optimizations\
-funroll-loops -fno-builtin -s -std=c89 -Os -O3

all : ${TARGET}

${TARGET} : ${SRC}
	${CC} ${CCFLAGS} ${SRC} -o ${TARGET}

clean : ${TARGET}
	rm -rf ${TARGET}
