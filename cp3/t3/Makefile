CC = gcc
CFLAG = -o

.SUFFIEXES:.o .c 

.o.c:
	${CC} ${CFLAGES} -c $<

all:createFile ccopy_system

createFile:createFile.o
	${CC} ${CFLAG} createFile createFile.o
ccopy_system:ccopy_system.o
	${CC} ${CFLAG} ccopy_system ccopy_system.o

createFile.o:createFile.c
ccopy_system.o:ccopy_system.c

.PHONY:all

clean:
	rm -rf *.o createFile ccopy_system
