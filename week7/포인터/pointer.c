#include <stdio.h>
#include <stdlib.h>

int main(){
    int n=4;

    int* arr = (int*) malloc(sizeof(int) * n);

    int* b;

    b = arr;

    printf("size of b : %d\n", sizeof(b));
    printf("b : %d\n", b);   

    for(int i = 0; i<10 ; i++){
        arr[i] = i;
    }

    printf("%0xld\n", arr);
    printf("%ld\n", sizeof(arr));


    for(int i = 0; i<10 ; i++){
        printf("%ld", arr[i]);
    }
    free(arr);
    return 0;
}
