ex12: isMultiple.o main.o
	gcc -g -Wall isMultiple.o main.o -o ex12
	
isMultiple.o: isMultiple.s  isMultiple.h
	gcc -g -Wall -c isMultiple.s -o isMultiple.o

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

clean:
	rm -f *.o ex12

run: ex12
	./ex12
