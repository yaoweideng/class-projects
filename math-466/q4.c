#include <math.h>
#include <stdio.h>

double f(double x){
	return x * cos(x);
}

double f_4(double x){
	return 4 * sin(x) + x * cos(x);
}

double S_ab(double T_ac, double T_cb, double T_ab){
	return (4 * T_ac + 4 * T_cb - T_ab) / 3;
}

double T_ac(double a, double b){
	return (f(a) + f((a + b) / 2)) / 2 * (((a + b) / 2) - a);
}

double T_cb(double a, double b){
	return (f((a + b) / 2) + f(b)) / 2 * (b - ((a + b) / 2));
}

double T_ab(double a, double b){
	return (f(a) + f(b)) / 2 * (b - a);
}

double I_ab(double a, double b){
	double epsilon = (b - a) / 2;
	double f4 = f_4(epsilon);

	return S_ab(T_ac(a, b), T_cb(a, b), T_ab(a, b)) - ((f4 / 2880) * pow((b - a), 5));
}


int main(){
	double a = 1.0;
	double b[4] = {2.0, 1.1, 1.01, 10.0};
	double I, T1, T2, T3, S;
	double answer1, answer2, answer3;

	for(int i = 0; i < 4; i++){
		I = I_ab(a, b[i]);
		T1 = T_ac(a, b[i]);
		T2 = T_cb(a, b[i]);
		T3 = T_ab(a, b[i]);
		S = S_ab(T1, T2, T3);
		answer1 = fabs(I - S);
		answer2 = fabs(I - T1 - T2);
		answer3 = fabs(S - T1 - T2);
		printf("\nFor b = %g: |%.15g| << |%.15g| ~ |%.15g|", b[i], answer1, answer2, answer3);
	}
	printf("\n\n");
	
	return 0;
}
