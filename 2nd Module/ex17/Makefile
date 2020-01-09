file: calculator.o main.o
	gcc -g -Wall calculator.o main.o -o file
	
calculator.o: calculator.s
	gcc -g -Wall -c calculator.s -o calculator.o

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

clean:
	rm -f *.o file

run: file
	./file
