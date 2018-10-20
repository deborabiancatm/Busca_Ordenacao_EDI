/*
Universidade Federal de Roraima – UFRR
Departamento de Ciência da Computação – DCC
DCC 302 – Estrutura de Dados I
Prof. Acuan Ribeiro
Trabalho de Busca e Ordenacao
Integrantes da Dupla:   Debora Bianca Taveira de Moura
                        Josemar Rocha

REFERENCIAS:
https://www.inf.pucrs.br/~pinho/LaproI/Arquivos/Arquivos.htm#Gravacao
https://stackoverflow.com/questions/8403447/swapping-pointers-in-c-char-int
https://www.geeksforgeeks.org/rand-and-srand-in-ccpp
https://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <unistd.h>

//GERAR ARQUIVOS DE DIFERENTES TAMANHOS COM NUMEROS ALEATORIOS

int criaCem(){ //Essa funcao cria o arquivo com 100 numeros aleatorios
    FILE *arq = fopen("100 Numeros Aleatorios.txt", "wt"); //Gera arquivo
    if (arq == NULL){ //Não conseguiu criar o arquivo
       printf("Problemas na criacao do arquivo com 100 numeros\n");
       return 0;
    } else {
        srand(time(0));
        int n, i;
        for(i = 0; i < 10; i++) {
            n = rand()%100; //Gera numero aleatorio
            fprintf(arq,"%d ", n); //Imprime numero aleatorio no arquivo
        }
         fclose(arq); //Fecha o arquivo
    }
    return 1;
}

int criaMil(){ //Essa funcao cria o arquivo com 1000 numeros aleatorios
    FILE *arq = fopen("1000 Numeros Aleatorios.txt", "wt"); //Gera arquivo
    if (arq == NULL){ //Não conseguiu criar o arquivo
       printf("Problemas na criacao do arquivo com 1000 numeros\n");
       return 0;
    } else {
        srand(time(0));
        int n, i;
        for(i = 0; i < 1000; i++) {
            n = rand()%100; //Gera numero aleatorio
            fprintf(arq,"%d ", n); //Imprime numero aleatorio no arquivo
        }
         fclose(arq); //Fecha o arquivo
    }
    return 1;
}

int criaDezmil(){ //Essa funcao cria o arquivo com 10000 numeros aleatorios
    FILE *arq = fopen("10000 Numeros Aleatorios.txt", "wt"); //Gera arquivo
    if (arq == NULL){ //Não conseguiu criar o arquivo
       printf("Problemas na criacao do arquivo com 10000 numeros\n");
       return 0;
    } else {
        srand(time(0));
        int n, i;
        for(i = 0; i < 10000; i++) {
            n = rand()%100; //Gera numero aleatorio
            fprintf(arq,"%d ", n); //Imprime numero aleatorio no arquivo
        }
         fclose(arq); //Fecha o arquivo
    }
    return 1;
}
int criaCemmil(){ //Essa funcao cria o arquivo com 10000 numeros aleatorios
    FILE *arq = fopen("100000 Numeros Aleatorios.txt", "wt"); //Gera arquivo
    if (arq == NULL){ //Não conseguiu criar o arquivo
       printf("Problemas na criacao do arquivo com 100000 numeros\n");
       return 0;
    } else {
        srand(time(0));
        int n, i;
        for(i = 0; i < 100000; i++) {
            n = rand()%100; //Gera numero aleatorio
            fprintf(arq,"%d ", n); //Imprime numero aleatorio no arquivo
        }
         fclose(arq); //Fecha o arquivo
    }
    return 1;
}

//FUNCOES BASICAS

int swap(int *menor, int *i){ //Funcao que troca enderecos
    int aux = *i;
    *i = *menor;
    *menor = aux;
    return 0;
}
void leArquivo (int* vet, int* vet1, int* vet2, int* vet3){
    int i = 0, num;
    FILE *arquivo;

    arquivo = fopen("100 Numeros Aleatorios.txt", "rt");
    while((fscanf(arquivo,"%d ",&num)) != EOF){
        vet[i]= num;
        i++;
    }
    fclose(arquivo);

    arquivo = fopen("1000 Numeros Aleatorios.txt", "rt");
    i = 0;
    while((fscanf(arquivo,"%d ",&num)) != EOF){
        vet1[i]= num;
        i++;
    }
    fclose(arquivo);

    arquivo = fopen("10000 Numeros Aleatorios.txt", "rt");
    i = 0;
    while((fscanf(arquivo,"%d ",&num)) != EOF){
        vet2[i]= num;
        i++;
    }
    fclose(arquivo);

    arquivo = fopen("100000 Numeros Aleatorios.txt", "rt");
    i = 0;
    while(!feof(arquivo)){
        vet3[i]= num;
        fscanf(arquivo,"%d ",&num);
        i++;
    }
    fclose(arquivo);

}

void escreveArquivo(int *vet, int size){
    FILE *arquivo;
    int i;
    if (size = 100){
        arquivo = fopen("100 numeros ordenados.txt", "wt"); //Gera arquivo
        if (arquivo == NULL){ //Não conseguiu criar o arquivo
           printf("Problemas na criacao do arquivo com 100 numeros ordenados\n");
           return 0;
        } else {
            for(i = 0; i < size; i++) {
                fprintf(arquivo,"%d ", vet[i]); //Imprime numero aleatorio no arquivo
            }
             fclose(arquivo); //Fecha o arquivo
        }
    } else if (size = 1000){
        arquivo = fopen("1000 numeros ordenados.txt", "wt"); //Gera arquivo
        if (arquivo == NULL){ //Não conseguiu criar o arquivo
           printf("Problemas na criacao do arquivo com 1000 numeros ordenados\n");
           return 0;
        } else {
            for(i = 0; i < size; i++) {
                fprintf(arquivo,"%d ", vet[i]); //Imprime numero aleatorio no arquivo
            }
             fclose(arquivo); //Fecha o arquivo
        }
    } else if (size = 10000){
        arquivo = fopen("10000 numeros ordenados.txt", "wt"); //Gera arquivo
        if (arquivo == NULL){ //Não conseguiu criar o arquivo
           printf("Problemas na criacao do arquivo com 10000 numeros ordenados\n");
           return 0;
        } else {
            for(i = 0; i < size; i++) {
                fprintf(arquivo,"%d ", vet[i]); //Imprime numero aleatorio no arquivo
            }
             fclose(arquivo); //Fecha o arquivo
        }
    } else if (size = 100000){
        arquivo = fopen("100000 numeros ordenados.txt", "wt"); //Gera arquivo
        if (arquivo == NULL){ //Não conseguiu criar o arquivo
           printf("Problemas na criacao do arquivo com 100000 numeros ordenados\n");
           return 0;
        } else {
            for(i = 0; i < size; i++) {
                fprintf(arquivo,"%d ", vet[i]); //Imprime numero aleatorio no arquivo
            }
             fclose(arquivo); //Fecha o arquivo
        }
    }
}

//FUNCOES DE ORDENACAO
int selectionSort(int *vet, int size){
    //ORDENA SELECTION SORT
    int i, j, min, aux, time = 0;
    for (i = 0; i < size-1; i++){
        min = i;
        for (j = i+1; j < size; j++){
            if (vet[j] < vet[i]){
                min = j;
            }
        }
        if (min != i){
            aux = vet[i];
            vet[i] = vet[min];
            vet[min] = aux;
        }
        printf("pos %d: %d", i, vet[i]);
    }

  //  t = clock() - t;
  //  time0 = ((double)t)/CLOCKS_PER_SEC;
    //Salva em um arquivo os numeros ordenados
    escreveArquivo(vet, size);
    printf("ALGORITMO: SELECTION SORT\n");
    printf("TAMANHO: %d numeros\n", size);
    printf("TEMPO: %fs", time);

    return 1;
}

//FUNCOES DE BUSCA

int main()
{
    int op;
    //Gera o cabecalho do programa
    printf("===========PROJETO DE ORDENACAO E BUSCA==============\n");
    printf("Por Debora Bianca e Josemar Rocha\n\n");
    printf("[1]GERAR ARQUIVOS\n[2]ORDENAR ARQUIVOS\n[3]Sair\n\n");
    printf("Opcao: ");
    scanf("%d", &op);
    //Seleciona a opcao do menu
    switch (op){
        case 1:
            printf("\n\n=================GERAR ARQUIVOS======================\n\n");
            if (criaCem() && criaDezmil() && criaMil() && criaCemmil()){
                printf("Todos os arquivos foram gerados com sucesso\n\n");
            }
            break;
        case 2:
            printf("\n\n================ORDENA ARQUIVOS=====================\n\n");
            int v0[100], v1[1000], v2[10000], v3[100000], i = 0, j, time;
            leArquivo(v0, v1, v2, v3);
            selectionSort(v0, 100);
            break;
        case 3:
            exit(0);
            break;
    }
    return 0;
}
