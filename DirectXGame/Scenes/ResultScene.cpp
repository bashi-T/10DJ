#include "ResultScene.h"

using namespace KamataEngine;

void ResultScene::Initialize()
{
	if (isClear_)
	{
		textureHandleResult_ = TextureManager::Load("tex1.png");
		result = Sprite::Create(textureHandleResult_, {100, 50}, {1, 1, 1, 1}, {0.5,0.5});
	}
	else
	{
		textureHandleResult_ = TextureManager::Load("uvChecker.png");
		result = Sprite::Create(textureHandleResult_, { 100, 50 }, {1, 1, 1, 1}, {0.5, 0.5});
	}

	textureHandleTitle_ = TextureManager::Load("title.png");
	title = Sprite::Create(textureHandleTitle_, { 400, 250 }, {1, 1, 1, 1}, {0.5, 0.5});
	textureHandleSelect_ = TextureManager::Load("select.png");
	select = Sprite::Create(textureHandleSelect_, { 400, 400 }, {1, 1, 1, 1}, {0.5, 0.5});
	textureHandleRetry_ = TextureManager::Load("retry.png");
	retry = Sprite::Create(textureHandleRetry_, { 400, 550 }, {1, 1, 1, 1}, {0.5, 0.5});
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
