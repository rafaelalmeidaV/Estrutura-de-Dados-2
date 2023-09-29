#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct Produto{
	int codigo;
	char descricao[100];
	char categoria[100];
	int quantidadeEstoque;
	float precoUnitario;
	
	struct Produto *proximo;
};

FILE *pFile = NULL;
// define o n� inicial da lista
	struct Produto *inicio;

// 1-Listar todos os produtos.
void listar_todos_produtos(){
	
	// define o n� inicial da lista
	struct Produto *inicio=NULL;
	struct Produto *novo = (struct Produto*)malloc(sizeof(struct Produto));
	
	int codigo;
	pFile = fopen("estoque.txt", "r");
	
	if(pFile != NULL){
		
		while(fscanf(pFile, "%d ", &codigo) != EOF){
				
			novo->codigo=codigo;
				
			fscanf(pFile, "%s ", novo->descricao);
			fscanf(pFile, "%s ", novo->categoria);
			fscanf(pFile, "%d ", &novo->quantidadeEstoque);
			fscanf(pFile, "%f ", &novo->precoUnitario);
			
			novo->proximo=inicio;
			inicio=novo;
			
			if(inicio->quantidadeEstoque>0){
				printf("\n");
				printf("%d", inicio->codigo);	
				printf(" %s", inicio->descricao);
				printf(" %s", inicio->categoria);
				printf(" %d ", inicio->quantidadeEstoque);
				printf(" %f ", inicio->precoUnitario);
			}	
		}	
		fclose(pFile);

	}
	else{
		printf("Erro ao abrir o arquivo de estoque->\n");
	}
	
}


//2 � Buscar produto de acordo com categoria.
void listar_produtos_categoria(char categorias[100]){
	// define o n� inicial da lista
	struct Produto *inicio=NULL;
	struct Produto *novo = (struct Produto*)malloc(sizeof(struct Produto));
	int codigo;
	pFile = fopen("estoque.txt", "r");
	
	if(pFile != NULL){
		
		while(fscanf(pFile, "%d ", &codigo) != EOF){
				
			novo->codigo=codigo;
				
			fscanf(pFile, "%s ", novo->descricao);
			fscanf(pFile, "%s ", novo->categoria);
			fscanf(pFile, "%d ", &novo->quantidadeEstoque);
			fscanf(pFile, "%f ", &novo->precoUnitario);
			
			novo->proximo=inicio;
			inicio=novo;
			
			if(strcmp(categorias, inicio->categoria)==0){
				printf("\n");
				printf("%d", inicio->codigo);	
				printf(" %s", inicio->descricao);
				printf(" %s", inicio->categoria);
				printf(" %d ", inicio->quantidadeEstoque);
				printf(" %f ", inicio->precoUnitario);
			}	
		}	
		fclose(pFile);

	}
	else{
		printf("Erro ao abrir o arquivo de estoque->\n");
	}
}

//3 � Adicionar produtos em carrinho de compra.
void addCarrinho(int codigoC, int quantidadeC){

	struct Produto *novo = (struct Produto*)malloc(sizeof(struct Produto));
	int codigo;
	pFile = fopen("estoque.txt", "r+");
	
	if(pFile!=NULL){
		// ler o arquivo e mostra-lo
		while(fscanf(pFile, "%d ", &codigo) != EOF){
			novo->codigo=codigo;
				
			fscanf(pFile, "%s ", novo->descricao);
			fscanf(pFile, "%s ", novo->categoria);
			fscanf(pFile, "%d ", &novo->quantidadeEstoque);
			fscanf(pFile, "%f ", &novo->precoUnitario);
		
			novo->proximo = NULL; // Defina o pr�ximo do novo n� como NULL, pois ele ser� o �ltimo da lista

	        if (inicio == NULL) {
	            inicio = novo;
	        } 
			else {
	            // Encontre o �ltimo n� na lista e defina o pr�ximo para o novo n�
	            struct Produto *ultimo = inicio;
	            while (ultimo->proximo != NULL) {
	                ultimo = ultimo->proximo;
	            }
	            ultimo->proximo = novo;
	        }
		
			printf("\n");
			printf("%d", inicio->codigo);	
			printf(" %s", inicio->descricao);
			printf(" %s", inicio->categoria);
			printf(" %d ", inicio->quantidadeEstoque);
			printf(" %f ", inicio->precoUnitario);
		}
		
		struct Produto *aux=inicio;
		
		while(aux != NULL){
			printf("\n%d", aux->codigo);
			aux=aux->proximo;
		}
		
	}
	else{
		printf("Erro ao abrir o arquivo de estoque->\n");
	}
	
}

int main(){
	
	//listar_todos_produtos();
	//listar_produtos_categoria("alimenticio");
	addCarrinho(1,5);
}