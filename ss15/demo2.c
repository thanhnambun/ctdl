#include <stdio.h>
#include <stdlib.h>

#define V 5

typedef struct Graph {
    int v;
    int adj[V][V];
}Graph;

void init_graph(Graph*g, int v, int adj){
    g->v = v;
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            g->adj[i][j] = 0;
        }
    }
}

void add_edge(Graph*g, int src, int dest){
    g->adj[src][dest] = 1;
    g->adj[dest][src] = 1;
}

typedef struct Queue{
    int items[V];
    int front, rear;
}Queue;

void init_queue(Queue* q){
    q->front = -1;
    q->rear = -1;
}

int is_empty(Queue* q){
    return (q->front == -1 && q->rear == -1);
}

void add_queue(Queue *q, int value)
{
    if(q->rear == V-1){
        printf("Queue is full\n");
        return;
    }
    if(q->front == -1){
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

int deque_queue(Queue *q){
    if (q->rear == V - 1)
    {
        printf("Queue is full\n");
        return;
    }
    return q->items[(q->front)++];
}

void BFS(Graph* g, int start){
    int visited[V] = {0};
    Queue q;
    init_queue(&q);
    visited[start] =1;
    add_queue(&q, start);
    while(!is_empty(&q)){
        int u = deque_queue(&q);
        printf("%d ", u);
        for(int v=0; v<g->v; v++){
            if(!visited[v] && g->adj[u][v]){
                visited[v] = 1;
                add_queue(&q, v);
            }
        }
    }
}
int main(){
    Graph g;
    int v = 5;
    init_graph(&g, v, 1);
    add_edge(&g, 0, 1);
    add_edge(&g, 0, 4);
    add_edge(&g, 1, 2);
    add_edge(&g, 1, 3);
    add_edge(&g, 1, 4);
    BFS(&g,0);

    return 0;
}