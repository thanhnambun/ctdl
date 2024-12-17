#include <stdio.h>
#include <stdlib.h>

#define MAX 100 

void printAdjacencyMatrix(int matrix[MAX][MAX], int vertices) {
    printf("\nMa tr?n k? c?a d? th?:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int adjacencyMatrix[MAX][MAX] = {0}; 
    int vertices, edges;                 
    int u, v;                            

    printf("dinh: ");
    scanf("%d", &vertices);
    printf("canh: ");
    scanf("%d", &edges);

    printf("Nh?p các c?nh (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            adjacencyMatrix[u][v] = 1;  
            adjacencyMatrix[v][u] = 1;  
        } else {
            printf("C?nh không h?p l?! Hãy nh?p l?i.\n");
            i--;  
        }
    }

    printAdjacencyMatrix(adjacencyMatrix, vertices);

    return 0;
}

