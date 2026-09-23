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

PPilha pop(PPilha p);



int main(){
    int n;
    PPilha p = inicializa(p);

    printf("Numero a ser convertido: ");
    scanf("%d", &n);

    for(int i = n; i != 0; i /= 2){
        p = push(p, i%2);
    }

    printf("%d em binario: ", n);
    while(p){
        p = pop(p);
    }

    printf("\n");
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

    return novo;
}

PPilha pop(PPilha p){
    PPilha aux;
    aux = p;

    p = aux->prox;
    printf("%d", aux->info);
    free(aux);

    return p;
}