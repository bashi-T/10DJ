#include "ResultScene.h"

using namespace KamataEngine;

void ResultScene::Initialize()
{
	if (SceneManager::GetInstance()->GetIsClear())
	{
		textureHandleResult_ = TextureManager::Load("succeed.png");
		result = Sprite::Create(textureHandleResult_, {600, 150}, {1, 1, 1, 1}, {0.5,0.5});
	}
	else
	{
		textureHandleResult_ = TextureManager::Load("fail.png");
		result = Sprite::Create(textureHandleResult_, { 600, 150 }, {1, 1, 1, 1}, {0.5, 0.5});
	}

	textureHandleTitle_ = TextureManager::Load("toTitle.png");
	title = Sprite::Create(textureHandleTitle_, posTitle_, {1, 1, 1, 1}, {0.5, 0.5});
	textureHandleSelect_ = TextureManager::Load("select.png");
	select = Sprite::Create(textureHandleSelect_, posSelect_, {1, 1, 1, 1}, {0.5, 0.5});
	textureHandleRetry_ = TextureManager::Load("retry.png");
	retry = Sprite::Create(textureHandleRetry_, posRetry_, {1, 1, 1, 1}, {0.5, 0.5});
}

std::unique_ptr<BaseScene> ResultScene::Update()
{


#ifdef _DEBUG
	ImGui::Begin("RESULT");
	ImGui::Text("isClear: %s", SceneManager::GetInstance()->GetIsClear() ? "true" : "false");
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
	Sprite::PostDraw();
}
