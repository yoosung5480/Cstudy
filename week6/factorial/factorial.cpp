#include <stdio.h>

int func(int n){
    if (n == 1){
        return 1;
    }
    return n * func(n-1);
}

int main(){
    printf("%d", func(5));
    return 0;
}