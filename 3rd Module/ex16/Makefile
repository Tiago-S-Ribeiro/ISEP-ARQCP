file: swap.o main.o
	gcc -g -Wall swap.o main.o -o file
	
swap.o: swap.s
	gcc -g -Wall -c swap.s -o swap.o

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

clean:
	rm -f *.o file

run: file
	./file
