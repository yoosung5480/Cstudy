#include <stdio.h>

void swap(char*x, char*y){
	int temp = *x;
	*x = *y;
	*y = temp;
}
void permute(char* str, int start, int end){
	if(start == end) printf("%s\n", str);
	else{
		for(int i = start; i <= end; i++){
			swap(str + start, str + i); //배열 원소 바꿔주기
			permute(str, start + 1, end); //그 바꿔준 원소 다음 원소부터 다시 permute 수행
			swap(str + i, str + start); //바꿔준 배열 다시 되돌려놓기
		}
	}
}

void print_all_permutations(char *str) {
	int len = 0;
	while(str[len] != '\0') len++;
	permute(str, 0, len -1); //실제 배열길이 - 1 해야 올바른 인덱스 번호나옴
	return;
}

int main(void) { 
	char str[256] = "ABC";

	print_all_permutations(str);
	return 0; 
} 