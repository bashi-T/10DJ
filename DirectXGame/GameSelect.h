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

	    // ホバー管理
    int hoveredSprite_ = -1;          // マウスが重なっているスプライトの番号 (-1 = なし)
    bool wasHovered_[kStageCount]{};  // 前のフレームでホバーされてたかどうか
    float animationTimer_ = 0.0f;     // アニメーション用のタイマー
	Vector2 baseSpriteSize_[kStageCount];

	Sprite* fadeSprite_{ nullptr }; 
	bool isFadingIn_ = false;
bool isFadingOut_ = false;
float fadeAlpha_ = 0.0f;
float fadeSpeed_ = 0.02f;
int nextScene_ = -1;
};

