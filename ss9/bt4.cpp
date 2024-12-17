#include <stdio.h>
#include <stdlib.h>

#define MAX 100  

typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX - 1) {
        printf("Hàng d?i d?y!\n");
        return;
    }
    if (q->front == -1) q->front = 0;  
    q->rear++;
    q->items[q->rear] = value;
}


int dequeue(Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Hàng d?i r?ng!\n");
        return -1;
    }
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;  
    }
    return item;
}

int adjacencyMatrix[MAX][MAX] = {0};
int visited[MAX];  


void addEdge(int u, int v) {
    adjacencyMatrix[u][v] = 1;
    adjacencyMatrix[v][u] = 1;  
}

void bfs(int startVertex, int vertices) {
    Queue q;
    initQueue(&q);

    visited[startVertex] = 1;
    enqueue(&q, startVertex);

    printf("Th? t? các d?nh du?c duy?t theo BFS: ");

    while (!isEmpty(&q)) {
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);

        for (int i = 0; i < vertices; i++) {
            if (adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1; 
                enqueue(&q, i); 
            }
        }
    }
    printf("\n");
}

int main() {
    int vertices, edges, u, v, startVertex;

    printf("Nh?p s? d?nh và s? c?nh: ");
    scanf("%d %d", &vertices, &edges);

    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }

    printf("Nh?p các c?nh (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("Nh?p d?nh b?t d?u duy?t BFS: ");
    scanf("%d", &startVertex);

    bfs(startVertex, vertices);

    return 0;
}

