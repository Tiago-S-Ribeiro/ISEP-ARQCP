file: compute.o main.o
	gcc -g -Wall compute.o main.o -o file
	
compute.o: compute.s
	gcc -g -Wall -c compute.s -o compute.o

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

clean:
	rm -f *.o file

run: file
	./file
