#include<stdio.h>
typedef struct Count{
	int number;
	int current;
}Count;

int main(){
	int n,current ;
	
	printf("vui long nhap tong so phan tu cua mang \n");
	scanf("%d",&n);
	
	int arr[n];
	
	Count count [n];
	
	int i, j;
	for( i =0 ; i < n; i++){
		printf("vui long nhap gia tri cac phan tu \n");
		scanf("%d",&arr[i]);
		count[i].number = arr[i];
		count[i].current = -1;
	};

	for(i = 0 ; i < n; i++){
		current =1 ;
		if(count[i].current != -1){
			continue;	
		}
		for(j = i + 1; j < n;j++){
			if(arr[i] == arr[j]){
			current ++ ;
			count[i].current=0;
			}
		}
		count[i].current = current;
	}
	int hasDuplicate = 0;
	for(i =0 ; i< n; i++){
		if(count[i].current > 1 ){
			printf("phan tu %d lap lai %d lan \n",count[i].number,count[i].current);
			hasDuplicate = 1; 
		}
	 }	 
	if (!hasDuplicate) {
        printf("khong co phan tu bi lap lai.\n");
    } 
	return 0;
}

