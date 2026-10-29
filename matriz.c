#

#define MaxLinha 100;

typedef struct ni *pme;

struct no{
    int col, val;
    pme prox;
};

typedef pme matriz[MaxLinha];

void libera(matriz m, int l){
    pme p, q;
    for(int i = 0; i < l; i++){
        for(p = m[i]); p != NULL; ){
            q = p->prox;
            free(p);
            p = q;
        }
        m[i] = NULL;
    }
}