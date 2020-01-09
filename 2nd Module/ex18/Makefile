ex18: somatorio.o main.o
	gcc -g -Wall somatorio.o main.o -o ex18
	
somatorio.o: somatorio.s
	gcc -g -Wall -c somatorio.s -o somatorio.o

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

clean:
	rm -f *.o ex18

run: ex18
	./ex18
