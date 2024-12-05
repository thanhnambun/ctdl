#include<stdio.h>

int fibo (int n){
	if( n == 0 ) return 0;
	if( n == 1 ) return 1;
	return fibo(n-1) + fibo(n-2);
};

int main(){
	int n;
	int i;
	
	printf("nhap so n :\n");
	scanf("%d",&n);
	
	if( n <= 0){
		printf("loi \n");
	}else{
		printf(" chuoi fibo cua %d la \n",n);
		for (i = 0 ; i < n; i++){
			printf ("%d ",fibo(i));
		};
	};
	
	return 0;

}

