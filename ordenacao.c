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
void selectionSort(int *vet, int size){
    clock_t start, end;
    int i, j, min;

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
    printf("TEMPO: %f segundos\n\n", total_time);
}

void insertSort(int *vet, int size){
    clock_t start, end;
    int i, j, pin;

    start = clock(); //Comeca a contar o tempo de execucao

    for (i = 1; i < size; i++){
        pin = vet[i];
        j = i-1;
        while (j >= 0 && vet[j] > pin){
            vet[j+1] = vet[j];
            j = j-1;
        }
        vet[j+1] = pin;
    }

    end = clock(); // finaliza a contagem do tempo
    float total_time = ((double) (end - start)) / CLK_TCK; //realiza o calculo de temp

    printf("ALGORITMO: INSERT SORT\n");
    printf("TAMANHO: %d numeros\n", size);
    printf("TEMPO: %f segundos\n\n", total_time);
}

void bubbleSort(int *vet, int size){
    clock_t start, end;
    int i, j;

    start = clock(); //Comeca a contar o tempo de execucao

    for (i = 0; i < size-1; i++){
        for (j = 0; j < (size-i-1); j++){ //percorre o vetor procurando o menor valor
            if (vet[j] > vet[j+1]){ //se encontrar um valor menor
                swap(&vet[j+1], &vet[j]); //troca os valores
            }
        }
    }

    end = clock(); // finaliza a contagem do tempo
    float total_time = ((double) (end - start)) / CLK_TCK; //realiza o calculo de temp

    printf("ALGORITMO: BUBBLE SORT\n");
    printf("TAMANHO: %d numeros\n", size);
    printf("TEMPO: %f segundos\n\n", total_time);
}
void quick(int *vet, int first, int last){
    int i, j, piv, aux;
    if (first < last){
        piv = first;
        i = first;
        j = last;

        while (i < j){
            while ((vet[i] <= vet[piv]) && (i < last))
                i++;
            while ((vet[j] > vet[piv]))
                j--;
            if (i < j){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
        aux = vet[piv];
        vet[piv] = vet[j];
        vet[j] = aux;
        quick(vet, first, j-1);
        quick(vet, j+1, last);
    }
}
void quickSort(int *vet, int size){
    clock_t start, end;
    start = clock(); //Comeca a contar o tempo de execucao

    quick(vet, 0, size);

    end = clock(); // finaliza a contagem do tempo
    float total_time = ((double) (end - start)) / CLK_TCK; //realiza o calculo de temp

    printf("ALGORITMO: QUICK SORT\n");
    printf("TAMANHO: %d numeros\n", size);
    printf("TEMPO: %f segundos\n\n", total_time);
}

 void merge(int *vet, int begin, int middle, int end){
    int i = begin, j = middle+1, k = 0, size = end-begin+1;
    int *aux = (int*)malloc(size* sizeof(int));

    while (i <= middle && j <= end){
        if (vet[i] < vet[j]){
            aux[k] = vet[i];
            i++;
        } else {
            aux[k] = vet[j];
            j++;
        }
        k++;
    }

    while (i <= middle){
        aux[k] = vet[i];
        k++;
        i++;
    }

    while (j <= end){
        aux[k] = vet[j];
        k++;
        j++;
    }

    for (k = begin; k <= end; k++){
        vet[k] = aux[k-begin];
    }

    free(aux);
}

void mergeAgain(int *vet, int i, int j){
    if (i < j){
        int middle = (i+j)/2;
        mergeAgain(vet, i, middle);
        mergeAgain(vet, middle+1, j);
        merge(vet, i, middle, j);
    }
}


int mergeSort(int *vet, int size){

    clock_t start, end;
    start = clock(); //Comeca a contar o tempo de execucao

    mergeAgain(vet, 0, size-1);


    end = clock(); // finaliza a contagem do tempo
    float total_time = ((double) (end - start)) / CLK_TCK; //realiza o calculo de temp

    printf("ALGORITMO: MERGE SORT\n");
    printf("TAMANHO: %d numeros\n", size);
    printf("TEMPO: %f segundos\n\n", total_time);

    return 0;
}

void buscaSequencial(int *vet, int size, int n){
    int i, j = 0;
    for (i = 0; i < size; i++){
        if (vet[i] == n)
            j++;
    }
    if ( j > 0)
        printf("\n%d FOI ENCONTRADO %d VEZES NO ARQUIVO COM %d VALORES\n", n, j, size);
    else
        printf("\n%d NAO ENCONTRADO NO ARQUIVO COM %d VALORES\n", n, size);
}

void buscaBinaria(int *vet, int size, int n){
    int r = binary(vet, 0, size-1, n);
    if (r != -1)
        printf("\n%d FOI ENCONTRADO COM INDEX %d NO ARQUIVO COM %d VALORES\n", n, r, size);
    else
        printf("\n%d NAO ENCONTRADO NO ARQUIVO COM %d VALORES\n", n, size);

}

int binary(int *vet, int l, int r, int num){
    if (r >= l){
        int mid = l + (r-l)/2;

        if (vet[mid] == num)
            return mid;

        if (vet[mid] > num)
            return binary(vet, l, mid-1, num);
        return binary(vet, mid+1, r, num);
    }
    return -1;
}
