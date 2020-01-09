ex06: power_ref.o main.o
	gcc -Wall power_ref.o main.o -o main

power_ref.o: power_ref.c power_ref.h
	gcc -Wall -c power_ref.c

main.o: main.c power_ref.h
	gcc -Wall -c main.c
clean:
	rm -f *.o main
run: ex06
	./main

