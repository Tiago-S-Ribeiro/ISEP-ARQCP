file: rotate.o main.o
	gcc -g -Wall rotate.o main.o -o file
	
rotate.o: rotate.c
	gcc -g -Wall -c rotate.c -o rotate.o

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

clean:
	rm -f *.o file

run: file
	./file
