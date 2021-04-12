// ESTE CÓDIGO IMPLEMENTA UMA LISTA COM ENCADEAMENTO SIMPLES

#include <stdio.h>
#include <stdlib.h>

    typedef struct produto {

        int cod;
        char nome[10];
        float valor;
        int qtde;
        struct produto *prox;

    }prod; // DEFINE STRUCT

    prod *ptr = NULL;
    prod *head = NULL;

    //METODO VERIFICA SE A LISTA ESTA VAZIA
    int listEmpty() {

        if(head == NULL){
            return 1;
        }
        else {
            return 0;
        }
    }

    //METODO INSERE NO INICIO
    void insert() {

        if(head == NULL) {

            head = (prod *)malloc(sizeof(prod));
            ptr = head;

            printf("---------PRODUTO---------\n");
            printf("\n");
            printf("Insira o codigo do produto: ");
            scanf("%d", &ptr->cod);
            printf("Insira o nome do produto: ");
            scanf("%s", &ptr->nome);
            printf("Insira o valor do produto: ");
            scanf("%f", &ptr->valor);
            printf("Insira a quantidade em estoque: ");
            scanf("%d", &ptr->qtde);
            printf("\n");
            printf("_____________________________________________________________________________");
            printf("\n");

            ptr->prox = NULL;

        }
        else {

            ptr->prox = (prod *) malloc(sizeof(prod));
            ptr = ptr->prox;

            printf("---------PRODUTO---------\n");
            printf("\n");
            printf("Insira o codigo do produto: ");
            scanf("%d", &ptr->cod);
            printf("Insira o nome do produto: ");
            scanf("%s", &ptr->nome);
            printf("Insira o valor do produto: ");
            scanf("%f", &ptr->valor);
            printf("Insira a quantidade em estoque: ");
            scanf("%d", &ptr->qtde);
            printf("\n");
            printf("_____________________________________________________________________________");
            printf("\n");

            ptr->prox = NULL;

        }
    }

    //METODO CONSULTA POR CODIGO
    void consulCod(void) {

       if(listEmpty()) {

            printf("O estoque esta vazio !!");
            printf("\n");
            printf("_____________________________________________________________________________");
            printf("\n");

       }
       else {

            prod *ptrS;
            int a = 0;
            int resp;

            printf("Digite o codigo do produto: ");
            scanf("%d", &resp);

            ptrS = (prod *)head;

            while(ptrS != NULL) {


                if(resp == ptrS->cod) {
                    printf("---------PRODUTO---------\n");
                    printf("Codigo: %d\n", ptrS->cod);
                    printf("Nome: %s\n", ptrS->nome);
                    printf("Valor: %2.lf\n", ptrS->valor);
                    printf("Quantidade em estoque: %d\n", ptrS->qtde);
                    printf("\n");
                    printf("_____________________________________________________________________________");
                    printf("\n");
                    a = 1;

                }
                ptrS = (prod *)ptrS->prox;
            }

            if(a == 0) {

                printf("Codigo do produto nao encontrado !!");
                printf("\n");
                printf("_____________________________________________________________________________");
                printf("\n");
            }
        }
    }

    // METODO BUSCA PELO PRODUTO MAIS BARATO
    void searchB() {

        if(listEmpty()) {

            printf("O estoque esta vazio !!\n");
            printf("\n");
            printf("_____________________________________________________________________________");
            printf("\n");
        }
        else {

            prod *aux = NULL;
            prod *ptrB;
            ptrB = (prod *)head;

            int min = ptrB->valor;

            while(ptrB != NULL) {

                if(ptrB->valor <= min && ptrB->valor != 0) {

                    min = ptrB->valor;
                    aux = ptrB;

                }
                ptrB = ptrB->prox;
            }

            printf("---------PRODUTO---------\n");
            printf("\n");
            printf("Codigo: %d\n", aux->cod);
            printf("Nome: %s\n", aux->nome);
            printf("Valor: %2.lf\n", aux->valor);
            printf("Quantidade em estoque: %d\n", aux->qtde);
            printf("\n");
            printf("_____________________________________________________________________________");
            printf("\n");
        }
    }

    // METODO BUSCA PELO MAIS CARO
    void searchC() {

        if(listEmpty()) {

            printf("O estoque esta vazio !!");
            printf("\n");
            printf("_____________________________________________________________________________");
            printf("\n");
        }
        else {

            prod *aux = NULL;
            prod *ptrC;
            ptrC = (prod *)head;

            int max = 0;

            while(ptrC != NULL) {

                if(ptrC->valor > max && ptrC->valor != 0) {

                    max = ptrC->valor;
                    aux = ptrC;

                }
                ptrC = ptrC->prox;
            }

            printf("---------PRODUTO---------\n");
            printf("\n");
            printf("Codigo: %d\n", aux->cod);
            printf("Nome: %s\n", aux->nome);
            printf("Valor: %2.lf\n", aux->valor);
            printf("Quantidade em estoque: %d\n", aux->qtde);
            printf("\n");
            printf("_____________________________________________________________________________");
            printf("\n");
        }
    }

    //METODO PARA EXCLUIR POR CODIGO
    void excluir() {

        if(listEmpty()) {

            printf("O estoque esta vazio !!");
            printf("\n");
            printf("_____________________________________________________________________________");
            printf("\n");
        }
        else {

            int resp = 0;
            int c = 0;
            prod *ptrE = NULL; // PONTEIRO AUX
            ptrE = head;

            printf("Digite o codigo do produto que deseja excluir: ");
            scanf("%d", &resp);
            printf("\n");
            printf("_____________________________________________________________________________");
            printf("\n");

            if(resp == ptrE->cod) { // SE RESP = COD NA PRIMEIRA LISTA

                head = ptrE->prox; // PRIMEIRA LISTA = LISTA DENTRO DE PROX, OU SEJA PROXIMA LISTA
                printf("Produto excluido !!\n");
                printf("\n");
                printf("_____________________________________________________________________________");
                printf("\n");
                c = 1; // EXPRESSÃO DE CONTROLE
            }
            else {

               while(ptrE != NULL) {

                if(resp == ptrE->prox->cod) { // SENÃO: RESP = CODIGO NA PROXIMA LISTA

                    ptrE->prox = ptrE->prox->prox; // PROXIMA LISTA = PROXIMA LISTA DA PROXIMA :)
                    printf("Produto excluido !!\n");
                    printf("\n");
                    printf("_____________________________________________________________________________");
                    printf("\n");
                    c = 1;
                }

                ptrE = ptrE->prox;
            }

            }

            if(c != 1) {
                printf("Codigo nao encontrado !!\n");
            }
        }
    }


int main() {

    int opcao;

        do {

            printf("\n Opcoes: ");
            printf("\n");
            printf("\n 1. Inserir dados.");
            printf("\n 2. Consultar por codigo.");
            printf("\n 3. Procurar pelo mais barato.");
            printf("\n 4. Procurar pelo mais Caro.");
            printf("\n 5. Remover por codigo.");
            printf("\n 6. sair.\n");

            printf("\n Digite a opcao desejada: ");
            scanf("%d",&opcao);
            printf("\n");
            printf("_____________________________________________________________________________");
            printf("\n");

            switch(opcao) {

                case 1:
                    insert();
                    break;

                case 2:
                    listEmpty();
                    consulCod();
                    break;

                case 3:
                    listEmpty();
                    searchB();
                    break;

                case 4:
                    listEmpty();
                    searchC();
                    break;

                case 5:
                    listEmpty();
                    excluir();
                    break;

                case 6:
                    printf("Fechando...\n");
                    printf("Pressione enter.\n");
                    break;

                default:
                    printf("\n Opcao nao existe.");
                    break;
            }

        } while(opcao != 6);
        getch();

    return 0;
}
