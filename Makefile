CFLAGS=-Wall -pedantic -std=c11 -I. -g

all:   		test_put

%.o:		%.c %.h
			gcc $(CLAGS) -c $<

test_put:   queue.o car.o test_put.o 
			gcc $(CFLAGS) queue.o car.o test_put.o -o $@

clean:
			rm -f *.o test_put

