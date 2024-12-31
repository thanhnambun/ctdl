#include <stdio.h>
#include <stdlib.h>

// �?nh nghia c?u tr�c m?t n�t trong c�y nh? ph�n
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// H�m t?o m?t n�t m?i
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int findMaxValue(Node* root) {
    if (root == NULL) {
        return -1; 
    }
    int max = root->data;
    int leftMax = findMaxValue(root->left);
    int rightMax = findMaxValue(root->right);
    if (leftMax > max) max = leftMax;
    if (rightMax > max) max = rightMax;
    return max;
}



int main() {
    Node* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->left = createNode(5);
    root->right->right = createNode(7);

    int maxValue = findMaxValue(root);
    printf("Max value in the tree: %d\n", maxValue);

    return 0;
}

