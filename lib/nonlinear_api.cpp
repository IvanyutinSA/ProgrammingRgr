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
        "Method\n"
        "1. dichotomy\n"
        "2. secant\n";
    float a, b, root;
    int method;
    cin >> method;
    cout << "start\n";
    cin >> a;
    cout << "end\n";
    cin >> b;
    switch(method) {
        case 1: 
            root = dichotomy_method(f, a, b);
            break;
        case 2:
            root = secant_method(f, a, b);
            break;
    }
    cout << "Result: " << root <<"\n";
}
