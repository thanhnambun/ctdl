#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 50

typedef struct Node {
    int priority;
    char data[50]; 
} Node;

typedef struct Queue {
	Node arr[MAX];
	int size;
} Queue;

int isEmpty(Queue *queue) {
	return (queue->size == 0);
}

Queue* intialQueue(){
	Queue* newQueue = (Queue*)malloc(sizeof(Queue));
	newQueue->size =0;
	return newQueue;
};



void enqueue(Queue *queue, const char value, int priority) {
	if (queue->size >= MAX) {
		printf("day\n");
		return;
	}
	
	Node newNode = {priority, ""};
	queue->arr[queue->size++] = newNode;
    strcpy(newNode.data, value);
    
	int i ;
	for(i = queue->size - 1; i > 0; i--) {
		if (queue->arr[i].priority < queue->arr[i - 1].priority) {
            Node temp = queue->arr[i];
            queue->arr[i] = queue->arr[i - 1];
            queue->arr[i - 1] = temp;
        }
	}
}

void printQueue(Queue* pq) {
    printf("hang doi hien tai: ");
    int i;
    for ( i = 0; i < pq->size; i++) {
        printf("(%d, \"%s\") ", pq->arr[i].priority, pq->arr[i].data);
    }
    printf("\n");
}

int main() {
	Queue* pq = intialQueue();

    // Thêm các ph?n t? vào hàng d?i
    enqueue(pq, 2, "Task A");
    enqueue(pq, 1, "Task B");
    enqueue(pq, 3, "Task C");

    // Th?c hi?n dequeue
//    dequeue(pq);
//    dequeue(pq);

	return 0;

}

