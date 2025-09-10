#include "InGameScene.h"
#include "Math\CGVector.h"

using namespace KamataEngine;

InGameScene::InGameScene() {}

InGameScene::~InGameScene() 
{

	delete inGameController_;
}

void InGameScene::Initialize() 
{
	worldTransform_.Initialize();
	camera_.Initialize();
	SceneManager::GetInstance()->SetIsClear(false);
	inGameController_ = new InGameController({(float)KamataEngine::WinApp::kWindowWidth, (float)KamataEngine::WinApp::kWindowHeight});
	inGameController_->Initialize();

	fade_ = new Fade();
}

std::unique_ptr<BaseScene> InGameScene::Update()
{
	if (Input::GetInstance()->TriggerKey(DIK_0)) {
		inGameController_->Initialize();
	}
	inGameController_->Update();

	if (inGameController_->IsGameEndFlag())
	{
		if (fade_->GetState() == FadeState::NONE)
		{
			fade_->Start(FadeState::FADE_OUT, 0.02f);
		}
	}

	fade_->Update();

#ifdef _DEBUG
	ImGui::Begin("INGAME");
	ImGui::End();
#endif

	if (fade_->GetState() == FadeState::NONE && fade_->GetAlpha() >= 1.0f)
	{
		if (inGameController_->IsGameClearFlag())
		{
			SceneManager::GetInstance()->SetIsClear(inGameController_->IsGameClearFlag());
		}
		return std::make_unique<ResultScene>();
	} else {
		return nullptr;
	}
}

void InGameScene::Draw() 
{
	inGameController_->Draw();
	fade_->Draw();
}
