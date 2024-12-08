#include <stdio.h> 
/**
* @brief : compare the guessed number with the target and return the match results
* @return : return 2-digits number, 1st digit stands for the number of strikes and 2nd digit stands for the number of balls. For example 11 means 1 strike 1 ball
* @param	 : 	target - 3-digits target integer
			guessed - 3-digits guessed integer
*/
int get_match_result(int target, int guessed) {
	int n_strike=0, n_ball=0;
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

	return (n_strike*10 + n_ball);
}

// Test codes below are hidden intentionally
int main(void) {
	int n_target[10] = {742,864,135,61,658,192,167,217,680,183};
	int n_guess[10] = {618,278,805,410,89,912,317,721,650,183};
	int n_answer[10] = {0,1,10,2,1,12,11,3,20,30};
	
	int i, n_correct = 0;
	
	for (i=0; i<10; i++) 
		if (get_match_result(n_target[i],n_guess[i])==n_answer[i]) 	n_correct++;
		else break;	
	
	if (n_correct < 10) 
		printf("Sorry, Your function does not pass the test\n");
	else
		printf("Good, Your function pass the test\n");
	
	return 0;
}