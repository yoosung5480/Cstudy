#include <stdio.h>

// 배열은 메모리에서 연속적인 공간


/*
/ : 나누기
% : 나머지
* : 곱하기
*/



int main(){
    int arr[100] = {0}; //int 4byte * 8 = 32byte
    int size = sizeof(arr); // 32
    int num_elements = sizeof(arr) / sizeof(int); // 8
    char str[] = "hello";
    int nums[] = {1, 2,3,7 ,5,5,5};


    for(int i = 0; i < sizeof(str)/sizeof(char); i++){
        printf("%c", str[i]);
    }
    printf("");
    

    return 0;
}
// if, for, while, switch, 함수선언 
// for, 1차배열, 2채배열, 함수선언