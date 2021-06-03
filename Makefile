ccontain: container.o main.o
	gcc container.o main.o -o ccontain

container.o: container.c container.h
	gcc -c container.c

main.o: main.c container.h
	gcc -c main.c 