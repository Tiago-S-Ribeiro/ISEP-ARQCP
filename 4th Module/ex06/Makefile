ex06: test_equal.o main.o
	gcc -g -Wall test_equal.o main.o -o ex06
	
test_equal.o: test_equal.s
	gcc -g -Wall -c test_equal.s -o test_equal.o

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

clean:
	rm -f *.o ex06

run: ex06
	./ex06
