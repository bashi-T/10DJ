#pragma once
#include "KamataEngine.h"
#include "Fade.h"
using namespace KamataEngine;

class TitleScene {
public:
    TitleScene();
    ~TitleScene();

    void Initialize();
    void Update(Fade& fade);
    void Draw(Fade& fade);

private:
    Sprite* bgSprite_ = nullptr;
    Sprite* titleSprite_ = nullptr;
    uint32_t bgHandle_ = 0;
    uint32_t titleHandle_ = 0;

    int screenWidth = 1280;
    int screenHeight = 720;
};
