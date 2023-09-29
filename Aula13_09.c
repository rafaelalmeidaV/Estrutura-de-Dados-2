#include <stdio.h>

 struct no{
    int valor;
    struct no *esquerda;
    struct no *direita;
};

int main(){
    struct no *raiz;
    raiz = malloc(sizeof(struct no));
    raiz->valor = 2;

    raiz->esquerda = malloc(sizeof(struct no));
    raiz->esquerda->valor = 1;

    raiz->direita = malloc(sizeof(struct no));
    raiz->direita->valor = 7;

    printf("Valor da raiz: %d\n", raiz->valor);
    printf("Valor da raiz->esquerda: %d\n", raiz->esquerda->valor);
    printf("Valor da raiz->direita: %d\n", raiz->direita->valor);


    return 0;
}