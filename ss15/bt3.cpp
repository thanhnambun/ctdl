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

    for (int i = 0; i < g->V; i++) {
        if (g->adj[current][i] == 1 && !visited[i]) {
            dfsRecursive(g, i, visited);
        }
    }
}

bool isConnected(Graph *g) {
    bool visited[MAX] = {false};

    dfsRecursive(g, 0, visited);

    for (int i = 0; i < g->V; i++) {
        if (!visited[i]) {
            return false; 
        }
    }
    return true;
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

    if (isConnected(&g)) {
        printf("Ð? th? liên thông\n");
    } else {
        printf("Ð? th? không liên thông\n");
    }

    return 0;
}

