#pragma once
#include <windows.h>
#include <KamataEngine.h>

class Input {
public:
    static POINT GetMousePosition(HWND hwnd);
    static bool IsMouseDown();
};
