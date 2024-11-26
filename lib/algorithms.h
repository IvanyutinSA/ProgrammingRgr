#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <functional>
using namespace std;

float dichotomy_method(function<float(float)> f, float a, float b, float e=0.0001);
float secant_method(function<float(float)> f, float a, float b, float e=0.0001);
float definite_integral(function<float(float)> f, float a, float b, int n=50);

#endif
