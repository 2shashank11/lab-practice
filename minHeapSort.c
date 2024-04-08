#include<stdio.h>

// min heap used to sort in descending order

void swap(int *arr, int a, int b){
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

void heapify(int *arr, int n, int i){
    int smallest=i;
    int left=smallest*2;
    int right=smallest*2+1;

    if(left<=n && arr[smallest]>arr[left]){
        smallest=left;
    }
    if(right<=n && arr[smallest]>arr[right]){
        smallest=right;
    }

    if(smallest!=i){
        swap(arr, i, smallest);
        heapify(arr, n, smallest);
    }
}

void printArray(int *arr, int n){
    for(int i=1; i<=n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void minHeapSort(int *arr, int n){
    int size=n;

    while(size>1){
        swap(arr, size, 1);
        size--;

        heapify(arr, size, 1);
    }
    
}

int main(){
    int n;
    printf("Enter size: ");
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

    minHeapSort(arr, n);

    printf("Sorted: ");
    printArray(arr, n);


    return 0;
}