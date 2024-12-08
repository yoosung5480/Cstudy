#include <stdio.h>



int n, m; //nPm의 permutaion생성.
int arr[10] = {0};
int is_used[10] = {0};
char str[] = "abc";
int cnt = 0;

//현재 원소 수 = k
void permutaion(int k){
    if(k == m){
        cnt++;
        for(int i = 0; i < m; i++){
            printf("%c ", str[arr[i]]);
        }
        printf("\n");
    }

    int start = arr[k];
    for(int i = start ; i < n; i++){
        if(!is_used[i]){
            arr[k] = i;
            
            // start
            is_used[i] = 1;

            permutaion(k+1);

            // back tracking
            is_used[i] = 0;
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    permutaion(0);
    printf("%d\n", cnt);
    return 0;
}
