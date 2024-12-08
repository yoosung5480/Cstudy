#include <stdio.h>

#define MAX_SIZE 1000

// 버블소트 -> 왜 포인터를쓰는가!
// C언어 특징: 리턴값 1개!!!, 배열, 구조체등을 인자나, 리턴값으로 할수없어.


void bubbleSort(int arr[],int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}



// int func(int a, int b){
//     a = a + b;
//     return a;
// }


void func(int* a, int* b){
    *a = *a + *b;
}

int main() {
    int n;
    int arr[MAX_SIZE];
    // scanf("%d", &n);
    // for (int i = 0; i < n; i++) {
    //     scanf("%d", &arr[i]);
    // }

    // bubbleSort(arr, n);

    // for (int i = 0; i < n; i++) {
    //     printf("%d ", arr[i]);
    // }
    printf("\n");
    int x = 1;
    int y = 2;
    int *j;
    int *a = &x;
    int *b = &y;
    func(a, b);
    printf("%0x", j);
    // int c = func(a, b);
    printf("%d\n", *a);
    // print("%d %d\n", a, c);
    return 0;
}


// main()실행

// arr 선언 (main 함수 안에서)

// bubbleSort 호출 -> return 자료형이 void.





