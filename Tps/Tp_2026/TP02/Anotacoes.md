Fazer as questões do TP02

o que falta ser feito

- Questão 01 -> Esta tudo certo e pronto 
- Questão 02 -> Falta fazer tudo 
- Questão 03 -> Falta fazer tudo e os log
- Questão 04 -> Falta fazer o log para contar e gerar um arquivo para mostrar o tempo de execução
- Questão 05 -> Falta fazer a pesquisa sequencial e o log  < classes prontas > 
- Questão 06 -> Falta fazer tudo e os log
- Questão 07 -> Falta fazer a ordenação e o log  < classes prontas >
- Questão 08 -> Falta fazer tudo e os log
- Questão 09 -> Falta fazer a ordenação e o log  < classes prontas >
- Questão 10 -> Falta fazer tudo e os log
- Questão 11 -> Falta fazer a lista com alocação sequencial e o log  < classes prontas >
- Questão 12 -> Falta fazer tudo e os log
- Questão 13 -> Falta fazer a fila circular com Alocação sequencial e o log  < classes prontas >

-------------

Todos os logs devem ser utilizado no que esta em fontes na unidade 3 na parte de ordenação

em java para calcular seria assim:


      //Execucao do algoritmo de ordenacao
		inicio = algoritmo.now();
		algoritmo.sort();
		fim = algoritmo.now();


      //Mostrar o conjunto ordenado, tempo de execucao e status da ordenacao
		//algoritmo.mostrar();
		System.out.println("Tempo para ordenar: " + (fim-inicio)/1000.0 + " s.");
		System.out.println("isOrdenado: " + algoritmo.isOrdenado());


em C para calcular seria assim:

chamar essa biblioteca 

#include < time.h >



declarar variaveis assim 

   clock_t inicio, fim;
    double total;

//Execucao do algoritmo de ordenacao
	 
    inicio = clock();
    
    //insercao(array, n);
    
    fim = clock();
    total = ((fim - inicio) / (double)CLOCKS_PER_SEC);    // esse CLOCKS_PER_SEC transforma o tempo para segundos, tem que tirar e deixar em milissegundos


    //Mostrar o conjunto ordenado, tempo de execucao e status da ordenacao
	 //algoritmo.mostrar(array, n);

	 printf("Tempo para ordenar: %f s.\n", total);
	 printf("isOrdenado: %s\n", isOrdenado(array, n) ? "true" : "false");


-------------


Arrumar as classes em java, pois o ler arquivo que esta em coleção restaurante deve ser lido na classe Restaurante.