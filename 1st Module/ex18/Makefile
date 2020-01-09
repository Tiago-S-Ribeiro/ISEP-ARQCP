ex18: compress_shorts.o main.o
	gcc -Wall compress_shorts.o main.o -o main

compress_shorts.o: compress_shorts.c compress_shorts.h
	gcc -Wall -c compress_shorts.c

main.o: main.c compress_shorts.h
	gcc -Wall -c main.c
clean:
	rm -f *.o main
run: ex18
	./main
