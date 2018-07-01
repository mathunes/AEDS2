	Para execução do programa, no prompt de comando:
	- acesse a pasta 'source', onde estão os arquivos para compilação
	- chame a aplicação 'make', esta irá compilar todos os arquivos e gerar o arquivo 'main.exe';
	- chamar 'main.exe' sem passar nenhum parametro ira executar o mesmo com as variáveis do caso incial conforme o documentado;
	- para ajuda em como alterar as variáveis do caso de estudo entre com o comando '-help';

A seguir um exemplo de execução para linux:

	C:\...\source\ make
		gcc -c main.c
		gcc -c array.c
		gcc -c sort.c
		gcc -o main.exe main.o array.o sort.o

	C:\...\source\ ./main.exe
		--------------------------------------
		Tamanho: 100 | Ordenacao: 1
	        Select: 0.000000 segundos
        	Insert: 0.000000 segundos
        	Bubble: 0.000000 segundos
        	Shell:  0.000000 segundos
        	Quick:  0.000000 segundos
        	Heap:   0.000000 segundos
		--------------------------------------
		Ajuda -help

	C:\...\source\ ./main.exe -help
		--------------------------------------
	 	Parametros do programa:
		 -n [#] ..... Tamanho do vetor. M├íximo: 100000 Default: -n 100
		 -p [#] ..... Estado inical da ordenacao. Default: -p 1
        		1: Crescente
      		  2: Decrescente
     		  3: Aleatorio
		--------------------------------------

	C:\...\source\ ./main.exe -n 10000 -p 2
		--------------------------------------
 		Tamanho: 10000 | Ordenacao: 2
        	Select: 0.121000 segundos
        	Insert: 0.123000 segundos
        	Bubble: 0.210000 segundos
        	Shell:  0.001000 segundos
        	Quick:  0.001000 segundos
        	Heap:   0.001000 segundos
		--------------------------------------

Ajuda: -help