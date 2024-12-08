#include <stdio.h>
#include <string.h>



int main(){
    char alpha[26] = "ACFJ";
    for(int i = 4; i < 26; i++){
        alpha[i] = '-';
    }
    int num[] = {0,1,2,3,5,6,7,8,9};

    char str_encoded[] = "0123456789238193746601562839184734849512067";

    // for(int i = 0; i < sizeof(str_encoded)/sizeof(char)-1; i++){
    //     printf("%c", alpha[str_encoded[i]-'0']);
    // }

    for (int i = 0; i < 4 ; i++){
        printf("암호:%d 해독:%c %d 알파벳번호:%d\n", str_encoded[i]-'0', alpha[i], alpha[i], alpha[i]-'A');
    }
    return 0;
}