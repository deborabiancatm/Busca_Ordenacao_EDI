/*
Universidade Federal de Roraima � UFRR
Departamento de Ci�ncia da Computa��o � DCC
DCC 302 � Estrutura de Dados I
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
#include "files.c"
#include "ordenacao.c"

int main()
{
    int op;
    //Gera o cabecalho do programa
    printf("===========PROJETO DE ORDENACAO E BUSCA==============\n");
    printf("[1]GERAR ARQUIVOS\n[2]SELECIONAR ORDENACAO DE ARQUIVOS\n[3]SELECIONAR BUSCA\n[4]SAIR\n\n");
    printf("Opcao: ");
    scanf("%d", &op);
    //Seleciona a opcao do menu
    int v0[100], v1[1000], v2[10000], v3[100000]; //cria todos os vetores necessarios

    switch (op){
        case 1:
            system ("CLS");
            printf("=================GERAR ARQUIVOS======================\n\n");
            if (criaCem() && criaDezmil() && criaMil() && criaCemmil()){
                printf("Todos os arquivos foram gerados com sucesso\n\n");
            }
            break;
        case 2:
            system ("CLS");
            printf("================ORDENA ARQUIVOS=====================\n\n");
            printf("[1]SELECTION SORT\n");
            printf("[2]INSERTION SORT\n");
            printf("[3]BUBBLE SORT\n");
            printf("[4]RADIX SORT\n");
            printf("[5]QUICK SORT\n");
            printf("[6]MERGE SORT\n\n");
            printf("Escolha o tipo de ordenacao: ");
            int tipo;
            scanf("%d", &tipo);

            leArquivo(v0, v1, v2, v3); //passa os valores dos arquivos pros vetores
            system("CLS");
            switch (tipo){
                case 1:
                    printf("================SELECTION SORT===================\n\n");
                    selectionSort(v0, 100);
                    arq100(v0);

                    selectionSort(v1, 1000);
                    arq1000(v1);

                    selectionSort(v2, 10000);
                    arq10000(v2);

                    selectionSort(v3, 100000);
                    arq100000(v3);
                    break;
                case 2:
                    printf("================INSERTION SORT===================\n\n");
                    insertSort(v0, 100);
                    arq100(v0);

                    insertSort(v1, 1000);
                    arq1000(v1);

                    insertSort(v2, 10000);
                    arq10000(v2);

                    insertSort(v3, 100000);
                    arq100000(v3);
                    break;
                case 3:
                    printf("================BUBBLE SORT===================\n\n");
                    bubbleSort(v0, 100);
                    arq100(v0);

                    bubbleSort(v1, 1000);
                    arq1000(v1);

                    bubbleSort(v2, 10000);
                    arq10000(v2);

                    bubbleSort(v3, 100000);
                    arq100000(v3);
                    break;
                case 4:
                    printf("================RADIX SORT===================\n\n");

                    break;
                case 5:
                    printf("================QUICK SORT===================\n\n");
                    quickSort(v0, 100);
                    arq100(v0);

                    quickSort(v1, 1000);
                    arq1000(v1);

                    quickSort(v2, 10000);
                    arq10000(v2);

                    quickSort(v3, 100000);
                    arq100000(v3);
                    break;
                case 6:
                    printf("================MERGE SORT===================\n\n");
                    mergeSort(v0, 100);
                    arq100(v0);

                    mergeSort(v1, 1000);
                    arq1000(v1);

                    mergeSort(v2, 10000);
                    arq10000(v2);

                    mergeSort(v3, 100000);
                    arq100000(v3);
                    break;
                default:
                    printf("Opcao nao disponivel");
            }
            break;
        case 3:
            system("CLS");
            printf("================SELECIONAR BUSCA=====================\n\n");
            printf("[1]BUSCA SEQUENCIAL\n[2]BUSCA BINARIA\n\nOBS.: Para realizar a busca binaria voce necessariamente precisa executar uma ordenacao.\n");
            printf("Escolha o tipo de busca: ");
            int a;
            scanf("%d", &a);

            switch(a){
                case 1:
                    leArquivo(v0, v1, v2, v3); //passa os valores dos arquivos pros vetores
                    system("CLS");
                    printf("================BUSCA SEQUENCIAL=====================\n\n");
                    printf("Digite o valor de 0-999 que deseja buscar: ");
                    int n;
                    scanf("%d", &n);
                    buscaSequencial(v0, 100, n);
                    buscaSequencial(v1, 1000, n);
                    buscaSequencial(v2, 10000, n);
                    buscaSequencial(v3, 100000, n);
                    break;
                case 2:
                    system("CLS");
                    arquivoRand(v0, v1, v2, v3);
                    printf("================BUSCA BINARIA=====================\n\n");
                    printf("Digite o valor de 0-999 que deseja buscar: ");
                    int m;
                    scanf("%d", &m);
                    buscaBinaria(v0, 100, m);
                    buscaBinaria(v1, 1000, m);
                    buscaBinaria(v2, 10000, m);
                    buscaBinaria(v3, 100000, m);
                    break;
                    default:
                        printf("Opcao nao disponivel");
                }
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Opcao nao disponivel");
    }
    printf("\n\nFeito por: Debora Bianca e Josemar Rocha\n");

    return 0;
}
