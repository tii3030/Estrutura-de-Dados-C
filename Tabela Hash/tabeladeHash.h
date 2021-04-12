struct conc {

    int cod;
    char desc[30];
};

typedef struct hash Hash;

Hash* criaHash(int TABLE_SIZE);
void liberaHash(Hash* ha);
int valorString(char *str);
int insereHash_SemColisao(Hash* ha, struct conc al);
int buscaHash_SemColisao(Hash* ha, char v[], struct aluno* al);
int chaveMultiplicacao(int chave, int TABLE_SIZE);

int chaveDobra(int chave, int TABLE_SIZE);
