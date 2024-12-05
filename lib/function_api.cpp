#include "/usr/x86_64-w64-mingw32/sys-root/mingw/include/windows.h"
// #include <conio.h>
// #include "/usr/x86_64-w64-mingw32/sys-root/mingw/include/conio.h"
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
    float x, y; 
    int n;
    vector<vector<float>> table;
    HPEN pen;
    HWND hwn;
    HDC hdc;
    HBRUSH brush;

    n = 200;

    cout << "start\n";
    cin >> x;
    cout << "end\n";
    cin >> y;

    table = FunctionAPI::get_table(f, x, y, n);

    hwn = GetConsoleWindow();
    hdc = GetDC(hwn); 

    pen = CreatePen(PS_SOLID, 3, RGB(255, 255, 255));
    brush = CreateSolidBrush(RGB(0, 0, 0));

    SelectObject(hdc, pen);
    MoveToEx(hdc, table[0][0], table[0][0], NULL);

    for (int i = 1; i < table.size(); i++) {
        LineTo(hdc, table[i][0], table[i][1]);
        MoveToEx(hdc, table[i][0], table[i][1], NULL);
    }

    cin >> y;
    ReleaseDC(hwn, hdc);
}
