#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int binarySearch(int arr[], int left, int right, int value) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value)
            return mid; 
        if (arr[mid] > value)
            return binarySearch(arr, left, mid - 1, value); 
        return binarySearch(arr, mid + 1, right, value); 
    }
    return -1; 
}


int linearSearch(int arr[], int sizeArr, int value) {
    for (int i = 0; i < sizeArr; i++) {
        if (arr[i] == value) {
            return i; 
        }
    }
    return -1;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, choice, key, result;

    printf("Nh?p s? ph?n t? c?a m?ng: ");
    scanf("%d", &n);

    int arr[n];
    printf("Nh?p c�c ph?n t? c?a m?ng:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\nMenu:\n");
        printf("1. In m?ng ban d?u\n");
        printf("2. S?p x?p m?ng (Insertion Sort)\n");
        printf("3. T�m ki?m tuy?n t�nh\n");
        printf("4. T�m ki?m nh? ph�n\n");
        printf("5. Tho�t\n");
        printf("Nh?p l?a ch?n c?a b?n: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("M?ng hi?n t?i: ");
                printArray(arr, n);
                break;

            case 2:
                insertionSort(arr, n);
                printf("M?ng sau khi s?p x?p: ");
                printArray(arr, n);
                break;

            case 3:
                printf("Nh?p gi� tr? c?n t�m (tuy?n t�nh): ");
                scanf("%d", &key);
                result = linearSearch(arr, n, key);
                if (result != -1) {
                    printf("Ph?n t? %d du?c t�m th?y t?i v? tr� %d (tuy?n t�nh).\n", key, result);
                } else {
                    printf("Ph?n t? %d kh�ng t?n t?i trong m?ng (tuy?n t�nh).\n", key);
                }
                break;

            case 4:
                printf("Nh?p gi� tr? c?n t�m (nh? ph�n): ");
                scanf("%d", &key);
                result = binarySearch(arr, 0, n - 1, key);
                if (result != -1) {
                    printf("Ph?n t? %d du?c t�m th?y t?i v? tr� %d (nh? ph�n).\n", key, result);
                } else {
                    printf("Ph?n t? %d kh�ng t?n t?i trong m?ng (nh? ph�n).\n", key);
                }
                break;

            case 5:
                printf("Tho�t chuong tr�nh.\n");
                break;

            default:
                printf("L?a ch?n kh�ng h?p l?. Vui l�ng th? l?i.\n");
        }
    } while (choice != 5);

    return 0;
}

