#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 5

typedef struct Deque {
	int front;
	int rear;
	int size;
	char data[MAX_SIZE][50];
} Deque;

Deque* createDeque() {
	Deque* deque = (Deque*)malloc(sizeof(Deque));
	deque->front = -1;
	deque->rear = -1;
	deque->size = 0;
	return deque;
}

int isEmpty(Deque* deque) {
	return deque->size == 0;
}

int isFull(Deque* deque) {
	return deque->size == MAX_SIZE;
}


void addFront(Deque* deque, const char* data) {
	if (isFull(deque)) {
		printf("Không th? thêm ph?n t?: Hàng d?i dã d?y\n");
		return;
	}
	if (deque->front == -1) {
		deque->front = 0;
		deque->rear = 0;
	} else {
		deque->front = (deque->front - 1 + MAX_SIZE) % MAX_SIZE;
	}
	strcpy(deque->data[deque->front], data);
	deque->size++;
	printf("Thêm ph?n t? vào d?u: \"%s\"\n", data);
	printDeque(deque);
}


void addRear(Deque* deque, const char* data) {
	if (isFull(deque)) {
		printf("Không th? thêm ph?n t?: Hàng d?i dã d?y\n");
		return;
	}
	if (deque->rear == -1) {
		deque->front = 0;
		deque->rear = 0;
	} else {
		deque->rear = (deque->rear + 1) % MAX_SIZE;
	}
	strcpy(deque->data[deque->rear], data);
	deque->size++;
	printf("Thêm ph?n t? vào cu?i: \"%s\"\n", data);
	printDeque(deque);
}


char* removeFront(Deque* deque) {
	if (isEmpty(deque)) {
		printf("Không th? l?y ph?n t?: Hàng d?i r?ng\n");
		return NULL;
	}
	char* data = deque->data[deque->front];
	if (deque->front == deque->rear) {
		deque->front = -1;
		deque->rear = -1;
	} else {
		deque->front = (deque->front + 1) % MAX_SIZE;
	}
	deque->size--;
	printf("L?y ph?n t? ra kh?i d?u: \"%s\"\n", data);
	printDeque(deque);
	return data;
}


char* removeRear(Deque* deque) {
	if (isEmpty(deque)) {
		printf("Không th? l?y ph?n t?: Hàng d?i r?ng\n");
		return NULL;
	}
	char* data = deque->data[deque->rear];
	if (deque->front == deque->rear) {
		deque->front = -1;
		deque->rear = -1;
	} else {
		deque->rear = (deque->rear - 1 + MAX_SIZE) % MAX_SIZE;
	}
	deque->size--;
	printf("L?y ph?n t? ra kh?i cu?i: \"%s\"\n", data);
	printDeque(deque);
	return data;
}


void printDeque(Deque* deque) {
	printf("Hàng d?i hi?n t?i: ");
	if (isEmpty(deque)) {
		printf("R?ng\n");
		return;
	}
	int i = deque->front;
	while (1) {
		printf("\"%s\" ", deque->data[i]);
		if (i == deque->rear) break;
		i = (i + 1) % MAX_SIZE;
	}
	printf("\n");
}

int main() {
	Deque* deque = createDeque();

	int choice;
	do {
		printf("\nMenu:\n");
		printf("1. Thêm ph?n t? vào d?u\n");
		printf("2. Thêm ph?n t? vào cu?i\n");
		printf("3. L?y ph?n t? t? d?u\n");
		printf("4. L?y ph?n t? t? cu?i\n");
		printf("5. In hàng d?i\n");
		printf("6. Thoát\n");
		printf("L?a ch?n c?a b?n: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1: {
				char data[100];
				printf("Nh?p d? li?u: ");
				scanf("%s", data);
				addFront(&deque, data);
				break;
			}
			case 2: {
				char data[100];
				printf("Nh?p d? li?u: ");
				scanf("%s", data);
				addRear(&deque, data);
				break;
			}
			case 3:
				removeFront(&deque);
				break;
			case 4:
				removeRear(&deque);
				break;
			case 5:
				printDeque(&deque);
				break;
			case 6:
				exit(0);
				break;
			default:
				printf("chon lai \n");
		}
	} while (1);

	return 0;
}

