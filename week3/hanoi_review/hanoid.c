#include <stdio.h>
int cnt = 0;

void hanoi(int k, int start, int rest, int det){
    if(k==1){
        cnt++;
        printf("%d -> %d\n", start, det);
        return;
    }
    hanoi(k-1, start, det, rest);
    hanoi(1, start, rest, det); //핵심!
    hanoi(k-1, rest, start, det);
}


int main(){
    int k = 0;
    scanf("%d", &k);
    hanoi(k, 1, 2, 3);
    //시작1, 나머지2, 목표3
    printf("%d\n", cnt);
    return 0;
}