#include <stdio.h>

char *mystrstr(char *str, char *substr) {
	int len_substr = 0;
	for(int i = 0; substr[i] != '\0'; i++) len_substr++;
	int len_str = 0;
	for(int i = 0; str[i] != '\0'; i++) len_str++;
	// printf("%d %d\n", len_substr, len_str);
	int count = 0, i, j;
	for(i = 0; i < len_str - len_substr; i++){
		count = 0;
		for(j = 0; j < len_substr; j++){
			if(str[i+j] == substr[j]) count++;
		}
		if(count == len_substr) return &str[i];
	}
	return 0;
}

void find_str(char * str, char * substr) {
	char* pos = mystrstr(str, substr);
	if(pos) 
		printf("found the string '%s' in '%s' at position: %ld\n", substr, str, pos - str);
	else
		printf("the string '%s' was not found in '%s'\n", substr, str);
}
 
int main(void) {
	char* str = "one two three";
	find_str(str, "two");
	find_str(str, "");
	find_str(str, "nine");
	find_str(str, "n");

	return 0;
}