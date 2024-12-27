#include<stdio.h>

void swap(int *a , int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selectionSort(int arr[] , int size) {
	for(int i = 0; i< size ; i++) {
		int a = i;
		for(int j=i+1 ; j < size ; j++ ) {
			if (arr[a] > arr[j]) {
				a = j;
			}
		}
		swap(&arr[a],&arr[i]);
	}
}

void printfArr(int arr[], int n){
	for(int i =0 ;i<n; i++){
		printf("%d",arr[i]);
	}
}

int main(){
	
	int arr[] ={1,5,3,7};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	selectionSort(arr,n);
	
	printfArr(arr,n);
	
	return 0;

}

