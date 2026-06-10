//Pedro Henrique Padilha Valente - 2510382
//Henrique Rocha Baumeier - 2510744


#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAVES 4
#define MAX_FILHOS 5

#define MAX 4
#define MIN 2

typedef struct no {
    int numChaves;
    int chaves[MAX_CHAVES];
    struct no *filhos[MAX_FILHOS];
    struct no *prox;

} No;

No* criarNo() 
{
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro ao alocar memória para o no.\n");
        exit(1);
    }
    novoNo->numChaves = 0;
    novoNo->prox = NULL;
    for (int i = 0; i < MAX_FILHOS; i++) {
        novoNo->filhos[i] = NULL;
    }
    return novoNo;
}

void imprimir(No* raiz, int nivel) 
{
    if (raiz == NULL) {
        return;
    }
    printf("Nivel %d: ", nivel);
    for (int i = 0; i < raiz->numChaves; i++) {
        printf("%d ", raiz->chaves[i]);
    }
    printf("\n");
    imprimir(raiz->prox, nivel + 1);
}

void intervalo(No *arv, int lim_inf, int lim_sup) 
{
    if (arv == NULL) {
        return;
    }

    int i;
    for (i = 0; i < arv->numChaves; i++) {
        intervalo(arv->filhos[i], lim_inf, lim_sup);

        if (arv->chaves[i] > lim_inf && arv->chaves[i] < lim_sup) {
            printf("%d ", arv->chaves[i]);
        }
    }


    intervalo(arv->filhos[i], lim_inf, lim_sup);
}

int main(void)
{
    No *raiz = criarNo();
    raiz->numChaves = 1;
    raiz->chaves[0] = 100;



    No *esq = criarNo();
    esq->numChaves = 2;
    esq->chaves[0] = 50;
    esq->chaves[1] = 75;

    No *dir = criarNo();
    dir->numChaves = 2;
    dir->chaves[0] = 120;
    dir->chaves[1] = 200;

    raiz->filhos[0] = esq;
    raiz->filhos[1] = dir;



    No *n1 = criarNo();
    n1->numChaves = 2;
    n1->chaves[0] = 10;
    n1->chaves[1] = 40;

    No *n2 = criarNo();
    n2->numChaves = 2;
    n2->chaves[0] = 60;
    n2->chaves[1] = 70;

    No *n3 = criarNo();
    n3->numChaves = 2;
    n3->chaves[0] = 80;
    n3->chaves[1] = 90;

    esq->filhos[0] = n1;
    esq->filhos[1] = n2;
    esq->filhos[2] = n3;


    
    No *n4 = criarNo();
    n4->numChaves = 2;
    n4->chaves[0] = 110;
    n4->chaves[1] = 115;

    No *n5 = criarNo();
    n5->numChaves = 4;
    n5->chaves[0] = 130;
    n5->chaves[1] = 135;
    n5->chaves[2] = 140;
    n5->chaves[3] = 170;

    No *n6 = criarNo();
    n6->numChaves = 4;
    n6->chaves[0] = 220;
    n6->chaves[1] = 230;
    n6->chaves[2] = 240;
    n6->chaves[3] = 250;

    dir->filhos[0] = n4;
    dir->filhos[1] = n5;
    dir->filhos[2] = n6;

    printf("Arvore B:\n\n");
    imprimir(n2, 0);


    int lim_inf = 50;
    int lim_sup = 100;
    printf("\nChaves no intervalo (%d < x < %d): ", lim_inf, lim_sup);
    intervalo(raiz, lim_inf, lim_sup);
    printf("\n");

    return 0;
}