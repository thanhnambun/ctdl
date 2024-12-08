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

void insertAtPosition(Node** head, int position, int value) {
    Node* newNode = createNode(value); 

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* current = *head;
    int currentPos = 1;
    while (current != NULL && currentPos < position - 1) {
        current = current->next;
        currentPos++;
    }

    
    if (current != NULL) {
        newNode->next = current->next;
        current->next = newNode;
    } else {
        printf("Vi tri khong dung");
        free(newNode); 
    }
}

Node* printfLink(Node* head){
	Node* temp = head;
	while( temp != NULL) {
		printf("%d \n",temp->data);
		temp = temp->next;
	};
	printf("---> NULL \n");
}

int main(){
	int n,position,value;
	 printf("vui long nhap \n");
	scanf("%d",&n);
	
	Node* head = creatLink(n);
	
	printf("danh sach luc dau");
	printfLink(head);
	
	printf("vui long nhap vi tri ban muon them \n");
	scanf("%d",&position);
	
	printf("vui long nhap gia tri \n");
	scanf("%d",&value);
	
	insertAtPosition(&head,position,value);
	
	printf("danh sach sau khi them ");
	printfLink(head);
	

	return 0;

}

