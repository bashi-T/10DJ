#include "ResultScene.h"

using namespace KamataEngine;

ResultScene::ResultScene() {}

ResultScene::~ResultScene() { delete sprite_; }

void ResultScene::Initialize(bool isClear)
{
	isClear_ = isClear;
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

void ResultScene::Update()
{


#ifdef _DEBUG
	ImGui::Begin("RESULT");
	ImGui::Text("isClear: %s", isClear_ ? "true" : "false");
	ImGui::End();
#endif
}

void ResultScene::Draw() 
{ 
	Sprite::PreDraw();
	sprite_->Draw();
	Sprite::PostDraw();
}
