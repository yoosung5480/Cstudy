#include <stdio.h>
#include <stdlib.h>
#include <time.h>

time_t xtime(int time_index);
void remove_zero(char *str){
	int i, j;
	int len = strlen(str);
	for(i = 0; i < len; i++){
		if(str[i] == '0'){
			for(j = i; j < len; j++){
				str[j] = str[j+1];
			}
			break;
		}
	}
}
void print_local_time(time_t t) {
	struct tm *local_time = localtime(&t);
	char date[80];
	char result[80];
	char month[3], day[3];
	
	strftime(month, sizeof(month), "%m", local_time);
	strftime(day, sizeof(day), "%d", local_time);
	
	remove_zero(month);
	remove_zero(day);
	
	strftime(result, sizeof(result), "%H:%M:%S, %A", local_time);
	
	sprintf(date, "%d/%s/%s, %s", local_time->tm_year+1900, month, day, result);
	
	printf("%s", date);
	return;
}
int main(void) {
	time_t t;
	int tindex;

	srand(0);
	scanf("%d", &tindex);

	t = xtime(tindex);
	print_local_time(t);

	return 0;
}
time_t xtime(int time_index) {
	//struct tm t_begin = {0, 0, 0, 1, 0, 120, };
	time_t xnow = 1577836800; // 2020. 1. 1, 00:00:00
	
	while (time_index-- > 0) 
		rand();
	
	xnow += rand()% 31622399;
	return xnow;	
}
