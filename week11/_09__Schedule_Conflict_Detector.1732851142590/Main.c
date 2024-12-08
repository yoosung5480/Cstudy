#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
	struct tm start;
	struct tm end;
} TimePeriod;

struct tm parse_datetime(char* datetime_str) { //2023-11-20 12:00
	// Implement your code
	struct tm date = {0};
	sscanf(datetime_str, "%d-%d-%d %d:%d", &date.tm_year, &date.tm_mon, &date.tm_mday, &date.tm_hour, &date.tm_min);
	date.tm_mon -= 1;
	date.tm_year -= 1900;
	return date;
}

TimePeriod detect_schedule_conflict(struct tm *start1, struct tm *end1, struct tm *start2, struct tm *end2) {
	// Implement your code
	TimePeriod conflict;
	struct tm latest_start;
	struct tm earliest_end;
	
	if(mktime(start1) > mktime(start2)){
		latest_start = *start1;
	}
	else{
		latest_start = *start2;
	}
	
	if(mktime(end1) < mktime(end2)){
		earliest_end = *end1;
	}
	else{
		earliest_end = *end2;
	}
	
	if(mktime(&latest_start) <= mktime(&earliest_end)){
		conflict.start = latest_start;
		conflict.end = earliest_end;
	}
	else{
		memset(&conflict, 0, sizeof(conflict));
	}
	return conflict;
}

void print_time(struct tm *t) {
	printf("%02d:%02d", t->tm_hour, t->tm_min);
}

void print_schedule_conflict(TimePeriod *overlap) {
	if (overlap->start.tm_year != 0) { 
		printf("Schedule conflict detected on %04d-%02d-%02d between ",
					 overlap->start.tm_year + 1900, overlap->start.tm_mon + 1, overlap->start.tm_mday);
		print_time(&overlap->start);
		printf(" and ");
		print_time(&overlap->end);
		printf(".\n");
	} else {
		printf("No schedule conflict.\n");
	}
}

int main() {
	struct tm periods[8][2] = {
		{parse_datetime("2023-11-20 09:00"), parse_datetime("2023-11-20 12:00")},
		{parse_datetime("2023-11-20 11:00"), parse_datetime("2023-11-20 13:00")},
		{parse_datetime("2023-11-20 14:00"), parse_datetime("2023-11-20 15:00")},
		{parse_datetime("2023-11-20 15:30"), parse_datetime("2023-11-20 16:00")},
		{parse_datetime("2023-11-21 17:00"), parse_datetime("2023-11-21 18:00")},
		{parse_datetime("2023-11-21 18:00"), parse_datetime("2023-11-21 19:00")},			
		{parse_datetime("2023-11-21 08:00"), parse_datetime("2023-11-21 09:00")},
		{parse_datetime("2023-11-22 08:00"), parse_datetime("2023-11-22 09:00")},		
	};

	for (int i = 0; i < 4; i++) {
		TimePeriod overlap = detect_schedule_conflict(&periods[i][0], &periods[i][1], &periods[i + 1][0], &periods[i + 1][1]);
		print_schedule_conflict(&overlap);
	}

	return 0;
}