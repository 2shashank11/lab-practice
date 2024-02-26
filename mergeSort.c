#include<stdio.h>

void merge(int *arr, int low, int mid, int high){

    int temp[high+1];
    int left=low, right=mid+1;
    int k=0;
    while(left<=mid && right<=high){
        if(arr[left] <= arr[right]){
            temp[k++]=arr[left++];
        }
        else{
            temp[k++]=arr[right++];
        }
    }
    while(left<=mid){
        temp[k++]=arr[left++];
    }
    while(right<=high){
        temp[k++]=arr[right++];
    }
    for(int i=low; i<=high; i++){
        arr[i]=temp[i-low];
    }
}

void mergeSort(int *arr, int low, int high){
    if(low>=high) return;
    int mid=(low+high)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
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

    mergeSort(arr, 0, size-1);
    printf("\nSorted array: ");
    printArray(arr, size); 
}