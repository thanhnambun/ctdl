#include <stdio.h>

int main() {
    int n, x, count = 0;
    int array[100];

    do {
        printf("Nh?p s? ph?n t? c?a m?ng (0 < n <= 100): ");
        scanf("%d", &n);
        if (n <= 0 || n > 100) {
            printf("Gi� tr? kh�ng h?p l?. Vui l�ng nh?p l?i.\n");
        }
    } while (n <= 0 || n > 100);

    printf("Nh?p c�c ph?n t? c?a m?ng:\n");
    for (int i = 0; i < n; i++) {
        printf("Ph?n t? [%d]: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("Nh?p gi� tr? x c?n d?m: ");
    scanf("%d", &x);

    for (int i = 0; i < n; i++) {
        if (array[i] == x) {
            count++;
        }
    }

    printf("S? l?n xu?t hi?n c?a %d trong m?ng l�: %d\n", x, count);

    return 0;
}

