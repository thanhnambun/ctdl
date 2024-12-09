#include <stdio.h>

int main() {
    int n;

    do {
        printf("Nh?p s? ph?n t? c?a m?ng (0 < n <= 100): ");
        scanf("%d", &n);
        if (n <= 0 || n > 100) {
            printf("Giá tr? không h?p l?. Vui lòng nh?p l?i.\n");
        }
    } while (n <= 0 || n > 100);

    int array[100];

    printf("Nh?p các ph?n t? c?a m?ng:\n");
    for (int i = 0; i < n; i++) {
        printf("Ph?n t? [%d]: ", i + 1);
        scanf("%d", &array[i]);
    }

    int left = 0, right = n - 1;
    while (left < right) {
        int temp = array[left];
        array[left] = array[right];
        array[right] = temp;

        left++;
        right--;
    }

    printf("M?ng sau khi d?o ngu?c là:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

