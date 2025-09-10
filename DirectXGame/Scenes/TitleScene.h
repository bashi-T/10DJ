#pragma once
#include "BaseScene.h"
#include "KamataEngine.h"

class TitleScene : public BaseScene
{
public:
	void Initialize();

	std::unique_ptr<BaseScene> Update();

	void Draw();

private:
	bool isSelectScene_ = false;
};
