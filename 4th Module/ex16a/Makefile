ex16: changes.o main.o
	gcc -Wall changes.o main.o -o main

changes.o: changes.c changes.h
	gcc -Wall -c changes.c

main.o: main.c changes.h
	gcc -Wall -c main.c
clean:
	rm -f *.o main
run: ex16
	./main
