ex17: swap.o main.o
	gcc -Wall swap.o main.o -o main

swap.o: swap.c swap.h
	gcc -Wall -c swap.c

main.o: main.c swap.h
	gcc -Wall -c main.c
clean:
	rm -f *.o main
run: ex17
	./main
