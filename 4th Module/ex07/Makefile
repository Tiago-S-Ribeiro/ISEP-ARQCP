file: count_even.o main.o
	gcc -g -Wall count_even.o main.o -o file
	
count_even.o: count_even.s
	gcc -g -Wall -c count_even.s -o count_even.o

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

clean:
	rm -f *.o file

run: file
	./file
