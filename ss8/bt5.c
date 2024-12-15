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

    printf("Chuong tr�nh C�y T�m Ki?m Nh? Ph�n (BST):\n");
    do {
        printf("\nMenu:\n");
        printf("1. Ch�n gi� tr? v�o c�y\n");
        printf("2. T�m ki?m gi� tr?\n");
        printf("3. In c�c ph?n t? theo th? t? tang d?n\n");
        printf("4. Tho�t\n");
        printf("L?a ch?n: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nh?p gi� tr? d? ch�n: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                printf("�� ch�n gi� tr? %d v�o c�y.\n", value);
                break;

            case 2:
                printf("Nh?p gi� tr? c?n t�m ki?m: ");
                scanf("%d", &value);
                if (search(root, value)) {
                    printf("Gi� tr? %d c� trong c�y.\n", value);
                } else {
                    printf("Gi� tr? %d kh�ng c� trong c�y.\n", value);
                }
                break;

            case 3:
                printf("C�c ph?n t? theo th? t? tang d?n: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 4:
                printf("Tho�t chuong tr�nh.\n");
                break;

            default:
                printf("L?a ch?n kh�ng h?p l?. Vui l�ng th? l?i.\n");
        }
    } while (choice != 4);

    return 0;
}

