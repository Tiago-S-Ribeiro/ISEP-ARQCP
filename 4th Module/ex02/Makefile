ex02: sum_n.o main.o
	gcc -g -Wall sum_n.o main.o -o ex02
	
sum_n.o: sum_n.s
	gcc -g -Wall -c sum_n.s -o sum_n.o

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

clean:
	rm -f *.o ex02

run: ex02
	./ex02
