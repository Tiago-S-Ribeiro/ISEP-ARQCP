file: str_cat.o main.o
	gcc -g -Wall str_cat.o main.o -o file
	
str_cat.o: str_cat.s
	gcc -g -Wall -c str_cat.s -o str_cat.o

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

clean:
	rm -f *.o file

run: file
	./file
