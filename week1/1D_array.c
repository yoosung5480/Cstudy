#include <stdio.h>

int main(){
    char arr[31] = {0};
    int len = 0;
    scanf("%d", &len); //& 주소 참조연산자.

    for(int i = 0; i <= len; i++)
    { // len + 1 만큼 받아온다. 
        scanf("%c", &arr[i]);
    }
    
    for(int i = len; i > 0; i--){
        printf("%c", arr[i]);
    }
    
    return 0;
}