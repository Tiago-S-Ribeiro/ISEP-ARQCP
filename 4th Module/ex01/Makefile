file: cube.o cube.o main.o
	gcc -g -Wall cube.o main.o -o file
	
cube.o: cube.s
	gcc -g -Wall -c cube.s -o cube.o

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

clean:
	rm -f *.o file

run: file
	./file
