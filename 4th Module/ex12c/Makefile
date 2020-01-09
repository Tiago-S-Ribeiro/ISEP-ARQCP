ex12: activate_2bits.o activate_bit.o main.o
	gcc -g -Wall activate_2bits.o activate_bit.o main.o -o ex12

activate_2bits.o: activate_2bits.s
	gcc -g -Wall -c activate_2bits.s -o activate_2bits.o
		
activate_bit.o: activate_bit.s
	gcc -g -Wall -c activate_bit.s -o activate_bit.o

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

clean:
	rm -f *.o ex12

run: ex12
	./ex12
