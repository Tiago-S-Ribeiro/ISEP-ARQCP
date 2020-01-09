file: str_copy_porto.o main.o
	gcc -g -Wall str_copy_porto.o main.o -o file
	
str_copy_porto.o: str_copy_porto.s
	gcc -g -Wall -c str_copy_porto.s -o str_copy_porto.o

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

clean:
	rm -f *.o file

run: file
	./file
