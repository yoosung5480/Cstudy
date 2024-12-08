#include <stdio.h>
#include <string.h>

void decode(char* encrypted){
    int base = 'A';
    int decode_num = 0;
    char alpha[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char result[100];

    int value;
    for (int i = 0; i< strlen(encrypted); i++){
        if (encrypted[i] == '-'){
            result[i] = '-';
        }
        else{
            decode_num = ((i*(i+1))/2);
            result[i] = alpha[(encrypted[i]-'0'+decode_num)%26];
        }
    }

    result[strlen(encrypted)] = '\0';  // 문자열 종료
    
    printf("%s\n", result);
}

int main(){
    char encrypted[] = "0123456789-2381937466-015628391847-34849512067";
    decode(encrypted);
    return 0;
}