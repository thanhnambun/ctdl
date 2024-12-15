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



int search(Node* root, int value) {
    if (root == NULL) {
        return 0; 
    }
    if (root->data == value) {
    	printf("fount");
        return 1;  
    } else if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
    printf("not found");
}

int main() {
	int value;
	Node* tree = NULL;

	tree = insertNode(tree,1);
	tree = insertNode(tree,2);
	tree = insertNode(tree,5);
	tree = insertNode(tree,3);
	tree = insertNode(tree,7);

	printf("nhap gia tri can tim kiem : ");
	scanf("%d",&value);

	search(tree,value);

	return 0;

}

