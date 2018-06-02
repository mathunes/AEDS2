Para execução do programa, no prompt de comando:
	- acesse a pasta 'source', onde estão os arquivos para compilação
	- chame a aplicação 'make', esta irá compilar todos os arquivos e gerar o executavel 'lunch';
	- chamar 'lunch' sem passar nenhum parametro ira executar o mesmo com as variáveis do caso incial conforme o documentado;
	- para ajuda em como alterar as variáveis do caso de estudo entre com o comando '-help';

A seguir, um exemplo:

	C:\...\source\ make
		gcc -c lunch.c
		gcc -c queue.c
		gcc -c stack.c
		gcc -o lunch.exe lunch.o queue.o stack.o
	C:\...\source lunch
		--------------------------------------
		 Qtd. Maxima de Bandejas: 30
		 Qtd. de Caixas para Atendimento: 1
		 Qtd. de Pilhas de Bandeja: 1
		 Tempo para renovacao da Pilha: 12
		--------------------------------------
		 Atendimentos Finalizados: 216
		 Tempo Medio de Atendimento: 65.185
		--------------------------------------
		Ajuda: -help
	C:\...\source\ lunch -help
		--------------------------------------
		 Parametros do programa:
		 -q [#] ..... Quantidade maxima de bandejas na pilha. Default: -d 30
		 -r [#] ..... Quantidade de caixas para atendimento. Default: -r 1
		 -s [#] ..... Quantiadade de pilhas de bandeja. Default: -s 1
		 -t [#] ..... Tempo para que haja refil de bandejas. Default: -t 12
		--------------------------------------
	C:\...\source lunch -q 35
		--------------------------------------
		 Qtd. Maxima de Bandejas: 35
		 Qtd. de Caixas para Atendimento: 1
		 Qtd. de Pilhas de Bandeja: 1
		 Tempo para renovacao da Pilha: 12
		--------------------------------------
		 Atendimentos Finalizados: 221
		 Tempo Medio de Atendimento: 64.778
		--------------------------------------
		Ajuda: -help