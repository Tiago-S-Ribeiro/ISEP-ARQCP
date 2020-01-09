ex20: check_num.o main.o
	gcc -g -Wall check_num.o main.o -o ex20
	
check_num.o: check_num.s
	gcc -g -Wall -c check_num.s -o check_num.o

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

clean:
	rm -f *.o ex20

run: ex20
	./ex20
