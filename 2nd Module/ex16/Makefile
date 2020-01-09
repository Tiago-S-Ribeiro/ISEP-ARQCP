ex16: steps.o main.o
	gcc -g -Wall steps.o main.o -o ex16
	
steps.o: steps.s
	gcc -g -Wall -c steps.s -o steps.o

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

clean:
	rm -f *.o ex16

run: ex16
	./ex16
