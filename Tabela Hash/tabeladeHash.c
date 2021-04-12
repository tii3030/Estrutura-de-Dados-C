// ESTE ALGORITMO IMPLEMENTA UMA ESTRURA DE ARMAZENAMENTO BASEADO EM HASH (TABELA HASH)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tabeladeHash.h"

/////
struct hash{

    int qtd, TABLE_SIZE;
    struct conc **itens;
};

/////
Hash *criarHash(int TABLE_SIZE){

    Hash *ha = (Hash*) malloc (TABLE_SIZE* sizeof(struct conc*));
    if(ha != NULL) {

        int i;
        ha->TABLE_SIZE = TABLE_SIZE;

        // ACESSO DUPLO POR ITENS**
        ha->itens = (struct conc**) malloc (TABLE_SIZE* sizeof(struct conc));

        if(ha->itens == NULL) {
            free(ha);
            return NULL;
        }

        ha->qtd = 0;
        for(i = 0; i < ha->TABLE_SIZE; i++) {

            ha->itens[i] = NULL;

        }
    }

    return ha;

}

/////
void liberaHash(Hash* ha) {

    if(ha != NULL) {

        int i;
        for(i = 0; i < ha->TABLE_SIZE; i++) {

            if(ha->itens[i] != NULL) {
                free(ha->itens[i]);
            }
        }
        free(ha->itens);
        free(ha);
    }

}


/////
int valorString(char *str) {

    int i, valor = 7;
    int tam = strlen(str);

    for(i = 0; i < tam; i++) {
        valor = 31 * valor + (int) str[i];
    }

    //printf("\nValor puro: %d", valor);
    //printf("\Valor corrigido: %d", valor & 0x7FFFFFFF);

    return (valor & 0x7FFFFFFF);
}

/////
int chaveDivisao(int chave, int TABLE_SIZE) {

    //printf("\nChave de divisao %d\n", chave & 0x7FFFFFFF);
    return (chave & 0x7FFFFFFF) % TABLE_SIZE;

}


// Hash Multiplicação
// int chave = valorString(nome);
// pos = chaveDobra(chave, TABLE_SIZE);
int chaveMultiplicacao(int chave, int TABLE_SIZE) {

    double A = 0.6180339887; //CONSTANTE
    double val = chave * A;
    val = val - (int) val;

    return (int) (TABLE_SIZE * val);
}




// Hash chave dobra
//int chave = valorString(nome)
int chaveDobra(int chave, int TABLE_SIZE) {

    int num_bits = 10;
    int parte1 = chave >> num_bits;
    int parte2 = chave & (TABLE_SIZE -1);
    return (parte1 ^ parte2);


}

/////
int sondagemLinear(int pos, int i, int TABLE_SIZE) {

    printf("\nPOS: %i i: %i\n", pos, i);
    return ((pos + i) & 0x7FFFFFFF) % TABLE_SIZE;

}



/////
int sondagemQuadratica(int pos, int i, int TABLE_SIZE) {

    pos = pos +2*i + 5*i*i;
    return (pos & 0x7FFFFFFF) % TABLE_SIZE;
}


/////
int duploHash(int H1, int chave, int i, int TABLE_SIZE) {

    int H2 = chaveDivisao(chave, TABLE_SIZE-1) + 1;
    return ((H1 + i*H2) & 0x7FFFFFFF) % TABLE_SIZE;

}



///// INSERE SEM TRATAMENTO DE COLISÃO
int insereHash_SemColisao(Hash* ha, struct conc al) {

    if(ha == NULL || ha->qtd == ha->TABLE_SIZE) {

        return 0;
    }

    int chave = valorString(al.desc);
    int pos = chaveDivisao(chave, ha->TABLE_SIZE);

    //int pos = chaveMultiplicacao(chave, ha->TABLE_SIZE);
    //int pos = chaveDobra(chave, ha->TABLE_SIZE);


    printf("\nPosicao inserida %d\n", pos);
    struct conc *novo;

    novo = (struct conc*) malloc(sizeof(struct conc));

    if(novo == NULL) {
        return 0;
    }

    *novo = al;
    ha->itens[pos] = novo;
    ha->qtd++;

    return 1;

}

int buscaHash_SemColisao(Hash* ha, char v[], struct conc* al) {

    if(ha == NULL) {
        return 0;
    }


    int chave = valorString(v);
    int pos = chaveDivisao(chave, ha->TABLE_SIZE);
    //int pos = chaveDobra(v, ha->TABLE_SIZE);


    if(ha->itens[pos] == NULL) {
        return 0;
    }

    *al = *(ha->itens[pos]);

    return 1;

}

