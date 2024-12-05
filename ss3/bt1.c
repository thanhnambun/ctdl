#include<stdio.h>

int a(int n){
	if(n ==0){
		
		return 1;
	};
	return n * a(n-1);
	
};

int main(){
	int n ;
	
	printf("nhap so nguyen n:");
	
	scanf("%d",&n);
	
	if( n < 0 ){
		
		printf("khong the tinh giai thua so am .\n");
		
	}else{
	
		printf("giai thua cua %d :%d \n",n,a(n));
			
	};
	
	return 0;

}

