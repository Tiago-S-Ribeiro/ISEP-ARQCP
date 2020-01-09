file: greatest.o main.o
	gcc -g -Wall greatest.o main.o -o file
	
greatest.o: greatest.s
	gcc -g -Wall -c greatest.s -o greatest.o

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

clean:
	rm -f *.o file

run: file
	./file
