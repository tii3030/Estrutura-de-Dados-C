// ESTE ALGORITIMO IMPLEMENTA UMA PILHA NA LINGUAGEM DE PROGRAMAÇÃO C

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define LIMPA_TELA system("cls")


#define LIMPA_TELA system("cls")
#define MAX_TAM 15

    //RETORNO DO POP
    int resPop;
    int head = 0;

    typedef struct {

        int valor[MAX_TAM];
        int topo;

    }Tpilha;
    typedef Tpilha *pPilha;


    typedef struct {

        int valor[MAX_TAM];
        int topo;

    }Tpilha2;
    typedef Tpilha2 *pPilha2;

    // METODO QUE CRIA PILHA VAZIA
    pPilha criarPilha() {

        pPilha p = (pPilha *)malloc(sizeof(Tpilha));
        p->topo = -1;

        return p;
    }

    // METODO QUE CRIA a 2º PILHA VAZIA
    pPilha2 criarPilha2() {

        pPilha2 p2 = (pPilha2 *)malloc(sizeof(Tpilha2));
        p2->topo = -1;

        return p2;
    }

    // METODO PUSH (INSERE)
    int push(pPilha p, int val) {

        if(p == NULL) {

            return -1;
        }
        if(p -> topo >= MAX_TAM - 1) {

            return -1;
        }
        p->topo++;
        p->valor[p->topo] = val;

    return 1;
    }

    // METODO POP (REMOVE)
    int pop(pPilha p) {

        if(p == NULL) {

            return -1;
        }
        if(p->topo >= MAX_TAM -1) {

            return -1;
        }

        resPop = p->valor[p->topo];
        p->topo--;

        return 1;
    }

    // METODO PARA DROPAR PILHA
    void drop(pPilha p) {

        while(p->topo >= 0) {
            pop(p);
        }
        free(p);
    }

    // METODO PEEK
    int peek(pPilha p) {

        return p->valor[p->topo];
    }

    // METODO PRINT ALL ELEMENT OF LIST
    void printAll(pPilha p) {

        int i;

        if(p == NULL) {

            printf("A PILHA ESTA VAZIA !!\n");
            return;
        }

        printf("QUANTIDADE DE ELEMENTOS NA PILHA: %d\n", p->topo+1);

        for(i = p->topo; i >= 0; i--) {

            printf("PILHA[%d] = %d\n", i, p->valor[i]);

        }
    }

    //SE O ELEMENTO FOR PARA INSERIR NA PILHA X 2.
    pPilha2 novaPilhaInvertida(pPilha2 p2, int val) {



        if(p2 == NULL) {

            return -1;
        }

        if(p2 -> topo >= MAX_TAM - 1) {

            return -1;
        }

        if(val % 2 == 0) {
            p2->topo++;
            p2->valor[head] = (val * 2);

        }
        else {
            p2->topo++;
            p2->valor[head] = (val * 3);
        }


    return p2;
    }



int resPop;

int main()
{
    int val, op;
    pPilha *pilha;
    pPilha2 *pilha2;
    pPilha2 *newP;

    do {

        printf("\n 1.INICIAR A PILHA.");
        printf("\n 2.INSERIR ELEMENTO NA PILHA.");
        printf("\n 7.SAIR.");

        printf("\n DIGITE UMA OPCAO: ");
        scanf("%d", &op);

        switch(op){

            case 1:
                pilha = criarPilha();
                pilha2 = criarPilha2();
                break;

            case 2:
                printf("\n DIGITE UM VALOR (INTEIRO): ");
                scanf("%d", &val);
                push(pilha, val);
                newP = novaPilhaInvertida(pilha2, val);
                printAll(pilha2);
                break;

            case 3:
                printf("Saindo...");
                break;

            default:
                printf("\nOPCAO INVALIDA !!\n");
                break;
        }

        getch();
        LIMPA_TELA;


    }while(op != 3);

    //EXCLUINDO A NOVA PILHA
    drop(pilha2);

    return 0;
}
