#include<stdio.h>

int sum ( int arr[], int start , int end){
	if(start > end){
		return 0;
	};
	return arr[start] + sum(arr,start+1,end);
};

int main(){
	int n;
	
	printf("nhap so phan tu n: \n");
	scanf("%d",&n);
	
	int arr[n];
	int i ;
	int j;
	
	for ( i=0; i<n ; i++){
		printf("phan tu %d la ",i);
		scanf("%d",&arr[i]);
	};
	
	printf("danh sach các phan tu cua mang \n");
	for( j = 0; j < n; j++){
		printf(" \n array[%d] = %d",j,arr[j]);	
	};
	
	printf("tong cac phan tu la : %d",sum(arr,0,n-1));
	
	return 0;

}

