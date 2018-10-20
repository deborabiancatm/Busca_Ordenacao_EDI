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
            printf("[5]MERGE SORT\n\n");
            printf("Escolha o tipo de ordenacao: ");
            int tipo;
            scanf("%d", &tipo);

            int v0[100], v1[1000], v2[10000], v3[100000]; //cria todos os vetores necessarios
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
                    break;
                case 3:
                    printf("================BUBBLE SORT===================\n\n");
                    break;
                case 4:
                    printf("================RADIX SORT===================\n\n");

                    break;
                case 5:
                    printf("================MERGE SORT===================\n\n");
                    break;
                default:
                    printf("Opcao nao disponivel");
            }

            break;
        case 3:
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
