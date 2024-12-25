#include<stdio.h>

void swap(int *a , int *b) {
	int temp = *a ;
	*a = *b;
	*b = temp;
}

void selectionSort(int arr[] , int n ) {
	int swap_count =0;
	for (int i=0; i<n; i++ ) {
		int min = i;
		for( int j = i+1 ;j<n;j++){
			if(arr[j]<arr[min]){
				min = j;
			}
		}
		if (min != i) {
            swap(&arr[i], &arr[min]);
            swap_count++;
            
            printf("Hoan doi: ");
            for (int j = 0; j < n; j++) {
                printf("%d ", arr[j]);
            }
            printf("\n");
        }
	}
	 printf("hoan thanh sau %d lan hoan doi.\n", swap_count);
    printf("Mang da sap xep: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main(){
	
	int arr[] = {64, 25, 12, 22, 11};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	selectionSort(arr,n);
	
	
	return 0;

}

