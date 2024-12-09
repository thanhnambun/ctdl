#include <stdio.h>

int main() {
    int n, i, maxValue;
    int array[100];

    
    do {
        printf("Nh?p s? ph?n t? c?a m?ng (0 < n <= 100): ");
        scanf("%d", &n);
        if (n <= 0 || n > 100) {
            printf("Giá tr? không h?p l?. Vui lòng nh?p l?i.\n");
        }
    } while (n <= 0 || n > 100);


    printf("Nh?p các ph?n t? c?a m?ng:\n");
    for (i = 0; i < n; i++) {
        printf("Ph?n t? [%d]: ", i + 1);
        scanf("%d", &array[i]);
    }

    maxValue = array[0]; 
    for (i = 1; i < n; i++) {
        if (array[i] > maxValue) {
            maxValue = array[i];
        }
    }

    printf("Ph?n t? l?n nh?t trong m?ng là: %d\n", maxValue);

    return 0;
}

