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

// int wmain() {
int main() {
    int option;
    setlocale(LC_ALL, "RU");
    cout <<
        "Menu:\n"
        "1. Intro\n"
        "2. Table\n"
        "3. Plot\n"
        "4. Equation\n"
        "5. Definite integral\n";
    cin >> option;
    switch (option) {
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
    }
}

string default_option(vector<string> _) {
    cout << "Incorrect option.\nTry again\n";
    return "";
}

