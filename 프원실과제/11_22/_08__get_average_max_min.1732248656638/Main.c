#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE	1000
#define END_MARK -1

int get_len_max_min(int *pnums, int *pmax, int *pmin) {
	int *pcur = pnums;
	//정수배열의 길이, 최대, 최소를 구할수있게 소스코드를 수정하여라. 마지막 끝원소를 제외하곤 모두 양수이다.
	// 첫번째는 정수배열의 포인터, 두번찌는 최대, 그뒤는 최소 포인터로 값을 변환
	int len;
	int max = pnums[0], min = pnums[0];
	for(len = 0; pnums[len] > 0; len++){
		if(max < pnums[len]) max = pnums[len];
		if(min > pnums[len]) min = pnums[len];
	}
	*pmax = max;
	*pmin = min;
	return len;
}

void generate_values(int *pnums) {
	int nseed = 0;
	int n_items;
	
	scanf("%d", &nseed);
	srand(nseed);
	
	n_items = rand()%999+1;
	while(n_items) {
		*pnums++ = rand()%10000;
		n_items--;
	}
	*pnums = END_MARK;	
	
}

int main(void) {
	int nums[MAX_SIZE];
	int max=0, min=0, len=0;
	
	generate_values(nums);
	len = get_len_max_min(nums, &max, &min);

	printf("Length(Nums) = %d, Max(nums)=%d, Min(nums)=%d\n", len, max, min);
	return 0;
}