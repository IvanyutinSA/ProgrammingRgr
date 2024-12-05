#include "algorithms.h"
#include <functional>
#include <iostream>
using namespace std;

class NonlinearAPI {
    public:
        void invoke(function<float(float)> f);
};

void NonlinearAPI::invoke(function<float(float)> f) {
    cout << 
        "Выберите метод:\n"
        "1. Деления пополам\n"
        "2. Хорд\n";
    float a, b, root;
    int method;
    cin >> method;
    cout << "Введите начало отрезка\n";
    cin >> a;
    cout << "Введите конец отрезка\n";
    cin >> b;
    switch(method) {
        case 1: 
            root = dichotomy_method(f, a, b);
            break;
        case 2:
            root = secant_method(f, a, b);
            break;
    }
    cout << "Найденный корень: " << root <<"\n";
}
