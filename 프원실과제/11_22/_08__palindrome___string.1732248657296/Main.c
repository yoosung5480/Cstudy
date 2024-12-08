#include <stdio.h> 
#include <string.h>
#include <ctype.h>

int ispalindrome(char *str) {
	//문자나 숫자만 남겨두고 모두 이어붙여야한다. 새로운 배열에 값을 넣는게 좋을거같다.
	char new[1024];
	int count = 0;
	for(int i = 0; str[i] != '\0'; i++){
		if(isalpha(str[i])){
			new[count++] = str[i];
		}
		else if(isdigit(str[i])){
			new[count++] = str[i];
		}
	}
	// printf("\n%s %d\n", new, count);
	//비교시, 모든 문자를 소문자로 변환	
	for(int i = 0; i < count; i++){
		if(tolower(new[i]) != tolower(new[(count -1) - i])) return 0; //양끝을 비교시작.
	}
	return 1;
	
}
int main(void) {
	char buffer[1024];

	gets(buffer);
	printf("[%s] is ", buffer);
	if (ispalindrome(buffer)) puts("a palindrome");
	else puts("not a palindrome");
	
	return 0;
}