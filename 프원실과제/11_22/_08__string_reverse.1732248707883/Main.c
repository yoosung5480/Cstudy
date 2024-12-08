#include <stdio.h>

char * mystrrev(char * str) {
	//길이 홀수, 짝수일때 나눠서 실행해야함

	int count = 0;
	for(count = 0; str[count] != '\0'; count++); //길이 구하기

// printf("%d\n", 5/2);

//짝수일때
if(count % 2 == 0){
	for(int i = 0; i < count / 2; i++){
		int temp = str[i];
		str[i] = str[count - i - 1];
		str[count - i - 1] = temp;
	}
}
//홀수일때
else{
	for(int i = 0; i < count / 2 + 1; i++){
		int temp = str[i];
		str[i] = str[count - i - 1];
		str[count - i - 1] = temp;
	}
}
	return str;
}

int main(void) {
	char str[256];
	
	gets(str);
	
	printf("%-20s  : After Reverse >>>\n",str);
	printf("%-20s\n", mystrrev(str));

	return 0;
}