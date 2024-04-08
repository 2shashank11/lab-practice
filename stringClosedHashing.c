#include<stdio.h>
#include<string.h>

#define CAPACITY 10
char hash[CAPACITY][20];

void insert(char *str){
    int index=strlen(str)%CAPACITY;

    if(strcmp(hash[index], "")==0){
        strcpy(hash[index], str);
    }
    else{
        int k=0;
        while(strcmp(hash[(index+k)%CAPACITY], "") != 0 ){
            if(k>CAPACITY){
                printf("\nNo Space!!\n");
                return;
            }
            k++;
        }
        strcpy(hash[(index+k)%CAPACITY], str);
    }
}

int main(){

    printf("No. of strings: ");
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        char str[20];
        scanf(" %s", str);
        insert(str);
    }

    for(int i=0; i<CAPACITY; i++){
        if(strcmp(hash[i], "")==0){
            printf("NULL ");
            continue;
        }
        printf("%s ", hash[i]);
    }

}