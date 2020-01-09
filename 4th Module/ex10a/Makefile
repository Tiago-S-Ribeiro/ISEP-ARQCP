ex10: count_bits_zero.o main.o
	gcc -Wall count_bits_zero.o main.o -o main

count_bits_zero.o: count_bits_zero.c count_bits_zero.h
	gcc -Wall -c count_bits_zero.c

main.o: main.c count_bits_zero.h
	gcc -Wall -c main.c
clean:
	rm -f *.o main
run: ex10
	./main
