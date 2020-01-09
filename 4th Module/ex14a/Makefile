ex14: join_bits.o main.o
	gcc -Wall join_bits.o main.o -o main

join_bits.o: join_bits.c join_bits.h
	gcc -Wall -c join_bits.c

main.o: main.c join_bits.h
	gcc -Wall -c main.c
clean:
	rm -f *.o main
run: ex14
	./main
