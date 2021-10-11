CFLAGS=-Wall -pedantic -std=c11 -I. -g

all:   		test_put dev_qapply

%.o:		%.c %.h
			gcc $(CLAGS) -c $<

dev_qapply: queue.o car.o dev_qapply.o
			gcc $(CFLAGS) queue.o car.o dev_qapply.o -o $@

test_put:   queue.o car.o test_put.o
			gcc $(CFLAGS) queue.o car.o test_put.o -o $@

clean:
			rm -f *.o test_put dev_qapply