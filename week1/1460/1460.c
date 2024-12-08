#include <stdio.h>

//2D선언법
int arr[101][101] = {0};

//벌점 list 지훈2점, 지민1점

int main(){
    int n;
    scanf("%d", &n);


    // 입력
    int temp = 1;

    for(int k = 0; k <= 2*n-1; k++){
        for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(i + j == k){
                        arr[i][j] = temp++;
                    }
                }
            }   
    }

    // 출력
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf(" %d", arr[j][i]); 
        }
        printf("\n");
    }
}
