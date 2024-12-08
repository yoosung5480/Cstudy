#include <stdio.h>
#include <string.h>
int arr[] = {0,2,5,9,14,20,27,35,44,54};

void rotation(char *encrypted, char *decrypted) {
    int value;
    char converted;
    //int plus = 0;

    for (int i = 0; i<strlen(encrypted); i++){
        if (encrypted[i] == '-'){
            decrypted[i] = '-';
        }
        else{
            value = encrypted[i] - '0';
            //converted = encrypted[i] + 17 + (2*(value)-1);
            //converted = (encrypted[i] + 17) + (value*(value)/2);
            //converted = encrypted[i] + 17 + value;
            converted = 'A' + arr[value];
            if (converted > 'Z') {
                converted -= 26;
            }
            decrypted[i] = converted;
        }

    }

}


int main() {
    char encrypted[] = "0123456789-2381937466-015628391847-34849512067";
    char decrypted[0];


    rotation(encrypted, decrypted);
    printf("%s", decrypted);

    return 0;
}


// 아직 풀고 있는 코든데,,, 풀다가 gpt돌려봤는데 gpt도 못풀어요...