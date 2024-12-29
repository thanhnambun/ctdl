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
}

bool dfsCycleCheck(Graph *g, int current, bool visited[], bool recStack[]) {
    if (!visited[current]) {
        visited[current] = true;
        recStack[current] = true;

        for (int i = 0; i < g->V; i++) {
            if (g->adj[current][i]) {
                if (!visited[i] && dfsCycleCheck(g, i, visited, recStack)) {
                    return true;
                } else if (recStack[i]) {
                    return true;
                }
            }
        }
    }

    recStack[current] = false;
    return false;
}

bool hasCycle(Graph *g) {
    bool visited[MAX] = {false};
    bool recStack[MAX] = {false};

    for (int i = 0; i < g->V; i++) {
        if (!visited[i]) {
            if (dfsCycleCheck(g, i, visited, recStack)) {
                return true;
            }
        }
    }
    return false;
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

    if (hasCycle(&g)) {
        printf("Ð? th? có ch?a chu trình\n");
    } else {
        printf("Ð? th? không ch?a chu trình\n");
    }

    return 0;
}

