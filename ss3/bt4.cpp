#include<stdio.h>
#include<string.h>

void swap (char *a ,char *b){
	char temp = *a;
	*a = *b;
	*b = temp;	
};
void rever ( char str[], int start, int end ){
	if(start >=end){
		return;
	};
	swap (&str[start],&str[end]);
	
	rever (str,start+1,end-1);
}


int main(){
	char arr[100];
	
	printf("nhap chuoi ki tu");
	fgets(arr , sizeof(arr),stdin);
	
	int len = strlen(arr);
	
	printf("chuoi ban dau :%s",arr);
	
	rever(arr ,0 ,len-1);
	
	printf("chuoi sau khi dao nguoc %s",arr);
	
	return 0;

}

