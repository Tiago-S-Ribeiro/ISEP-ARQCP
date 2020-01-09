ex06: concatBytes.o main.o
	gcc -g -Wall concatBytes.o main.o -o ex06
	
concatBytes.o: concatBytes.s  concatBytes.h
	gcc -g -Wall -c concatBytes.s -o concatBytes.o

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

clean:
	rm -f *.o ex06

run: ex06
	./ex06
