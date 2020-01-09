file: even.o main.o
	gcc -g -Wall even.o main.o -o file
	
even.o: even.s
	gcc -g -Wall -c even.s -o even.o

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

clean:
	rm -f *.o file

run: file
	./file
