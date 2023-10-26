#include <stdio.h>
#include <locale.h>
struct No
{
    int dado;
    struct No *esq;
    struct No *dir;
};

// função de inserção

struct No *raiz = NULL;

// função que avalia se um nó é folha
int eh_folha(struct No *raiz)
{

    if (raiz != NULL)
    {
        if ((raiz->esq == NULL) && (raiz->dir == NULL))
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
    // exercicio para casa:avaliar se a raiz é folha
}

struct No *antecessor(struct No *raiz)
{

    // é o nó mais à direita do filho à esquerda
    if (raiz != NULL)
    {
        if (raiz->esq != NULL)
        {

            // vá para os antecessores
            raiz = raiz->esq;

            // procurar o nó mais à direita
            while (raiz->dir != NULL)
            {
                raiz = raiz->dir;
            }
            return raiz;
        }
    }
    return NULL; // caso não tenha
                 // filho à esquerda, não há antecessor
}

// Exercicio1 : função sucessor de um nó

struct No *sucessor(struct No *raiz)
{

    // é o nó mais à esquerda do filho à direita
    if (raiz != NULL)
    {
        if (raiz->dir != NULL)
        {

            // vá para os sucessores
            raiz = raiz->dir;

            // procurar o nó mais à esquerda
            while (raiz->esq != NULL)
            {
                raiz = raiz->esq;
            }
            return raiz;
        }
    }
    return NULL; // caso não tenha
                 // filho à esquerda, não há antecessor
}

int insere(struct No **raiz, int valor, int *contador)
{
    if ((*raiz) == NULL)
    {

        (*raiz) = malloc(sizeof(struct No));
        if ((*raiz) == NULL)
            return 0;
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
        (*raiz)->dado = valor;
        (*contador)++;
        return 1;
    }
    else
    {
        
        if (valor > (*raiz)->dado)
        {
            return insere(&((*raiz)->dir), valor, contador);
        }
        else if (valor < (*raiz)->dado)
        {
            return insere(&((*raiz)->esq), valor, contador);
        }

        else
        {
            return 0;
        }
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

/***Ex1
//fazer uma função para dado um valor retornar o nó
//que o contém, se ele estiver na árvore
//caso ele não esteja, retorne NULL

*/
struct No *busca(struct No *raiz, int valor)
{
    if (raiz != NULL)
    {
        // verifique se o valor está na raiz
        if (raiz->dado == valor)
        {
            return raiz;
        }
        else
        {

            if (valor < raiz->dado)
                return busca(raiz->esq, valor);
            else
                return busca(raiz->dir, valor);
        }
    }
    return NULL; // a raiz é nula
}

/****Ex2
Fazer a impressão da árvove em ordem descendente
*/

void inOrdemDesc(struct No *raiz)
{
    if (raiz != NULL)
    {
        inOrdemDesc(raiz->dir);
        printf("\n%d", raiz->dado);
        inOrdemDesc(raiz->esq);
    }
}

// remover um valor da árvore se ele existir
void deleta(int valor)
{

    // opção do  Breno- fazer a busca
    struct No *aux = busca(raiz, valor);

    // opção do Thiago, verificar se é nulo o aux
    if (aux == NULL)
    {
        return;
    }

    // opção do Leo verificar se é folha
    if (eh_folha(aux) == 1)
    {
        free(aux);
        aux = NULL;
        return;
    }

    // verificar se ele só possui um filho à esquerda
    if ((aux->dir == NULL) && (eh_folha(aux->esq) == 1))
    {
        // dica do Emanuel
        // copia para o nó raiz o filho à esquerda
        aux->dado = aux->esq->dado;
        free(aux->esq);
        aux->esq = NULL;
        return;
    }

    // verificar se ele só possui um filho à direita
    if ((aux->esq == NULL) && (eh_folha(aux->dir) == 1))
    {
        // dica do Emanuel
        // copia para o nó raiz o filho à esquerda
        aux->dado = aux->dir->dado;
        free(aux->dir);
        aux->dir = NULL;
        return;
    }
    // o aux possui dois filhos
    // procurar o antecessor
    struct No *ant = antecessor(aux);

    // copiar o valor do antecessor para a raiz
    valor = aux->dado;
    aux->dado = ant->dado;
    ant->dado = valor;

    deleta(valor);
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int contador=0;
    insere(&raiz, 7, &contador);
    insere(&raiz, 5, &contador);
    insere(&raiz, 12,&contador);
    insere(&raiz, 4,&contador);
    insere(&raiz, 6,&contador);

    printf("quantidade de nós: %d", contador);
    inOrdemDesc(raiz);

    struct No *aux;
    /*if(aux=busca(raiz,8)==NULL){
        printf("\n O nó não está na arvore");

    }
    else{
            printf("\n O nó está na arvore %p: %d", aux, aux->dado);
    }*/

    aux = antecessor(raiz);
    if (aux != NULL)
    {
        printf("\nO antecessor é: %d", aux->dado);
    }
    else
    {

        printf("\nO antecessor não existe");
    }

    // Exercicio2
    // imprimir o nó sucessor do 15.
    aux = sucessor(busca(raiz, 15));

    if (aux != NULL)
    {
        printf("\nO sucessor é: %d", aux->dado);
    }
    else
    {

        printf("\nO sucessor não existe");
    }
}