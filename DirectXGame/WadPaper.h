#pragma once
#include <KamataEngine.h>
#include "PlayerCursor.h"

class WadPaper {
public:
	WadPaper(uint32_t textureHandle,float paperSize);
	~WadPaper();

	void Initialize(const KamataEngine::Vector2 position,const PlayerCursor& playerCursor);
	void Update(bool isGrab);
	void Draw();

	void SetPosition(const KamataEngine::Vector2 position) { wadPaper_->SetPosition(position); }

	bool Collision(const KamataEngine::Vector2& squarePos,const KamataEngine::Vector2& squareScale);


	KamataEngine::Vector2 GetPosition() const { return wadPaper_->GetPosition(); }
	KamataEngine::Vector2 GetSize() const { return wadPaper_->GetSize(); }
	bool GetIsLife() const { return isLife_; }
	bool SetIsLife(bool life) { return isLife_ = life; }

private:

	void AddGravity();
	void MoveAtVelocity(KamataEngine::Vector2 pos);
	void Grab(const KamataEngine::Vector2& cursorPos);
	void CalculationForce();
	void CountDownLifeTime();

	const PlayerCursor* playerCursor_ = nullptr;
	KamataEngine::Sprite* wadPaper_ = nullptr;
	KamataEngine::Vector2 position_{};
	uint32_t textureHandle_ = 0;
	float paperSize_ = 0;
	bool isGrabed_ = false;
	bool isGrabing_ = false;
	bool isTouching_ = false;
	float gravity_ = 1.0f;
	KamataEngine::Vector2 moveVelocity_{};
	KamataEngine::Vector2 prePos_{};
	KamataEngine::Vector2 force_ {};
	float forceScale_ = 0.2f;
	float anchorPoint_ = 0.5f;
	float lifeTime_ = 0.0f;
	bool isLife_ = true;
	std::chrono::time_point<std::chrono::high_resolution_clock> startTime_ = {};
	std::chrono::time_point<std::chrono::high_resolution_clock> time_ = {};
};
