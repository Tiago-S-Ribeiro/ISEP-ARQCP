file: sort_without_reps.o main.o
	gcc -g -Wall sort_without_reps.o main.o -o file
	
sort_without_reps.o: sort_without_reps.s
	gcc -g -Wall -c sort_without_reps.s -o sort_without_reps.o

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

clean:
	rm -f *.o file

run: file
	./file
