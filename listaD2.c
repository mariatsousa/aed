#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct lista {
 char nome[30];
 struct lista *ant;
 struct lista *prox;
} TLista;

typedef TLista *PLista;

/*Implemente as seguintes funções:
PLista2 inserirPonto(PLista2 l, char nome[]);
void patrulhar(PLista2 inicio, int passos);
Regras:
• começa no primeiro nó; 
• inicialmente segue em sentido horário (prox); 
• se o tamanho do nome for par: 
o muda a direção; 
• se o tamanho do nome for ímpar: 
o mantém a direção; 
• após decidir a direção, move para o próximo ponto; 
• repetir por passos movimentos. 
Exemplo
Lista:
Ana <-> Bruno <-> Caio <-> Daniel <-> Eva
Tamanhos:
• Ana → 3 
• Bruno → 5 
• Caio → 4 
• Daniel → 6 
• Eva → 3 
Execução
patrulhar(lista, 12);
Saída:
Ana
Bruno
Caio
Bruno
Ana
Eva
Daniel
Eva
Ana
Bruno
Caio
Bruno
Exercício — “Histórico de Navegação”*/

PLista inserir(PLista l, char nome[]){
    PLista novo = (PLista)malloc(sizeof(TLista));
    strcpy(novo->nome, nome);

    if(l == NULL){
        novo->prox = novo;
        novo->ant = novo;
        printf("Ponto adicionado \n\n");
        return novo;
    }

    novo->ant = l->ant;
    novo->prox = l;
    l->ant->prox = novo;
    l->ant = novo;

    printf("Ponto adicionado \n\n");
    return l;
}

void patrulhar(PLista l, int passos){
    if(l == NULL){
        printf("Lista vazia \n\n");
        return;
    }

    PLista p = l;
    int cond = 0;
    for(int i = 0; i < passos; i++){
        printf("%s \n", p->nome);

        if(strlen(p->nome) % 2 == 0){
            if(cond == 0){
                cond = 1;
            }else{
                cond = 0;
            }
        }
        
        if(cond == 0){
            p = p->prox;
        }else{
            p = p->ant;
        }
    }
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
    int op, passos;
    char nome[30];

    do{
        printf("--- MENU --- \n");
        printf("(1) Inserir posicao \n");
        printf("(2) Patrulhar \n");
        printf("(3) Sair \n\n");

        printf("Opcao desejada: ");
        scanf("%d",  &op);
        getchar();

        switch(op){
            case 1:
                printf("Insira o nome da posicao: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strlen(nome) - 1] = '\0';
                
                l = inserir(l, nome);
                break;

            case 2:
                printf("Quantidade de passos: ");
                scanf("%d", &passos);

                patrulhar(l, passos);
                break;

            case 3:
                libera(l);
                break;

            default:
                printf("Opcao Invalida. \n\n");
                break;
        }

    }while(op != 3);

    return 0;
}