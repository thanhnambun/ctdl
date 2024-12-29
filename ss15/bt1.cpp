#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100 

typedef struct {
    int adj[MAX][MAX];
    int V; 
    int E; 
} Graph;

typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, int value) {
    if (q->rear == MAX - 1) {
        printf("Hàng d?i d?y!\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Hàng d?i r?ng!\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}

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
void bfs(Graph *g, int start) {
    bool visited[MAX] = {false};
    Queue q;
    initQueue(&q);

    visited[start] = true;
    enqueue(&q, start);

    printf("Th? t? các d?nh du?c duy?t BFS: ");
    while (!isEmpty(&q)) {
        int current = dequeue(&q);
        printf("%d ", current);

        for (int i = 0; i < g->V; i++) {
            if (g->adj[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                enqueue(&q, i);
            }
        }
    }
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

    bfs(&g, start);

    return 0;
}

