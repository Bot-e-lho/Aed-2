//Miguel Botelho -- M1 -- AED-2

#include <stdio.h>

#define MAX 20

int grafo[MAX][MAX];

void inicializar();
void adicionar(int u, int v, int peso);
void printGrafo(int vertices);

int main() {
    int vertices;
    printf("Informe a quantidade de vertices: ");
    scanf("%d", &vertices);

    if (vertices > MAX) {
        printf("Excede o limite de vertices(Limite atual: %d)\n", MAX);
        return 1;
    }

    inicializar();

    while (1) {
        printf("\n-------------Opcoes-------------\n");
        printf("1- Adicionar aresta\n");
        printf("2- Mostrar grafo\n");
        printf("3- Sair\n");

        int opcao;
        scanf("%d", &opcao);

        if (opcao == 1) {
            int u, v, peso;
            printf("Informe o par de vertices.\nPrimeiro vertice (1 a %d): ", vertices);
            scanf("%d", &u);
            printf("Segundo vertice (1 a %d): ", vertices);
            scanf("%d", &v);
            printf("Informe o peso da aresta: ");
            scanf("%d", &peso);
            adicionar(u, v, peso);
        } else if (opcao == 2) {
            printf("Matriz do grafo:\n");//adjacência
            printGrafo(vertices);
        } else if (opcao == 3) {
            break;
        } else {
            printf("Opcao invalida.\n");
        }
    }

    return 0;
}

void inicializar() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            grafo[i][j] = 0;
        }
    }
}

void adicionar(int u, int v, int peso) {
    if (u >= 1 && u <= MAX && v >= 1 && v <= MAX) {
        grafo[u - 1][v - 1] = peso;
        grafo[v - 1][u - 1] = peso;
    }
    else {
        printf("\nValores invalidos para vertices.\n");
    }
}

void printGrafo(int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", grafo[i][j]);
        }
        printf("\n");
    }
}
