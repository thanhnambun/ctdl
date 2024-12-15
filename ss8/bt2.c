#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* left;
	struct Node	*right;
}Node;

struct Node* createTree(int data){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
};

Node* insertNode(Node* tree , int data){
	if(tree == NULL){
		return createTree(data);
	}
	if(data<tree->data){
		tree->left = insertNode(tree->left,data);
	}else if(data> tree->data){
		tree->right = insertNode(tree->right,data);
	}
	return tree;
}

typedef struct QueueNode{
	Node*treeNode;
	int level;
	struct QueueNode*next;
}QueueNode;

typedef struct Queue{
	QueueNode* front;
	QueueNode* rear;
}Queue;

void initQueue(Queue*q){
	q->front=NULL;
	q->rear = NULL;
}

void enqueue(Queue* q, Node* treeNode, int level){
	QueueNode* newNode =(QueueNode*)malloc(sizeof(QueueNode));
	newNode->treeNode = treeNode;
	newNode->level = level;
	newNode->next = NULL;
	if(q->rear != NULL){
		q->rear->next = newNode;
	} 
	q->rear = newNode;
	if(q->front == NULL){
		q->front = newNode;
	}
}

QueueNode* dequeue(Queue*q){
	if(q->front == NULL) return NULL;
	QueueNode* temp = q->front;
	q->front= q->front->next;
	if(q->front == NULL){
		q->rear = NULL;
	}
	return temp;
}

int isQueueEmpty(Queue* q) {
    return q->front == NULL;
}

void findLevel2Nodes(Node*root){
	if(root == NULL) return;
    Queue q;
    initQueue(&q);
    enqueue(&q, root, 0);

    printf("dinh lop 2 là :  ");
    while (!isQueueEmpty(&q)) {
        QueueNode* current = dequeue(&q); 
        Node* treeNode = current->treeNode;
        int level = current->level;

        if (level == 2) {
            printf("%d ", treeNode->data);
        }
        if (treeNode->left != NULL) {
            enqueue(&q, treeNode->left, level + 1);
        }
        if (treeNode->right != NULL) {
            enqueue(&q, treeNode->right, level + 1);
        }

        free(current);  
    }
    printf("\n");
}

int main(){
	
	Node* tree = NULL;
	
	tree = insertNode(tree,1);
	tree = insertNode(tree,2);
	tree = insertNode(tree,5);
	tree = insertNode(tree,3);
	tree = insertNode(tree,7);
	
	findLevel2Nodes(tree);

	return 0;

}

