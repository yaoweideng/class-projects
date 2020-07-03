#include <stdio.h>
#include <math.h>

int main(){
	int n = 0;
	int count[9] = {0}; 
	
	for(int i = 1; i < 10; i++){
		for(int j = 1; j < 10; j++){
			for(int k = 1; k < 10; k++){
				//multiplying each number 
				n = i * j * k;
				
				//if number is one digit
				if(n / 10 == 0){
					count[n - 1]++;
				}

				//if number is two digits
				else if(n / 100 == 0){
					count[n / 10 - 1]++;
				}

				//if number is three digits
				else{
					count[n / 100 - 1]++;
				}
			}
		}
	}

	//keep track of the total number of counts(used for calculating percentage)
	float tnum = 0;
	for(int i = 0; i < 9; i++){
		tnum += count[i];
	}
	
	//output
	printf("#	digit	count	percent\n");
	for(int i = 0; i < 9; i++){
		printf("	%d	%.2d	%.2f\n", i + 1, count[i], count[i]*100/tnum);
	}

	return 0;
}

