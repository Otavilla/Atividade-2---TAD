#include <stdio.h>
#include <stdlib.h>

#define MAX_TAMANHO 20

typedef struct {
    int elementos[MAX_TAMANHO];
    int tamanho;
} Conjunto;

void criarConjuntoVazio(Conjunto *conjunto) {
    conjunto->tamanho = 0;
}

void lerConjunto(Conjunto *conjunto) {
    char num[10];
    printf("Digite os elementos do conjunto (0 para terminar): \n");
    conjunto->tamanho = 0;
    while (fgets(num, sizeof(num), stdin) != NULL && conjunto->tamanho < MAX_TAMANHO) {
        int n;
        if (sscanf(num, "%d", &n) == 1) {
            if (n == 0) {
                break;
            }
            conjunto->elementos[conjunto->tamanho++] = n;
        }
    }
}

void uniao(Conjunto *conjunto1, Conjunto *conjunto2, Conjunto *resultado) {
    int i, j, k = 0;
    criarConjuntoVazio(resultado);
    for (i = 0; i < conjunto1->tamanho; i++) {
        resultado->elementos[k++] = conjunto1->elementos[i];
    }
    for (i = 0; i < conjunto2->tamanho; i++) {
        int found = 0;
        for (j = 0; j < conjunto1->tamanho; j++) {
            if (conjunto2->elementos[i] == conjunto1->elementos[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            resultado->elementos[k++] = conjunto2->elementos[i];
        }
    }
    resultado->tamanho = k;
}

void interseccao(Conjunto *conjunto1, Conjunto *conjunto2, Conjunto *resultado) {
    int i, j, k = 0;
    criarConjuntoVazio(resultado);
    for (i = 0; i < conjunto1->tamanho; i++) {
        for (j = 0; j < conjunto2->tamanho; j++) {
            if (conjunto1->elementos[i] == conjunto2->elementos[j]) {
                resultado->elementos[k++] = conjunto1->elementos[i];
                break;
            }
        }
    }
    resultado->tamanho = k;
}

void imprimirConjuntos(Conjunto *conjunto) {
    for (int i = 0; i < conjunto->tamanho; i++) {
        printf("%d\n", conjunto->elementos[i]);
    }
    printf("\n");
}

int main() {
    Conjunto conjunto1, conjunto2, resultado;
    int option;

    while (1) {
        printf("1. Criar um conjunto vazio\n");
        printf("2. Ler os dados de um conjunto\n");
        printf("3. Fazer a uniao de dois conjuntos\n");
        printf("4. Fazer a intersecao de dois conjuntos\n");
        printf("5. Imprimir os conjuntos\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: \n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                criarConjuntoVazio(&conjunto1);
                criarConjuntoVazio(&conjunto2);
                criarConjuntoVazio(&resultado);
                printf("Conjuntos criados vazios.\n\n");
                break;
            case 2:
               printf("Digite os elementos do primeiro conjunto: \n");
                lerConjunto(&conjunto1);
                printf("Digite os elementos do segundo conjunto: \n");
                lerConjunto(&conjunto2);
                break;
            case 3:
                uniao(&conjunto1, &conjunto2, &resultado);
                if (resultado.tamanho == 0) {
                    printf("Os conjuntos estão vazios.\n\n");
                } else {
                    printf("União dos conjuntos: \n");
                    imprimirConjuntos(&resultado);
                }
                break;
            case 4:
                interseccao(&conjunto1, &conjunto2, &resultado);
                if (resultado.tamanho == 0) {
                    printf("Não ha interseccao.\n\n");
                } else {
                printf("Intersecao dos conjuntos: \n");
                imprimirConjuntos(&resultado);
                }
                break;
            case 5:
                if (resultado.tamanho == 0) {
                    printf("Os conjuntos estão vazios.\n\n");
                } else {
                printf("Primeiro conjunto: \n");
                imprimirConjuntos(&conjunto1);
                printf("Segundo conjunto: \n");
                imprimirConjuntos(&conjunto2);
                }
                break;
            case 6:
                exit(0);
            default:
                printf("Opcao invalida.\n");
        }
    }

    return 0;
}
