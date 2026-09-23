#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int info;
    struct no* prox;
}TNo;

typedef TNo* PNo;

typedef struct fila{
    PNo ini;
    PNo fim;
}TFila;

typedef TFila* PFila;

PFila inicializa(){
    PFila f = (PFila) malloc(sizeof(TFila)); 
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

PFila insere(PFila f, int n);
PFila remover(PFila f);
void imprime(PFila f);
PFila libera(PFila f);

int main(){
    PFila f = inicializa();
    int op, n;

    while(op!=4){
        printf("Menu: \n");
        printf("(1) Inserir \n");
        printf("(2) Remover \n");
        printf("(3) Imprimir \n");
        printf("(4) Sair \n\n");

        printf("Insira o comando desejado: ");
        scanf("%d", &op);

        switch(op){
            case 1:
                printf("Insira valor: ");
                scanf("%d", &n);
                f = insere(f, n);
                break;
            case 2:
                f = remover(f);
                break;
        case 3:
            imprime(f);
            break;
        case 4:
            f = libera(f);
            break;
        default:
            printf("Opcao invalida! \n\n");      
        }
    }
    return 0;
}

PFila insere(PFila f, int n){
    PNo novo;
    novo = (PNo)malloc(sizeof(TNo));

    novo->info = n;
    novo->prox = NULL;

    if(f->fim){
        f->fim->prox = novo;
        f->fim = novo;
    }else{
        f->ini = f->fim = novo;
    }

    return f;
}

PFila remover(PFila f){
    if (f->ini == NULL) {
        printf("Fila vazia!\n\n");
        return f;
    }

    PNo aux = f->ini;
    f->ini = aux->prox;

    if (f->ini == NULL) {
        f->fim = NULL; 
    }

    free(aux);

    return f;
}

void imprime(PFila f){
    PNo aux = f->ini;
    while(aux != NULL){
        printf("%d \n", aux->info);
        aux = aux->prox;
    }
}

PFila libera(PFila f){
    PNo aux = f->ini;

    while(aux != NULL){
        f->ini = aux->prox;
        free(aux);
        aux = f->ini;
    }
    free(f);
    return NULL;
}