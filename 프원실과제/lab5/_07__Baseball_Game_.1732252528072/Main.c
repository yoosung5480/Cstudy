#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ATTEMPT_LIMIT	9

// Function Prototypes
int generate_target_number(void);
int guess_number(void);
int get_match_result(int target, int guessed);
void receive_match_result(int result, int guessed);

int is_different_digits(int num);
int generate_a_digit(void);

// Implement generate_target_number()
int generate_target_number(){
	int n1, n2, n3;
	n1 = rand() % 10;
	while(1){
		n2 = rand() % 10;
		if(n1 != n2) break;
	}
	while(1){
		n3 = rand() % 10;
		if(n1 != n3 && n2 != n3) break;
	}
	return n1*100 + n2*10 + n3;
}
// Implement get_match_result()
int get_match_result(int target, int guessed){
	int n_strike = 0, n_ball = 0;
	int arr_target[3];
	int arr_guessed[3];
	for(int i = 0; i < 3; i++){
		arr_target[i] = target % 10;
		target /= 10;
		arr_guessed[i] = guessed % 10;
		guessed /= 10;
	}
	for(int i = 0; i < 3; i++){
		if(arr_target[i] == arr_guessed[i]) n_strike++;
		else {
			for(int j = 0; j < 3; j++){
				if(arr_target[i] == arr_guessed[j]) n_ball++;
			}
		}
	}
	return n_strike * 10 + n_ball;
}

int main(void) {
	int n_attempt = 0;
	int target_num, guessed_num, match_result;

	setvbuf(stdout,NULL,_IONBF, 0);

	srand(time(0));
	target_num = generate_target_number();
	do {
		printf("Attempt [%d/%d] ",++n_attempt, ATTEMPT_LIMIT);
		guessed_num = guess_number();
		match_result = get_match_result(target_num, guessed_num);
		receive_match_result(match_result, guessed_num);
	} while (n_attempt <= ATTEMPT_LIMIT && match_result != 30);

	if (match_result == 30)
		printf("Congratulation!!! You Win\n");
	else
		printf("Nice Try!!! But You Lose, The target number is %d\n", target_num);
	return 0;
}

/**
* @brief : check digit duplication
* @return : return true if all digits of the number are different, false otherwise.
* @param	 : 	num a 3-digits number to be checked for digit duplication.
*/
int is_different_digits(int num) {
	int digits[3];
	int is_different = 1;

	digits[0] = num%10;
	digits[1] = (num/10)%10;
	digits[2] = (num/100)%10;
	if ((digits[0] == digits[1]) ||
		(digits[0] == digits[2]) ||
		(digits[1] == digits[2]) )
		is_different = 0;

	return is_different;
}

/**
* @brief : generate and return a random digit in 0~9
* @return : a digit in 0~9
* @param	 : none
*/
int generate_a_digit(void) {
	return (rand()%10);
}

/**
* @brief : get a guessed number from the Attacker
* @return : return an integer with 3 different digits in 0~9
* @param	 : none
*/
int guess_number(void) {
	int num;
	while (1) {
		printf("Enter your guess : ");
		scanf("%d",&num);
		if (num < 1000 && is_different_digits(num)) break;
		printf("Input Error !!! Wrong number format\n");
	}
	return num;
}

/**
* @brief : notify the match result of the guessed number to the Attacker
* @return : none
* @param	 : 	result - 2-digits number for the match result, 1st digit stands for the number of strikes and 2nd digit stands for the number of balls.
			guessed - 3-digits guessed integer
*/
void receive_match_result(int result, int guessed) {
	int n_strike = result/10, n_ball = result%10;
	switch (result) {
		case 30 : printf("Congratulation !!!\n");
			break;
		case 0 : printf("Oops !!!\n");
			break;
		default : printf("Nice try !!!\n");
	}
	printf("Your guess %d is [%d] strikes and [%d] balls\n",
		guessed, n_strike, n_ball);
}
