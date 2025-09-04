#pragma once
#include "KamataEngine.h"
#include "mouthTracker.h"
#include "Math\Collision.h"

class testDebug {

public:
	testDebug();
	~testDebug();

	void Initialize();

	void Update();

	void Draw();

private:
	MouthTracker* mouthTracker_ = nullptr;
	KamataEngine::Sprite* Cursor_ = nullptr;
	KamataEngine::Sprite* testBox_ = nullptr;
	

	uint32_t textureHandle_ = 0;
	float textureScale_ = 50;

};
