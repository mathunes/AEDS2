all: main.exe

main.exe: main.o array.o sort.o
	gcc -o main.exe main.o array.o sort.o

array.o: array.c
	gcc -c array.c

sort.o: sort.c
	gcc -c sort.c
	
main.o: main.c
	gcc -c main.c
	 
clean:
	del array.o
	del sort.o
	del main.o
	del main.exe