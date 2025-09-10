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
	uiTextureHandle_ = TextureManager::Load("UI_01.png");

	bgSprite_ = Sprite::Create(bgHandle_, {0, 0});
	titleSprite_ = Sprite::Create(titleHandle_, {-100, -200});
	UI_ = Sprite::Create(uiTextureHandle_, { 640,660 });
	UI_->SetAnchorPoint({ 0.5f,0.5f });

}

std::unique_ptr<BaseScene> TitleScene::Update()
{
	ShowCursor(true);

	if (Input::GetInstance()->IsTriggerMouse(0))
	{
		if (fade_->GetState() == FadeState::NONE) {
			fade_->Start(FadeState::FADE_OUT, 0.02f);
		}
		Audio::GetInstance()->PlayWave(Audio::GetInstance()->LoadWave("paper.mp3"));
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
	UI_->Draw();
	Sprite::PostDraw();
}
