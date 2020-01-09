ex04: main.o asm.o
	gcc -Wall main.o asm.o -o ex04

asm.o: asm.s
	gcc -g -Wall -c asm.s -o asm.o

main.o: main.c asm.h 
	gcc -g -Wall -c main.c -o main.o
clean:
	rm -f *.o ex04
run: ex04
	./ex04
