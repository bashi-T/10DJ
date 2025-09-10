#pragma once
#include "BaseScene.h"
#include "KamataEngine.h"

class InGameScene : public BaseScene
{
public:
	void Initialize();

	std::unique_ptr<BaseScene> Update();

	void Draw();

private:
	bool isResultScene_ = false;
};
