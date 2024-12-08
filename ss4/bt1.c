#include<stdio.h>
#include<stdlib.h>

// b1 dinh nghia ham
typedef struct Node{
	int data;
	struct Node *next;
}Node; 

// b2 vt ham them node 
Node* createNode(int data){
	// khai báo 1 con tro co kieu node de tro den 1 con tro 
	// ham maloc(sizeof(Node)) la ham cap phap bo nho cho con tro 
	// ham maloc chi tra ve void nen ta phai ep kieu nó ve dang con tro node 
	Node* newNode = (Node*)malloc(sizeof(Node));
	// sau khi minh cap phat bo nho xong mk check xem du bo nho de tao node moi o
	if(newNode == NULL){
		printf("khong du bo nho de minh tao node moi \n");
		exit(1);
	};
	// sau khi kiem tra xong minh se bat dau gan gia tri cho node 
	newNode->data = data;
	newNode->next = NULL;
	return newNode; 
};

//b3 vt ham tao node tu n phan tu 

Node * createLink(int n){
	Node* head = NULL;
	Node* tail = NULL;
	int i ;
	for(i = 0 ; i < n; i++){
		int value;
		printf("vui long nhap gia tri cho phan tu %d : ",i+1);
		scanf("%d",&value);
		Node * newNode = createNode(value);
		if(head == NULL){
			head = newNode ;
		}else{
			tail->next = newNode ;
		};
		tail = newNode;
	};
	return head;	
};

// vt ham duyet va in cac nut 
void printLink (Node* head){
	printf("danh sach lien ket là \n");
	while(head !=NULL){
		printf("%d",head->data);
		head = head->next;
	};
	printf("NULL \n");	
};

// vt ham giai phong 
void freeLink(Node* head){
	Node* temp;
	while(head != NULL){
		temp = head;
		head = head->next;
		free(temp);
	};
};

int main(){
	int n ;
	
	printf("nhap so luong phan tu \n");
	scanf("%d",&n);
	
	Node* head = createLink(n);

    printLink(head);

    freeLink(head);
	
	return 0;

}

