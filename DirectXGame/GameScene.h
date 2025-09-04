#pragma once
#include "KamataEngine.h"
#include "testDebug.h"

class GameScene
{
public:
	GameScene();
	~GameScene();

	void Initialize();
	void Update();
	void Draw();


private:
	KamataEngine::Model* model_ = nullptr;
	KamataEngine::WorldTransform worldTransform_;
	KamataEngine::Camera camera_;
	KamataEngine::DebugCamera* debugCamera_ = nullptr;
	


	uint32_t textureHandle_ = 0;
	int screenWidth = 1280;
	int screenHeight = 720;

	testDebug* testDebug_ = nullptr;

};
