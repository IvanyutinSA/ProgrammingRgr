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
    cout << "Введите начало отрезка\n";
    cin >> a;
    cout << "Введите конец отрезка\n";
    cin >> b;
    cout << "Значение определённого интеграла: " 
         << definite_integral(f, a, b)
         << '\n';
}
