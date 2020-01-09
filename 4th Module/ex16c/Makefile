ex16: changes.o changes_vec.o main.o
	gcc -g -Wall changes.o changes_vec.o main.o -o ex16

changes.o: changes.s
	gcc -g -Wall -c changes.s -o changes.o
		
changes_vec.o: changes_vec.s
	gcc -g -Wall -c changes_vec.s -o changes_vec.o

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

clean:
	rm -f *.o ex16

run: ex16
	./ex16
