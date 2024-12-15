#include <functional>
#include <algorithm>
#include <vector>
#include <math.h>
#include "/usr/x86_64-w64-mingw32/sys-root/mingw/include/windows.h"
#include "/usr/x86_64-w64-mingw32/sys-root/mingw/include/conio.h"
#include <iostream>
#include <conio.h>
using namespace std;

void default_option();
void credentials();
void animation();
void table();
void plot();
void nonlinear_equation();
void defined_intergral();
void make_plot(function<float(float)> f, int *color_rgb);
void make_axes();

int main() {
    int stop = 0;
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
                credentials();
                break;
            case 1:
                animation();
                break;
            case 2:
                table();
                break;
            case 3:
                plot();
                break;
            case 4:
                nonlinear_equation();
                break;
            case 5:
                defined_intergral();
                break;
            case 6:
                return 0;
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

void credentials() {
    cout << "Author: Vitaliy Pudge, GG-173\n";
}

void animation() {
    float x;
    HWND hwn = GetConsoleWindow();
    HDC hdc = GetDC(hwn);
    RECT rect;
    GetClientRect(hwn, &rect);
    const int c = rect.right/2,
              d = rect.bottom/2,
              k = 100;

    int m = 4;
    HBRUSH brushes[m];
    float fade = 20;
    float bias = 0;
    for (int i = 0; i < m; i++) {
        brushes[i] = CreateSolidBrush(RGB(bias + fade*i, bias + fade*i, bias + fade*i));
    }

    int n = 100;

    for (int k = 0; k < 10; k++) {
        SelectObject(hdc, brushes[k%m]);
        Rectangle(hdc, c, d, c-n, d-n);
        SelectObject(hdc, brushes[(k+1)%m]);
        Rectangle(hdc, c, d, c+n, d-n);
        SelectObject(hdc, brushes[(k+2)%m]);
        Rectangle(hdc, c, d, c+n, d+n);
        SelectObject(hdc, brushes[(k+3)%m]);
        Rectangle(hdc, c, d, c-n, d+n);
        Sleep(0.5*1000);
    }

    ReleaseDC(hwn, hdc);
}

float table_f1(float x) {
    return sqrt(exp(x)-1);
}

float table_f2(float x) {
    return x*log(x)*log(x);
}

void table() {
    float x, a, b, step;
    int n;

    n = 20;
    float value_table[n][3];
    a = 0.01;
    b = 5;
    x = a;
    step = (b-a)/n;

    float dram_vals[4];

    cout << "x" << "\t"
         << "f(x)" << "\t"
         << "g(x)" << "\n";

    dram_vals[0] = +1000;
    dram_vals[1] = -1000;
    dram_vals[2] = +1000;
    dram_vals[3] = -1000;

    x = a;
    for (int i = 0; i < n; i++) {
        value_table[i][0] = (int)(x*100)/100.0;
        value_table[i][1] = (int)(100*table_f1(x))/100.0;
        value_table[i][2] = (int)(100*table_f2(x))/100.0;

        dram_vals[0] = min(dram_vals[0], value_table[i][1]);
        dram_vals[1] = max(dram_vals[1], value_table[i][1]);
        dram_vals[2] = min(dram_vals[2], value_table[i][2]);
        dram_vals[3] = max(dram_vals[3], value_table[i][2]);
        x += step;
    }

    for (int i = 0; i < n; i++) {
        cout << value_table[i][0] << "\t";
        if (dram_vals[0] == value_table[i][1]) {
            cout << "\033[34m" << value_table[i][1] <<"\033[00m\t";
        } else if (dram_vals[1] == value_table[i][1]){
            cout << "\033[91m" << value_table[i][1] <<"\033[00m\t";
        } else {
            cout << value_table[i][1] << "\t";
        }
        if (dram_vals[2] == value_table[i][2]) {
            cout << "\033[34m" << value_table[i][2] <<"\033[00m\n";
        } else if (dram_vals[3] == value_table[i][2]){
            cout << "\033[91m" << value_table[i][2] <<"\033[00m\n";
        } else {
            cout << value_table[i][2] << "\n";
        }
    }
}

void plot() {
    cout << "\033[31m*\033[0mf(x) = sqrt(exp(x)-1)\n";
    cout << "\033[34m*\033[0mg(x) = x*log^2(x)\n";
    make_axes();
    make_plot(table_f1, new int[] {255, 0, 0});
    make_plot(table_f2, new int[] {0, 0, 255});
}

void make_axes() {
    HWND hwn = GetConsoleWindow();
    HDC hdc = GetDC(hwn);
    RECT rect;
    GetClientRect(hwn, &rect);
    const int c = rect.right/2,
              d = rect.bottom/2,
              k = 100;

    HPEN pen = CreatePen(PS_DASH, 2, RGB(140, 90, 10));
    SelectObject(hdc, pen);
    MoveToEx(hdc, 0, d, NULL);
    LineTo(hdc, c*k, d);
    MoveToEx(hdc, c, 0, NULL);
    LineTo(hdc, c, k*d);
    ReleaseDC(hwn, hdc);
}

void make_plot(function<float(float)> f, int *color_rgb) {
    HWND hwn = GetConsoleWindow();
    HDC hdc = GetDC(hwn);
    RECT rect;
    GetClientRect(hwn, &rect);
    const int c = rect.right/2,
              d = rect.bottom/2,
              k = 100;

    HPEN pen = CreatePen(PS_DASH, 2, RGB(color_rgb[0], color_rgb[1], color_rgb[2]));
    SelectObject(hdc, pen);

    bool first = true;
    float h;
    h = 0.001;
    float a = 0;
    float b = 4;

    for (float x = a; x < b; x += h) {
        if (first) {
            SelectObject(hdc, pen);
            MoveToEx(hdc, c+k*x, d-k*f(x), NULL);
            first = false;
        } else {
            LineTo(hdc, c+k*x, d-k*f(x));
        }
    }
    ReleaseDC(hwn, hdc);
}

float dichotomy_method(function<float(float)> f, float a, float b, float e=0.0001) {
    if (f(a)*f(b)>0) {
        throw invalid_argument("f(a) and f(b) have same sign");
    }
    float x;
    x = a;
    while (abs(f(x))>=e) {
        // printf("f:%f\ta:%f\tb:%f\n", f(x), a, b);
        x = (a+b)/2;
        if (f(a)*f(x) < 0) {
            b = x;
        } else {
            a = x;
        }
    }
    return x;
}
    

float secant_method(function<float(float)> f, float a, float b, float e=0.0001) {
    if (f(a)*f(b)>0) {
        throw invalid_argument("f(a) and f(b) have same sign");
    }
    float x;
    x = a;
    while (abs(f(x))>=e) {
        x = (a*f(b)-b*f(a))/(f(b)-f(a));
        if (f(a)*f(x) < 0) {
            b = x;
        } else {
            a = x;
        }
    }
    return x;
}


float definite_integral(function<float(float)> f, float a, float b, float dx=0.01) {
    float step, x, accumulated_sum;
    step = dx;
    x = a+step;
    for (x = a+step/2; x <= b; x += step) {
        accumulated_sum += f(x)*step;
    }
    return accumulated_sum;
}


float equation(float x) {
    return 2*x*x*x - 3*x*x - 4;
}

void nonlinear_equation() {
    float a, b, root;
    a = 1;
    b = 3;
    cout << "Function: 2x^3-3x^2-4\n";
    cout << "Uncertenty interval: [1, 3]\n";
    root = dichotomy_method(equation, a, b);
    cout << "Dichotomy: "<< root << "\n";
    root = secant_method(equation, a, b);
    cout << "Secant: "<< root << "\n";

}

float integral_f(float x) {
    return 2*x*log10(x-3)-3;
}

void defined_intergral() {
    float a, b, s;
    s = 0;
    a = 4;
    b = 8;
    cout << "Function: 2xlg(x-3)-3\n";
    cout << "Integration interval: [4, 8]\n";
    s = definite_integral(integral_f, a, b);
    cout << "Definite integral: "<< s << "\n";
}
