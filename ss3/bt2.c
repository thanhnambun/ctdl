#include<stdio.h>

int sum (int n ,int m){
	if( n > m ){
		return 0;
	};
	return n + sum( n+1 , m );
};

int main(){
 	int n , m;
 	
 	printf ("nhap so n :");
 	scanf ("%d",&n);
 	
 	printf ("nhap so m :");
 	scanf ("%d",&m);
 	
 	if( n >= m){
 		printf("loi \n");
	 }else{
	 	printf("tong cua %d den %d la :%d",n , m, sum(n,m));
	 }
 	
	return 0;

}

