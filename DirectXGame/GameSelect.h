#pragma once
#include "KamataEngine.h"
using namespace KamataEngine; 

class GameSelect
{

public:
	GameSelect();
	~GameSelect();

	void Initialize();
	void Update();
	void Draw();

private:
	KamataEngine::Camera camera_;
	KamataEngine::DebugCamera* debugCamera_ = nullptr;

	int screenWidth = 1280;
	int screenHeight = 720;

	//ステージの数
	static const int kStageCount = 3;

	//各ステージの画像を描画するための情報を配列で管理する
	WorldTransform worldTransforms_[kStageCount];
	uint32_t textureHandles_[kStageCount] = { 0 };    
	Sprite*sprites_[kStageCount]={nullptr};

	int hoveredSprite_ = -1; // マウスが重なっているスプライトの番号 (-1はどこにも重なっていない)
    float animationTimer_ = 0.0f; // アニメーション用のタイマー
    bool isScalingUp_ = true;    // trueなら拡大中、falseなら縮小中
};

