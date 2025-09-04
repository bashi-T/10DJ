#pragma once
#include "Object.h"
#include "Fade.h"
#include <windows.h>

class TitleScene {
private:
    Object paper;
    Object bin;
    bool isDragging;

public:
    TitleScene();
    void Update(HWND hwnd, Fade& fade);
    void Draw(ID3D12GraphicsCommandList* cmdList, Fade& fade);
};
