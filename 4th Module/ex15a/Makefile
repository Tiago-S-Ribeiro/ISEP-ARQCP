file: greater_date.o main.o
	gcc -g -Wall greater_date.o main.o -o file
	
greater_date.o: greater_date.c
	gcc -g -Wall -c greater_date.c -o greater_date.o

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

clean:
	rm -f *.o file

run: file
	./file
