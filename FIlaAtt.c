#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_FILA 48

typedef struct pessoa{
    char nome[50];
    int idade;
    int prioridade;
}Pessoa;
//tempo 30m em 24 horas = 48
typedef struct {
    Pessoa pessoas[MAX_FILA];
    int tamanho;
}Fila;

int isFull(Fila fila){
    return fila.tamanho == 48 ? 1 : 0;
}

int isEmpty(Fila fila){
    return fila.tamanho == 0 ? 1 : 0;
}

void adicionar_na_fila(Fila *fila, Pessoa paciente){
    if(fila->tamanho >= MAX_FILA){
        printf("Fila cheia!");
        return;
    }
    fila->pessoas[fila->tamanho] = paciente;
    fila->tamanho++;
}
void remover_da_fila(Fila *fila, int posicao){
    for(int i = posicao ; i < fila->tamanho-1 ; i++){
        fila->pessoas[i] = fila->pessoas[i+1];
    }
    fila->tamanho--;
}

void atender(Fila *fila){
    if(fila->tamanho == 0){
        printf("Fila vazia. Ninguem pra atender!\n");
        return;
    }

    int posicao_da_maior_prioridade = 0;
    for(int i = 1; i < fila->tamanho;i++){
        if(fila->pessoas[i].prioridade > fila->pessoas[posicao_da_maior_prioridade].prioridade){
            posicao_da_maior_prioridade = i;
        }
    }

    printf("\nSenhor(a) %s vai ser atendido(a) agora!\n", fila->pessoas[posicao_da_maior_prioridade].nome);
    sleep(3);
    printf("\n%s foi atendido\n", fila->pessoas[posicao_da_maior_prioridade].nome);
    remover_da_fila(fila, posicao_da_maior_prioridade);
}

void mostrar_fila(Fila fila){
    if(fila.tamanho == 0){
        printf("Ninguem na fila\n");
        return;
    }
    for(int i =0; i< fila.tamanho;i++){
        printf("[%s]-[%d] ", fila.pessoas[i].nome, fila.pessoas[i].prioridade);
    }
    printf("\n");
}

void fila_do_dia(Fila fila){
    while (!isEmpty(fila))
    {
        atender(&fila);
        mostrar_fila(fila);
    }
}

int main(){
    char input;
    int input_dia, prioridade;
    Pessoa paciente;
    Fila fila_segunda = {0};
    Fila fila_terca = {0};
    Fila fila_quarta = {0};
    Fila fila_quinta = {0};
    Fila fila_sexta = {0};
    Fila fila_sabado = {0};
   
 
    do{
        printf("\nLigar e agendar ou ir no Hospital?\n(L)igar - (C)orrer pro hospital - (S)air\n");
        scanf(" %c", &input);

        switch (input)
        {
        case 'L':
            
            while(getchar() != '\n');

            printf("Qual seu nome?: ");
            scanf("%49[^\n]", &paciente.nome);
            printf("Qual sua idade?: ");
            scanf("%d", &paciente.idade);
            if(paciente.idade > 79 || paciente.idade < 6){
                prioridade = 0;
            }else if((paciente.idade > 5 && paciente.idade < 16) || (paciente.idade > 60 && paciente.idade < 80)){
                prioridade = 1;
            }else{
                prioridade = 2;
            }
            paciente.prioridade = prioridade;
            getchar();

            printf("Bom dia para que dia vocẽ quer seu atendimento?\n(1)Segunda - (2)Terça - (3)Quarta - (4)Quinta - (5)Sexta - (6)Sabado - (7) Desistir\n");
            scanf("%d", &input_dia);
            if(input_dia == 1){
                    if(isFull(fila_segunda)){
                        printf("\nInfelizmente Segunda esta lotada.\nTente outro dia\n");
                    }else{
                        adicionar_na_fila(&fila_segunda, paciente);
                        mostrar_fila(fila_segunda);
                    }
            }else if(input_dia == 2){
                 if(isFull(fila_terca)){
                        printf("\nInfelizmente Segunda esta lotada.\nTente outro dia\n");
                    }else{
                        adicionar_na_fila(&fila_terca, paciente);
                        mostrar_fila(fila_terca);
                    }
            }else if(input_dia == 3){
                 if(isFull(fila_quarta)){
                        printf("\nInfelizmente Segunda esta lotada.\nTente outro dia\n");
                    }else{
                        adicionar_na_fila(&fila_quarta, paciente);
                        mostrar_fila(fila_quarta);
                    }
            }else if(input_dia == 4){
                 if(isFull(fila_quinta)){
                        printf("\nInfelizmente Segunda esta lotada.\nTente outro dia\n");
                    }else{
                        adicionar_na_fila(&fila_quinta, paciente);
                        mostrar_fila(fila_quinta);
                    }
            }else if(input_dia == 5){
                 if(isFull(fila_sexta)){
                        printf("\nInfelizmente Segunda esta lotada.\nTente outro dia\n");
                    }else{
                        adicionar_na_fila(&fila_sexta, paciente);
                        mostrar_fila(fila_sexta);
                    }
            }else if(input_dia == 6){
                 if(isFull(fila_sabado)){
                        printf("\nInfelizmente Segunda esta lotada.\nTente outro dia\n");
                    }else{
                        adicionar_na_fila(&fila_sabado, paciente);
                        mostrar_fila(fila_sabado);
                    }
            }
            break;

        case 'C':
        
            while(getchar() != '\n');

            printf("Qual seu nome?: ");
            scanf("%49[^\n]", &paciente.nome);
            printf("Qual sua idade?: ");
            scanf("%d", &paciente.idade);
            if(paciente.idade > 79 || paciente.idade < 6){
                prioridade = 0;
            }else if((paciente.idade > 5 && paciente.idade < 16) || (paciente.idade > 60 && paciente.idade < 80)){
                prioridade = 1;
            }else{
                prioridade = 2;
            }
            paciente.prioridade = prioridade;
            getchar();

            printf("Que dia é hoje?: \n\t(1)Segunda - (2)Terça - (3)Quarta - (4)Quinta - (5)Sexta - (6)Sabado\n");
            scanf("%d", &input_dia);
            if(input_dia == 1){
                    if(isFull(fila_segunda)){
                        printf("\nInfelizmente Segunda esta lotada.\nTente outro dia\n");
                    }else{
                        adicionar_na_fila(&fila_segunda, paciente);
                        mostrar_fila(fila_segunda);
                    }
            }else if(input_dia == 2){
                 if(isFull(fila_terca)){
                        printf("\nInfelizmente Segunda esta lotada.\nTente outro dia\n");
                    }else{
                        adicionar_na_fila(&fila_terca, paciente);
                        mostrar_fila(fila_terca);
                    }
            }else if(input_dia == 3){
                 if(isFull(fila_quarta)){
                        printf("\nInfelizmente Segunda esta lotada.\nTente outro dia\n");
                    }else{
                        adicionar_na_fila(&fila_quarta, paciente);
                        mostrar_fila(fila_quarta);
                    }
            }else if(input_dia == 4){
                 if(isFull(fila_quinta)){
                        printf("\nInfelizmente Segunda esta lotada.\nTente outro dia\n");
                    }else{
                        adicionar_na_fila(&fila_quinta, paciente);
                        mostrar_fila(fila_quinta);
                    }
            }else if(input_dia == 5){
                 if(isFull(fila_sexta)){
                        printf("\nInfelizmente Segunda esta lotada.\nTente outro dia\n");
                    }else{
                        adicionar_na_fila(&fila_sexta, paciente);
                        mostrar_fila(fila_sexta);
                    }
            }else if(input_dia == 6){
                 if(isFull(fila_sabado)){
                        printf("\nInfelizmente Segunda esta lotada.\nTente outro dia\n");
                    }else{
                        adicionar_na_fila(&fila_sabado, paciente);
                        mostrar_fila(fila_sabado);
                    }
            }
            break;
        default:
            printf("Nao entendi\n");

            break;
        }
    }while(input != 'S');

    printf("\nQue dia bonito... Hoje é segunda :)\n");
    fila_do_dia(fila_segunda);
    printf("\nMais um dia se passou e vc continua linda... Hoje é terca :)\n");
    fila_do_dia(fila_terca);
    printf("\nDeus sabe q vc escuta kpop escondido..... Hoje é quarta :)\n");
    fila_do_dia(fila_quarta);
    printf("\nUndertale é muito bom sabia? Hoje é quinta :)\n");
    fila_do_dia(fila_quinta);
    printf("\nEu queria ta recebendo uns 15k agora.... #Sextou :)\n");
    fila_do_dia(fila_sexta);
    printf("\nTo namorando aquela mina, mas nao sei se ela me namora..... Hoje é sabidu :)\n");
    fila_do_dia(fila_sabado);
    printf("\nDomingo vc nao pode ficar doente ein\n");

    return 0;
}