#pragma once
#include "BaseScene.h"
#include "KamataEngine.h"
#include "SceneManager.h"

class GameScene {
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
	KamataEngine::Sprite* sprite_ = nullptr;

	SceneManager* sceneManager_ = nullptr;
	int32_t currentSceneNo_ = 0;
	int32_t prevSceneNo_ = 0;

	ResultScene* resultScene_ = nullptr;
	uint32_t textureHandle_ = 0;
	uint32_t textureHandleSprite_ = 0;
};
