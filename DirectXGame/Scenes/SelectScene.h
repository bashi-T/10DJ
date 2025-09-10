#pragma once
#include "BaseScene.h"
#include"SceneManager.h"
#include "KamataEngine.h"
#include"input/Input.h"
#include <3d/WorldTransform.h>
using namespace KamataEngine; 

class SelectScene : public BaseScene
{
public:
	SelectScene();
	~SelectScene();

	void Initialize();

	std::unique_ptr<BaseScene> Update();

	void Draw();

private:
	KamataEngine::Camera camera_;
	KamataEngine::DebugCamera* debugCamera_ = nullptr;

	uint32_t soundDataHandle_=0;

	int screenWidth = 1280;
	int screenHeight = 720;

	//ステージの数
	static const int kStageCount = 3;

	//各ステージの画像を描画するための情報を配列で管理する
	WorldTransform worldTransforms_[kStageCount];
	uint32_t textureHandles_[kStageCount] = { 0 };    
	Sprite*sprites_[kStageCount]={nullptr};

	// ホバー管理
    int hoveredSprite_ = -1;
    bool wasHovered_[kStageCount]{};
    float animationTimer_ = 0.0f;
	Vector2 baseSpriteSize_[kStageCount];
};
