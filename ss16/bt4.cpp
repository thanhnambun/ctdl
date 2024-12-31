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

Node* checkValue(Node* tree , int value){
	if (value == tree->data) {
        printf("Da tim thay %d\n", value);
        return tree;
    } else if (value < tree->data) {
        return checkValue(tree->left, value);
    } else {
        return checkValue(tree->right, value);
    }
    printf("khonn tim thay");
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

