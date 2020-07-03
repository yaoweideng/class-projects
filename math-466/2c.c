#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//polynomial
int p(int x){
	return pow(x, 3) + x + 1;
}

int main(){
	int n = 4;
	
	for(int j = 1; j < 21; j++){
		int seed = p(j);
		srandom(seed);
		printf("For S = {p(i): i = %d}:\n", j);
		for(int i = 0; i < n; i++){
			double epsilon = 0.0000001 * random() / RAND_MAX - 0.00000005;
			printf("%g\n", epsilon);
		}
		printf("\n");
	}
	return 0;
}