#pragma once
#include "BaseScene.h"
#include "SelectScene.h"
#include "KamataEngine.h"
#include "Fade.h"

class TitleScene : public BaseScene
{
public:
	TitleScene();
	~TitleScene();


	
	void Initialize();

	std::unique_ptr<BaseScene> Update();

	void Draw();

private:
	KamataEngine::Sprite* bgSprite_ = nullptr;
	KamataEngine::Sprite* titleSprite_ = nullptr;
	uint32_t bgHandle_ = 0;
	uint32_t titleHandle_ = 0;

	Fade* fade_ = nullptr;

	bool isSelectScene_ = false;
};
