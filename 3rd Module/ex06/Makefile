file: encrypt.o main.o
	gcc -g -Wall encrypt.o main.o -o file
	
encrypt.o: encrypt.s
	gcc -g -Wall -c encrypt.s -o encrypt.o

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

clean:
	rm -f *.o file

run: file
	./file
