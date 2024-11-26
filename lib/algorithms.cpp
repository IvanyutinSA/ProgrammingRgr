#include <stdio.h>
#include <cstdlib>
#include <functional>
#include <stdexcept>
using namespace std;

float dichotomy_method(function<float(float)> f, float a, float b, float e=0.0001) {
    if (f(a)*f(b)>0) {
        throw invalid_argument("f(a) and f(b) have same sign");
    }
    float x;
    x = a;
    while (abs(f(x))>=e) {
        // printf("f:%f\ta:%f\tb:%f\n", f(x), a, b);
        x = (a+b)/2;
        if (f(a)*f(x) < 0) {
            b = x;
        } else {
            a = x;
        }
    }
    return x;
}
    

float secant_method(function<float(float)> f, float a, float b, float e=0.0001) {
    if (f(a)*f(b)>0) {
        throw invalid_argument("f(a) and f(b) have same sign");
    }
    float x;
    x = a;
    while (abs(f(x))>=e) {
        x = (a*f(b)-b*f(a))/(f(b)-f(a));
        if (f(a)*f(x) < 0) {
            b = x;
        } else {
            a = x;
        }
    }
    return x;
}


float definite_integral(function<float(float)> f, float a, float b, int n=50) {
    float step, x, accumulated_sum;
    step = (b-a)/n;
    x = a+step;
    for (x = a+step/2; x <= b; x += step) {
        accumulated_sum += f(x)*step;
    }
    return accumulated_sum;
}

