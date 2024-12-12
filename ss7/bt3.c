#include <stdio.h>
#include <stdlib.h>

#define MAX 100  


typedef struct {
    int items[MAX];
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
    if (q->rear == MAX - 1) {
        printf("day.\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
    printf("da them.\n", value);
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("rong.\n");
        return -1;
    }
    int value = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    printf("da xoa.\n", value);
    return value;
}

int main() {
    Queue q;
    initializeQueue(&q);

    if (isEmpty(&q)) {
        printf("rong.\n");
    }

    enqueue(&q, 10);
    printf("check %s\n", isEmpty(&q) ? "rong" : "Không rong");

    dequeue(&q);
    printf("check? %s\n", isEmpty(&q) ? "rong" : "Không rong");

    return 0;
}

