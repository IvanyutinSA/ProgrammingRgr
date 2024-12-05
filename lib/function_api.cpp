#include "/usr/x86_64-w64-mingw32/sys-root/mingw/include/windows.h"
#include "/usr/x86_64-w64-mingw32/sys-root/mingw/include/conio.h"
// #include <windows.h>
#include <math.h>
#include <iostream>
#include <functional>
#include <string>
using namespace std;

class FunctionAPI {
    public:
        void invoke(function<float(float)> f, string action_name);
    private:
        void table(function<float(float)> f);
        void plot(function<float(float)> f);
        vector<vector<float>> get_table(function<float(float)>, float x, float y, int n);
};

vector<vector<float>> FunctionAPI::get_table(function<float(float)> f, float x, float y, int n) {
    float step;
    vector<vector<float>> table;
    vector<float> pair;
    step = (y-x)/n;
    while (x <= y) {
        pair = vector<float>();
        pair.push_back(x);
        pair.push_back(f(x));
        table.push_back(pair);
        x += step;
    };
    return table;
}

void FunctionAPI::invoke(function<float(float)> f, string action_name) {
    if (action_name == "table") {
        FunctionAPI::table(f);
    } else
    if (action_name == "plot") {
        FunctionAPI::plot(f);
    } else {
    }
}

void FunctionAPI::table(function<float(float)> f) {
    float x, y, step;
    int n;
    vector<vector<float>> table;

    cout << "start\n";
    cin >> x;
    cout << "end\n";
    cin >> y;
    cout << "number of partitions\n";
    cin >> n;

    table = FunctionAPI::get_table(f, x, y, n);

    cout << "x\tf(x)\n";
    for (vector<float> xf : table) {
        cout << xf[0] << '\t'
             << xf[1] << '\n';
    }
}

void FunctionAPI::plot(function<float(float)> f) {
    float x, y, step; 
    vector<vector<float>> table;

    // cout << "start\n";
    // cin >> x;
    // cout << "end\n";
    // cin >> y;

    table = FunctionAPI::get_table(f, x, y, (int)(y-x)/step);

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

    bool first = true;
    float h;
    h = 0.001;
    float a = -4;
    float b = 4;

    for (x = a; x < b; x += h) {
        if (first) {
            SelectObject(hdc, pen);
            MoveToEx(hdc, c+k*x, d-k*f(x), NULL);
            first = false;
        } else {
            LineTo(hdc, c+k*x, d-k*f(x));
        }
    }

    getch();
    ReleaseDC(hwn, hdc);
}
