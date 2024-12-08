#include <stdio.h>
#include <stdlib.h>

int main(){
    // 포인터의 값들의 정체는? 실제 컴퓨터 메모리상의 '실제'주소.
    // 왜 포언티를 쓰나요?
    
    int*** A; 
    int** B; 
    int* C;
    int D = 4;
    A = &B;
    B = &C;
    *C = D;
    printf("%ld %ld\n", A, &B);     
    printf("%ld %ld\n", *A, &C);
    printf("%ld %ld\n", **A, &D);
    printf("%d, %d\n", ***A, D);

    // ***(A : B의 주소) -> **(*A : B의 주소에 들어있는값 : C의 주소) -> *(*C의주소) -> *(D의주소) -> D에 저장된값 = 4 

    // 포인터 변수가 값고있는 값은 - > 주소!!
    // '*'연산자를 이용해서 그 주소의 값을 가져올수 있다.

    // printf("%d %d %d\n",x, *p1, *p2);
    // printf("%d %d %d",x, p1, p2);
    return 0;
}