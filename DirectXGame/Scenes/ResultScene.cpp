#include "ResultScene.h"

using namespace KamataEngine;

void ResultScene::Initialize()
{
	if (isClear_)
	{
		textureHandle_ = TextureManager::Load("tex1.png");
		sprite_ = Sprite::Create(textureHandle_, {100, 50});
	}
	else
	{
		textureHandle_ = TextureManager::Load("uvChecker.png");
		sprite_ = Sprite::Create(textureHandle_, {100, 50});
	}
}

std::unique_ptr<BaseScene> ResultScene::Update()
{


#ifdef _DEBUG
	ImGui::Begin("RESULT");
	ImGui::Text("isClear: %s", isClear_ ? "true" : "false");
	ImGui::End();
#endif

	if (isTitleScene_ == true)
	{
		return std::make_unique<TitleScene>();
	}
	else if (isSelectScene_ == true)
	{
		return std::make_unique<SelectScene>();
	}
	else if (isInGameScene_ == true)
	{
		return std::make_unique<InGameScene>();
	} else
	{
		return nullptr;
	}
}

void ResultScene::Draw() 
{ 
	Sprite::PreDraw();
	sprite_->Draw();
	Sprite::PostDraw();
}
