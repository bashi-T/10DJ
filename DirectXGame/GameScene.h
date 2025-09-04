#pragma once
#include "KamataEngine.h"
#include "ResultScene.h"

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

	ResultScene* resultScene_;
	uint32_t textureHandle_ = 0;
	int screenWidth = 1280;
	int screenHeight = 720;
};
