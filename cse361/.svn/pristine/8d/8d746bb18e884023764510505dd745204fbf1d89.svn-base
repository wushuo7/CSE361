.PHONY: all clean

# define variables necessary
PROG = sort test-swap
CFLAGS = -g -Wall -O0

all: $(PROG) 

swap.o: swap.c
	gcc $(CFLAGS) -c swap.c -o swap.o

test-swap.o: test-swap.c
	gcc $(CFLAGS) -c test-swap.c -o test-swap.o

test-swap: test-swap.o swap.o
	gcc test-swap.o swap.o -o test-swap

sort.o: sort.c
	gcc $(CFLAGS) -c sort.c -o sort.o

sort: sort.o swap.o
	gcc sort.o swap.o -o sort

clean:
	rm -f $(PROG) *.o

