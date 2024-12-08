
#include <stdio.h>

int max = 0;
int arr[101][101] = {0};

void get_sum(int i, int j, int x, int y){
    int temp = 0;
    for(int I = 0; I < y; I++)
        {
            for(int J = 0; J < x; J++)
            {
                temp += arr[i+I][j+J];
            }
        }
        if (temp > max) max = temp;
}

int main()
{
    int n,m,k,x,y;
    int sum = 0;
    
    scanf("%d %d %d %d", &m,&n,&x,&y);

    //입력받기
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++) scanf("%d", &arr[i][j]);
    }

    //sumMax계산
    for(int i = 0; i < n-y+1; i++)
    {
        for(int j = 0; j < m-x+1; j++)
        {
            get_sum(i, j, x, y);
        }
    }

    printf("%d", max);
    return 0;
}