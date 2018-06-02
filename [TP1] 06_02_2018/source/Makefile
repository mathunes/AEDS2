all: lunch.exe

lunch.exe: lunch.o queue.o stack.o
	gcc -o lunch.exe lunch.o queue.o stack.o

queue.o: queue.c
	gcc -c queue.c
	
stack.o: stack.c
	gcc -c stack.c
	
lunch.o: lunch.c
	gcc -c lunch.c
	 
clean:
	del queue.o
	del stack.o
	del lunch.o
	del lunch.exe