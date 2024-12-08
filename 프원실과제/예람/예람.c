#include <stdio.h>

int main(){
    int x = 1;
    int*p = &x;

    printf("%d, %p", x, p);
    return 0;
}