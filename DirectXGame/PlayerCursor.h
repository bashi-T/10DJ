#pragma once
#include<algorithm>
#include <KamataEngine.h>
#include "MouthTracker.h"

class PlayerCursor {
public:
	PlayerCursor();
	~PlayerCursor();

	void Initialize(uint32_t textureHandle, float AnchorPoint, float Scale);
	void Update();
	void Draw();


	bool MouthCollsion(const KamataEngine::Vector2& SquarePos, const KamataEngine::Vector2& SquareScale);

	void SetInGameFlag(bool inGame) { isGrab_ = inGame; }

	void TouchWadPaper(bool touch) { isTouch_ = touch; }

	KamataEngine::Vector2 GetPosition() const { return mouthPos_; }
	KamataEngine::Vector2 GetSize() const { return mouthScale_; }
	

private:
	//void Grab();
	void CalculationForce();



	MouthTracker* mouthTracker_ = nullptr;
	Sprite* cursor_ = nullptr;


	KamataEngine::Vector2 mouthPos_ {};
	KamataEngine::Vector2 mouthScale_{};
	KamataEngine::Vector2 prePos_  {};
	KamataEngine::Vector2 force_{};

	float forceScale_ = 0.0f;


	bool inGame_ = false;
	bool isGrab_ = false;
	bool isTouch_ = false;
};
