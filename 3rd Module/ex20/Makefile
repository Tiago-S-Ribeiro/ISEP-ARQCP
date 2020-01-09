file: count_seq.o main.o
	gcc -g -Wall count_seq.o main.o -o file
	
count_seq.o: count_seq.s
	gcc -g -Wall -c count_seq.s -o count_seq.o

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

clean:
	rm -f *.o file

run: file
	./file
