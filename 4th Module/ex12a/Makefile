ex12: activate_bit.o main.o
	gcc -Wall activate_bit.o main.o -o main

activate_bit.o: activate_bit.c activate_bit.h
	gcc -Wall -c activate_bit.c

main.o: main.c activate_bit.h
	gcc -Wall -c main.c
	
clean:
	rm -f *.o main
	
run: ex12
	./main
