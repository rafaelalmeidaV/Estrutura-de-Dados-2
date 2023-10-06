#include <stdio.h>
struct No
{
    int dado;
    struct No *esq;
    struct No *dir;
};

// função de inserção

struct No *raiz = NULL;

int insere(struct No **raiz, int valor)
{

    if ((*raiz) == NULL)
    {

        (*raiz) = malloc(sizeof(struct No));
        if ((*raiz) == NULL)
            return 0;
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
        (*raiz)->dado = valor;
        return 1;
    }
    else
    {
        if (valor > (*raiz)->dado)
        {
            return insere(&((*raiz)->dir), valor);
        }
        else if (valor < (*raiz)->dado)
        {
            return insere(&((*raiz)->esq), valor);
        }
        else
            return 0;
    }
}

// fazer todos os percursos
void preOrdem(struct No *raiz)
{
    if (raiz != NULL)
    {
        printf("\n%d", raiz->dado);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

void inOrdem(struct No *raiz)
{
    if (raiz != NULL)
    {
        inOrdem(raiz->esq);
        printf("\n%d", raiz->dado);
        inOrdem(raiz->dir);
    }
}

void posOrdem(struct No *raiz)
{
    if (raiz != NULL)
    {
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("\n%d", raiz->dado);
    }
}

/* EX1
    Fazer uma função para dado um valor retornar o nó
    que o contem, se ele estiver na arvore
    caso ele nao esteja, retorne NULL*/

struct No *retornaValor(struct No *raiz, int valor)
{
    if (raiz != NULL)
    {
        if (raiz->dado == valor)
        {   
            return raiz;
        }
        else
        {

            if (valor < raiz->dado)
                return retornaValor(raiz->esq, valor);
            else
                return retornaValor(raiz->dir, valor);
        }
    }
    else
    {
        return NULL;
    }
}

/*EX2
    Fazer a impressao da arvore em ordem descendente*/

void imprimeDescendente(struct No *raiz)
{
    if (raiz != NULL)
    {
        imprimeDescendente(raiz->dir);
        printf("\n%d", raiz->dado);
        imprimeDescendente(raiz->esq);
    }
}

int main()
{
    insere(&raiz, 7);
    insere(&raiz, 5);
    insere(&raiz, 12);
    insere(&raiz, 4);
    insere(&raiz, 6);

    printf("\npos Ordem");
    posOrdem(raiz);

    printf("\ninOrdem");
    inOrdem(raiz);

    printf("\npreOrdem");
    preOrdem(raiz);

    printf("\nBuscar valor");
    if(retornaValor(raiz, 4) == NULL)
        printf("\nValor nao encontrado");
    else
        printf("\nValor encontrado");

    printf("\nimprimeDescendente");
    imprimeDescendente(raiz);
}