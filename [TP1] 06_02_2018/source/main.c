#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void main() {
	//declaração das filas principais e variaveis auxiliares
	Queue ticketQueue, trayQueue, foodQueue;
	Time time = 1;
	Ticket ticket = 1;
	int finished = 0, trayCount = 30;

	//inicialização das filas
	clearQueue(&ticketQueue);
	clearQueue(&trayQueue);
	clearQueue(&foodQueue);


	//inicio do ciclo principal
	do {
		//caso a fila de comida não esteja vazia, verifica se o tempo na 
		//fila da célula cabeça é maior que 4, indicando que a mesma já
		//percorreu as 4 etapas do serviço. caso positivo, remove-o finalizando o atendimento
		if (!isEmpty(foodQueue)) {
			if (foodQueue.first->timeInQueue > 4) {
				deQueue(&foodQueue);
				finished++;
			}

			//incrementa o tempo em fila das celulas
			increaseTime(&foodQueue);
		}

		//caso a fila de bandejas não esteja vazia e a contagem de bandejas na pilha
		//seja maior que 0, verifica se o tempo na fila da célula cabeça é maior que 1,
		//indicando o tempo gasto no processo de chegar na fila e pegar a bandeja.
		//caso positivo, remove-o o transferindo para a fila de comidas.
		if (!isEmpty(trayQueue) && trayCount > 0) {
			if (trayQueue.first->timeInQueue > 1) {
			 	enQueue(&foodQueue, deQueue(&trayQueue));
				trayCount--;
			}

			//incrementa o tempo em fila das celulas
			increaseTime(&trayQueue);
		}

		//caso a fila de fichas não esteja vazia, verifica se o tempo na fila da
		//célula cabeça é maior que 1, indicando o tempo gasto no processo de chegar na
		//fila e ser atendido pelo caixa. caso positivo, remove-o o transferindo para
		//a fila de bandejas.
		if (!isEmpty(ticketQueue)) {
			if (ticketQueue.first->timeInQueue > 1) {
			 	enQueue(&trayQueue, deQueue(&ticketQueue));
			}

			//incrementa o tempo em fila das celulas
			increaseTime(&ticketQueue);
		}

		//em todas unidade de tempo, dois novos clientes chegam na fila de fichas.
		enQueue(&ticketQueue, ticket++);
		enQueue(&ticketQueue, ticket++);

		//de 12 em 12 unidades de tempo a pilha de bandeja é reabastecida com 10 novas bandejas.
		if (time%12 == 0) {
			trayCount += 10;
		}

		//incrementa o tempo em uma unidade
		time++;

	} while (time < 240); //repete o ciclo até finalizar 240 unidades de tempo 

	printf("\n\n%d clientes finalizados", finished);
}