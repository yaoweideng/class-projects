#include <stdio.h>
#include <math.h>

int main(){
	int n = 0;
	int count1[9] = {0}; 
	int count2[9] = {0};
	int count3[9] = {0};
	
	for(int x = 4; x < 7; x++){
		for(int i = 1; i < 10; i++){
			for(int j = 1; j < 10; j++){
				for(int k = 1; k < 10; k++){
					if(x == 4){
						for(int p = 1; p < 10; p++){
							n = i * j * k * p;
				
							//if number is one digit
							if(n / 10 == 0){
								count1[n - 1]++;
							}	

							//if number is two digits
							else if(n / 100 == 0){
								count1[n / 10 - 1]++;
							}
								
							//if number is three digits
							else if(n / 1000 == 0){
								count1[n / 100 - 1]++;
							}
					
							//if number is four digits
							else{
								count1[n / 1000 - 1]++;
							}
						}
					}
					if(x == 5){
						for(int p = 1; p < 10; p++){
							for(int q = 1; q < 10; q++){
								n = i * j * k * p * q;

								//if number is one digit
								if(n / 10 == 0){
									count2[n - 1]++;
								}	

								//if number is two digits
								else if(n / 100 == 0){
									count2[n / 10 - 1]++;
								}
								
								//if number is three digits
								else if(n / 1000 == 0){
									count2[n / 100 - 1]++;
								}
					
								//if number is four digits
								else if(n / 10000 == 0){
									count2[n / 1000 - 1]++;
								}

								//if number is five digits
								else{
									count2[n / 10000 - 1]++;
								}
							}
						}
					}
					if(x == 6){
						for(int p = 1; p < 10; p++){
							for(int q = 1; q < 10; q++){
								for(int r = 1; r < 10; r++){
									n = i * j * k * p * q * r;
	
									//if number is one digit
									if(n / 10 == 0){
										count3[n - 1]++;
									}

									//if number is two digits
									else if(n / 100 == 0){
										count3[n / 10 - 1]++;
									}
								
									//if number is three digits
									else if(n / 1000 == 0){
										count3[n / 100 - 1]++;
									}
					
									//if number is four digits
									else if(n / 10000 == 0){
										count3[n / 1000 - 1]++;
									}
		
									//if number is five digits
									else if(n / 100000 == 0){
										count3[n / 10000 - 1]++;
									}

									//if number is six digits
									else{
										count3[n / 100000 - 1]++;
									}
								}
							}
						}
					}
				}
			}
		}
	}

	//keep track of the total number of counts(used for calculating percentage)
	float tnum1, tnum2, tnum3 = 0;
	for(int i = 0; i < 9; i++){
		tnum1 += count1[i];
	}
	for(int i = 0; i < 9; i++){
		tnum2 += count2[i];
	}
	for(int i = 0; i < 9; i++){
		tnum3 += count3[i];
	}
	
	//output
	printf("\nFor n = 4:\n");
	printf("#	digit	count	percent\n");
	for(int i = 0; i < 9; i++){
		printf("	%d	%.2d	%.2f\n", i + 1, count1[i], count1[i]*100/tnum1);
	}

	printf("\nFor n = 5:\n");
	printf("#	digit	count	percent\n");
	for(int i = 0; i < 9; i++){
		printf("	%d	%.2d	%.2f\n", i + 1, count2[i], count2[i]*100/tnum2);
	}

	printf("\nFor n = 6:\n");
	printf("#	digit	count	percent\n");
	for(int i = 0; i < 9; i++){
		printf("	%d	%.2d	%.2f\n", i + 1, count3[i], count3[i]*100/tnum3);
	}

	return 0;
}