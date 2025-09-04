#include "InGameScene.h"

void InGameScene::Initialize() {}

std::unique_ptr<BaseScene> InGameScene::Update()
{
#ifdef _DEBUG 
	ImGui::Begin("INGAME");
	ImGui::End();
#endif
	return nullptr;
}

void InGameScene::Draw() {}
