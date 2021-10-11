CFLAGS=-Wall -pedantic -std=c11 -I. -g

all:   		test_success dev_qapply

%.o:		%.c %.h
			gcc $(CLAGS) -c $<

dev_qapply: queue.o car.o dev_qapply.o
			gcc $(CFLAGS) queue.o car.o dev_qapply.o -o $@

test_success:   queue.o car.o test_success.o
			gcc $(CFLAGS) queue.o car.o test_success.o -o $@

clean:
			rm -f *.o test_success dev_qapply