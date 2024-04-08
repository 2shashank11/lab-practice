#include<stdio.h>

int getMax(int *arr, int n){
    int max=arr[0];
    for(int i=0; i<n; i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}

void countSort(int *arr, int n){
    int max=getMax(arr, n);
    
    int output[n+1];

    int count[max+1];
    for(int i=0; i<=max; i++){
        count[i]=0;
    }

    for(int i=0; i<n; i++){
        count[arr[i]]++; //count of each element
    }

    for(int i=1; i<=max; i++){
        count[i]+=count[i-1]; //cummulative count
    }

    for(int i=n-1; i>=0; i--){
        output[count[arr[i]]-1]=arr[i];
        count[arr[i]]--;
    }

    for(int i=0; i<n; i++){
        arr[i]=output[i];
    }
}

void printArray(int *arr, int n){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}

int main(){

    int arr[] = { 11, 30, 24, 7, 31, 16 };  
    int n = sizeof(arr)/sizeof(arr[0]);  
    printf("Before sorting array elements are - \n");  
    printArray(arr, n);  
    countSort(arr, n);  
    printf("\nAfter sorting array elements are - \n");    
    printArray(arr, n);  

    return 0;
}