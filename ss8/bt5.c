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
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

int search(Node* root, int value) {
    if (root == NULL) {
        return 0; 
    }
    if (root->data == value) {
        return 1;  
    } else if (value < root->data) {
        
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}


void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);  
        printf("%d ", root->data);    
        inorderTraversal(root->right); 
    }
}

int main() {
    Node* root = NULL;  
    int choice, value;

    printf("Chuong trình Cây Tìm Ki?m Nh? Phân (BST):\n");
    do {
        printf("\nMenu:\n");
        printf("1. Chèn giá tr? vào cây\n");
        printf("2. Tìm ki?m giá tr?\n");
        printf("3. In các ph?n t? theo th? t? tang d?n\n");
        printf("4. Thoát\n");
        printf("L?a ch?n: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nh?p giá tr? d? chèn: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                printf("Ðã chèn giá tr? %d vào cây.\n", value);
                break;

            case 2:
                printf("Nh?p giá tr? c?n tìm ki?m: ");
                scanf("%d", &value);
                if (search(root, value)) {
                    printf("Giá tr? %d có trong cây.\n", value);
                } else {
                    printf("Giá tr? %d không có trong cây.\n", value);
                }
                break;

            case 3:
                printf("Các ph?n t? theo th? t? tang d?n: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 4:
                printf("Thoát chuong trình.\n");
                break;

            default:
                printf("L?a ch?n không h?p l?. Vui lòng th? l?i.\n");
        }
    } while (choice != 4);

    return 0;
}

