#include "Fade.h"
#include <algorithm>

Fade::~Fade()
{
    delete sprite_;
}

void Fade::Initialize()
{
	 uint32_t texture = TextureManager::Load("Fade.png"); // 画像ファイル名を指定
     Vector2 position={0,0};
    // スプライト生成
    sprite_ = Sprite::Create(texture,position); // 画面の中心に配置


}

void Fade::Update()
{
    // フェード状態による分岐
switch (status_) {
case Status::None:
    // 何もしない
    break;
case Status::FadeIn:
    // 1フレーム分の秒数をカウントアップ
    counter_ += 1.0f / 60.0f;
    // フェード継続時間に達したら打ち止め
   // 1フレーム分の秒数をカウントアップ
counter_ += 1.0f / 60.0f;
// フェード継続時間に達したら打ち止め
if (counter_ >= duration_) {
    counter_ = duration_;
}
// 1.0fから0.0fに向かってアルファ値を小さくしていく
sprite_->SetColor(Vector4(0, 0, 0, 1.0f - std::clamp(counter_ / duration_, 0.0f, 1.0f)));

    break;
case Status::FadeOut:
    // 1フレーム分の秒数をカウントアップ
    counter_ += 1.0f / 60.0f;
    // フェード継続時間に達したら打ち止め
    if (counter_ >= duration_) {
     counter_ = duration_;
    }
    // 0.0fから1.0fの間で、経過時間がフェード継続時間に近づくほどアルファ値を大きくする
    sprite_->SetColor(Vector4(0, 0, 0, std::clamp(counter_ / duration_, 0.0f, 1.0f)));
    break;
}
}

void Fade::Draw()
{
    if(status_==Status::None){
    return;
    }
    Sprite::PreDraw();
    sprite_->Draw();
    Sprite::PostDraw();
}

void Fade::Start(Status status, float duration)
{
    status_=status;
    duration_=duration;
    counter_=0.0f;
}

void Fade::Stop()
{
    status_=Status::None;
}

bool Fade::IsFinishd() const
{
    switch (status_) {
case Status::FadeIn:
case Status::FadeOut:
    if (counter_ >= duration_) {
        return true;
    } else {
        return false;
    }
}
    return false;
}
