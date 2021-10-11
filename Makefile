CFLAGS=-Wall -pedantic -std=c11 -I. -g

all:   		test1

%.o:	%.c %.h
		gcc $(CLAGS) -c $<

test_put:   test_put.o queue.o
			gcc $(CFLAGS) test_put.o queue.o -o t$@

clean:
			rm -f *.o test_put

