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
        printf("Ngan x?p dã d?y!\n");
        return;
    }
    stack->array[++(stack->top)] = value;
}

char pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Ngan x?p r?ng!\n");
        return '\0';
    }
    return stack->array[(stack->top)--];
}

int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int isValidExpression(char* expression) {
    Stack stack;
    init(&stack);
    int length = strlen(expression);
    int i;

    for ( i = 0; i < length; i++) {
        char ch = expression[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(&stack, ch);
        }

        else if (ch == ')' || ch == '}' || ch == ']') {

            if (isEmpty(&stack)) {
                return 0;
            }

            char top = pop(&stack);
            if (!isMatchingPair(top, ch)) {
                return 0;
            }
        }
    }

    return isEmpty(&stack);
}

int main() {
    char expression[MAX];

    printf("Nh?p bi?u th?c: ");
    fgets(expression, MAX, stdin);

    expression[strcspn(expression, "\n")] = '\0';

    if (isValidExpression(expression)) {
        printf("Bi?u th?c h?p l?.\n");
    } else {
        printf("Bi?u th?c không h?p l?.\n");
    }

    return 0;
}

