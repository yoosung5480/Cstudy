#include <stdio.h>
#include <stdlib.h>

// int* (포인터 변수) vs int (변수) 


int* func(n){
    
    int* ptr = (int*) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++){
        // *(ptr + i) = i;
        ptr[i] = i;
    }
    int a = 10;
    int b = 20;

    return ptr;
}


int* arr_func(){
    int arr[5] = { 1, 2, 3, 4, 5};
    return arr;
}



int main(){
    int n = 0;
    scanf("%d", &n);

    int* ptr = func(n);
    int* arr = arr_func();
    
    for (int i = 0; i < n; i++){
        // printf("%d\n", *(ptr+i));
        printf("%d\n", ptr[i]);
        printf("%p\n", (ptr+i));
        printf("\n");
    }

    for (int i = 0; i < n; i++){
        // printf("%d\n", *(ptr+i));
        printf("%d\n", arr[i]);
        printf("%p\n", (arr+i));
        printf("\n");
    }

    int a = 10;     // a는 변수 (값 : just 값)
    int* b = &a;    // 

    printf("%p\n", &a); //
    printf("%p\n", b);  // 
    printf("%d\n", *b); // *를 붙임으로써 b가 가르키고있는 주소의 "값"반환

    free(ptr);
    return 0;
}