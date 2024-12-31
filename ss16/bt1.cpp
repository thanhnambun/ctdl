#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* left;
	struct Node	*right;
} Node;

struct Node* createTree(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
};

Node* insertNode(Node* tree , int data) {
	if(tree == NULL) {
		return createTree(data);
	}
	if(data<tree->data) {
		tree->left = insertNode(tree->left,data);
	} else if(data> tree->data) {
		tree->right = insertNode(tree->right,data);
	}
	return tree;
}

typedef struct QueueNode {
	Node*treeNode;
	struct QueueNode*next;
} QueueNode;

typedef struct Queue {
	QueueNode* front;
	QueueNode* rear;
} Queue;

void initQueue(Queue*q) {
	q->front=NULL;
	q->rear = NULL;
}

void enqueue(Queue* q, Node* treeNode) {
	QueueNode* newNode =(QueueNode*)malloc(sizeof(QueueNode));
	newNode->treeNode = treeNode;
	newNode->next = NULL;
	if(q->rear != NULL) {
		q->rear->next = newNode;
	}
	q->rear = newNode;
	if(q->front == NULL) {
		q->front = newNode;
	}
}

QueueNode* dequeue(Queue*q) {
	if(q->front == NULL) return NULL;
	QueueNode* temp = q->front;
	q->front= q->front->next;
	if(q->front == NULL) {
		q->rear = NULL;
	}
	return temp;
}

int isQueueEmpty(Queue* q) {
	return q->front == NULL;
}

void searchLleaf(Node*root) {
	if(root == NULL) return;
	int value;
	Queue q;
	initQueue(&q);
	enqueue(&q,root);
	while(!isQueueEmpty(&q)) {
		QueueNode* current = dequeue(&q);
        Node* treeNode = current->treeNode; 
		if (treeNode->left != NULL) {
            enqueue(&q, treeNode->left);
        }
        if (treeNode->right != NULL) {
            enqueue(&q, treeNode->right);
        }
        value++;
		if(treeNode->left == NULL && treeNode->right == NULL){
			printf("chieu cao cua cay là %d",value);
			return ;
		}
        free(current);
	}
}

int main() {
	Node* tree = NULL;

	tree = insertNode(tree,1);
	tree = insertNode(tree,2);
	tree = insertNode(tree,5);
	tree = insertNode(tree,3);
	tree = insertNode(tree,7);
	
	searchLleaf(tree);

	return 0;

}

