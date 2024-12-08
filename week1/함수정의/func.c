#include <stdio.h>

// def 함수명:
//     #구현
//     return

// return의 자료형 함수명(인자1, 인자2){
//     //구현
//     return
// }

int arr[5] = {1,2,3,4,5};

int get_sum(){
    int sum = 0;
    // for (int i = 1; i <= x; i++)
    // {
    //     sum += i;
    // }
    for (int i = 0; i <= sizeof(arr)/sizeof(int); i++){
        sum += arr[i];
    }
    return sum;
}

int main(){
    int arr[5] = {1, 2,3, 4, 5};
    int x = get_sum();
    printf("%d", x);
    return 0;
}