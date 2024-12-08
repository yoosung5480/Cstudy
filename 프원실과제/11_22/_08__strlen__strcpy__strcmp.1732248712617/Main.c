#include <stdio.h>
#include <stdlib.h>
int mystrlen(char *str) {
//@return: length of string
	int count = 0;
	for(int i = 0; str[i] != '\0'; i++) count++;
	// printf("%d\n", count);
	return count;
}

char* mystrcpy(char *src) {
	//@ 문자열을 복사해주는것이다.
	int length = mystrlen(src); 

	char* dest = (char*) malloc((length + 1)* sizeof(char));
	for(int i = 0; i < length; i++){
		dest[i] = src[i];
	}
	dest[length] = '\0';

	// return dest;
	return dest;
}

int mystrcmp(char *lhs, char *rhs) {
	/*
	1.두 문자열을 받고 사전상에서 앞단어가 뒷단어 보다 앞을때 음수
	2.두 문자열이 같을때 0
	3.뒷단어가 앞단어보다 사전사에서 뒤일때 양수
	*/
	int l_length = mystrlen(lhs);
	int r_length = mystrlen(rhs);
	int length, l_int, r_int;
	
	for(int i = 0; lhs[i] != '\0' || rhs[i] != '\0'; i++){
		int compare = lhs[i]  - rhs[i]; //왼쪽이 크면 양수, 오른쪽이 크면 음수
		if(compare > 0) return 1; 
		else if(compare < 0) return -1;
	}
	return 0;
}


int main(void) {
	char str1[256] = "Hello World !!!\n Good Day !!!";
	char str2[256] = "Hello PNU CSE !!!";
	char* str3 = mystrcpy(str1);
	
	printf("mystrlen(str1) = %d, mystrlen(str2) = %d\n",
				mystrlen(str1), mystrlen(str2));
	
	printf("mystrcpy(str3,str1) = %s\n", str3);
	
	// printf("mystrcmp(str1,str3) = %d, mystrcmp(str2,str3) = %d", 
	// 			mystrcmp(str1,str3), mystrcmp(str2,str3));
	
	return 0;
}