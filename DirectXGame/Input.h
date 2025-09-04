#pragma once
#include <KamataEngine.h>
#include <windows.h>

class Input {
public:
    static POINT GetMousePosition(HWND hwnd);
    static bool IsMouseDown();
};

