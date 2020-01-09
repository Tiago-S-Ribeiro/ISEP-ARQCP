ex03: sum_even.o main.o
	gcc -Wall sum_even.o main.o -o main

sum_even.o: sum_even.c sum_even.h
	gcc -Wall -c sum_even.c

main.o: main.c sum_even.h
	gcc -Wall -c main.c
clean:
	rm -f *.o main
run: ex03
	./main

