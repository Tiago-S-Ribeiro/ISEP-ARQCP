ex07: array_sort1.o main.o
	gcc -Wall array_sort1.o main.o -o main

array_sort1.o: array_sort1.c array_sort1.h
	gcc -Wall -c array_sort1.c

main.o: main.c array_sort1.h
	gcc -Wall -c main.c
clean:
	rm -f *.o main
run: ex07
	./main

