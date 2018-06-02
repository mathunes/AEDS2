#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "stack.h"

//esta função calcula a média de dois inteiros e retorna em float
float mean(int total, int n);

void main(int argc, char *argv[]) {
	//declaração das filas principais e variaveis auxiliares
	Queue ticketQueue, trayQueue, foodQueue;
	Stack trayStack;
	Time time = 0, aux, totalServiceTime = 0;
	Ticket ticket = 1;
	int finished = 0;
	int i;

	//declaração dos parâmetros para o caso de análise
	int max_stack = 30, cashiers_number = 1, stacks_number = 1, refill_time = 12;

	//altera as variaveis de controle do ciclo de acordo com os parametros
	for (i = 0; i < argc; i++) {
		if (strcmp(argv[i], "-q") == 0)
			max_stack = atoi(argv[i+1]);
	
		if (strcmp(argv[i], "-r") == 0)
			cashiers_number = atoi(argv[i+1]);
		
		if (strcmp(argv[i], "-s") == 0)
			stacks_number = atoi(argv[i+1]);

		if (strcmp(argv[i], "-t") == 0)
			refill_time = atoi(argv[i+1]);
			
		//para exibir a ajuda verifica se tem o parametro -help ou ? na lista
		if (strcmp(argv[i], "-help") == 0 || argv[i][0] == '?') {
			printf("\n--------------------------------------\n\n");
			printf(" Parametros do programa:\n");
			printf(" -q [#] ..... Quantidade maxima de bandejas na pilha. Default: -d 30\n");
			printf(" -r [#] ..... Quantidade de caixas para atendimento. Default: -r 1\n");
			printf(" -s [#] ..... Quantiadade de pilhas de bandeja. Default: -s 1\n");				
			printf(" -t [#] ..... Tempo para que haja refil de bandejas. Default: -t 12\n");
			printf("\n--------------------------------------\n");			
			return;		
		}
	}

	//inicialização das filas
	clearQueue(&ticketQueue);
	clearQueue(&trayQueue);
	clearQueue(&foodQueue);

	//inicializa a pilha de bandejas, define o máximo de bandejas permitidas na pilha e a enche.
	//a nivel de codigo, as pilhas são implementadas em uma única, e.g. 2 pilhas de 30 se tornam 1 pilha de 60.
	clearStack(&trayStack, max_stack * stacks_number);
	fillStack(&trayStack, max_stack * stacks_number);

	//inicio do ciclo principal
	//incrementa o tempo em uma unidade e repete o ciclo até finalizar 240 unidades de tempo 
	while (++time <= 240) {
		//caso a fila de comida não esteja vazia, verifica se o tempo na 
		//fila da célula cabeça é maior ou igual a 4, indicando que a mesma já
		//percorreu as 4 etapas do serviço. caso positivo, remove-o finalizando o atendimento.
		if (!emptyQueue(foodQueue)) {
			//incrementa o tempo em fila das celulas
			increaseQueueTime(&foodQueue);

			if (foodQueue.first->queueTime >= 4) {
				totalServiceTime += foodQueue.first->serviceTime; //ao finalizar o atendimento o tempo total é incrementado.
				deQueue(&foodQueue);
				finished++;//incrementa o contador de clientes com antendimento finalizado
			}
		}

		//caso a fila de bandejas não esteja vazia e a contagem de bandejas na pilha
		//seja maior que 0, verifica se o tempo na fila da célula cabeça é maior ou igual a 1,
		//indicando o tempo gasto no processo de chegar na fila e pegar a bandeja.
		//caso positivo, remove-o o transferindo para a fila de comidas.
		if (!emptyQueue(trayQueue) && trayStack.size > 0) {

			//essa ação é repetida de acordo com o número de pilhas existentes.
			//na implementação todas as pilhas são unidas em uma e a remoção de bandejas ocorre desta pilha unica.
			for (i = 0; i < stacks_number; i++) {
				if (trayQueue.first->queueTime >= 1) {
					aux = trayQueue.first->serviceTime;
				 	enQueue(&foodQueue, deQueue(&trayQueue), aux);
					pop(&trayStack);
				}
			}

			//incrementa o tempo em fila das celulas
			increaseQueueTime(&trayQueue);
		}

		//caso a fila de fichas não esteja vazia, verifica se o tempo na fila da
		//célula cabeça é maior ou igual a 1, indicando o tempo gasto no processo de chegar na
		//fila e ser atendido pelo caixa. caso positivo, remove-o o transferindo para
		//a fila de bandejas.
		if (!emptyQueue(ticketQueue)) {

			//essa ação é repeitda de acordo com o número de caixas definidos para atendimento.
			for (i = 0; i < cashiers_number; i++) {
				if (ticketQueue.first->queueTime >= 1) {
					aux = ticketQueue.first->serviceTime;
				 	enQueue(&trayQueue, deQueue(&ticketQueue), aux);
				}
			}

			//incrementa o tempo em fila das celulas
			increaseQueueTime(&ticketQueue);
		}

		//em todas unidade de tempo, dois novos clientes chegam na fila de fichas
		enQueue(&ticketQueue, ticket++, 0);
		enQueue(&ticketQueue, ticket++, 0);

		//a pilha é reabastecida com 10 bandejas de acordo com o tempo definido em refill_time
		if (time%refill_time == 0) {
			fillStack(&trayStack, 10 * stacks_number);
		}

		//incrementa o tempo total de serviço para todas as células nas filas
		increaseServiceTime(&ticketQueue);
		increaseServiceTime(&trayQueue);
		increaseServiceTime(&foodQueue);

	}


	//imprime resultados
	printf("\n--------------------------------------\n\n");
	printf(" Qtd. Maxima de Bandejas: %d\n",max_stack);
	printf(" Qtd. de Caixas para Atendimento: %d\n",cashiers_number);
	printf(" Qtd. de Pilhas de Bandeja: %d\n",stacks_number);
	printf(" Tempo para renovacao da Pilha: %d\n",refill_time);
	
	printf("\n--------------------------------------\n");
	printf("\n Atendimentos Finalizados: %d\n Tempo Medio de Atendimento: %.3f\n", finished, mean(totalServiceTime, finished));
	printf("\n--------------------------------------\n");
	printf("Ajuda: -help\n");

	return;

}

//esta função calcula a média de dois inteiros e retorna em float
float mean(int total, int n) {
	return ((float) total/ (float) n);
}