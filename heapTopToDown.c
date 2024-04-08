#include<stdio.h>
#include<stdlib.h>

void swap(int *arr, int a, int b){
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

void insert(int *arr, int *n, int val){
    (*n)++;
    int index=*n;
    arr[index]=val;

    while(index>1){
        int parent=index/2;
        if(arr[parent]<arr[index]){
            swap(arr, parent, index);

            parent=index;
        }

        else{
            return ;
        }
    }
}

void delete(int *arr, int *n){
    if(*n==0){
        return;
    }

    arr[1]=arr[*n];
    (*n)--;

    int index=1;
    int size=*n;

    while(index<=size){
        int leftChild=2*index;
        int rightChild=2*index+1;

        if(leftChild<size && arr[index]<arr[leftChild]){
            swap(arr, index, leftChild);
            index=leftChild;
        }

        if(rightChild<size && arr[index]<arr[rightChild]){
            swap(arr, index, rightChild);
            index=rightChild;
        }

        else{
            return;
        }
    }
}

void printArray(int *arr, int n){
    for(int i=1; i<=n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[100], n=0;
    insert(arr, &n, 50);
    insert(arr, &n, 55);
    insert(arr, &n, 53);
    insert(arr, &n, 52);
    insert(arr, &n, 54);

    printArray(arr, n);

    delete(arr, &n);

    printArray(arr, n);

    return 0;
}