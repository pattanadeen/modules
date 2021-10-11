CFLAGS=-Wall -pedantic -std=c11 -I. -g

all:   		test1

queue.o: 	queue.c queue.h
			gcc $(CFLAGS) -c queue.c

test1.o:  	test1.c queue.h
			gcc $(CFLAGS) -c test1.c

test1:   	test1.o queue.o
			gcc $(CFLAGS) test1.o queue.o -o test1

clean:
			rm -f *.o test1

