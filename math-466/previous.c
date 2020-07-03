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
	double b = 2.0;
	double b2 = 1.1;
	double b3 = 1.01;
	double b4 = 10.0;

	//For b = 2.0
	double I = I_ab(a, b);
	double T1 = T_ac(a, b);
	double T2 = T_cb(a, b);
	double T3 = T_ab(a, b);
	double S = S_ab(T1, T2, T3);

	double answer1b = fabs(I - S);
	double answer2b = fabs(I - T1 - T2);
	double answer3b = fabs(S - T1 - T2);
	printf("\nFor b = 2.0: |%.15g| << |%.15g| ~ |%.15g|\n", answer1b, answer2b, answer3b);

	//For b = 1.1	
	double I2 = I_ab(a, b2);
	double T1_2 = T_ac(a, b2);
	double T2_2 = T_cb(a, b2);
	double T3_2 = T_ab(a, b2);
	double S2 = S_ab(T1_2, T2_2, T3_2);

	double answer1b2 = fabs(I2 - S2);
	double answer2b2 = fabs(I2 - T1_2 - T2_2);
	double answer3b2 = fabs(S2 - T1_2 - T2_2);
	printf("\nFor b = 1.1: |%.15g| << |%.15g| ~ |%.15g|\n", answer1b2, answer2b2, answer3b2);

	//For b = 1.01	
	double I3 = I_ab(a, b3);
	double T1_3 = T_ac(a, b3);
	double T2_3 = T_cb(a, b3);
	double T3_3 = T_ab(a, b3);
	double S3 = S_ab(T1_3, T2_3, T3_3);

	double answer1b3 = fabs(I3 - S3);
	double answer2b3 = fabs(I3 - T1_3 - T2_3);
	double answer3b3 = fabs(S3 - T1_3 - T2_3);
	printf("\nFor b = 1.01: |%.15g| << |%.15g| ~ |%.15g|\n", answer1b3, answer2b3, answer3b3);

	//For b = 10.0	
	double I4 = I_ab(a, b4);
	double T1_4 = T_ac(a, b4);
	double T2_4 = T_cb(a, b4);
	double T3_4 = T_ab(a, b4);
	double S4 = S_ab(T1_4, T2_4, T3_4);

	double answer1b4 = fabs(I4 - S4);
	double answer2b4 = fabs(I4 - T1_4 - T2_4);
	double answer3b4 = fabs(S4 - T1_4 - T2_4);
	printf("\nFor b = 10.0: |%.15g| << |%.15g| ~ |%.15g|\n\n", answer1b4, answer2b4, answer3b4);
	
	return 0;
}