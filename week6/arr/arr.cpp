#include <stdio.h>

char arr[20][20];

int main(){
    int n = 19;
    for(int i = 0; i < 19; i++){
        for(int j = 0; j < 19; j++){
            if((j >= 2*(i - n/2)) && (i + j >= n/2)&&(2*j < i + n)){
                arr[i][j] = '*';
            }
            else{
                arr[i][j] = ',';
            }
        }
    }

    for(int i = 0; i < 19; i++){
        for(int j = 0; j < 19; j++){
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }


    return 0;
}