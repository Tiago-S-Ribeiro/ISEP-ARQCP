file: needed_time.o main.o
	gcc -g -Wall needed_time.o main.o -o file
	
needed_time.o: needed_time.s
	gcc -g -Wall -c needed_time.s -o needed_time.o

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

clean:
	rm -f *.o file

run: file
	./file
