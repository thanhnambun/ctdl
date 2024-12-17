#include <stdio.h>

#define MAX 100  


void degreeUndirected(int graph[MAX][MAX], int vertices) {
    int degree[MAX] = {0}; 
    int maxDegree = 0, maxVertex = 0;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (graph[i][j] == 1) {
                degree[i]++;
            }
        }

        if (degree[i] > maxDegree) {
            maxDegree = degree[i];
            maxVertex = i;
        }
    }

    printf("Ð?nh có b?c l?n nh?t là %d v?i b?c là %d.\n", maxVertex, maxDegree);
}


void degreeDirected(int graph[MAX][MAX], int vertices) {
    int inDegree[MAX] = {0}, outDegree[MAX] = {0}; 
    int totalDegree[MAX] = {0}; 
    int maxDegree = 0, maxVertex = 0;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (graph[i][j] == 1) {
                outDegree[i]++;  
                inDegree[j]++; 
            }
        }
        totalDegree[i] = inDegree[i] + outDegree[i];

        if (totalDegree[i] > maxDegree) {
            maxDegree = totalDegree[i];
            maxVertex = i;
        }
    }

    printf("Ð?nh có t?ng b?c l?n nh?t là %d v?i b?c là %d.\n", maxVertex, maxDegree);
}

int main() {
    int graph[MAX][MAX] = {0};
    int vertices, edges, u, v, isDirected;

    printf("Nh?p s? d?nh và s? c?nh: ");
    scanf("%d %d", &vertices, &edges);

    printf("Ð? th? có hu?ng? (1: Có, 0: Không): ");
    scanf("%d", &isDirected);

    printf("Nh?p các c?nh (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;  
        if (!isDirected) {
            graph[v][u] = 1;  
        }
    }

    if (isDirected) {
        degreeDirected(graph, vertices);
    } else {
        degreeUndirected(graph, vertices);
    }

    return 0;
}

