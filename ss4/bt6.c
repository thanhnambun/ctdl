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

void deleteNode(Node** head,int n ){	
	if(n == 1){
		Node* temp = *head;
		*head = (*head)->next;
		free(temp);
		printf("da xoa thanh cong");
	};
	Node* current = *head;
	int a =1 ;
	while(current != NULL && a < n-1){
		current = current->next;
		a++;
	};
	if(current == NULL && current->next == NULL){
		printf("vi tri khong hop le \n");
		return;
	}
	Node* temp = current->next;
	current->next = current->next->next;
	free(temp); 
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
	int n, position;
	 printf("vui long nhap \n");
	scanf("%d",&n);
	
	Node* head = creatLink(n);
	
	printf("mang trc khi xoa ");
	printfLink(head);
	
	printf("vui long nhap vi tri can xoa :\n");
	scanf("%d",&position);
	
	deleteNode(&head,position);
	printf("danh sach sau khi xoa la : \n")
	printfLink(head);

	return 0;

}

