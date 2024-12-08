#include <stdio.h>
#include <time.h>
void print_local_time_after_kdays(time_t t, int k) {
	t += (86400)*k;
	struct tm* time = localtime(&t);
	char *weekend[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

	// struct my temp; temp.num;
	// strcut my* temp; temp->num; 
	printf("%04d/%d/%d, ", time->tm_year + 1900, time->tm_mon + 1, time->tm_mday);
	printf("%02d:%02d:%02d, ", time->tm_hour, time->tm_min, time->tm_sec);
	printf("%s", weekend[time->tm_wday]);

	return;
}
int main(void) {
	int k=0;
	time_t now = 1669856792; // 2022/12/01 01:06:32
	
	scanf("%d", &k);
	
	print_local_time_after_kdays(now, k);

	return 0;
}