#include <stdio.h>

int binarySearch(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] > target) {
            return binarySearch(arr, left, mid - 1, target);
        }

        return binarySearch(arr, mid + 1, right, target);
    }

    return -1;
}

int main() {
    int n, target;
    
    printf("Vui lòng nh?p s? lu?ng ph?n t? c?a m?ng: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("S? lu?ng ph?n t? ph?i l?n hon 0.\n");
        return 1;
    }

    int arr[n];

    printf("Nh?p các ph?n t? c?a m?ng (theo th? t? tang d?n):\n");
    int i ;
    for ( i = 0; i < n; i++) {
        printf("Ph?n t? th? %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Nh?p ph?n t? c?n tìm: ");
    scanf("%d", &target);

    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1) {
        printf("Ph?n t? %d n?m ? ch? s? %d trong m?ng.\n", target, result);
    } else {
        printf("Ph?n t? %d không t?n t?i trong m?ng.\n", target);
    }

    return 0;
}

