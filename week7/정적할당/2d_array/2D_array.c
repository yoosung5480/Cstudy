#include <stdio.h>

//2D선언법
int arr[101][101] = {0};

//벌점 list 지훈1점, 지민1점

int main(){
    int n,m;
    scanf("%d %d", &n, &m);


    // 입력
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &arr[i][j]); //j, i  
        }
    }

    // 출력
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d", arr[i][j]); 
        }
        printf("\n");
    }
}
