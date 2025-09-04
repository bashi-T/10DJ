#include "SelectScene.h"

void SelectScene::Initialize() {}

std::unique_ptr<BaseScene> SelectScene::Update()
{
#ifdef _DEBUG 
	ImGui::Begin("SELECT");
	ImGui::End();
#endif
	return nullptr;
}

void SelectScene::Draw() {}
