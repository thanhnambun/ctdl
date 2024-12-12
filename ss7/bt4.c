#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  


typedef struct {
    int items[MAX_SIZE];
    int front; 
    int rear; 
} Queue;

void initializeQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    return (q->front == -1);
}


void enqueue(Queue *q, int value) {
    if (q->rear == MAX_SIZE - 1) {
        printf("day.\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0; 
    }
    q->rear++;
    q->items[q->rear] = value;
    printf("Ðã thêm %d .\n", value);
}


int peek(Queue *q) {
    if (isEmpty(q)) {
        printf("rong.\n");
        return -1;
    }
    return q->items[q->front];
}


int main() {
    Queue q;
    initializeQueue(&q);

    if (isEmpty(&q)) {
        printf("rong.\n");
    }

    enqueue(&q, 10);
    printf("%d\n", peek(&q));


    initializeQueue(&q);  
    printf("%d\n", peek(&q));  

    return 0;
}

