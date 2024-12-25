#include<stdio.h>

void bubbleSort(int arr[], int n){
	for(int i =0 ; i < n-1; i++){
		int a =0;
		for (int j = 0; j< n-i-1;j++ ){
			if(arr[j]>arr[j+1]){
				int temp =arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				a = 1;
			}
		}
		if(a == 0 ){
			break;
		}
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
	
	bubbleSort(arr,n);
	
	printfArr(arr,n);
	
	return 0;

}

