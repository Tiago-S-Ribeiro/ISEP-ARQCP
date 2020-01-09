ex16: changes.o main.o
	gcc -g -Wall changes.o main.o -o ex16
	
changes.o: changes.s
	gcc -g -Wall -c changes.s -o changes.o

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

clean:
	rm -f *.o ex10

run: ex16
	./ex16
