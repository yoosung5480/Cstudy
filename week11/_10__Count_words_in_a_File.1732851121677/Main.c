#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int count_words(char *txt) {

	int count = 0;
	const char *delim = " \r\n";
	
	char *token = strtok(txt, delim);
	while(token != NULL){
		count++;
		token = strtok(NULL, delim);
	}
	return count;
}
int main(void) {
	char * filename = "data/ai.txt";
	FILE *fd = NULL;
	int test_case = 1;
	
	scanf("%d", &test_case);
	
	switch (test_case) {
		case 2:
			filename = "data/internet.txt";
			break;
		case 3:
			filename = "data/ce.txt";
			break;
		default :
			break;
	}
	
	fd = fopen(filename, "rt");
	if (fd) {
		int nsize;
		char * buffer = NULL;

		fseek(fd, 0, SEEK_END);
		nsize = ftell(fd);
		rewind(fd);	
			
		buffer = (char *)malloc(nsize+1);
		assert(buffer);
		
		nsize = fread(buffer, sizeof(char), nsize, fd);
		buffer[nsize] = '\0';
		printf("# of words in %s is %d\n",filename,count_words(buffer));
		fclose(fd);
	} 
	else puts("File Open Error\n");
	
	return 0;	
}