#pragma once
#include "KamataEngine.h"
#include"BaseScene.h"
#include"SceneManager.h"

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

	SceneManager* sceneManager_ = nullptr;
	int32_t currentSceneNo_ = 0;
	int32_t prevSceneNo_ = 0;

	ResultScene* resultScene_ = nullptr;
	uint32_t textureHandle_ = 0;
	int screenWidth = 1280;
	int screenHeight = 720;
};
