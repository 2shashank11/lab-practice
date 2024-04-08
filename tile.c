#include<stdio.h>

int tileCalc(int n){
    if(n<=0){
        return 0;
    }

    if(n==1 || n==2){
        return n;
    }

    return tileCalc(n-1)+tileCalc(n-2);
}

int main(){
    printf("%d", tileCalc(4));
    return 0;
}