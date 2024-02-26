#include<stdio.h>

void insertionSort(int *arr, int n){
    for(int i=0; i<n; i++){
        int j=i;
        while(j>0 && arr[j]<arr[j-1]){
            int temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
            j--;
        }
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int arr[]={9, 4, 2, 1, 6, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array: ");
    printArray(arr, size);

    insertionSort(arr, size);
    printf("\nSorted array: ");
    printArray(arr, size); 
}