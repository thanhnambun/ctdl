#include<stdio.h>

int linearSearch(int arr[], int sizeArr, int value){
	for(int i = 0 ; i < sizeArr; i++){
		if(arr[i] == value){
			return i;
		}
	}
	return -1;
}

int main(){
	int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    printf("Nh?p giá tr? c?n tìm: ");
    scanf("%d", &key);
    int result = linearSearch(arr, n, key);
    if (result != -1) {
        printf("Phan t? %d du?c tìm th?y t?i v? trí %d.\n", key, result);
    } else {
        printf("Ph?n t? %d không t?n t?i trong m?ng.\n", key);
    }
	return 0;

}

