#include<stdio.h>
#include<stdlib.h>

void swap(int *arr, int a, int b){
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

void heapify(int *arr, int n, int i){
    int largest=i;
    int leftChild=2*i;
    int rightChild=2*i+1;
    if(leftChild<n && arr[largest]<arr[leftChild]){
        largest=leftChild;
    }
    if(rightChild<n && arr[largest]<arr[rightChild]){
        largest=rightChild;
    }
    if(largest != i){
        swap(arr, largest, i);
        heapify(arr, n, largest);
    }

}

void printArray(int *arr, int n){
    for(int i=1; i<=n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int n;
    printf("Size: ");
    scanf("%d", &n);
    int arr[n+1];

    printf("Enter elements: ");
    for(int i=1; i<=n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i=n/2; i>0; i--){
        heapify(arr, n, i);
    }

    printArray(arr, n);

    return 0;
}