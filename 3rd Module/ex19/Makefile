file: frequencies.o main.o
	gcc -g -Wall frequencies.o main.o -o file
	
frequencies.o: frequencies.s
	gcc -g -Wall -c frequencies.s -o frequencies.o

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

clean:
	rm -f *.o file

run: file
	./file
