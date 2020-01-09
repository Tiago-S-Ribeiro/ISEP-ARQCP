file: crossSumBytes.o main.o
	gcc -g -Wall crossSumBytes.o main.o -o file
	
crossSumBytes.o: crossSumBytes.s
	gcc -g -Wall -c crossSumBytes.s -o crossSumBytes.o

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

clean:
	rm -f *.o file

run: file
	./file
