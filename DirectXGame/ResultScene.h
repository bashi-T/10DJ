#pragma once
#include "KamataEngine.h"
class ResultScene
{
public:

	ResultScene();
	~ResultScene();

	void Initialize(bool isClear);

	void Update();

	void Draw();

private:
	KamataEngine::Sprite* sprite_ = nullptr;
	bool isClear_ = false;

	uint32_t textureHandle_ = 0;
};
