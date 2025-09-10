#include "TitleScene.h"
using namespace KamataEngine;

TitleScene::TitleScene() {}

TitleScene::~TitleScene() {
	delete bgSprite_;
	delete titleSprite_;
	delete fade_;
}

void TitleScene::Initialize()
{

	fade_ = new Fade();
	bgHandle_ = TextureManager::Load("Titlebg.png");
	titleHandle_ = TextureManager::Load("Title.png");

	bgSprite_ = Sprite::Create(bgHandle_, {0, 0});
	titleSprite_ = Sprite::Create(titleHandle_, {-100, -100});
}

std::unique_ptr<BaseScene> TitleScene::Update()
{

	if (Input::GetInstance()->TriggerKey(DIK_SPACE))
	{
		if (fade_->GetState() == FadeState::NONE) {
			fade_->Start(FadeState::FADE_OUT, 0.02f);
		}
	}

	fade_->Update();

#ifdef _DEBUG 
	ImGui::Begin("TITLE");
	ImGui::End();
#endif
	if (fade_->GetState() == FadeState::NONE && fade_->GetAlpha() >= 1.0f)
	{
		return std::make_unique<SelectScene>();
	} 
	else
	{
		return nullptr;
	}
}

void TitleScene::Draw() 
{
	Sprite::PreDraw();
	bgSprite_->Draw();
	titleSprite_->Draw();
	fade_->Draw();
	Sprite::PostDraw();
}
