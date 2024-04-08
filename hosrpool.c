#include<stdio.h>
#include<string.h>
#define MAX_CHAR 256

void shiftTable(char* substr, int m, int* shift){
    for(int i=0; i<MAX_CHAR; i++){
        shift[i]=m;
    }
    for(int i=0; i<m-1; i++){
        shift[substr[i]]= m-i-1;
    }
}

int search(char* str, char* substr, int* shift){
    int n=strlen(str);
    int m=strlen(substr);
    int i=m-1, k;

    while(i<n){
        k=0;
        while(k<m && str[i-k]==substr[m-k-1]){
            k++;
        }
        if(k==m){
            return i-m+1;
        }
        else{
            i+=shift[str[i]];
        }
    }
    return -1;
}

int main(){
    char str[100], substr[100];
    int shift[MAX_CHAR];

    printf("Enter main string: ");
    scanf("%s", str);
    printf("Enter substring: ");
    scanf("%s", substr);

    shiftTable(substr, strlen(substr), shift);
    printf("Found at index: %d", search(str, substr, shift));

    return 0;
}