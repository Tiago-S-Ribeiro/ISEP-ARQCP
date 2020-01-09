file: calculate.o main.o
	gcc -g -Wall calculate.o main.o -o file
	
calculate.o: calculate.s
	gcc -g -Wall -c calculate.s -o calculate.o

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

clean:
	rm -f *.o file

run: file
	./file
