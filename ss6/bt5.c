#include <stdio.h>
#include <string.h>
#define MAX 100 

typedef struct Stack {
    char array[MAX];
    int top;
} Stack;

void init(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}


void push(Stack* stack, char value) {
    if (isFull(stack)) {
        printf("day\n");
        return;
    }
    stack->array[++(stack->top)] = value;
}

char pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Ngan x?p r?ng, không th? l?y ký t?!\n");
        return '\0'; 
    }
    return stack->array[(stack->top)--];
}

void reverseString(char* str) {
    Stack stack;
    init(&stack);
    int len = strlen(str);
    int i;

    for ( i = 0; i < len; i++) {
        push(&stack, str[i]);
    }
    
    for ( i = 0; i < len; i++) {
        str[i] = pop(&stack);
    }
}

int main() {
    char str[MAX];

    printf("Nhap: ");
    fgets(str, MAX, stdin);

    str[strcspn(str, "\n")] = '\0';

    reverseString(str);

    printf("Chuoi sau khi dao nguoc: %s\n", str);

    return 0;
}

