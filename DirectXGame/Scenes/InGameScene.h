#pragma once
#include "BaseScene.h"
#include "KamataEngine.h"
#include "InGameController.h"

class InGameScene : public BaseScene
{
public:
	InGameScene();
	~InGameScene();

	void Initialize();

	std::unique_ptr<BaseScene> Update();

	void Draw();

private:
	KamataEngine::WorldTransform worldTransform_;
	KamataEngine::Camera camera_;

	InGameController* inGameController_ = nullptr;

	bool isResultScene_ = false;
};
