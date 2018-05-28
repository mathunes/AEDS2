typedef int Time;
typedef int Ticket;
typedef struct Cell *Pointer;
typedef struct Cell {
	Ticket ticket;
	Time timeInQueue;
	Pointer next;
} Cell;

typedef struct Queue {
	Pointer first;
	Pointer last;
	int size;
} Queue;

void clearQueue (Queue *queue);
int isEmpty (Queue queue);
void enQueue (Queue *queue, Ticket ticket);
Ticket deQueue (Queue *queue);
void printQueue (Queue queue);
void increaseTime (Queue *queue);
