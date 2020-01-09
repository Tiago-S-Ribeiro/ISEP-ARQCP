ex14: getArea.o main.o
	gcc -g -Wall getArea.o main.o -o ex14
	
getArea.o: getArea.s
	gcc -g -Wall -c getArea.s -o getArea.o

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

clean:
	rm -f *.o ex14

run: ex14
	./ex14
