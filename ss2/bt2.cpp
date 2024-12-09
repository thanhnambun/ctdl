#include <stdio.h>

int main() {
    int n, x, count = 0;
    int array[100];

    do {
        printf("Nh?p s? ph?n t? c?a m?ng (0 < n <= 100): ");
        scanf("%d", &n);
        if (n <= 0 || n > 100) {
            printf("Giá tr? không h?p l?. Vui lòng nh?p l?i.\n");
        }
    } while (n <= 0 || n > 100);

    printf("Nh?p các ph?n t? c?a m?ng:\n");
    for (int i = 0; i < n; i++) {
        printf("Ph?n t? [%d]: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("Nh?p giá tr? x c?n d?m: ");
    scanf("%d", &x);

    for (int i = 0; i < n; i++) {
        if (array[i] == x) {
            count++;
        }
    }

    printf("S? l?n xu?t hi?n c?a %d trong m?ng là: %d\n", x, count);

    return 0;
}

