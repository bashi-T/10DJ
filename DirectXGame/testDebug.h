#pragma once
#include "KamataEngine.h"
#include "mouthTracker.h"

class testDebug {

public:
	testDebug();
	~testDebug();

	void Initialize();

	void Update();

	void Draw();

private:
	mouthTracker* mouthTracker_ = nullptr;
	KamataEngine::Sprite* sprite_ = nullptr;

	uint32_t textureHandle_ = 0;

};
