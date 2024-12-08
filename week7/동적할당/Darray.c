#include <stdio.h>
#include <stdlib.h>

int main(){
    // 사용자가 원하는 길이만큼의 정수배열을 만드느는 프로그램.
    int n;
    scanf("%d", &n);
    int* arr = (int*) malloc(n * sizeof(int)); // 스텍에 블럭n개를 붙여놓은 메모리 만큼의 크기를 할당. (블락 1개의 크기는 int)

    for(int i = 0; i < n; i++){
        arr[i] = i;
    }


    for(int i = 0; i < n; i++){
        printf("%d\n", arr[i]);
    }
}

//아래의 기능을 하는 프로그램을 만드시오.

// 입력 예시
// 5
// abcde

// 출력값
// abcde