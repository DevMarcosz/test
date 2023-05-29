#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define NUM_ELEVADORES 5
#define NUM_ANDARES 30
#define NUM_CORREDORES 3
#define GASTO_ENERGIA 10

typedef struct {
    int andar;
    int corredor;
    int emMovimento;
    int consumiuEnergia;
} Elevador;

void inicializarElevadores(Elevador elevadores[]) {
    int i;
    srand(time(NULL));  // Inicializar semente para geração de números aleatórios
    for (i = 0; i < NUM_ELEVADORES; i++) {
        elevadores[i].andar = rand() % NUM_ANDARES + 1;
        elevadores[i].corredor = rand() % NUM_CORREDORES + 1;
        elevadores[i].emMovimento = 0;
        elevadores[i].consumiuEnergia = 0;
    }
}

int proximoElevador(Elevador elevadores[], int andarOrigem, int andarDestino, int corredorOrigem, int corredorDestino) {
    int i, minGasto = abs(elevadores[0].andar - andarOrigem) + abs(andarOrigem - andarDestino) + abs(elevadores[0].corredor - corredorOrigem) + abs(corredorOrigem - corredorDestino);
    int index = 0;
    for (i = 1; i < NUM_ELEVADORES; i++) {
        int gasto = abs(elevadores[i].andar - andarOrigem) + abs(andarOrigem - andarDestino) + abs(elevadores[i].corredor - corredorOrigem) + abs(corredorOrigem - corredorDestino);
        if (gasto < minGasto || (gasto == minGasto && elevadores[i].consumiuEnergia < elevadores[index].consumiuEnergia)) {
            minGasto = gasto;
            index = i;
        }
    }
    return index;
}

void moverElevador(Elevador* elevador, int andarDestino, int corredorDestino) {
    elevador->emMovimento = 1;
    int passosAndar = abs(elevador->andar - andarDestino);
    int passosCorredor = abs(elevador->corredor - corredorDestino);
    int passosTotais = passosAndar + passosCorredor;

    for (int passo = 1; passo <= passosTotais; passo++) {
        if (passo <= passosAndar) {
            if (andarDestino > elevador->andar) {
                elevador->andar++;
            } else {
                elevador->andar--;
            }
        } else {
            if (corredorDestino > elevador->corredor) {
                elevador->corredor++;
            } else {
                elevador->corredor--;
            }
        }

        system("clear");

        imprimirStatusPredio(elevador);

        
        sleep(3);
    }

    elevador->consumiuEnergia += GASTO_ENERGIA * passosTotais;
    elevador->emMovimento = 0;
}

void solicitarElevador(Elevador elevadores[]) {
    int andarOrigem, andarDestino, corredorOrigem, corredorDestino;
    printf("Digite o andar de origem: ");
    scanf("%d", &andarOrigem);
    printf("Digite o andar de destino: ");
    scanf("%d", &andarDestino);
    printf("Digite o corredor de origem: ");
    scanf("%d", &corredorOrigem);
    printf("Digite o corredor de destino: ");
    scanf("%d", &corredorDestino);

    printf("Solicitação recebida no andar %d, corredor %d.\n", andarOrigem, corredorOrigem);
    int elevadorIndex = proximoElevador(elevadores, andarOrigem, andarDestino, corredorOrigem, corredorDestino);
    printf("Elevador %d alocado para atender a solicitação.\n", elevadorIndex + 1);
    moverElevador(&elevadores[elevadorIndex], andarOrigem, corredorOrigem);
    printf("Elevador %d chegou ao andar %d, corredor %d.\n", elevadorIndex + 1, elevadores[elevadorIndex].andar, elevadores[elevadorIndex].corredor);
    moverElevador(&elevadores[elevadorIndex], andarDestino, corredorDestino);
    printf("Elevador %d chegou ao andar %d, corredor %d.\n", elevadorIndex + 1, elevadores[elevadorIndex].andar, elevadores[elevadorIndex].corredor);
}

void imprimirStatusPredio(Elevador elevadores[]) {
    int andar, corredor;
    for (andar = NUM_ANDARES; andar >= 1; andar--) {
        for (corredor = 1; corredor <= NUM_CORREDORES; corredor++) {
            int i;
            int elevadorPresente = 0;
            for (i = 0; i < NUM_ELEVADORES; i++) {
                if (elevadores[i].andar == andar && elevadores[i].corredor == corredor) {
                    printf("E%d ", i + 1);
                    elevadorPresente = 1;
                    break;
                }
            }
            if (!elevadorPresente) {
                printf("- ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int calcularEnergiaTotal(Elevador elevadores[]) {
    int i, energiaTotal = 0;
    for (i = 0; i < NUM_ELEVADORES; i++) {
        energiaTotal += elevadores[i].consumiuEnergia;
    }
    return energiaTotal;
}

int main() {
    Elevador elevadores[NUM_ELEVADORES];
    int opcao;

    inicializarElevadores(elevadores);

    do {
        printf("----- MENU -----\n");
        printf("1. Solicitar elevador\n");
        printf("2. Imprimir status do prédio\n");
        printf("3. Calcular energia total\n");
        printf("4. Sair\n");
        printf("Digite sua opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                solicitarElevador(elevadores);
                break;
            case 2:
                imprimirStatusPredio(elevadores);
                break;
            case 3: {
                int energiaTotal = calcularEnergiaTotal(elevadores);
                printf("Energia total consumida: %d\n", energiaTotal);
                break;
            }
            case 4:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida. Por favor, tente novamente.\n");
        }

        printf("\n");
    } while (opcao != 4);

    return 0;
}
