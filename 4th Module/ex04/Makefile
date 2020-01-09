ex04: sum_smaller.o main.o
	gcc -g -Wall sum_smaller.o main.o -o ex04
	
sum_smaller.o: sum_smaller.s
	gcc -g -Wall -c sum_smaller.s -o sum_smaller.o

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

clean:
	rm -f *.o ex04

run: ex04
	./ex04
