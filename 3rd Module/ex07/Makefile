ex07: encrypt.o decrypt.o main.o
	gcc -g -Wall encrypt.o decrypt.o main.o -o ex07
	
encrypt.o: encrypt.s
	gcc -g -Wall -c encrypt.s -o encrypt.o
	
decrypt.o: decrypt.s
	gcc -g -Wall -c decrypt.s -o decrypt.o

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

clean:
	rm -f *.o ex07

run: ex07
	./ex07
