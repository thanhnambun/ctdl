#include <stdio.h>
#include <stdlib.h>
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

void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("day \n");
        return;
    }
    stack->array[++(stack->top)] = value; 
}

void printStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("rong !\n");
        return;
    }
    printf("phan tu cua ngan xep :\n");
    int i ;
    for (i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->array[i]);
    }
}

int main() {
    int value, choice;
    Stack stack; 
    inital(&stack); 

    do {
        printf("\n--- MENU ---\n");
        printf("0. Thoát\n");
        printf("1. Thêm ph?n t? vào ngan x?p\n");
        printf("2. In ra ngan x?p\n");
        printf("L?a ch?n c?a b?n: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0: 
                printf("Chuong trình ket thúc.\n");
                exit(0);
            case 1: 
                printf("nhap gia tri ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2: 
                printStack(&stack);
                break;
            default:
                printf("L?a ch?n không h?p l?, vui lòng th? l?i!\n");
        }
    } while (1);

    return 0;
}

