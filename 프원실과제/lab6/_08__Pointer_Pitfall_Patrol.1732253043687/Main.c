#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>
// 

double calculateAverage(int *values, size_t count) { //정수 배열과, 그 배열의 크기를 인자로 받는다.
	double sum = 0;
	for (size_t i = 0; i < count; i++) {
			sum += values[i];
	}
	return sum / count;
}

void updateTemperature(float *temp) {//빈 배열일경우 그냥 넘어가게하기
	if(temp != NULL)*temp = 25.0; 
}

void reverseString(char *str) {
	if(str == NULL) return;
	size_t len = strlen(str);
	for (size_t i = 0; i < len / 2; i++) {
			char temp = str[i];
			str[i] = str[len - i - 1];
			str[len - i - 1] = temp;
	}
}

// The main function is intentionally hidden.
// int main(){
// 	int i_arr[] = {1, 2, 3, 4, 5};
// 	char c_arr[] = "abcde";
// 	double average = calculateAverage(i_arr, sizeof(i_arr)/sizeof(int));
// 	printf("Average: %f", average);
	
// 	float tp = 15.0;;
// 	updateTemperature(&tp);
// 	printf("new : %f\n", tp);
	
	
// 	reverseString(c_arr);
// 	printf("new: %s\n", c_arr);
	
// 	return 0;
// } 
int* allocateMemory(size_t size) {
	int *ptr = malloc(size * sizeof(int));
	if(ptr){
		for(int i=0; i<size;++i)
		ptr[i] = 0;
	}
	return ptr;
}

char* readInputFromKeyboard(){
	return NULL;
}

// Signal handler function
void signalHandler(int sig) {
	printf("Error: A signal %d was caught. Pointer misuse detected.\n", sig);
	exit(sig);
}

void setupSignalHandlers() {
	signal(SIGSEGV, signalHandler); 
	// Add handlers for other signals as needed
}

int main() {
	setupSignalHandlers();

	int values1[] = {1, 2, 3, 4, 5};
	printf("Average: %.2f\n", calculateAverage(values1, 5));

	updateTemperature(NULL);

	char* str = readInputFromKeyboard();
	reverseString(str);
	printf("Reversed String: %s\n", str);

	int* memory = allocateMemory(SIZE_MAX / 2);
	if (memory) free(memory);

	printf("All functions executed successfully!\n");
	return 0;
}
