ex10: count_bits_zero.o main.o
	gcc -g -Wall count_bits_zero.o main.o -o ex10
	
count_bits_zero.o: count_bits_zero.s
	gcc -g -Wall -c count_bits_zero.s -o count_bits_zero.o

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

clean:
	rm -f *.o ex10

run: ex10
	./ex10
