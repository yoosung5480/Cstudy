#include <stdio.h>

int str_len(char *str){
	int len = 0;
	while(str[len] != '\0') len++;
	return len;
}
char *mystrcat(char *dest, char *src) {
	int len_dest = str_len(dest);
	int len_src = str_len(src);
	int i = 0;
	for(i = 0; i < len_src; i++){
		dest[len_dest + i] = src[i]; 
	}
	// dest[i] = '\0';
	return dest;
}

int main(void) {
	char str[256] = "Hello ";
	char * pstr2 = "Good Bye World !!!";
	
	printf("%s\n", mystrcat(mystrcat(str, " World !!! ..."), pstr2 ));

	return 0;
}