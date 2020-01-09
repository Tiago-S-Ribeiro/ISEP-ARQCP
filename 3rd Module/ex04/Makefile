file: vec_add_one.o main.o
	gcc -g -Wall vec_add_one.o main.o -o file
	
vec_add_one.o: vec_add_one.s
	gcc -g -Wall -c vec_add_one.s -o vec_add_one.o

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

clean:
	rm -f *.o file

run: file
	./file
