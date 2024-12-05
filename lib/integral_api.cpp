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
    cout << "������� ������ �������\n";
    cin >> a;
    cout << "������� ����� �������\n";
    cin >> b;
    cout << "�������� ������������ ���������: " 
         << definite_integral(f, a, b)
         << '\n';
}
