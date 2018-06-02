#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void clearStack(Stack *stack, int max_size) {
	stack->top = (sCell*) malloc(sizeof(sCell));
	stack->bottom = stack->top;
	stack->top->next = NULL;
	stack->size = 0;
	stack->max_size = max_size;
}

int emptyStack(Stack stack) {
	return (stack.size == 0);
}

int fullStack(Stack stack) {
	return (stack.size == stack.max_size);
}

void push(Stack *stack, Tray trayNumber) {
	if (!fullStack(*stack)) {
		sPointer aux = (sCell*) malloc(sizeof(sCell));
		if (aux == NULL) {
			printf("Memory error");
			exit(0);
		}

		aux->trayNumber = trayNumber;

		if (stack->size == 0) {
			stack->top = aux;
			stack->bottom = aux;
		} else {
			aux->next = stack->top;
			stack->top = aux;
		}

		stack->size++;
	} else
		return;

}

Tray pop(Stack *stack) {
	if(!emptyStack(*stack)) {
		sPointer aux = stack->top;
		Tray trayNumber = stack->top->trayNumber;
		stack->top = stack->top->next;
		
		free(aux);
		stack->size--;

		return trayNumber;
	} else
		return -1;
}

void fillStack(Stack *stack, int amount) {
	for(int i=0; i<amount;i++) {
		push(stack, i+1);
	}
}