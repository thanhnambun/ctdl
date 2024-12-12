#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct Queue {
    int array[MAX];
    int front;
    int rear;
} Queue;

void initalQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(Queue *queue) {
    return (queue->front == -1);
}

int isFull(Queue *queue) {
    return (queue->rear == MAX - 1);
}

void enqueue(Queue *queue, int value) {
    if (isFull(queue)) {
        printf("day\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear++;
    queue->array[queue->rear] = value;
    printf("them: %d\n", value);
}

void dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("rong\n");
        return;
    }
    printf("xoa: %d\n", queue->array[queue->front]);
    queue->front++;
    if (queue->front > queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    }
}

void printQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("rong\n");
        return;
    }
    printf("Queue: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

int main() {
    Queue queue;
    initalQueue(&queue);
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("0. Exit\n");
        printf("1. them\n");
        printf("2. xoa\n");
        printf("3.in\n");
        printf("chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("thoat...\n");
                break;
            case 1:
                printf("nhap: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;
            case 2:
                dequeue(&queue);
                break;
            case 3:
                printQueue(&queue);
                break;
            default:
                printf("vui long chon lai.\n");
        }
    } while (choice != 0);

    return 0;
}

