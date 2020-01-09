file: inc_and_square.o main.o
	gcc -g -Wall inc_and_square.o main.o -o file
	
inc_and_square.o: inc_and_square.s
	gcc -g -Wall -c inc_and_square.s -o inc_and_square.o

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

clean:
	rm -f *.o file

run: file
	./file
