#include "InGameScene.h"
#include "Math\CGVector.h"

using namespace KamataEngine;

InGameScene::InGameScene() {}

InGameScene::~InGameScene() 
{
	delete fade_;
	delete inGameController_;
}

void InGameScene::Initialize() 
{
	worldTransform_.Initialize();
	camera_.Initialize();

	inGameController_ = new InGameController({(float)KamataEngine::WinApp::kWindowWidth, (float)KamataEngine::WinApp::kWindowHeight});
	inGameController_->Initialize();

	fade_=new Fade();
fade_->Initialize();
fade_->Start(Fade::Status::FadeIn,1);

}

std::unique_ptr<BaseScene> InGameScene::Update()
{
	if (Input::GetInstance()->TriggerKey(DIK_0)) {
		inGameController_->Initialize();
	}
	inGameController_->Update();

	fade_->Update();

#ifdef _DEBUG 
	ImGui::Begin("INGAME");
	ImGui::End();
#endif
	return nullptr;
}

void InGameScene::Draw() 
{
	inGameController_->Draw();
	fade_->Draw();
}
