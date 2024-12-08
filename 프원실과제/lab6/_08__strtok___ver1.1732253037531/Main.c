#include <stdio.h>

char *mystrtok1(char *str, char delim) {
	static char *psave = NULL; //저장지점
	
	if(str != NULL) psave = str; //빈 문자열이면 저장지점은 문자열의 첫글자
	if(*psave == '\0') return NULL; // 빈 문자열이면 바로 널포인터 리턴
	
	while(*psave == delim) psave++; //구분자 여러개 일때 뛰워넣고 그 뛰워넣은 만큼 주소값 ++
	if(*psave == '/0') return NULL; //기존 문자열의 맨 마지막 이스케입 코드 받으면 널 포인터 리턴
	
	char * start = psave; //시작점 설정 (저장 지점)
	while(*psave != '\0' && *psave != delim) psave++; //다음 구분자 나올때까지 저장지점 ++
	
	
	while(*psave == delim){ //저장지점이 구분자일때 이면 
		*psave = '\0'; //구분자를 이스케입 코드로 바꾸고
		psave++; //그 다음 문자를 저장지점으로 해두기
	}
	return start; 
}

int main(void) {
	char *pstr, *ptoken, delim;
	int test = 0;

	char test_str[][256] = { ",123,hello,34 56, Good.,Bye",

		" T1 T2  T3\t33   T4,4\n T5555    ",
		",,,,Token1,, Token2, Token3,,,,"};
	
	scanf("%d", &test);
	if (test > 2 || test < 0) test = 0;
	delim = test_str[test][0];
	pstr = test_str[test]+1;

	ptoken = mystrtok1(pstr, delim);
	
	while (ptoken) {
		printf("%s\n",ptoken);
		ptoken = mystrtok1(0, delim);		
	}
		
	return 0;
}