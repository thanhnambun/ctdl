#include<stdio.h>

void swap(int *a,int *b){
	int temp =*a;
	*a = *b;
	*b=temp;
}

void selectionSort(int arr[], int n ){
	for(int i =0 ; i< n -1; i++){
		int min = i;
		for(int j = i+1 ; j < n ;j++){
			if(arr[j]<arr[min]){
					min = j;
			}
		}
		swap(&arr[min],&arr[i]);
	}
}

void printfArr(int arr[], int n){
	for(int i =0 ;i<n; i++){
		printf("%d \n",arr[i]);
	}
}

int main(){
	
	int arr[] ={1,5,3,7};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	selectionSort(arr,n);
	
	printfArr(arr,n);
	
	int value;
	
	printf("vui long nhap phan tu can tim kiem \n");
	scanf("%d",&value);
	
	for(int i =0 ; i < n-1 ; i++ ){
		if(arr[i] == value ){
			printf("phan tu %d duoc tim thay o vi tri %d \n",value , i);
		}else{
			printf("khong tim thay phan %d",value);
		}
	}
	
	return 0;

}

