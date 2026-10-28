#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct lista{
    char nome[50];
    struct lista *prox;
    struct lista *ant;
}TLista;

typedef TLista *PLista;


/* PLista2 inserirJ(PLista2 l, char nome[]);
A função deve inserir o jogador no final da lista circular.h */

PLista inserir(PLista l, char nome[]){
    PLista novo;
    novo = (PLista)malloc(sizeof(TLista));
    strcpy(novo->nome, nome);

    if(l == NULL){
        novo->prox = novo;
        novo->ant = novo;

        printf("Jogador inserido. \n\n");
        return novo;
    }else{
        novo->ant = l->ant;
        novo->prox = l;
        l->ant->prox = novo;
        l->ant = novo;
    }

    printf("Jogador inserido. \n\n");
    return l;
}


/*void mostrarHor(PLista2 l);
Mostra os jogadores no sentido horário.
Exemplo:
 Ana -> Bruno -> Carlos -> Diana*/

void mostrarH(PLista l){
    if(l == NULL){
        printf("Lista Vazia \n\n");
        return;
    }

    PLista p = l;

    while(p != l->ant){
        printf("%s -> ", p->nome);
        p = p->prox;
    }
    printf("%s \n\n", p->nome);
}


 /*PLista2 avancarRodada(PLista2 l);
A função deve retornar o próximo jogador da rodada.
Como a lista é circular:
 Diana -> Ana*/

PLista avancar(PLista l){
    if(l == NULL){
        printf("Lista Vazia \n\n");
        return NULL;
    }

    return l->prox;
}


 /*PLista2 eliminarJ(PLista2 l, char nome[]);
A função remove um jogador da fila circular.*/

PLista eliminar(PLista l, char nome[]){
    if(l == NULL){
        printf("Lista Vazia. \n\n");
        return l;
    }

    PLista p = l;

    do{
        if(strcmp(p->nome, nome) == 0){
            if(p == p->prox){
                free(p);

                printf("Jogador removido. \n\n");
                return NULL;
            }

            if(p == l){
                l = l->prox;
            }

            p->ant->prox = p->prox;
            p->prox->ant = p->ant;

            free(p);

            printf("Jogador removido. \n\n");
            return l;
        }

        p = p->prox;
    }while(p != l);

    printf("Jogador nao encontrado. \n\n");
    return l;
}

void libera(PLista l){
    if(l == NULL){
        return;
    }
    PLista aux, p = l->prox;

    while(p != l){
        aux = p;
        p = p->prox;
        free(aux);
    }

    free(l);
}

int main(){
    PLista l = NULL;
    int op;
    char nome[50];

    do{
        printf("--- Menu --- \n");
        printf("(1) Adicionar jogador \n");
        printf("(2) Mostrar os jogadors no sentido horario \n");
        printf("(3) Avancar rodada \n");
        printf("(4) Eliminar jogador \n");
        printf("(5) Sair \n\n");

        printf("Opcao desejada: ");
        scanf("%d", &op);
        getchar();

        printf("\n");

        switch (op){
        case 1:
            printf("Nome do jogador: ");
            fgets(nome, sizeof(nome), stdin);
            nome[strlen(nome) - 1] = '\0';

            l = inserir(l, nome);
            break;

        case 2:
            mostrarH(l);
            break;

        case 3:
            l = avancar(l);
            break;

        case 4:
            printf("Nome do jagador que deseja remover: ");
            fgets(nome, sizeof(nome), stdin);
            nome[strlen(nome) - 1] = '\0';

            l = eliminar(l, nome);
            break;

        case 5:
            libera(l);
            break;
        
        default:
            printf("Opcao invalida. \n\n");
            break;
        }

    }while(op != 5);
}