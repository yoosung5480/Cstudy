#include <stdio.h>
typedef struct student {
	int id;
	char *pname;
	double points;
} STUD;

int main(){
    STUD temp = {0, "adsf", 5};
    printf("%d", sizeof(temp));
    return 0;
}