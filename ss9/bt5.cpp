#include <stdio.h>
#include <limits.h>

#define MAX 100   
#define INF INT_MAX  

int minDistance(int distance[], int visited[], int vertices) {
    int min = INF, min_index = -1;
    for (int v = 0; v < vertices; v++) {
        if (!visited[v] && distance[v] <= min) {
            min = distance[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int graph[MAX][MAX], int vertices, int source) {
    int distance[MAX];
    int visited[MAX];

    for (int i = 0; i < vertices; i++) {
        distance[i] = INF; 
        visited[i] = 0;   
    }
    distance[source] = 0;

    for (int count = 0; count < vertices - 1; count++) {
        int u = minDistance(distance, visited, vertices);
        visited[u] = 1; 
        
        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && graph[u][v] && distance[u] != INF && distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }

    printf("\nKho?ng cách t? d?nh ngu?n %d d?n các d?nh:\n", source);
    for (int i = 0; i < vertices; i++) {
        if (distance[i] == INF) {
            printf("Ð?nh %d: Không th? di t?i\n", i);
        } else {
            printf("Ð?nh %d: %d\n", i, distance[i]);
        }
    }
}

int main() {
    int graph[MAX][MAX];
    int vertices, edges, u, v, w, source;

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            graph[i][j] = 0; 
        }
    }

    printf("Nh?p s? d?nh và s? c?nh: ");
    scanf("%d %d", &vertices, &edges);

    printf("Nh?p các c?nh và tr?ng s? (u v w):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; 
    }

    printf("Nh?p d?nh ngu?n: ");
    scanf("%d", &source);

    // Ch?y thu?t toán Dijkstra
    dijkstra(graph, vertices, source);

    return 0;
}

