file: test_flags.o main.o
	gcc -g -Wall test_flags.o main.o -o file
	
test_flags.o: test_flags.s
	gcc -g -Wall -c test_flags.s -o test_flags.o

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

clean:
	rm -f *.o file

run: file
	./file
