ex13: where_is.o main.o
	gcc -Wall where_is.o main.o -o main

where_is.o: where_is.c where_is.h
	gcc -Wall -c where_is.c

main.o: main.c where_is.h
	gcc -Wall -c main.c
clean:
	rm -f *.o main
run: ex13
	./main
