#include "TitleScene.h"

void TitleScene::Initialize() {}

std::unique_ptr<BaseScene> TitleScene::Update()
{
#ifdef _DEBUG 
	ImGui::Begin("TITLE");
	ImGui::End();
#endif
	return nullptr;
}

void TitleScene::Draw() {}
