all: test main

test: IlgasInt.o IlgasIntTest.o test.o
	gcc -lm -g -o test IlgasInt.o IlgasIntTest.o test.o

main: main.o IlgasInt.o
	gcc -lm -g -o main main.c IlgasInt.o
	    
IlgasInt.o: IlgasInt.c IlgasInt.h
	gcc -g -c IlgasInt.c

test.o: test.c
	gcc -g -c test.c

main.o: main.c
	gcc -g -c test.c

IlgasIntTest.o: IlgasIntTest.c IlgasIntTest.h
	gcc -g -c IlgasIntTest.c

clean: 
	rm -f *.o test main

