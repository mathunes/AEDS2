#include <stdio.h>
#include <stdlib.h>
#include "array.h"

void printArray(ItemArray array, Index n) {
	Index i;
	printf("[");
	for (i = 1; i <= n; i++) {
		printf("%li ", array[i].id);
	}
	printf("]\n");
}

void fillArray(ItemArray array, Index n, int option) {
	Index i;

	switch(option) {
		case 1:
			for(i = 1; i <= n; i++) {
				array[i].id = i;
			}
			break;
		case 2:
			for (i = n; i > 0; i--) {
				array[n - i + 1].id = i;
			}
			break;
		case 3:
			for (i = 1; i <= n; i++) {
				array[i].id = ((rand()%n) + 1); 
			}
			break;
		default:
			for(i = 1; i <= n; i++) {
				array[i].id = i;
			}
	}
}

void copyArray(ItemArray array, ItemArray copy, Index n) {
	Index i;

	for (i = 1; i <= n; i++) {
		copy[i].id = array[i].id;
	}
}