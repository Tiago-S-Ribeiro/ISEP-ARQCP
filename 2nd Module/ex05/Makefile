file: swapBytes.o main.o
	gcc -g -Wall swapBytes.o main.o -o file
	
swapBytes.o: swapBytes.s
	gcc -g -Wall -c swapBytes.s -o swapBytes.o

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

clean:
	rm -f *.o file

run: file
	./file
