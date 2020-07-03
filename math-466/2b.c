#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//polynomial
int p(int x){
	return pow(x, 3) + x + 1;
}

int main(){
	
	int n = 20;
	int seed[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
	int i = 0;

	//prints output
	for(int i = 0; i < n; i++){
		printf("p(%d) = (%.2d)^3 + %.2d + 1 = %.2d \n", seed[i], seed[i], seed[i], p(seed[i]));
	}

	return 0;
}