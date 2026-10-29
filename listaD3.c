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

    return l;
}

void mostrarHistorico(PLista l){
    if(l == NULL){
        printf("Historico vazio. \n\n");
        return;
    }

    PLista p = l;

    printf("Historico de navegacao: ");

    while(p != l->ant){
        printf("%s -> ", p->site);
        p = p->prox;
    }

    printf("%s \n\n", p->site);
}

PLista removeRepeticao(PLista l){
    if(l == NULL){
        printf("Historico vazio. \n\n");
        return l;
    }

    if(l->prox == l){
        return l;
    }

    PLista aux, p = l;

    do{
        if(strcmp(p->site, p->prox->site) == 0){
            aux = p->prox;

            if(aux == p){   
                p->prox = p;
                p->ant = p;
            }else{
                aux = p->prox;
                p->prox = aux->prox;
                aux->prox->ant = p;
            }
            free(aux);
        }else{
            p = p->prox;
        }

    }while(p->prox != l);

    printf("Repeticoes removidas. \n\n");
    return p;
}

PLista avancar(PLista l){
    if(l == NULL){
        printf("Historico  vazio. \n\n");
        return l;
    }

    l = l->prox;
    printf("Site acessado: %s \n\n", l->site);
    return l;
}

PLista voltar(PLista l){
    if(l == NULL){
        printf("Historico vazio. \n\n");
        return l;
    }

    l = l->ant;
    printf("Site acessado: %s \n\n", l->site);
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
    char site[30];

    do{
        printf("--- MENU --- \n");
        printf("(1) Acessar site \n");
        printf("(2) Mostrar historico de navegacao \n");
        printf("(3) Remover duplicata \n");
        printf("(4) Avancar \n");
        printf("(5) Voltar \n");
        printf("(6) Sair \n\n");

        printf("Insira opcao desejada: ");
        scanf("%d", &op);
        getchar();
        printf("\n");

        switch(op){
            case 1:
                printf("Nome do site: ");
                fgets(site, sizeof(site), stdin);
                site[strlen(site) - 1] = '\0';

                l = visitSite(l, site);
                break;

            case 2:
                mostrarHistorico(l);
                break;

            case 3:
                l = removeRepeticao(l);
                break;

            case 4:
                l = avancar(l);
                break;

            case 5:
                l = voltar(l);
                break;

            case 6:
                libera(l);
                break;

            default:
                printf("Opcao invalida. \n\n");
                break;
        }

    }while(op != 6);

    return 0;
}