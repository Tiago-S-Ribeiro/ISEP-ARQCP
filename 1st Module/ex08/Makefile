ex08: array_sort2.o main.o
	gcc -Wall array_sort2.o main.o -o main

power_ref.o: array_sort2.c array_sort2.h
	gcc -Wall -c array_sort2.c

main.o: main.c array_sort2.h
	gcc -Wall -c main.c
clean:
	rm -f *.o main
run: ex08
	./main
