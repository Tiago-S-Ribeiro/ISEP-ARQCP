file: upper2.o main.o
	gcc -Wall upper2.o main.o -o file

upper1.o: upper2.c
	gcc -Wall -c upper2.c -o upper2.o

main.o: main.c
	gcc -Wall -c main.c -o main.o
