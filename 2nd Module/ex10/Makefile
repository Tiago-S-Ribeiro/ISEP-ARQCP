ex10: sum2ints.o main.o
	gcc -g -Wall sum2ints.o main.o -o ex10
	
sum2ints.o: sum2ints.s  sum2ints.h
	gcc -g -Wall -c sum2ints.s -o sum2ints.o

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

clean:
	rm -f *.o ex10

run: ex10
	./ex10
