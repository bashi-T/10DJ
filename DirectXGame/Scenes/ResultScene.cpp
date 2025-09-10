#include "ResultScene.h"

using namespace KamataEngine;

ResultScene::ResultScene()
{
}

ResultScene::~ResultScene()
{
	delete fade_;
}

void ResultScene::Initialize()
{
	if (isClear_)
	{
		textureHandleResult_ = TextureManager::Load("result.png");
		result = Sprite::Create(textureHandleResult_, {600, 50}, {1, 1, 1, 1}, {0.5,0.5});
	}
	else
	{
		textureHandleResult_ = TextureManager::Load("result.png");
		result = Sprite::Create(textureHandleResult_, { 600, 50 }, {1, 1, 1, 1}, {0.5, 0.5});
	}

	textureHandleTitle_ = TextureManager::Load("title.png");
	title = Sprite::Create(textureHandleTitle_, posTitle_, {1, 1, 1, 1}, {0.5, 0.5});
	textureHandleSelect_ = TextureManager::Load("select.png");
	select = Sprite::Create(textureHandleSelect_, posSelect_, {1, 1, 1, 1}, {0.5, 0.5});
	textureHandleRetry_ = TextureManager::Load("retry.png");
	retry = Sprite::Create(textureHandleRetry_, posRetry_, {1, 1, 1, 1}, {0.5, 0.5});

fade_=new Fade();
fade_->Initialize();
fade_->Start(Fade::Status::FadeIn,1);


}

std::unique_ptr<BaseScene> ResultScene::Update()
{


#ifdef _DEBUG
	ImGui::Begin("RESULT");
	ImGui::Text("isClear: %s", isClear_ ? "true" : "false");
	ImGui::End();
#endif
	if (Input::GetInstance()->IsTriggerMouse(0))
	{
		if (isCollisionToMouse({ 5, 5 }, posTitle_, { 128,128 }))
		{
			isTitleScene_ = true;
		}
		else if (isCollisionToMouse({ 5, 5 }, posSelect_, { 128, 128 }))
		{
			isSelectScene_ = true;
		}
		else if (isCollisionToMouse({ 5, 5 }, posRetry_, { 128, 128 }))
		{
			isInGameScene_ = true;
		}
	}
	fade_->Update();

	if (isTitleScene_ == true)
	{
		fade_->Start(Fade::Status::FadeOut,1);
		return std::make_unique<TitleScene>();
	}
	else if (isSelectScene_ == true)
	{
		fade_->Start(Fade::Status::FadeOut,1);
		return std::make_unique<SelectScene>();
	}
	else if (isInGameScene_ == true)
	{
		fade_->Start(Fade::Status::FadeOut,1);
		return std::make_unique<InGameScene>();
	}
	else
	{
		return nullptr;
	}

	
}

void ResultScene::Draw() 
{ 
	Sprite::PreDraw();
	result->Draw();
	title->Draw();
	select->Draw();
	retry->Draw();
	fade_->Draw();
	Sprite::PostDraw();
}
