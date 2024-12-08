#include <stdio.h>
#include <stdlib.h>

int main(){

    int arr[4][3] = {{1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 9},
                    {10, 11, 12}};

    printf("%d", arr[3][2]);

    return 0;
}