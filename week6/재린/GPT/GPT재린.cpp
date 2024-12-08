#include <stdio.h>
#include <string.h>

#define ALPHABET_LENGTH 26
#define BASE_SEQUENCE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

// 회전된 알파벳을 구하는 함수
char rotate(char start_char, int rotation) {
    int start_index = start_char - 'A';
    return BASE_SEQUENCE[(start_index + rotation) % ALPHABET_LENGTH];
}

void decrypt(const char* encrypted, char* decrypted) {
    int base_rotation[] = {0, 2, 5, 10, 3, 4, 9, 6, 7, 1}; // "0123456789"를 기반으로 한 회전 값
    int i = 0, j = 0, rotation_index = 0;

    // 문자를 하나씩 처리
    while (encrypted[i] != '\0') {
        if (encrypted[i] == '-') {
            decrypted[j++] = '-'; // '-'는 그대로 유지
        } else {
            int num = encrypted[i] - '0'; // 문자 숫자를 숫자로 변환
            decrypted[j++] = rotate('A', base_rotation[num]);
            rotation_index++;
        }
        i++;
    }
    decrypted[j] = '\0'; // 문자열 끝 표시
}

int main() {
    char encrypted[] = "0123456789-2381937466-015628391847-34849512067";
    char decrypted[100]; // 결과를 저장할 배열

    decrypt(encrypted, decrypted); // 암호 해독

    printf("Decrypted message: %s\n", decrypted);

    return 0;
}
