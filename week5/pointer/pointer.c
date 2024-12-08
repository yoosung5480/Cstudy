#include <stdio.h>
#include <stdlib.h>

void swap(int* a , int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap2(int a_, int b_){
    int temp = a_;
    a_ = b_;
    b_ = temp;
}

// malloc(size_t size) : 할당 → 댕글링 포인터 이슈 발생 가능
// realloc(size_t size) : 재할당
// calloc(size_t size) : 할당 후 값을 0으로 채움
// int* pBMI = (int*) malloc(sizeof(int) * count)

void ptr(int* a){
    int* ptr = (int*) malloc(sizeof(int));
    int* a = ptr;
    return ptr;
}

void var(int b){
    int a = 10;
    b = a;
}

int main(){
    int* ptr = (int*) malloc(sizeof(int));
    *ptr = 1;
    printf("%d\n", *ptr);
    printf("%p\n", ptr);

    int a = 1;
    int b = 2;

    // swap(&a, &b);
    swap2(a, b);
    printf("a:%d b:%d", a ,b);

    free(ptr);
    return 0;
}