#include<stdio.h>

int partion(int *arr, int low, int high){
    int pivot = arr[low];
    int i=low, j=high;

    while(i<=j){
        while(arr[i] <= pivot && i<=high){
            i++;
        }
        while(arr[j] > pivot && j>=low){
            j--;
        }
        if(i<j){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp=arr[low];
    arr[low]=arr[j];
    arr[j]=temp;

    return j;

}

void quickSort(int *arr, int low, int high){
    if(low<high){
        int partionPoint=partion(arr, low, high);
        quickSort(arr, low, partionPoint-1);
        quickSort(arr, partionPoint+1, high);
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

    quickSort(arr, 0, size-1);
    printf("\nSorted array: ");
    printArray(arr, size); 
}