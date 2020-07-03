#include <stdio.h>
#include <math.h>

// returns h
double h(double a, double b, double n){
    return (b - a) / n;
}

// given function
double f(double x){
    return x * cos(x);
}

// returns S_i
double S_i(double a, double b){
    double c = (a + b) / 2.0;
    return ((f(a) + 4.0 * f(c) + f(b)) / 6.0) * (b - a);
}

// returns T_i
double T_i(double a, double b){
    return ((f(a) + f(b)) / 2) * (b - a);
}

double R_ab(double a, double b){
    double c = (a + b) / 2.0;
    return (16 * S_i(a, c) + 16 * S_i(c, b) - S_i(a, b)) / 15;
}

int main(){
    double a = 1.0;
    double b = 10.0;
    double n = 10.0;
    double R;

    return 0;
}