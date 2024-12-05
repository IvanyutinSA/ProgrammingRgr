#include "lib/api.h"
#include "lib/algorithms.h"
#include <iostream>
#include <map>
#include <string>
#include <functional>
using namespace std;

string default_option(vector<string> args);
string menu(vector<string> args);

int stop = 0;
double f(double x) {
    return x*x-1;
}

int main() {
    int option;
    setlocale(LC_ALL, "RU");
    cout <<
        "Меню:\n"
        "1. Заставка\n"
        "2. Рассчёт таблиц\n"
        "3. Построение графика\n"
        "4. Решение нелинейного уравнения\n"
        "5. Взятие определённого интеграла\n";
    cin >> option;
    switch (option) {
        case 4:
            NonlinearAPI().invoke(f);
            break;
        case 5:
            IntegralAPI().invoke(f);
    }
}

string default_option(vector<string> _) {
    cout << "Incorrect option.\nTry again\n";
    return "";
}

