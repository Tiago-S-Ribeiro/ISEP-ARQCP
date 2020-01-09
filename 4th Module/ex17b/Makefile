file: add_byte.o main.o
	gcc -g -Wall add_byte.o main.o -o file
	
add_byte.o: add_byte.s
	gcc -g -Wall -c add_byte.s -o add_byte.o

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

clean:
	rm -f *.o file

run: file
	./file
