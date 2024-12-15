#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
}Node;

struct Node* createNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

Node* insertNode(Node* tree , int data){
	if(tree == NULL){
		return createNode(data);
	}
	if(data<tree->data){
		tree->left = insertNode(tree->left,data);
	}else if(data> tree->data){
		tree->right = insertNode(tree->right,data);
	}
	return tree;
}

void preorderTraversal(Node* node){
	if(node!=NULL){
		printf("%d ",node->data);
		preorderTraversal(node->left);
		preorderTraversal(node->right);
	}
}

void inorder(Node* node){
	if(node!=NULL){
		inorder(node->left);
		printf("%d ",node->data);
		inorder(node->right);
	}
}

void postorder(Node*node){
	if(node!=NULL){
		postorder(node->left);
		postorder(node->right);
		printf("%d ",node->data);
	}
}

int main(){
	Node* tree = NULL;
	
	tree = insertNode(tree,1);
	tree = insertNode(tree,2);
	tree = insertNode(tree,5);
	tree = insertNode(tree,3);
	tree = insertNode(tree,7);
	
	printf("tien thu tu la: ");
	preorderTraversal(tree);
	printf("trung thu tu la: ");
	inorder(tree);
	printf("hau thu tu la: ");
	postorder(tree);
	return 0;

}
