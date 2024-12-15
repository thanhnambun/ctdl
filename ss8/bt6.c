#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int data;             
    struct Node* left;       
    struct Node* right;      
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
int isBSTUtil(Node* root, int min, int max) {
    if (root == NULL) {
        return 1;  
    }
    if (root->data <= min || root->data >= max) {
        return 0;
    }
    return isBSTUtil(root->left, min, root->data) &&
           isBSTUtil(root->right, root->data, max);
}

int isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}


int main() {

    Node* root = createNode(10);
    root->right = createNode(5);
    root->left = createNode(20);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    if (isBST(root)) {
        printf("dung.\n");
    } else {
        printf("sai.\n");
    }

    return 0;
}

