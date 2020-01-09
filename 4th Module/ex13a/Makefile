file: activate_bits.o main.o
	gcc -g -Wall activate_bits.o main.o -o file
	
activate_bits.o: activate_bits.c
	gcc -g -Wall -c activate_bits.c -o activate_bits.o

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

clean:
	rm -f *.o file

run: file
	./file
