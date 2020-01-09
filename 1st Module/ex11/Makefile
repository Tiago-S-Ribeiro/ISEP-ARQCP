ex11: palindrome.o main.o
	gcc -Wall palindrome.o main.o -o main

palindrome.o: palindrome.c palindrome.h
	gcc -Wall -c palindrome.c

main.o: main.c palindrome.h
	gcc -Wall -c main.c
clean:
	rm -f *.o main
run: ex11
	./main
