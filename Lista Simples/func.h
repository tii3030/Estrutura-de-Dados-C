// ESTE ALGORITMO IMPLEMENTA UM LISTA SIMPLES

#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

//ESTRUTURA
    struct estudante {

            int nMatricula;
            char nome[100];
            float nMensalidade;
            char dataBacharelado[100];
        };

        struct estudante stud[100], *ptr_studn; //DEFINI플O DE TIPOS DE ESTRUTURA E PONTEIRO

        //VARIAVEIS DE CONTROLE
        int back = -1;
        int after = 0;
        int tam = 100;
        int i;

        int listFull() {

            if(back == (tam - 1)) {
                return 1;
            }
            else {
                return 0;
            }
        }


        //FUN플O VERIFICA LISTA VAZIA
        int listEmpty() {

            if(back == -1) {
                return 1;
            }
            else {
                return 0;
            }
        }

        //FUN플O VERIFICA TAMANHO DA LISTA
        int listSize() {

            printf("\nLISTA DE TAMANHO: %d", back + 1);
            printf("\n");
            printf("_____________________________________________________________________________");
            printf("\n");
            return back + 1;
        }

        //PROCEDIMENTO QUE INICIA A LISTA
        void init() {

            ptr_studn = &stud[0];

            ptr_studn->nMatricula = 0;
            strcpy(ptr_studn->nome, "\0");
            ptr_studn->nMensalidade = 0;
            strcpy(ptr_studn->dataBacharelado, "\0");

        }

        //PROCEDIMENTO INSERE NO FIM
        void insertLast() {

            if(listFull()) {

                printf("Lista cheia !!");
            }

            else {
                back++;
                ptr_studn = &stud[back];

                printf("\n Entre com a matricula: ");
                scanf("%d", &ptr_studn->nMatricula);
                printf("\n Entre com o nome: ");
                scanf("%s", &ptr_studn->nome);
                printf("\n Entre com a mensalidade: ");
                scanf("%f", &ptr_studn->nMensalidade);
                printf("\n Entre com a data do bacharelado: ");
                scanf("%s", &ptr_studn->dataBacharelado);
                printf("\n");
                printf("_____________________________________________________________________________");
                printf("\n");
            }
        }

        //METODO INSERE NO INICIO
        void insertFirst() {

            if(listFull()) {

                printf("Lista cheia !!");
            }
            else if(listEmpty) {
                insertLast();
            }
            else {

                for(i = back; i > after; i--) {

                    stud[i] = stud[i - 1];
                }

                printf("Insira o valor no inicio. \n");
                printf("\n");
                ptr_studn = &stud[i];

                printf("\n Entre com a matricula: ");
                scanf("%d", &ptr_studn->nMatricula);
                printf("\n Entre com o nome: ");
                scanf("%s", &ptr_studn->nome);
                printf("\n Entre com a mensalidade: ");
                scanf("%f", &ptr_studn->nMensalidade);
                printf("\n Entre com a data do bacharelado: ");
                scanf("%s", &ptr_studn->dataBacharelado);
                printf("\n");
                printf("_____________________________________________________________________________");
                printf("\n");

                back++;
            }
        }

        //METODO INSERE NA POSICAO
        void insertPosition() {

            if(listFull()) {

                printf("\nA LISTA ESTA CHEIA !!\n");
                printf("\n");
                printf("_____________________________________________________________________________");
                printf("\n");
            }
            else if(listEmpty) {

                printf("\nA LISTA ESTA VAZIA !!");
                printf("\n");
                printf("_____________________________________________________________________________");
                printf("\n");
            }

            else {
                int inPosicao;
                printf("\nDigite a posicao que deseja inserir: \n");
                scanf("%d", &inPosicao);

                if(inPosicao >= after && inPosicao <= back) {
                    for(i = back+1; i > inPosicao; i--) {
                        stud[i] = stud[i-1];
                    }

                    printf("INSIRA OS VALORE.\n");
                    printf("\n");
                    ptr_studn = &stud[inPosicao];

                    printf("\n Entre com a matricula: ");
                    scanf("%d", &ptr_studn->nMatricula);
                    printf("\n Entre com o nome: ");
                    scanf("%s", &ptr_studn->nome);
                    printf("\n Entre com a mensalidade: ");
                    scanf("%f", &ptr_studn->nMensalidade);
                    printf("\n Entre com a data do bacharelado: ");
                    scanf("%s", &ptr_studn->dataBacharelado);
                    back++;

                    printf("LISTA INSERIDA NA POSICAO %d COM SUCESSO!!\n", inPosicao);
                    printf("\n");
                    printf("_____________________________________________________________________________");
                    printf("\n");

                }
                else {
                    printf("POSICAO NAO EXISTE !!\n");
                }
            }
        }

        //METODO MOOSTRA A PRIMEIRA POSICAO
        void printFirst() {

            if(listEmpty()) {
                printf("\nA LISTA ESTA VAZIA !\n");
                printf("_____________________________________________________________________________");
                printf("\n");
            }
            else {
                ptr_studn = &stud[after];

                printf("\n**********CADASTRO DO ESTUDANTE***********");
                printf("\n");

                printf("\n No. Matricula = %d", ptr_studn->nMatricula);
                printf("\n Nome = %s", ptr_studn->nome);
                printf("\n Valor da mensalidade = %9.2f", ptr_studn->nMensalidade);
                printf("\n Data do bacharelado = %s", ptr_studn->dataBacharelado);
                printf("\n");
                printf("_____________________________________________________________________________");
                printf("\n");
            }


        }

        //METODO MOSTRA A ULTIMA LISTA
        void printLast() {

            if(listEmpty()) {

                printf("\nA LISTA ESTA VAZIA !\n");
                printf("_____________________________________________________________________________");
                printf("\n");
            }
            else {
                ptr_studn = &stud[back];

                printf("\n**********CADASTRO DO ESTUDANTE***********");
                printf("\n");

                printf("\n No. Matricula = %d", ptr_studn->nMatricula);
                printf("\n Nome = %s", ptr_studn->nome);
                printf("\n Valor da mensalidade = %9.2f", ptr_studn->nMensalidade);
                printf("\n Data do bacharelado = %s", ptr_studn->dataBacharelado);
                printf("\n");
                printf("_____________________________________________________________________________");
                printf("\n");
            }
        }



        //METODO IMPRIME E BUSCA POR MATRICULA
        void printValue() {

            int aux = 0;
            int j;
            if(listEmpty()) {
                printf("\nA LISTA ESTA VAZIA !\n");
                printf("_____________________________________________________________________________");
                printf("\n");
            }
            else {

                int matricula;
                printf("Digite a matricula do aluno: ");
                scanf("%d", &matricula);


                for(i = after; i <= back; i++) {
                    if(stud[i].nMatricula == matricula) {
                        aux = 1;
                        j = i;
                    }
                }


                    if(aux == 1) {

                        ptr_studn = &stud[j];

                        printf("\n**********CADASTRO DO ESTUDANTE***********");
                        printf("\n");

                        printf("\n No. Matricula = %d", ptr_studn->nMatricula);
                        printf("\n Nome = %s", ptr_studn->nome);
                        printf("\n Valor da mensalidade = %9.2f", ptr_studn->nMensalidade);
                        printf("\n Data do bacharelado = %s", ptr_studn->dataBacharelado);
                        printf("\n");
                        printf("_____________________________________________________________________________");
                        printf("\n");
                    }
                    else {
                        printf("\nMATRICULA NAO ENCONTRADA !!");
                        printf("\n");
                        printf("_____________________________________________________________________________");
                        printf("\n");
                    }
                }
            }

        //MOSTRAR LISTA POR POSI플O
        void printPosition() {

            int searchPosicao;

            if(listEmpty()) {
                printf("\nA LISTA ESTA VAZIA!!");
                printf("\n");
                printf("_____________________________________________________________________________");
                printf("\n");
            }
            else {

                printf("\nINSIRA A POSICAO PARA BUSCAR.");
                scanf("%d", &searchPosicao);
                printf("\n");
                searchPosicao = searchPosicao - 1;

                if(searchPosicao >= after && searchPosicao <= back) {

                    ptr_studn = &stud[searchPosicao];

                    printf("\n**********CADASTRO DO ESTUDANTE***********");
                    printf("\n");

                    printf("\n No. Matricula = %d", ptr_studn->nMatricula);
                    printf("\n Nome = %s", ptr_studn->nome);
                    printf("\n Valor da mensalidade = %9.2f", ptr_studn->nMensalidade);
                    printf("\n Data do bacharelado = %s", ptr_studn->dataBacharelado);
                    printf("\n");
                    printf("_____________________________________________________________________________");
                    printf("\n");

                }
                else {
                    printf("\nPOSICAO NAO ENCONTRADA!!");
                    printf("\n");
                    printf("_____________________________________________________________________________");
                    printf("\n");
                }
            }

        }

        //METODO REMOVE NO FIM
        void rmLast() {

            if(listEmpty()) {
                printf("\nA LISTA ESTA VAZIA ");
                printf("\n");
                printf("_____________________________________________________________________________");
                printf("\n");
            }
            else {

                ptr_studn = &stud[back];

                printf("\nVALORES REMOVIDOS\n");
                printf("\n");

                printf("%d\n", ptr_studn->nMatricula);
                printf("%s\n", ptr_studn->nome);
                printf("%f\n", ptr_studn->nMensalidade);
                printf("%s\n", ptr_studn->dataBacharelado);
                back--;
                printf("\n");
                printf("_____________________________________________________________________________");
                printf("\n");
            }
        }

        //METODO REMOVE NO INICIO
        void rmFirst() {

            if(listEmpty()) {

                printf("\nA LISTA ESTA VAZIA !\n");
                printf("_____________________________________________________________________________");
                printf("\n");
            }
            else {
                for(i = after; i < back; i++) {
                    stud[i] = stud[i + 1];
                }
                back--;
                printf("A PRIMEIRA LISTA FOI REMOVIDA !\n");
                printf("\n");
                printf("_____________________________________________________________________________");
                printf("\n");
            }
        }

        //METODO REMOVE EM POSI플O
        void rmPosition() {

            if(listEmpty()) {
                printf("\nA LISTA ESTA VAZIA !!");
                printf("\n");
                printf("_____________________________________________________________________________");
                printf("\n");
            }
            else {
                int rmPosicao;
                printf("INSIRA A POSICAO QUE DESEJA REMOVER: ");
                scanf("%d", &rmPosicao);

                if(rmPosicao >= after && rmPosicao <= back) {

                    for(i = rmPosicao; i < back; i++) {
                        stud[i] = stud[i + 1];
                    }
                    back--;
                    printf("\nLISTA NA POSICAO %d REMOVIDA COM SUCESSO !!", rmPosicao);
                    printf("\n");
                printf("_____________________________________________________________________________");
                printf("\n");
                }
                else {
                    printf("\nPOSICAO NAO EXISTE !!");
                    printf("\n");
                    printf("_____________________________________________________________________________");
                    printf("\n");
                }

            }

        }

#endif // FUNC_H_INCLUDED
