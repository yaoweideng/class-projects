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

// returns x_i
double x_i(double a, double b, double n, double i){
    double z = h(a, b, n);
    return a + (i * z);
}

// returns x_i+1/2
double x_i_half(double a, double b, double n, double i){
    double z = h(a, b, n);
    return a + ((i + 0.50) * z);
}

// returns x_i+1
double x_i2(double a, double b, double n, double i){
    double z = h(a, b, n);
    return a + ((i + 1.0) * z);
}

// returns S_i
double S_i(double a, double b){
    double c = (a + b) / 2.0;
    return ((f(a) + 4.0 * f(c) + f(b)) / 6.0) * (b - a);
}

// returns sum of all S_i's
double S_sum(double a, double b, double n){
    double sum = 0;
    double x, x2;
    double S;
    for(int i = 0; i < n; i++){
        x = x_i(a, b, n, i);
        x2 = x_i2(a, b, n, i);
        sum += S_i(x, x2);
    }
    return sum;
}

// returns T_i
double T_i(double a, double b){
    return ((f(a) + f(b)) / 2) * (b - a);
}

// returns |I_ab - S|
double I_ab(double a, double b, double n){
    double I = b * sin(b) + cos(b) - a * sin(a) - cos(a);
    return fabs(I - S_sum(a, b, n));
}

// returns sum of |S_i - T_i|
double E_sum(double a, double b, double n){
    double sum = 0;
    double x, x2, x3;
    for(int i = 0; i < n; i++){
        x = x_i(a, b, n, i);
        x2 = x_i_half(a, b, n, i);
        x3 = x_i2(a, b, n, i);
        sum += fabs(S_i(x, x3) - T_i(x, x2) - T_i(x2, x3)); // splits T_i into two, as defined
    }
    return sum;
}

int main(){
    double a = 1.0;
    double b = 10.0;
    double n[4] = {10, 20, 50, 100};
    double S[4];
    double I[4];
    double E[4];

    for(int i = 0; i < 4; i++){
        S[i] = S_sum(a, b, n[i]);
        E[i] = E_sum(a, b, n[i]);
        I[i] = I_ab(a, b, n[i]);
        printf("\nFor n = %g, S = %.30f", n[i], S[i]);
        printf("\nFor n = %g, |I_ab - S| = %.30f", n[i], I[i]);
        printf("\nFor n = %g, E = %.30f", n[i], E[i]);
        printf("\n");
    }
    printf("\n");

    return 0;
}