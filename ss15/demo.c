#include <stdio.h>

#define V 5
int visted[V] = {0};  // Initialize all to 0
int graph[V][V] = {0};  // Initialize all to 0

void DFS(int v, int n) {
    visted[v] = 1;
    printf("Visited vertex: %d\n", v);  // Print visited vertex
    int i;
    for ( i = 0; i < n; i++) {
        if (visted[i] == 0 && graph[v][i] == 1) {
            DFS(i, n);
        }
    }
}

int main() {
    int n, u, v, start, edges;
    printf("Vui long nhap so dinh:\n");
    scanf("%d", &n);


    printf("Vui long nhap so canh:\n");
    scanf("%d", &edges);

    printf("Nhap cac cap dinh cua canh (u v):\n");
    int i;
    for ( i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        if (u < n && v < n) {
            graph[u][v] = 1;
            graph[v][u] = 1;  
        } else {
            printf("Canh (%d, %d) khong hop le.\n", u, v);
        }
    }

    printf("Nhap dinh bat dau duyet:\n");
    scanf("%d", &start);
   

    DFS(start, n);

    return 0;
}

