#pragma once
#include <d3d12.h>

enum class FadeState {
    NONE,
    FADE_IN,
    FADE_OUT
};

class Fade {
private:
    FadeState state;
    float alpha;
    float speed;

public:
    Fade();
    void Start(FadeState fadeType, float fadeSpeed);
    void Update();
    void Draw(); 

    bool IsFinished() const;
    float GetAlpha() const { return alpha; }
    FadeState GetState() const { return state; }
};
