#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <unistd.h>

int criaCem(){ //Essa funcao cria o arquivo com 100 numeros aleatorios
    FILE *arq = fopen("100 Numeros Aleatorios.txt", "wt"); //Gera arquivo
    if (arq == NULL){ //Não conseguiu criar o arquivo
       printf("Problemas na criacao do arquivo com 100 numeros\n");
       return 0;
    } else {
        srand(time(0));
        int n, i;
        for(i = 0; i < 100; i++) {
            n = rand()%1000; //Gera numero aleatorio
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
            n = rand()%1000; //Gera numero aleatorio
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
            n = rand()%1000; //Gera numero aleatorio
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
            n = rand()%1000; //Gera numero aleatorio
            fprintf(arq,"%d ", n); //Imprime numero aleatorio no arquivo
        }
         fclose(arq); //Fecha o arquivo
    }
    return 1;
}

//FUNCOES BASICAS

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

void arq100(int *vet){
    int i;
    FILE *arquivo = fopen("100 Numeros Ordenados.txt", "wt"); //Gera arquivo
    for(i = 0; i < 100; i++) {
        fprintf(arquivo,"%d ", vet[i]); //Imprime numero aleatorio no arquivo
    }
     fclose(arquivo); //Fecha o arquivo
}

void arq1000(int *vet){
    int i;
    FILE *arquivo = fopen("1000 Numeros Ordenados.txt", "wt"); //Gera arquivo
    for(i = 0; i < 1000; i++) {
        fprintf(arquivo,"%d ", vet[i]); //Imprime numero aleatorio no arquivo
    }
     fclose(arquivo); //Fecha o arquivo
}

void arq10000(int *vet){
    int i;
    FILE *arquivo = fopen("10000 Numeros Ordenados.txt", "wt"); //Gera arquivo
    for(i = 0; i < 10000; i++) {
        fprintf(arquivo,"%d ", vet[i]); //Imprime numero aleatorio no arquivo
    }
     fclose(arquivo); //Fecha o arquivo
}

void arq100000(int *vet){
    int i;
    FILE *arquivo = fopen("100000 Numeros Ordenados.txt", "wt"); //Gera arquivo
    for(i = 0; i < 100000; i++) {
        fprintf(arquivo,"%d ", vet[i]); //Imprime numero aleatorio no arquivo
    }
     fclose(arquivo); //Fecha o arquivo
}
