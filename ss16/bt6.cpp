#include <stdio.h>
#include <stdlib.h>

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

Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

int countNodesGreaterThanX(Node* root, int X) {
    if (root == NULL) return 0;
    int count = 0;
    if (root->data > X) count = 1;
    return count + countNodesGreaterThanX(root->left, X) + countNodesGreaterThanX(root->right, X);
}

int main() {
    Node* root = NULL;
    root = insertNode(root, 4);
    root = insertNode(root, 2);
    root = insertNode(root, 6);
    root = insertNode(root, 1);
    root = insertNode(root, 3);
    root = insertNode(root, 5);
    root = insertNode(root, 7);

    int X = 3;
    int countGreaterThanX = countNodesGreaterThanX(root, X);
    printf(" %d: %d\n", X, countGreaterThanX);

    return 0;
}

