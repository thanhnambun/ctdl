#include<stdio.h>
#include<string.h>
#include<ctype.h>

int isPalindrome(char str[], int start , int end){
	if(start >= end){
		return 1;
	};
	if (tolower(str[start]) != tolower(str[end])){
		return 0;
	};
	return isPalindrome(str ,start , end);
};

int main(){
	char str[100];
	
	printf("nhap chuoi ");
	fgets(str, sizeof(str),stdin);
	
	int len = strlen(str);
	
	if (isPalindrome(str, 0, len - 1)) {
        printf("Palindrome valid\n");
    } else {
        printf("Palindrome invalid\n");
    };
	
	return 0;

}

