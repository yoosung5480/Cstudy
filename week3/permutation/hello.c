#include <stdio.h>

int main(){
    int x = 8;
    double result = (((5.12 * 1e9 + 1.28 * 1e9 * 12)) + (5 * 256 * 1e6)) / (2 * 1e9);
    printf("%f", result);
    return 0;
}
