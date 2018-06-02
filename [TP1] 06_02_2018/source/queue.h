typedef int Time;
typedef int Ticket;
typedef struct qCell *qPointer;
typedef struct qCell {
	Ticket ticket;
	Time queueTime;
	Time serviceTime;
	qPointer next;
} qCell;

typedef struct Queue {
	qPointer first;
	qPointer last;
	int size;
} Queue;

void clearQueue (Queue *queue);
int emptyQueue (Queue queue);
void enQueue (Queue *queue, Ticket ticket, Time currentServiceTime);
Ticket deQueue (Queue *queue);
void increaseQueueTime (Queue *queue);
void increaseServiceTime (Queue *queue);