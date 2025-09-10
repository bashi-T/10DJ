#include "Fade.h"
#include <algorithm>

Fade::Fade() : state(FadeState::NONE), alpha(0.0f), speed(0.02f) {}

void Fade::Start(FadeState fadeType, float fadeSpeed) {
    state = fadeType;
    speed = fadeSpeed;
    if (fadeType == FadeState::FADE_IN) alpha = 1.0f;
    if (fadeType == FadeState::FADE_OUT) alpha = 0.0f;
}

void Fade::Update() {
    if (state == FadeState::FADE_IN) {
        alpha -= speed;
        if (alpha <= 0.0f) {
            alpha = 0.0f;
            state = FadeState::NONE;
        }
    }
    else if (state == FadeState::FADE_OUT) {
        alpha += speed;
        if (alpha >= 1.0f) {
            alpha = 1.0f;
            state = FadeState::NONE;
        }
    }
}

bool Fade::IsFinished() const {
    return state == FadeState::NONE;
}

void Fade::Draw() {
    if (alpha <= 0.0f) return;
    // TODO: KamataEngine の Sprite で黒四角を画面全体に描画
    // alpha 値を乗算してブレンドする
}
