#include<stdio.h>

int main(){
	int n,start,end ;
	int arr[n];
	
	printf("vui long nhap tong so phan tu cua mang \n");
	scanf("%d",&n);
	
	int i, j;
	for( i =0 ; i < n; i++){
		printf("vui long nhap gia tri cac phan tu \n");
		scanf("%d",&arr[i]);
	};

	for(i = 0 ; i < n; i++){
		for(j = i + 1; j < n;j++){
			if(arr[i] ==arr[j]){
				printf("cap doi xung la %d va %d \n .",arr[i],arr[j]);
			}
		}
	}

	return 0;
}

