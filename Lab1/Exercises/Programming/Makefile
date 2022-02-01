all: readline.o factorial.o main.o
	gcc readline.o factorial.o main.o -o myfactorial
readline.o: readline.c readline.h
	gcc -c readline.c
factorial.o: factorial.c factorial.h
	gcc -c factorial.c
main.o: main.c readline.h factorial.h
	gcc -c main.c
clean:
	rm -f *.o myfactorial
pro4: problem4.c
	gcc problem4.c -o pro4_run

pro4clean:
	rm -f pro4_run
