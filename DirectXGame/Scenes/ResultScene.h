#pragma once
#include "BaseScene.h"
#include "TitleScene.h"
#include "SelectScene.h"
#include "InGameScene.h"
#include "KamataEngine.h"
#include "Math/Collision.h"

class ResultScene : public BaseScene
{
public:

	void Initialize();

	std::unique_ptr<BaseScene> Update();

	void Draw();

private:
	KamataEngine::Sprite* result = nullptr;
	KamataEngine::Sprite* title = nullptr;
	KamataEngine::Sprite* select = nullptr;
	KamataEngine::Sprite* retry = nullptr;

	uint32_t textureHandleResult_ = 0;
	uint32_t textureHandleTitle_ = 0;
	uint32_t textureHandleSelect_ = 0;
	uint32_t textureHandleRetry_ = 0;

	KamataEngine::Vector2 posTitle_ = {400, 250};
	KamataEngine::Vector2 posSelect_ = {400, 400};
	KamataEngine::Vector2 posRetry_ = {400, 550};

	bool isClear_ = false;
	bool isTitleScene_ = false;
	bool isSelectScene_ = false;
	bool isInGameScene_ = false;
};
