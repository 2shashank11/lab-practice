#include<stdio.h>

// max heap used to sort in ascending order

void swap(int *arr, int a, int b){
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

void heapify(int *arr, int n, int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;

    if(left<=n && arr[largest]<arr[left]){
        largest=left;
    }
    if(right<=n && arr[largest]<arr[right]){
        largest=right;
    }

    if(largest != i){
        swap(arr, i, largest);
        heapify(arr, n, largest);
    }
}

void maxHeapSort(int *arr, int n){
    int size=n;

    while(size>1){
        swap(arr, 1, size);
        size--;

        heapify(arr, size, 1);
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

    printf("Heap: ");
    printArray(arr, n);

    maxHeapSort(arr, n);

    printf("Sorted: ");
    printArray(arr, n);

    return 0;
}