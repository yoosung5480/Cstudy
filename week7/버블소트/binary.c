#include <stdio.h>
#include <stdlib.h>


// 동적으로 배열을 선언하고 값을 반환.
int* bubbleSort(int* _n) { // 배열의 길이 n을 알고싶지만, arr의 포인터를 반환해서 추가적으로 n 반환이 불가능하다.
    int n;
    scanf("%d", &n);
    *_n = n; // 하지만 포인터 파라미터와의 상호작용을 통해서 return없이 main에 바뀐 n값을 전달할수있다.


    int* arr = (int*) malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    return arr;
}


int main() {
    int n;
    int* arr = bubbleSort(&n); // 기분좋다 헤헤헤헿

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
