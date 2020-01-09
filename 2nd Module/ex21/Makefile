file: new_salary.o main.o
	gcc -g -Wall new_salary.o main.o -o file
	
new_salary.o: new_salary.s
	gcc -g -Wall -c new_salary.s -o new_salary.o

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

clean:
	rm -f *.o file

run: file
	./file
