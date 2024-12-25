#include<stdio.h>


void insertSort(int arr[],int n ){
	for(int i = 0 ; i < n-1 ;i++){
		int key = arr[i];
		int j = i - 1;
		
		while(arr[j] > key && j >= 0 ){
			arr[j+1] = arr[j];
			j = j - 1 ;
		}
		
		arr[j+1] = key;
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


