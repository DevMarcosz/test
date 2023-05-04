#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[100];
}Pessoa;

typedef struct no{
    Pessoa p;
    struct no *proximo;
}No;

Pessoa ler_pessoa(char nome[100]){
    Pessoa p;
    strcpy(p.nome, nome);
    return p;
}

void imprimir_pessoa(Pessoa p){
    printf("Livros: %s | ", p.nome);
}

// função para a operação push (empilhar)
No* empilhar(No *topo, char nome[100]){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->p = ler_pessoa(nome);
        novo->proximo = topo;
        return novo;
    }
    else
        printf("\nErro ao alocar memoria...\n");
    return NULL;
}
// função para a operação pop (desempilhar)
No* desempilhar(No **topo){
    if(*topo != NULL){
        No *remover = *topo;
        *topo = remover->proximo;
        return remover;
    }
    else
        printf("\nPilha vazia!\n");
    return NULL;
}

void imprimir_pilha(No *topo){
    printf("\n----------- Prateleira --------------\n");
    while(topo){
        imprimir_pessoa(topo->p);
        topo = topo->proximo;
    }
    printf("\n--------- Fim prateleira ------------\n");
}

int main() {
    int qtd_estantes, qtd_pratileira = 6;
    No *remover, *topo = NULL;

    

    for (int i = 0; i < qtd_estantes; i++)
    {
       char input[100], aux[256];
       fgets(input, 100, stdin);
       
       for (size_t i = 0; i < strlen(input); i++)
        {
        if(input[i] == '/')
            {
                while(input[i] != '\\'){
                    aux[i] = input[i];
                    i++;
                }   
                aux[0] = '|';
                aux[strlen(aux)] = '\0';
                topo = empilhar(topo, aux);
            }
        }
    }

    
    return 0;
}
