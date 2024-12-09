#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Kh�ng d? b? nh?.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode; 
}


Node* createLink(int n) {
    Node* head = NULL;
    Node* tail = NULL;
    int i ;
    for ( i = 0; i < n; i++) {
        int value;
        printf("Vui l�ng nh?p gi� tr? ph?n t? %d: ", i + 1);
        scanf("%d", &value);

        Node* newNode = createNode(value);
        if (head == NULL) {
            head = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
        }
        tail = newNode;
    }
    return head;
}


void changeNode(Node** head, int data, int position) {
    
    Node* temp = *head;
    int currentPos = 1;
    while (temp != NULL && currentPos < position) {
        temp = temp->next;
        currentPos++;
    }

    if (temp == NULL) {
        printf("Kh�ng th? doi t?i v? tr� %d\n", position);
        return;
    }
	temp->data = data;
}


void printList(Node* head) {
    Node* temp = head;
    printf("NULL");
    while (temp != NULL) {
        printf(" <--> %d", temp->data);
        temp = temp->next;
    }
    printf(" <--> NULL\n");
}

int main() {
    int position, value, n;

    printf("Vui l�ng nh?p s? ph?n t?: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("S? ph?n t? kh�ng h?p l?.\n");
        return 1;
    }

    Node* head = createLink(n);

    printf("Danh s�ch li�n k?t ban d?u:\n");
    printList(head);

    printf("Vui l�ng nh?p v? tr� c?n th�m: ");
    scanf("%d", &position);

    if (position <= 0) {
        printf("V? tr� kh�ng h?p l?.\n");
        return 1;
    }

    printf("Nh?p gi� tr?: ");
    scanf("%d", &value);

    changeNode(&head, value, position);

    printf("Danh s�ch li�n k?t sau khi thay doi:\n");
    printList(head);

    return 0;
}

