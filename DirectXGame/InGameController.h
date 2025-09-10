#pragma once
#include "KamataEngine.h"
#include "mouthTracker.h"
#include "Math\Collision.h"
#include "PlayerCursor.h"
#include "WadPaper.h"
#include "TextureLoader.h"
#include "TrashCan.h"
#include "Block.h"
#include "AudioLoader.h"
#include "GrabArea.h"
#include "Portal.h"
#include "EffectController.h"

class InGameController {
public:

	InGameController(const KamataEngine::Vector2 screenSize);
	~InGameController();

	void Initialize();
	void Update();
	void Draw();



private:

	void RespornWadPaper();
	void IsClear();
	void ScreenOutSide();
	void GameOver();
	void Warp();

	MouthTracker* mouthTracker_ = nullptr;
	KamataEngine::Sprite* testBox_ = nullptr;
	PlayerCursor* playerCursor_ = nullptr;
	WadPaper* wadPaper_ = nullptr;
	TextureLoader* textureLoader_ = nullptr;
	AudioLoader* audioLoader_ = nullptr;
	TrashCan* trashCan_ = nullptr;
	KamataEngine::Vector2 initialPaperPos_{};
	KamataEngine::Vector2 screenSize_{};
	float screenEdgeOffset_ = 0.0f;
	GrabArea* grabArea_ = nullptr;
	Portal* portalA_ = nullptr;
	Portal* portalB_ = nullptr;
	EffectController* effectController_ = nullptr;

	float textureScale_ = 50;
	bool inGame_ = true;
	bool clearFlag_ = false;
	bool gameOverFlag_ = false;
	bool gameEndFlag_ = false;
	int life_ = 3;
	bool isCanGrab_ = false;
};
