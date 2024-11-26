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
    cout <<
        "Menu:\n"
        "1. Intro\n"
        "2. Calculate tables\n"
        "3. Make graph\n"
        "4. Solve non-linear equation\n"
        "5. Calculate defined integral\n";
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

