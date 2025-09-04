#pragma once
#include "BaseScene.h"
#include "KamataEngine.h"

class SelectScene : public BaseScene
{
public:
	void Initialize();

	std::unique_ptr<BaseScene> Update();

	void Draw();

private:
	bool isInGameScene_ = false;
};
