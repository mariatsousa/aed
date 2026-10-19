#include <stdio.h>
#include <stdlib.h> 

typedef struct lista{
    int info;
    struct lista *prox;
}TLista;

typedef TLista *PLista;

PLista inicializa(PLista l){
    l = NULL;
    return l;
}

PLista insere (PLista ultimo, int n){
    PLista novo;
    novo = (PLista)malloc(sizeof(TLista));

    if(ultimo == NULL){
        novo->prox = novo;
        novo->info = n;
        return novo;
    }

    novo->info = n;
    novo->prox = ultimo->prox;
    ultimo->prox = novo;

    return ultimo;
}

PLista remover(PLista ultimo, int n){
    PLista aux = ultimo->prox, ant = ultimo;

    if(ultimo == NULL){
        printf("Lista vazia!");
        return ultimo;
    }

    do{
        if(aux->info == n){
            if(aux ==  aux->prox){
                free(aux);
                return NULL;
            }
            ant->prox = aux->prox;
            printf("Removido %d \n\n", n);
            if(aux == ultimo){
                free(aux);
                return ant;
            }
            free(aux);
            return ultimo;
        }

        ant = ant->prox;
        aux = aux->prox;

    }while(aux != ultimo->prox);
    
    printf("Nao Encontrado \n\n");
    return ultimo;
}

void imprime(PLista l){
    PLista p = l->prox;

    if(l == NULL){
        printf("Lista vazia! \n");
        return;
    }

    do{
        printf("%d ", p->info);
        p = p->prox;
    }while(p != l->prox);
}

void libera(PLista ultimo){
    PLista aux = ultimo->prox;

    if(ultimo == NULL){
        return;
    }

    while(aux != ultimo){
        aux = aux->prox;
        free(ultimo->prox);
        ultimo->prox = aux;
    }

    free(ultimo);
}

int main(){
    PLista l = inicializa(l);
    int op, n;

    do{
        printf("--- MENU --- \n");
        printf("(1) Inserir \n");
        printf("(2) Remover \n");
        printf("(3) Imprimir \n");
        printf("(4) Sair \n\n");

        printf("Opcao: ");
        scanf("%d", &op);

        switch(op){
            case 1:
                printf("Insira o novo elemento: ");
                scanf("%d", &n);

                l = insere(l, n);

                break;

            case 2:
                printf("Insira valor para gremover: ");
                scanf("%d", &n);

                l = remover(l, n);
                break;

            case 3:
                imprime(l);
                printf("\n\n");
                break;

            case 4:
                libera(l);
                break;

            default:
                printf("Opcao Invalida!");

        }
    }while(op != 4);

    return 0;
}