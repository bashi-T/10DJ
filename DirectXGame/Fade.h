#pragma once
#include <d3d12.h>
#include <wrl.h>

// フェード状態
enum class FadeState {
    NONE,
    FADE_IN,
    FADE_OUT
};

// 定数バッファ構造体
struct FadeConstantBuffer {
    float alpha;
    float padding[3]; // 16バイト境界合わせ
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
    void Draw(ID3D12GraphicsCommandList* cmdList);

    bool IsFinished() const;
    float GetAlpha() const { return alpha; }
    FadeState GetState() const { return state; }
};

