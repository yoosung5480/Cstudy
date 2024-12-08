#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    // 1차원 배열로 메모리 할당 (n x n 크기)
    int* ptr = (int*) malloc(n * n * sizeof(int));

    // 배열에 값 채우기
    int temp = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            *(ptr + i * n + j) = temp++;  // 1차원 배열에 2차원처럼 값 할당
        }
    }

    // 값 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", *(ptr + i * n + j));  // 1차원 배열에서 값 출력
        }
        printf("\n");
    }

    // 메모리 해제
    free(ptr);

    return 0;
}
