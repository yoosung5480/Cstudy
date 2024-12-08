#include <stdio.h>
#define MAX_NUMBER	10000


int main(void) {
	int n = 1;
	int arr_num[MAX_NUMBER + 36] = {0};
	int sum = 0;
	
	for(int i = 0; i < MAX_NUMBER; i++){
		if(i < 10) sum = i + i;
		else if(i < 100) sum = i + i / 10 + i % 10;
		else if(i < 1000) sum = i + (i / 100) + (i / 10) % 10 + i % 10; 
		else sum = i + (i / 1000) + (i / 100) % 10 + (i / 10) % 10 + i % 10;
		
		if(sum < MAX_NUMBER + 36){
			arr_num[sum] = 1;
		} 
		
	}
	
	for(int i = 0; i < MAX_NUMBER; i++){
		if(arr_num[i] == 0) printf("%d\n", i);
	}

	return 0;
}
