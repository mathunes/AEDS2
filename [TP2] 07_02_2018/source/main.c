#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "array.h"
#include "sort.h"

typedef clock_t Time;

void main(int argc, char *argv[]) {
	ItemArray a,b;
	Index i, n = 100;
	int p = 1;
	Time t;

	srand(time(NULL));

	//altera as variaveis de acordo com os parametros
	for (i = 0; i < argc; i++) {
		if (strcmp(argv[i], "-n") == 0) {
			n = atoi(argv[i+1]);

			if (n > MAXLEN) n = MAXLEN;
			else if (n < 1) n = 1;
		}

		if (strcmp(argv[i], "-p") == 0)
			p = atoi(argv[i+1]);
			
		//para exibir a ajuda verifica se tem o parametro -help ou ? na lista
		if (strcmp(argv[i], "-help") == 0 || argv[i][0] == '?') {
			printf("\n--------------------------------------\n\n");
			printf(" Parametros do programa:\n");
			printf(" -n [#] ..... Tamanho do vetor. Máximo: 100000 Default: -n 100\n");
			printf(" -p [#] ..... Estado inical da ordenacao. Default: -p 1\n");
			printf("\t1: Crescente\n");
			printf("\t2: Decrescente\n");
			printf("\t3: Aleatorio\n");
			printf("\n--------------------------------------\n");			
			return;		
		}
	}

	fillArray(a,n,p); /*Preenche o arranjo principal para funcionar como referência*/

    printf("\n--------------------------------------\n\n");
	printf(" Tamanho: %d | Ordenacao: %d \n", n, p);

	copyArray(a,b,n); /*Copia a referência para o arranjo secundário que será ordenado*/
	t = clock(); Select(b,n); t = clock() - t; /*Ordena e registra o tempo de execução em t*/
	printf("\tSelect:\t%lf segundos\n", ((double)t)/CLOCKS_PER_SEC);
	
	copyArray(a,b,n); /*Copia a referência para o arranjo secundário que será ordenado*/
	t = clock(); Insert(b,n); t = clock() - t; /*Ordena e registra o tempo de execução em t*/
	printf("\tInsert:\t%lf segundos\n", ((double)t)/CLOCKS_PER_SEC);
	
	copyArray(a,b,n); /*Copia a referência para o arranjo secundário que será ordenado*/
	t = clock(); Bubble(b,n); t = clock() - t; /*Ordena e registra o tempo de execução em t*/
	printf("\tBubble:\t%lf segundos\n", ((double)t)/CLOCKS_PER_SEC);
	
	copyArray(a,b,n); /*Copia a referência para o arranjo secundário que será ordenado*/
	t = clock(); Shell(b,n); t = clock() - t; /*Ordena e registra o tempo de execução em t*/
	printf("\tShell:\t%lf segundos\n", ((double)t)/CLOCKS_PER_SEC);
	
	copyArray(a,b,n); /*Copia a referência para o arranjo secundário que será ordenado*/
	t = clock(); Quick(b,n); t = clock() - t; /*Ordena e registra o tempo de execução em t*/
	printf("\tQuick:\t%lf segundos\n", ((double)t)/CLOCKS_PER_SEC);
	
	copyArray(a,b,n); /*Copia a referência para o arranjo secundário que será ordenado*/
	t = clock(); Heap(b,n); t = clock() - t; /*Ordena e registra o tempo de execução em t*/
	printf("\tHeap:\t%lf segundos\n", ((double)t)/CLOCKS_PER_SEC);

    printf("\n--------------------------------------\n\n");		
    printf("Ajuda: -help\n");
}