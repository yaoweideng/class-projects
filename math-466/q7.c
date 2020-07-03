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

// returns T_i
double T_i(double a, double b){
    return ((f(a) + f(b)) / 2) * (b - a);
}

// quad recursive function
double quad(double a, double b, double epsilon){
    double c = (a + b) / 2.0;
    if(fabs(S_i(a, b) - T_i(a, c) - T_i(c, b)) < epsilon){
        return S_i(a, b);
    } else {
        return quad(a, c, epsilon / 2) + quad(c, b, epsilon / 2);
    }
}

// returns sum of all quads
double quad_sum(double a, double b, double epsilon, double n){
    double sum = 0;
    double x, x2;
    double e_n = epsilon / n;
    for(int i = 0; i < n; i++){
        x = x_i(a, b, n, i);
        x2 = x_i2(a, b, n, i);
        sum += quad(x, x2, e_n);
    }
    
    return sum;
}

int main(){
    double a = 1.0;
    double b = 10.0;
    double n[5] = {5.0, 10.0, 20.0, 50.0, 100.0};
    double epsilon = 10e-7;
    double answer;

    for(int i = 0; i < 5; i++){
        answer = quad_sum(a, b, epsilon, n[i]);
        printf("\nFor n = %g, I_ab = %.30g", n[i], answer);
    }
    printf("\n\n");

    return 0;
}