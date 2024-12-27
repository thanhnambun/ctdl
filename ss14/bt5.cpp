#include<stdio.h>

void insertSort(int arr[], int n) {
	for(int i =1 ; i< n; i++) {
		int j = i - 1;
		int key = arr[i];
		while(j>= 0 && arr[j] > key ) {
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] =key;
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
	
	insertSort(arr,n);
	
	printfArr(arr,n);
	
	return 0;

}

