#pragma once
#include "BaseScene.h"
#include "TitleScene.h"
#include "SelectScene.h"
#include "InGameScene.h"
#include "KamataEngine.h"

class ResultScene : public BaseScene
{
public:

	void Initialize();

	std::unique_ptr<BaseScene> Update();

	void Draw();

private:
	KamataEngine::Sprite* sprite_ = nullptr;
	bool isClear_ = false;
	bool isTitleScene_ = false;
	bool isSelectScene_ = false;
	bool isInGameScene_ = false;

	uint32_t textureHandle_ = 0;
};
