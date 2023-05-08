#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
} Livros;

typedef struct {
    int topo;
    Livros livro[5];
} Prateleira;

typedef struct {
    int topo;
    Prateleira prateleiras[6];
} Estante;

void push(Estante* estante, Livros livro) {
    if (estante->topo == -1 || estante->prateleiras[estante->topo].topo == 5) {
        estante->topo++;
        estante->prateleiras[estante->topo].topo = -1;
    }

    Prateleira* prateleira_atual = &(estante->prateleiras[estante->topo]);
    prateleira_atual->topo++;
    strcpy(prateleira_atual->livro[prateleira_atual->topo].nome, livro.nome);
}


Livros* pop(Estante* estante) {
    if (estante->topo == -1 || estante->prateleiras[estante->topo].topo == -1) {
        return NULL;
    }

    Prateleira* prateleira_atual = &(estante->prateleiras[estante->topo]);
    Livros* livro = &(prateleira_atual->livro[prateleira_atual->topo]);
    prateleira_atual->topo--;

    if (prateleira_atual->topo == -1) {
        estante->topo--;
    }

    return livro;
}

int main() {
    Estante estante;
    estante.topo = -1;

    char entrada[1500] = "/O poder do Habito,Boa noite PunPun,A revolucao dos bixos,Harry Potter,Senhor dos aneis,oxe\\/Berserk,One Piece,Calculo1,calulo2,geometria analitica\\";
    //printf("Digite a entrada: ");
    //fgets(entrada, 200, stdin);

    Livros livro;
    int i = 0;
    int j = 0;
    while (entrada[i] != '\0') {
        if (entrada[i] == '/') {
            estante.topo++;
            estante.prateleiras[estante.topo].topo = -1;
            i++;
            j = 0;
        } else if (entrada[i] == '\\') {
            i++;
        } else if (entrada[i] == ',') {
            livro.nome[j] = '\0';
            push(&estante, livro);
            i++;
            j = 0;
        } else {
            livro.nome[j] = entrada[i];
            i++;
            j++;
        }
    }
    livro.nome[j] = '\0';
    push(&estante, livro);

    for (int i = 0; i <= estante.topo; i++) {
        printf("Prateleira %d:\n", i+1);
        Prateleira prateleira = estante.prateleiras[i];
        for (int j = 0; j <= prateleira.topo; j++) {
            Livros livro = prateleira.livro[j];
            printf("- %s\n", livro.nome);
        }
    }
    printf("\n\n");
    Livros* livro_removido = pop(&estante);
    if (livro_removido != NULL) {
        printf("%s\n", livro_removido->nome);
    }
    printf("\n\n");

    for (int i = 0; i <= estante.topo; i++) {
        printf("Prateleira %d:\n", i+1);
        Prateleira prateleira = estante.prateleiras[i];
        for (int j = 0; j <= prateleira.topo; j++) {
            Livros livro = prateleira.livro[j];
            printf("- %s\n", livro.nome);
        }
    }

    return 0;

}
   
