#include<stdio.h>

int binaySearch(int arr[], int left,int right, int value){
	int mid = left + (right-left)/2;
	if(left < right){
		if(arr[mid] == value ) return mid;
		if(arr[mid] > value)	return binaySearch(arr,left,mid-1,value);
		return binaySearch(arr,mid+1,right,value);
	}	
	return -1;
}

int main(){
int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    printf("Nh?p gi� tr? c?n t�m: ");
    scanf("%d", &key);
    int result = binaySearch(arr,arr[0],n-1, key);
    if (result != -1) {
        printf("Phan t? %d du?c t�m th?y t?i v? tr� %d.\n", key, result);
    } else {
        printf("Ph?n t? %d kh�ng t?n t?i trong m?ng.\n", key);
    }
	return 0;

}

