#include <stdio.h>
#include <stdlib.h>
#include "tabeladeHash.h"

int main()
{

    char v1[40] = "concreto_bombeavel";
    char v2[40] = "concreto_convencional";
    char v3[40] = "concreto_magro";
    char v4[40] = "concreto_fluido";
    char v5[40] = "concreto_impermeavel";

    int tamanho = 1024;
    Hash *tabela = criarHash(tamanho);

    struct conc al, a[5] = {{118922, "concreto_bombeavel"},
                              {227790, "concreto_convencional"},
                              {212341, "concreto_magro"},
                              {332754, "concreto_fluido"},
                              {227790, "concreto_impermeavel"}};

    int i;
    for(i = 0; i < 5; i++) {

        insereHash_SemColisao(tabela, a[i]);

    }


    printf("----------\n\n");


    buscaHash_SemColisao(tabela, v1, &al);
    printf("%s, %d\n", al.desc, al.cod);

    buscaHash_SemColisao(tabela, v2, &al);
    printf("%s, %d\n", al.desc, al.cod);

    buscaHash_SemColisao(tabela, v3, &al);
    printf("%s, %d\n", al.desc, al.cod);

    buscaHash_SemColisao(tabela, v4, &al);
    printf("%s, %d\n", al.desc, al.cod);




    liberaHash(tabela);
    return 0;
}
