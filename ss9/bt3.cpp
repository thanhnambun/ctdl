#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjacencyList[MAX];
int visited[MAX];
int recStack[MAX];

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdgeDirected(int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adjacencyList[u];
    adjacencyList[u] = newNode;
}

int dfsCycleDirected(int vertex) {
    visited[vertex] = 1;
    recStack[vertex] = 1;

    Node* temp = adjacencyList[vertex];
    while (temp != NULL) {
        int neighbor = temp->vertex;
        if (!visited[neighbor] && dfsCycleDirected(neighbor)) {
            return 1; 
        } else if (recStack[neighbor]) {
            return 1; 
        }
        temp = temp->next;
    }

    recStack[vertex] = 0; 
    return 0;
}

int isCyclicDirected(int vertices) {
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            if (dfsCycleDirected(i)) {
                return 1; 
            }
        }
    }
    return 0; 
}

int main() {
    int vertices, edges, u, v;

    printf("Nh?p s? d?nh và s? c?nh: ");
    scanf("%d %d", &vertices, &edges);

    for (int i = 0; i < vertices; i++) {
        adjacencyList[i] = NULL;
    }

    printf("Nh?p các c?nh (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdgeDirected(u, v);
    }

    if (isCyclicDirected(vertices)) {
        printf("co chu ki .\n");
    } else {
        print("khong chu ki.\n");
    }

    return 0;
}

