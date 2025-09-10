#include "TitleScene.h"
#include "SceneManager.h"
#include <dinput.h>
using namespace KamataEngine;

TitleScene::TitleScene()
{
	
}

TitleScene::~TitleScene()
{
    delete bgSprite_;
    delete titleSprite_;
    delete fade_;
}

void TitleScene::Initialize() {
bgHandle_ = TextureManager::Load("Titlebg.png");
    titleHandle_ = TextureManager::Load("Title.png");
    Vector2 position={0,0};
    bgSprite_ = Sprite::Create(bgHandle_,position);
    titleSprite_ = Sprite::Create(titleHandle_,{-100,-150});

    fade_=new Fade();
    fade_->Initialize();
    fade_->Start(Fade::Status::FadeIn,1);
}

std::unique_ptr<BaseScene> TitleScene::Update()
{
     if (Input::GetInstance()->TriggerKey(DIK_SPACE)) {
      fade_->Start(Fade::Status::FadeOut,1);
    }

    fade_->Update();

#ifdef _DEBUG 
	ImGui::Begin("TITLE");
	ImGui::End();
#endif
	return nullptr;
}

void TitleScene::Draw() {
 Sprite::PreDraw();
    bgSprite_->Draw();
    titleSprite_->Draw();
    fade_->Draw();
    Sprite::PostDraw();
}
