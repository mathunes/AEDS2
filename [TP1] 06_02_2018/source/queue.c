#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void clearQueue (Queue *queue) {
	queue->first = (Cell*) malloc(sizeof(Cell));
	queue->last = queue->first;
	queue->first->next = NULL;
	queue->size = 0;
}

int isEmpty (Queue queue) {
	return (queue.size == 0);
}

void enQueue (Queue *queue, Ticket ticket) {
	Pointer aux = (Cell*) malloc (sizeof(Cell));
	if (aux == NULL) {
		printf("Memory error");
		exit(0);
	}

	queue->last->next = aux;
	queue->last = queue->last->next;
	queue->last->ticket = ticket;
	queue->last->timeInQueue = 1;
	queue->last->next = NULL;

	if (queue->size == 0) {
		queue->first = queue->last;
	}

	queue->size++;
}

Ticket deQueue (Queue *queue) {
	if (!isEmpty(*queue)) {
		Pointer aux = queue->first;
		Ticket ticket = aux->ticket;

		queue->first = queue->first->next;
		
		free (aux);
		queue->size--;

		return ticket;

	} else {
		printf("ERROR: The queue is already empty.");
		return -1;
	}
}

void increaseTime (Queue *queue) {
	if (!isEmpty(*queue)) {
		Pointer p = queue->first;
		
		while (p != NULL) {
			p->timeInQueue++;
			p = p->next;
		}
	} else
		return;
}