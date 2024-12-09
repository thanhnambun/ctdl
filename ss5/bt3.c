#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
}Node;

Node* createNode (int value){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
};

Node* creatLink(int n) {
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

void deleteNode(Node** head){
	if(head==NULL){
		printf("khong the xoa ");
		return;
	}
	Node* temp = *head;
	
	if(temp->next == NULL){
		*head = NULL;
		free(temp);
		return;
	}
	
	while (temp != NULL ){
		temp = temp->next;
	}
	temp->next->prev = NULL;
	free(temp);
};

void printList(Node* head) {
    Node* temp = head;
    printf("NULL");
    while (temp != NULL) {
        printf(" <--> %d", temp->data);
        temp = temp->next;
    }
    printf(" <--> NULL\n");
}

int main(){
	 int n;

    printf("Vui l�ng nh?p s? ph?n t?: ");
    scanf("%d", &n);

    Node* head = creatLink(n);

    printf("Danh s�ch ban d?u:\n");
    printList(head);

    printf("X�a n�t cu?i c�ng...\n");
    deleteNode(&head);

    printf("Danh s�ch sau khi x�a n�t cu?i:\n");
    printList(head);

	return 0;

}

