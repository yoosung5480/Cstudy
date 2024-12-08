#include <stdio.h>


int is_delim(char str, const char * delim){
	while(*delim != '\0'){
		if(str == *delim){
			return 1;
		}
		delim++;
	}
	return 0;
}


char *mystrtok(char *str, const char *delim) {
	static char *psave = NULL;
	const char * real_delim = delim;
	
	if(str != NULL) psave = str;
	if(*psave == '\0') return NULL;
	
	while(*psave != '\0' && is_delim(*psave, delim)) psave++;
	if(*psave == '\0') return NULL;
	
	char * start = psave;
	
	while(*psave != '\0' && !is_delim(*psave, delim)) psave++;
		
	if(*psave != '\0'){
		*psave = '\0';
		psave++;
	}
	return start;
}


int main(void) {
	char *pstr, *ptoken, *delim;
	int test = 0;

	char test_str[][256] = { "T1,T2 T3, T4  ,T5,,",", ",
		"abc\t  x\ny  z\n\nk", " \t\n",
		"#include <stdio.h>\nint\tmain(void){ int x=3;","# <>\n\t(){}=;"};
	
	scanf("%d", &test);
	if (test > 2 || test < 0) test = 0;
	pstr = test_str[2*test];
	delim = test_str[2*test+1];

	ptoken = mystrtok(pstr, delim);
	
	while (ptoken) {
		printf("%s\n",ptoken);
		ptoken = mystrtok(0, delim);		
	}
		
	return 0;
}