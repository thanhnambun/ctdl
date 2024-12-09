#include<stdio.h>

int main(){
	int n;
	do {
		printf("nhap vao so luong phan tu cua mang ");
		scanf("%d",&n);
	}while(n<=0 || n>100);
	int arr[n];
	for(int i =0 ;i<n;i++){
		printf("phan tu arr[%d]",i);
		scanf("%d",&arr[i]);
	};
	for(int i = 0; i < n ;i++){
		printf(" \n array[%d] = %d",i,arr[i]);	
	}
//	int max =
	return 0;

}

