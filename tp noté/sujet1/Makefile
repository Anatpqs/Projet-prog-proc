prog: main.o fonction.o
	gcc -Wall -o prog main.o fonction.o -lm

main.o: main.c
	gcc -o main.o -c main.c 

fonction.o: fonction.c
	gcc -o fonction.o -c fonction.c

exe: prog
	./prog

clean :
	rm *.o prog