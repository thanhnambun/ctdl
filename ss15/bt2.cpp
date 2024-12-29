#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100


typedef struct {
    int adj[MAX][MAX];
    int V; 
    int E;
} Graph;

void initGraph(Graph *g, int V, int E) {
    g->V = V;
    g->E = E;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            g->adj[i][j] = 0;
        }
    }
}

void addEdge(Graph *g, int u, int v) {
    g->adj[u][v] = 1;
    g->adj[v][u] = 1; 
}

void dfsRecursive(Graph *g, int current, bool visited[]) {
    visited[current] = true;
    printf("%d ", current);

    for (int i = 0; i < g->V; i++) {
        if (g->adj[current][i] == 1 && !visited[i]) {
            dfsRecursive(g, i, visited);
        }
    }
}

void dfs(Graph *g, int start) {
    bool visited[MAX] = {false};

    printf("Th? t? các d?nh du?c duy?t DFS: ");
    dfsRecursive(g, start, visited);
    printf("\n");
}

int main() {
    Graph g;
    int V, E;

    printf("Nh?p s? d?nh: ");
    scanf("%d", &V);
    printf("Nh?p s? c?nh: ");
    scanf("%d", &E);

    initGraph(&g, V, E);

    printf("Nh?p các c?nh (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(&g, u, v);
    }

    int start;
    printf("Nh?p d?nh b?t d?u: ");
    scanf("%d", &start);

    dfs(&g, start);

    return 0;
}

