#include "TitleScene.h"
#include "SceneManager.h"
#include <dinput.h>

using namespace KamataEngine;

TitleScene::TitleScene() {}

TitleScene::~TitleScene() {
    delete bgSprite_;
    delete titleSprite_;
    delete fade_;
}

void TitleScene::Initialize() {

    bgHandle_ = TextureManager::Load("Titlebg.png");
    titleHandle_ = TextureManager::Load("Title.png");

    bgSprite_ = Sprite::Create(bgHandle_, {1280,720});
    titleSprite_ = Sprite::Create(titleHandle_, { 1280,720 });

    fade_=new Fade();
    fade_->Initialize();
}

void TitleScene::Update() {
    if (Input::GetInstance()->TriggerKey(DIK_SPACE)) {
      
    }

    fade_->Update();

    
}

void TitleScene::Draw() {
    titleSprite_->Draw();
    bgSprite_->Draw();
    fade_->Draw();
}
