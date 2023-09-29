#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Implementação dos algoritmos de 
//percurso em profundidade

struct No{
    int dado;
    struct No* esquerda;
    struct No* direita;
};

void preOrdem(struct No* raiz){
    //SE HOUVER ELEMENTO DA ARVORE
    if(raiz!=NULL){
        //passo 1 - imprima os dados da raiz
        printf("\nDado: %d", raiz->dado);
        getch();
        //passo 2 - chame o processo pré-ordem
        //para a esquerda
        preOrdem(raiz->esquerda);
        //passo 3 - chame o processo pré-ordem
        //para a esquerda
        preOrdem(raiz->direita);

    }
}

void inOrdem(struct No* raiz){

    if(raiz!=NULL){
    //esquerda
    inOrdem(raiz->esquerda);
    //raiz
    printf("\nDado: %d", raiz->dado);
    getch();
    //direita
    inOrdem(raiz->direita);
    }
}

int main(){
    struct No* raiz = malloc(sizeof(struct No));
    raiz->dado = 1;

    raiz->esquerda = malloc(sizeof(struct No));
    raiz->esquerda->dado = 2;

    raiz->direita = malloc(sizeof(struct No));
    raiz->direita->dado = 3;

    raiz->esquerda->esquerda = NULL;
    raiz->esquerda->direita = NULL;
    raiz->direita->esquerda = NULL;
    raiz->direita->direita = NULL;
    
    inOrdem(raiz);

}