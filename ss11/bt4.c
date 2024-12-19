#include<stdio.h>

typedef struct Student{
	char name[50];
	float score;
}Student;

int main(){
	int n ;
	char checkName;
	
	printf("vui long nhap so luong sinh vien \n");
	scanf("%d",&n);
	
	Student students[n];
	
	int i;
	for(i = 0 ;i < n ; i++){
		 printf("nhap ten %d: ", i + 1);
        scanf(" %[^\n]", students[i].name); 
        printf("nhap diem :  ");
        scanf("%f", &students[i].score);
	}
	
	printf("vui long nhap ten sinh vien can tim :\n");
	scanf("%s",&checkName);
	
	for(i =0 ; i<n ; i++ ){
		if(checkName == students[i].name){
			printf(" Diem cua %s la %d",students[i].name,students[i].score);
		}
	}
	
	return 0;

}

