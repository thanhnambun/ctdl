#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Graph
{
    Node *adjList[MAX];
    int visited[MAX];
    int vertices;
} Graph;
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void initGraph(Graph *graph, int vertices)
{
	int i;
    graph->vertices = vertices;
    for (i = 0; i < vertices; i++)
    {
        graph->adjList[i] = NULL;
        graph->visited[i] = 0;
    }
}
void addEdge(Graph *graph, int src, int dest)
{
    Node *newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}
void DFS(Graph *graph, int vertex)
{
    printf("%d ", vertex);
    graph->visited[vertex] = 1;
    Node *adjNode = graph->adjList[vertex];
    while (adjNode != NULL)
    {
        int adjVertex = adjNode->data;
        if (graph->visited[adjVertex] == 0)
        {
            DFS(graph, adjVertex);
        }
        adjNode = adjNode->next;
    }
}
void BFS(Graph *graph, int start)
{
    int queue[MAX], front = 0, rear = 0;
    graph->visited[start] = 1;
    queue[rear++] = start;
    while (front < rear)
    {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);
        Node *adjNode = graph->adjList[currentVertex];
        while (adjNode != NULL)
        {
            int adjVertex = adjNode->data;
            if (graph->visited[adjVertex] == 0)
            {
                graph->visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            adjNode = adjNode->next;
        }
    }
}
int main()
{
    Graph graph;
    int vertices, edges, src, dest, i;
    printf("Nh?p s? lu?ng d?nh và s? lu?ng c?nh: ");
    scanf("%d %d", &vertices, &edges);
    initGraph(&graph, vertices);
    printf("Nh?p các c?nh (m?i c?nh g?m 2 d?nh):\n");
    for (i = 0; i < edges; i++)
    {
        scanf("%d %d", &src, &dest);
        addEdge(&graph, src, dest);
    }
    printf("\nDuy?t d? th? b?ng DFS:\n");
    for (i = 0; i < vertices; i++)
    {
        graph.visited[i] = 0;
    }
    DFS(&graph, 0);
    printf("\n\nDuy?t d? th? b?ng BFS:\n");
    for (i = 0; i < vertices; i++)
    {
        graph.visited[i] = 0;
    }
    BFS(&graph, 0);
    return 0;
}
