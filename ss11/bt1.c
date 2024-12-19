#include<stdio.h>

int main(){
	int n ;
	int max = 0;
	int arr[n];
	
	printf("vui long nhap tong so phan tu cua mang \n");
	scanf("%d",&n);
	
	int i;
	for( i =0 ; i < n; i++){
		printf("vui long nhap gia tri cac phan tu \n");
		scanf("%d",&arr[i]);
	}
	for ( i =0 ; i< n; i++){
		if(max < arr[i]){
			max= arr[i];
		}
	}
	printf("gia tri lon nhat là %d",max);
	
	return 0;

}

