ex03: main.o asm.o sum_v2.o
	gcc main.o asm.o sum_v2.o -o ex03

sum_v2.o: sum_v2.s
	gcc -g -Wall -c sum_v2.s -o sum_v2.o
	
main.o: main.c asm.h sum_v2.h
	gcc -g -Wall -c main.c -o main.o
	
clean:
	rm -f *.o ex03
	
run: ex03
	./ex03
