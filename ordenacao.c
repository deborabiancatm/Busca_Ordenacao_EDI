#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <unistd.h>

int swap(int *menor, int *i){ //Funcao que troca valores de endereco
    int aux = *i;
    *i = *menor;
    *menor = aux;
    return 0;
}

//FUNCOES DE ORDENACAO
int selectionSort(int *vet, int size){
    //ORDENA SELECTION SORT
    clock_t start, end;
    int i, j, min, aux = 0;

    start = clock(); //Comeca a contar o tempo de execucao
    for (i = 0; i < size-1; i++){
        min = i; //define i a posicao minima
        for (j = i+1; j < size; j++){ //percorre o vetor procurando o menor valor
            if (vet[min] > vet[j]){ //se encontrar um valor menor
                min = j; //a posicao de menor valor e redefinida
            }
        }
        if(min != i)
            swap(&vet[min], &vet[i]); //troca os valores
    }

    end = clock(); // finaliza a contagem do tempo
    float total_time = ((double) (end - start)) / CLK_TCK; //realiza o calculo de temp

    printf("ALGORITMO: SELECTION SORT\n");
    printf("TAMANHO: %d numeros\n", size);
    printf("TEMPO: %f segundos\n", total_time);

    return 0;
}
