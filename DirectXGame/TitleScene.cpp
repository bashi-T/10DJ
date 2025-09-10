#include "TitleScene.h"
#include "SceneManager.h"
#include <dinput.h>

using namespace KamataEngine;

TitleScene::TitleScene() {}

TitleScene::~TitleScene() {
    delete bgSprite_;
    delete titleSprite_;
}

void TitleScene::Initialize() {

    bgHandle_ = TextureManager::Load("Titlebg.png");
    titleHandle_ = TextureManager::Load("Title.png");

    bgSprite_ = Sprite::Create(bgHandle_, {1280,720});
    titleSprite_ = Sprite::Create(titleHandle_, { 1280,720 });
}

void TitleScene::Update(Fade& fade) {
    if (Input::GetInstance()->TriggerKey(DIK_SPACE)) {
        if (fade.GetState() == FadeState::NONE) {
            fade.Start(FadeState::FADE_OUT, 0.02f);
        }
    }

    fade.Update();

    if (fade.GetState() == FadeState::NONE && fade.GetAlpha() >= 1.0f) {
        SceneManager::ChangeScene(STAGE_SELECT);
        fade.Start(FadeState::FADE_IN, 0.02f);
    }
}

void TitleScene::Draw(Fade& fade) {
    titleSprite_->Draw();
    bgSprite_->Draw();
    fade.Draw();
}
