#include "/usr/x86_64-w64-mingw32/sys-root/mingw/include/windows.h"
#include "/usr/x86_64-w64-mingw32/sys-root/mingw/include/conio.h"
// #include <windows.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

class AnimationAPI {
    public:
        void invoke();
};

void AnimationAPI::invoke() {
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

    for (int k = 0; k < 1000000; k++) {
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
