#include <stdio.h>
typedef struct student {
	int id;
	char *pname;
	double points;
} STUD;




void stud_print(STUD *ps);
void stud_swap(STUD *a, STUD *b);
STUD * stud_get_last(STUD *ps_array);
int stud_compare_points(STUD *ps1, STUD *ps2);

int compare(STUD *ps1, STUD *ps2){
	// 포인트 별로 내림차순, 포인트가 같으면? 이름으로 내림차순.
	// return 1 (ps1 > ps2)
	// return -1 (ps1 < ps2)
	// return 0 (ps1 = ps2)

	// print -> 정상 작동 확인
}

void stud_swap(STUD *a, STUD *b){
	// id 에대한 swap

	// pname에 대한 swap

	// points swap;

	// print문 만들기. -> 정상 작동 확인
}

void stud_bubble_sort(STUD * pnucse) {	
	int count = 0;
	for(;pnucse[count].id > 0; count++);

	// for(int i = 0; i < count; i++){
	// 	for(int j = 0; j < count -1; j++){
	// 		if(stud_compare_points(&pnucse[j], &pnucse[j+1]) < 0)stud_swap(&pnucse[j+1], &pnucse[j]);
	// 	}
	// }
	for(int i = 0; i < count; i++){
		for(int j = 0; j < count -1; j++){
			if(compare(&pnucse[i], &pnucse[i+1]) == -1) stud_swap(&pnucse[j+1], &pnucse[j]);
		}
	}
	// printf("%d", stud_compare_points(&pnucse[1], &pnucse[0]));
}

void set_values_of_pnucse(STUD * pnucse, int test) {
	STUD pnucse1[] = { {1, "Choi", 3.9}, {2, "Park", 2.1},
		{3, "Kim", 9.0 }, {4, "Lee", 3.5 }, {5, "Moon", 4.5 },
		{6, "Kang", 2.0 }, {7, "Jeon", 8.9 }, {-1, NULL, 0 } };
	STUD pnucse2[] = { {1, "Choi", 2.5}, {2, "Park", 4.1},
		{3, "Kim", 1.0 }, {4, "Lee", 8.0 }, {5, "Moon", 8.5 },
		{6, "Kang", 5.0 }, {7, "Jeon", 3.9 }, {-1, NULL, 0 } };
	STUD *pnew = (test%2) ? pnucse1 : pnucse2;
	int i=0;
	
	while (i<7) {
		pnucse[i] = pnew[i];
		i++;
	}
}
int main(void) {
	STUD pnucse[] = { {1, "Choi", 9.9}, {2, "Park", 0.1},
		{3, "Kim", 5.0 }, {4, "Lee", 3.0 }, {5, "Moon", 9.5 },
		{6, "Kang", 7.0 }, {7, "Jeon", 0.9 }, {-1, NULL, 0 } };
		
	STUD * ps_cur = pnucse;
	int test_id = 0;
	scanf("%d",&test_id);
	if (test_id) set_values_of_pnucse(pnucse, test_id); 
	
	stud_bubble_sort(pnucse);
	
	while (ps_cur->id > 0)
		stud_print(ps_cur++);	

	return 0;
}
void stud_print(STUD *ps) {
    printf("[%d:%s] = %lf\n", ps->id, ps->pname, ps->points);	
}

void stud_swap(STUD *a, STUD *b) {
    STUD buf;
    buf = *a;
    *a = *b;
    *b = buf;
}

STUD * stud_get_last(STUD *ps_array) {
	while (ps_array->id >= 0) {
		ps_array++;
	}
	return --ps_array;
}

int stud_compare_points(STUD *ps1, STUD *ps2) {
	int ret = 1;
	if (ps1->points < ps2->points)
		ret = -1;
	else if (ps1->points == ps2->points)
		ret = 0;
	return ret;
}