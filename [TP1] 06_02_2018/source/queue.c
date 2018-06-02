#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void clearQueue (Queue *queue) {
	queue->first = (qCell*) malloc(sizeof(qCell));
	queue->last = queue->first;
	queue->first->next = NULL;
	queue->size = 0;
}

int emptyQueue (Queue queue) {
	return (queue.size == 0);
}

void enQueue (Queue *queue, Ticket ticket, Time serviceTime) {
	qPointer aux = (qCell*) malloc (sizeof(qCell));
	if (aux == NULL) {
		printf("Memory error");
		exit(0);
	}

	queue->last->next = aux;
	queue->last = queue->last->next;
	queue->last->ticket = ticket;
	queue->last->queueTime = 0;
	queue->last->serviceTime = serviceTime;
	queue->last->next = NULL;

	if (queue->size == 0) {
		queue->first = queue->last;
	}

	queue->size++;
}

Ticket deQueue (Queue *queue) {
	if (!emptyQueue(*queue)) {
		qPointer aux = queue->first;
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

void increaseQueueTime (Queue *queue) {
	if (!emptyQueue(*queue)) {
		qPointer p = queue->first;
		
		while (p != NULL) {
			p->queueTime++;
			p = p->next;
		}
	} else
		return;
}

void increaseServiceTime (Queue *queue) {
	if (!emptyQueue(*queue)) {
		qPointer p = queue->first;
		
		while (p != NULL) {
			p->serviceTime++;
			p = p->next;
		}
	} else
		return;
}