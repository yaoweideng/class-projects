#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//polynomial
int p(int x){
	return pow(x, 3) + x + 1;
}

double R(int n){
	double total1 = 0;
	double total2 = 0;

	for(int j = 1; j < 21; j++){
		int seed = p(j);
		srandom(seed);
		for(int i = 1; i < n + 1; i++){
			double epsilon = 0.0000001 * random() / RAND_MAX - 0.00000005;
			total1 += epsilon;
			//printf("total = %.2g\n", total1);
		}
		total2 += pow(fabs(total1), 2);
		total1 = 0;
	}

	return sqrt(1.0/20.0 * total2);
}

int main(){

	for(int k = 2; k < 21; k++){
		int n = pow(2, k);
		printf("for R_%d: %.4g\n", n, R(n)); 
	}

	return 0;
}
