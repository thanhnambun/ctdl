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
        printf("Không d? b? nh?.\n");
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
        printf("Vui lòng nh?p giá tr? ph?n t? %d: ", i + 1);
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


void insertRandom(Node** head, int data, int position) {
    Node* newNode = createNode(data);
    if (position == 1) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }

    Node* current = *head;
    int currentPos = 1;
    while (current != NULL && currentPos < position - 1) {
        current = current->next;
        currentPos++;
    }

    if (current == NULL) {
        printf("Không th? thêm t?i v? trí %d\n", position);
        free(newNode);
        return;
    }

    newNode->next = current->next;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
    newNode->prev = current;
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

    printf("Vui lòng nh?p s? ph?n t?: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("S? ph?n t? không h?p l?.\n");
        return 1;
    }

    Node* head = createLink(n);

    printf("Danh sách liên k?t ban d?u:\n");
    printList(head);

    printf("Vui lòng nh?p v? trí c?n thêm: ");
    scanf("%d", &position);

    if (position <= 0) {
        printf("V? trí không h?p l?.\n");
        return 1;
    }

    printf("Nh?p giá tr?: ");
    scanf("%d", &value);

    insertRandom(&head, value, position);

    printf("Danh sách liên k?t sau khi thêm:\n");
    printList(head);

    return 0;
}

