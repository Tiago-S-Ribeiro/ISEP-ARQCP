file: duplicates.o main.o
	gcc -g -Wall duplicates.o main.o -o file
	
duplicates.o: duplicates.s
	gcc -g -Wall -c duplicates.s -o duplicates.o

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

clean:
	rm -f *.o file

run: file
	./file
