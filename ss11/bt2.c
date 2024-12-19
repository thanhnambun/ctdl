#include<stdio.h>

int main(){
	int n ;
	int arr[n];
	
	printf("vui long nhap tong so phan tu cua mang \n");
	scanf("%d",&n);
	
	int i;
	for( i =0 ; i < n; i++){
		printf("vui long nhap gia tri cac phan tu \n");
		scanf("%d",&arr[i]);
	}
	int min = arr[0];
	for ( i =0 ; i < n; i++){
		if(min > arr[i]){
			min= arr[i];
		}
	}
	printf("gia tri nho nhat là %d",min);
	
	return 0;

}

