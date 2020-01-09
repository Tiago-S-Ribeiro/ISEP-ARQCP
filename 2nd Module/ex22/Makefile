ex22: f.o main.o
	gcc -g -Wall f.o main.o -o ex22
	
f.o: f.s
	gcc -g -Wall -c f.s -o f.o

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

clean:
	rm -f *.o ex22

run: ex22
	./ex22
