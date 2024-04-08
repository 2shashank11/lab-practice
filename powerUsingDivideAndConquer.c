#include<stdio.h>

int power(int a, int n){
    if(a==0){
        return 0;
    }

    if(n==1){
        return a;
    }

    if(n%2==0){
        return power(a*a, n/2);
    }
    else {
        return a*power(a*a, n/2);
    }
}

int main(){
    printf("%d", power(5, 3));
}