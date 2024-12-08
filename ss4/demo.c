#include<stdio.h>
#include<stdlib.h>

//dinh nghia 1 node
typedef struct Node {
	int data;//phan du lieu cua node
	struct Node* next;//con tro tro den node tiep theo
} Node;

// tao node moi
Node* createNode(int value) {
	//cap phat bo nho
	Node* newNode = (Node*)malloc(sizeof(Node)) ;
	newNode->data = value;
	// gan phan link
	newNode -> next=NULL;
	return newNode;
};

// them phan tu vao dau list
void insertHead(Node**head,int value) {
	// tao node moi
	Node* newNode=createNode(value);
	// tro cai node moi den cai head
	newNode ->next = *head;
	//cap nhat head tro den node moi
	*head = newNode ;
};

// duyet list
void printList(Node *head) {
	Node* temp = head;
	while( temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
	};
	printf("---> NUULL");
};

int main() {
	Node* head = NULL;
	// thêm 1 phan tu vao dau danh sach
//	printf("nhap vao phan tu dau ");
	int value;
//	scanf ("%d",&value);
//
//	insertHead(&head,value);
//
//	printf("danh sach ");
//	printList(head);

	do {
		printf("=============menu=================");
		printf("1.them 1 phan tu vao dau ");
		printf("2.xem danh sach");
		printf("thoat :");
		printf("chon ");

		int choice;
		scanf("%d",&choice);
		switch (choice) {
			case 1:
				printf("nhap vao phan tu dau ");
				scanf ("%d",&value);
				insertHead(&head,value);
				break;

			case 2 :
				printf("danh sach ");
				printList(head);
				break;
			case 3 :
				exit(0);


			default :
				printf("vui long chon lia");
		}
	} while(1==1);

	return 0;

}

