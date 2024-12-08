#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node ;

Node* createNode (int data){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data =data;
	newNode->next =NULL;
	return newNode;
};

Node*  creatLink (int n ){
	Node* head = NULL;
	Node* tail =NULL;
	int i;
	for(i=0;i<n;i++){
		int value;
		printf("vui ;òng nh?p gia tri phan tu %d : ",i+1);
		scanf("%d",&value);
		Node* newNode = createNode(value);
		if(head == NULL){
			head = newNode;
		}else{
			tail->next = newNode;
		}
		tail=newNode;
	}	
	return head;
};

void search(Node* head ,int n){
	Node* current = head;
	int fount = 1;
	while(current != NULL){
		if (current->data == n ){
			printf("%d",fount);
			break;		
		}
		current = current->next;
		fount++; 
	};
	return -1;
};
Node* printfLink(Node* head){
	Node* temp = head;
	while( temp != NULL) {
		printf("%d \n",temp->data);
		temp = temp->next;
	};
	printf("---> NULL \n");
}

int main(){
	int n,value;
	printf("vui long nhap \n");
	scanf("%d",&n);
	
	Node* head = creatLink(n);
	
	printf("danh sach mang  ");
	printfLink(head);
	
	printf("vui long nhap gia tri can tim ");
	scanf("%d",&value);
	search(head,value);
	

	return 0;

}

