ex09: sort_without_reps.o main.o
	gcc -Wall sort_without_reps.o main.o -o main

sort_without_reps.o: sort_without_reps.c sort_without_reps.h
	gcc -Wall -c sort_without_reps.c

main.o: main.c sort_without_reps.h
	gcc -Wall -c main.c
clean:
	rm -f *.o main
run: ex09
	./main
