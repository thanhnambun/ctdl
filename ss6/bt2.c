#include<stdio.h>
#include<stdlib.h>
#define MAX 5

typedef struct Stack {
	int array[MAX];
	int top;
} Stack;

void inital(Stack* stack) {
	stack->top = -1;
}

int isEmpty(Stack* stack) {
	return stack->top == -1;
}

int isFull(Stack* stack) {
	return stack->top >= MAX - 1;
}

void deleteStack(Stack* stack) {
	if(isFull(stack) == 1 ) {
		printf("xin loi da day roi");
		return;
	}
	stack->array[--(stack->top)];
}

void push(Stack* stack, int value) {
	if (isFull(stack)) {
		printf("day \n");
		return;
	}
	stack->array[++(stack->top)] = value;
}

void printfStack(Stack* stack) {
	printf("phan tu cua ngan xep :\n");
	int i ;
	for ( i =stack->top; i >=0 ; i--) {
		printf("%d \n",stack->array[i]);
	};
}

int main() {
	int value, choice;
	Stack stack;
	inital(&stack);

	printf("nhap gia tri ");
	scanf("%d", &value);
	push(&stack, value);
	
	printfStack(&stack);
	
	deleteStack(&stack);
	
	printfStack(&stack);

	return 0;

}

