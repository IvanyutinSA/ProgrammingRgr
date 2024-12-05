#include "lib/api.h"
#include <iostream>
#include <string>
#include <functional>
#include <conio.h>
using namespace std;

void default_option();

int stop = 0;
double f(double x) {
    return x*x-1;
}

int main() {
    int option;
    setlocale(LC_ALL, "RU");
    while (!stop) {
        cout <<
            "Menu:\n"
            "0. Author\n"
            "1. Intro\n"
            "2. Table\n"
            "3. Plot\n"
            "4. Equation\n"
            "5. Definite integral\n"
            "6. Exit\n";
        cin >> option;
        system("cls");
        switch (option) {
            case 0:
                CredentialsAPI().invoke();
                break;
            case 1:
                AnimationAPI().invoke();
                break;
            case 2:
                FunctionAPI().invoke(f, "table");
                break;
            case 3:
                FunctionAPI().invoke(f, "plot");
                break;
            case 4:
                NonlinearAPI().invoke(f);
                break;
            case 5:
                IntegralAPI().invoke(f);
                break;
            case 6:
                stop = 1;
                break;
            default:
                default_option();
                break;
        }
        getch();
        system("cls");
    }
}

void default_option() {
    cout << "Incorrect option.\nTry again\n";
}

