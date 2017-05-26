CC = gcc 
CFLAG = -o

.SUFFIXES:.o .c

.o.c:
	${CC} ${CFLAGES} -c $<

all:bcopy_system

bcopy_system:bcopy_system.o
	${CC} ${CFLAG} bcopy_system bcopy_system.o

bcopy_system.o:bcopy_system.c

.PHONY:all

clean:
	rm -rf *.o bcopy_system.c
