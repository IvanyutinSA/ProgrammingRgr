#include <iostream>
#include "algorithms.h"
#include <functional>
using namespace std;
class IntegralAPI {
    public:
        void invoke(function<float(float)> f);
};

void IntegralAPI::invoke(function<float(float)> f) {
    float a, b, integral;
    cout << "start\n";
    cin >> a;
    cout << "end\n";
    cin >> b;
    cout << "Result: " 
         << definite_integral(f, a, b)
         << '\n';
}
