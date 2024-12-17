#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

Node *adjacencyList[MAX_VERTICES];

int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];

int vertexCount = 0;

void initializeGraph()
{
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        adjacencyList[i] = NULL;
        for (int j = 0; j < MAX_VERTICES; j++)
        {
            adjacencyMatrix[i][j] = 0;
        }
    }
}

void addVertex()
{
    if (vertexCount < MAX_VERTICES)
    {
        vertexCount++;
        printf("da them.\n", vertexCount - 1);
    }
    else
    {
        printf("day.\n");
    }
}

Node *createNode(int v)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int start, int end, int isDirected)
{
    if (start >= vertexCount || end >= vertexCount)
    {
        printf("loiªá.\n");
        return;
    }

    adjacencyMatrix[start][end] = 1;
    if (!isDirected)
    {
        adjacencyMatrix[end][start] = 1;
    }

    Node *newNode = createNode(end);
    newNode->next = adjacencyList[start];
    adjacencyList[start] = newNode;

    if (!isDirected)
    {
        newNode = createNode(start);
        newNode->next = adjacencyList[end];
        adjacencyList[end] = newNode;
    }
}

void displayAdjacencyMatrix()
{
    printf("\n ma tran ke :\n");
    for (int i = 0; i < vertexCount; i++)
    {
        for (int j = 0; j < vertexCount; j++)
        {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

void displayAdjacencyList()
{
    printf("\n danh sach keÅ:\n");
    for (int i = 0; i < vertexCount; i++)
    {
        printf("dinh %d: ", i);
        Node *temp = adjacencyList[i];
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    int choice, start, end, isDirected;

    initializeGraph();

    while (1)
    {
        printf("\n==== MENU ====\n");
        printf("1. them dinh\n");
        printf("2. them canh\n");
        printf("3. hien thi ma tran keÅ\n");
        printf("4. hien thi danh sach keÅ\n");
        printf("5. thoat\n");
        printf("chon: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addVertex();
            break;
        case 2:
            printf("dinh dau : ");
            scanf("%d", &start);
            printf("dinh cuoi: ");
            scanf("%d", &end);
            printf("do thi co huong khong (1: cÛ, 0: khong): ");
            scanf("%d", &isDirected);
            addEdge(start, end, isDirected);
            break;
        case 3:
            displayAdjacencyMatrix();
            break;
        case 4:
            displayAdjacencyList();
            break;
        case 5:
            printf("Tho√°t ch∆∞∆°ng tr√¨nh.\n");
            return 0;
        default:
            printf("loi.\n");
        }
    }

    return 0;
}
