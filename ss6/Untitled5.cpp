#include<stdio.h>
#include<stdlib.h>
#define MAX 5
// cau truc ve ngan xep

typedef struct Stack {
	int array[MAX];
	int top;
};
// khoi tao stack
void inital(Stack* stack) {
	stack->top = -1;
};

int isEmpty(Stack* stack) {
	if(stack->top == -1) {
		return 1;
	}
	return 0;
};
// kiem tra ngan xep day
int isFull(Stack* stack) {
	if(stack->top >= MAX -1) {
		return 1;
	}
	return 0;
};

void push(Stack* stack , int value) {
	if(isFull(stack) == 1) {
		printf("xin loi da day roi");
		return;
	}
	stack->array[++(stack->top)] = value;
}

void deleteStack(Stack* stack){
	if(isFull(stack) == 1 ){
		printf("xin loi da day roi");
		return;
	}
	stack->array[--(stack->top)];
}
int peek(Stack* stack){
	if(isFull(stack) == 1 ){
		printf("xin loi da day roi");
		return -2;
	}
	return stack->top;
}

void printfStack(Stack* stack) {
	for (int i =stack->top; i >=0 ; i--) {
		printf("%d \n",stack->array[i]);
	};
}

int main() {
	int value;
	int choice;
	Stack stack;
	inital(&stack);
	do {
		printf("menu\n");
		printf("0.thoat \n");
		printf("1. them phan tu vao ngan xep \n");
		printf("2. in ra ngan xep \n");
		printf("3.xoa\n");
		printf("moi ban chon \n");
		scanf("%d",&choice);
		switch(choice) {
			case 0:
				exit(0);
			case 1:
				printf("nhap vao gia tri\n");
				scanf("%d",&value);
				push(&stack,value);
				break;
			case 2 :
				printfStack(&stack);
				break;
			case 3: 
				deleteStack(&stack);
				break;	
			default:
				printf("vui llong chon lai \n");
		}
	} while(1==1);
		return 0;

}

