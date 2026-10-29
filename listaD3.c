/*Um navegador de internet armazena as páginas visitadas usando uma lista duplamente 
encadeada não circular. Cada nó representa uma página acessada.
Estrutura

Implemente as funções:
PLista2 visitSite(PLista2 l, char site[]);
A função deve inserir o site no final da lista.
void mostrarHist(PLista2 l);
Exemplo:
 google.com -> youtube.com -> wikipedia.org -> 
github.com
PLista2 removerRep(PLista2 l);
A função deve remover páginas consecutivas repetidas.
Exemplo
Antes:
 google -> youtube -> youtube -> github -> github -> 
github -> gmail
Depois:
 google -> youtube -> github -> gmail
Funções de Navegação
PLista2 voltarP(PLista2 atual);
PLista2 avancarP(PLista2 atual);
As funções devem:
• voltar para a página anterior (ant); 
• avançar para a próxima página (prox). 
Se não existir página anterior/próxima, permanecer na atual.*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct lista{
    char site[30];
    struct lista *prox;
    struct lista *ant;
}TLista;

typedef TLista *PLista;

PLista visitSite(PLista l, char site[]){
    PLista novo = (PLista)malloc(sizeof(TLista));

    strcpy(novo->site, site);

    if(l == NULL){
        novo->prox = novo;
        novo->ant = novo;

        return novo;
    }

    novo->ant = l->ant;
    novo->prox = l;
    l->ant->prox = novo;
    l->ant = novo;

    return novo;
}

void mostrarHistorico(PLista l){
    if(l == NULL){
        printf("Historico vazio. \n\n");
        return;
    }

    PLista p = l;

    while(p != l->ant){
        printf("%s -> ", p->site);
        p = p->prox;
    }

    printf("%s \n\n", p->site);
}

PLista removeRepeticao(PLista l){
    if(l == NULL){
        printf("Historico vazio.");
        return l;
    }

    PLista aux, p = l;

    do{
        if(p->site == p->prox->site){
            
        }
    }while(p != l);
}