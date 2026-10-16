#include <stdio.h>
#include <stdlib.h> 

typedef struct lista{
    int info;
    lista *prox;
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
    }

    novo->info = n;
    novo->prox = ultimo->prox;
    ultimo->prox = novo;

    return ultimo;
}

PLista remove(PLista ultimo, int *n){
    PLista aux = ultimo->prox, ant = ultimo;

    if(ultimo == NULL){
        return;
    }

    do{
        if(aux->info == n){
            if(aux ==  aux->prox){
                free(aux);
                return NULL;
            }
            ant->prox = aux->prox;
            n = aux->info;
            printf("Removido %d \n\n", n);
            free(aux);
            return aux;
        }

    }while(aux != ultimo->prox);
    
    printf("Nao Encontrado \n\n");
    return l;
}

void imprime(PLista l){
    PLista p = l->prox;

    if(l == NULL){
        printf("Lista vazia! \n");
        return;
    }

    do{
        printf("%d", p->info);
        p = p->prox;
    }while(p != l->prox);
}

void libera(PLista l){
    PLista aux = l->prox;

    if(l == NULL){
        return;
    }

    do{
        l->prox = aux->prox;
        free(aux);
        aux = l->prox;
    }while(l != l->prox);

    free(l);
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
                printf("Insira valor para remover: ");
                scanf("%d", &n);

                l = remove(l, *n);
                break;

            case 3:
                imprime(l);
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