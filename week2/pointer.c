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

    printf("%0xd\n", arr);
    printf("%d\n", sizeof(arr));


    for(int i = 0; i<10 ; i++){
        printf("%d", arr[i]);
    }
    free(arr);
    return 0;
}
