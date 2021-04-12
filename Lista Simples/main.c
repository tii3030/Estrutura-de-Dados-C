#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

    //FUNÇÃO PRINCIPAL
    int main(void) {

        init();
        listFull();

        int opcao;

        do {


            printf("\n Opcoes: ");
            printf("\n");
            printf("\n 1. Inserir dados no fim Lista.");
            printf("\n 2. Inserir dados no inicio da lista.");
            printf("\n 3. Inserir dados em qualquer posicao da lista.");
            printf("\n 4. Imprimir primeira lista.");
            printf("\n 5. Imprimir ultima Lista.");
            printf("\n 6. Busca e imprime por matricula.");
            printf("\n 7. Busca e imprime por posicao.");

            printf("\n 8. Exibir tamanho da lista.");
            printf("\n 9. Remover a ultima lista.");
            printf("\n 10. Remover a primeira lista.");
            printf("\n 11. Remover lista em qualquer posicao.");
            printf("\n 12. sair.\n");

            printf("\n Digite a opcao desejada: ");
            scanf("%d",&opcao);
            printf("\n");
            printf("_____________________________________________________________________________");
            printf("\n");

            switch(opcao) {

                case 1:
                    insertLast();
                    break;

                case 2:
                    insertFirst();
                    break;

                case 3:
                    insertPosition();
                    break;

                case 4:
                    printFirst();
                    break;

                case 5:
                    printLast();
                    break;

                case 6:
                    printValue();
                    break;
                case 7:
                    printPosition();
                    break;

                case 8:
                    listSize();
                    break;

                case 9:
                    rmLast();
                    break;

                case 10:
                    rmFirst();
                    break;

                case 11:
                    rmPosition();
                    break;

                case 12:
                    printf("Fechando...\n");
                    printf("Pressione enter.\n");
                    break;

                default:
                    printf("\n Opcao nao existe.");
                    break;
            }



        } while(opcao != 12);
        getch();

        return 0;



    }
