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
        "�������� �����:\n"
        "1. ������� �������\n"
        "2. ����\n";
    float a, b, root;
    int method;
    cin >> method;
    cout << "������� ������ �������\n";
    cin >> a;
    cout << "������� ����� �������\n";
    cin >> b;
    switch(method) {
        case 1: 
            root = dichotomy_method(f, a, b);
            break;
        case 2:
            root = secant_method(f, a, b);
            break;
    }
    cout << "��������� ������: " << root <<"\n";
}
