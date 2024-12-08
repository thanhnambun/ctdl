#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data ; 
	struct Node * next; 
}Node; 

Node* createNode (int data){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data =data;
	newNode->next =NULL;
	return newNode;
};
 
 Node* createList(int n ){
 	Node* head =NULL;
 	Node* tail =NULL;
 	int i;
 	for(i=0;i<n;i++){
 		int value;
 		printf("nhap gia tri cua phan tu %d : ",i+1);
 		scanf("%d",&value);
 		Node* newNode = createNode(value);
 		if(head == NULL){
 			head = newNode;
		 }else{
		 	tail->next = newNode;
		 };
		 tail = newNode;
	 };
	 return head;
 };
 
void insertHead(Node** head, int value){
	Node* newNode = createNode(value);
	newNode->next = *head;
	*head = newNode;
};

void printList(Node *head) {
	Node* temp = head;
	while( temp != NULL) {
		printf("%d \n",temp->data);
		temp = temp->next;
	};
	printf("---> NULL \n");
};

int main(){
	
	int n , value;
	
	printf(" vui long nhap so phan tu \n");
	scanf("%d",&n);
	
	Node* head =createList(n);
	
	printList(head);
	
	printf("vui long nhap gia tri can chen \n");
	scanf("%d",&value);
	
	insertHead(&head,value);
	
	printf("danh sach sau khi chen la \n");
	
	printList(head);
	
	
	return 0;

}

