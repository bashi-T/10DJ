#pragma once
#include "KamataEngine.h"
using namespace KamataEngine;

enum class FadeState {
    NONE,
    FADE_IN,
    FADE_OUT
};

class Fade {
public:
     void Initialize();
    void Update();
    void Draw();

private:

    Sprite*sprite_=nullptr;
};

