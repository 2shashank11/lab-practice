#include<stdio.h>
#include<stdlib.h>

#define CAPACITY 10

int hash[CAPACITY];

void insert(int key){
    int index=key%CAPACITY;

    if(hash[index]==-1){
        hash[index]=key;
        return;
    }
    else{
        int k=0;
        while(hash[(index+k)%CAPACITY] !=-1 ){
            if(k>CAPACITY){
                printf("\nNo Space!!\n");
                return;
            }
            k++;
        }
        hash[(index+k)%CAPACITY]=key;
    }
}

int main(){

    for(int i=0; i<CAPACITY; i++){
        hash[i]=-1;
    }

    int n;
    printf("Size: ");
    scanf("%d", &n);
    int arr[n];

    // 8 23 34 45 67 52 63 58 90
    printf("Enter Elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i=0; i<n; i++){
        insert(arr[i]);
    }

    for(int i=0; i<CAPACITY; i++){
        if(hash[i]==-1){
            printf("NULL ");
            continue;
        }
        printf("%d ", hash[i]);
    }


}