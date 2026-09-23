#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
    int info;
    struct pilha *prox;
}TPilha;

typedef TPilha* PPilha;

PPilha inicializa(PPilha p){
    p = NULL;
    return p;
}

PPilha push(PPilha p, int n);
PPilha pop(PPilha p, int n);
void imprime(PPilha p);
PPilha libera(PPilha p);

int main(){
    int n, op, nr;
    PPilha p = inicializa(p);

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
                p = push(p, n);
                break;
            case 2:
            if(!p){
                printf("Pilha vazia! \n\n");
            }else{
                printf("Valor a remover: ");
                scanf("%d", &nr);
                p = pop(p, nr);
            }
            break;
        case 3:
            imprime(p);
            break;
        case 4:
            p = libera(p);
            break;
        default:
            printf("Opcao invalida! \n\n");
                
        }
    }

    return 0;
}

PPilha push(PPilha p, int n){
    PPilha novo;
    novo = (PPilha)malloc(sizeof(TPilha));
    if(!novo){
        printf("Não foi possivel alocar memoria \n");
        return p;
    }
    novo->prox = p;
    novo->info = n;

    printf("Item adicionado a pilha! \n\n");

    return novo;
}

PPilha pop(PPilha p, int n){
    PPilha q, ant;
    q = p;
    ant = NULL;

    while(q){
        if(q->info == n){
            if(!ant){
                p = p->prox;
            }else{
                ant->prox = q->prox;
            }
            free(q);

            printf("Item removido da pilha!\n");
            imprime(p);

            return p;
        }
        ant = q;
        q = q->prox;
    }
    printf("Item nao encontrado! \n");
    imprime(p);
    return q;
}

void imprime(PPilha p){
    if(!p)
        return;
    printf("%d \n", p->info);
    imprime(p->prox);
}

PPilha libera(PPilha p){
    PPilha aux;
    if(!p)
        return NULL;
    aux = p;
    p = p-> prox;
    free(aux);
    return libera(p);

}