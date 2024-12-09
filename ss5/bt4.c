#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;


Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Không th? c?p phát b? nh?.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node* creatLink(int n) {
    Node* head = NULL;
    Node* tail = NULL;
    int i;
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


int countNodes(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
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
    int n;

    printf("Vui lòng nh?p s? ph?n t?: ");
    scanf("%d", &n);

    Node* head = creatLink(n);

    printf("Danh sách ban d?u:\n");
    printList(head);


    int count = countNodes(head);
    printf("S? lu?ng ph?n t? trong danh sách: %d\n", count);

    return 0;
}

