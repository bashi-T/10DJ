#include "Fade.h"

void Fade::Initialize()
{
	 uint32_t texture = TextureManager::Load("Fade.png"); // 画像ファイル名を指定

    // スプライト生成
    sprite_ = Sprite::Create(texture, Vector2(1280.0f / 2, 720.0f / 2)); // 画面の中心に配置

    // サイズと色を設定
    sprite_->SetSize(Vector2(1280.0f, 720.0f));
    sprite_->SetColor(Vector4(0, 0, 0, 1));
}

void Fade::Update()
{
}

void Fade::Draw()
{
    Sprite::PreDraw();
    sprite_->Draw();
    Sprite::PostDraw();
}
