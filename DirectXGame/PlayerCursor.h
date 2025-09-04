#pragma once
#include<algorithm>
#include <KamataEngine.h>
#include "MouthTracker.h"
#include "WadPaper.h"

class PlayerCursor {
public:
	PlayerCursor();
	~PlayerCursor();

	void Initialize(uint32_t textureHandle, float AnchorPoint, float Scale);
	void Update();
	void Draw();


	bool MouthCollsion(const KamataEngine::Vector2& SquarePos, const KamataEngine::Vector2& SquareScale);

	void SetInGameFlag(bool inGame) { isGrab_ = inGame; }

	void SetWadPaper(WadPaper* wadPaper) { wadPaper_ = wadPaper; }
	void TouchWadPaper(bool touch) { isTouch_ = touch; }
	

private:
	void Grab();




	MouthTracker* mouthTracker_ = nullptr;
	Sprite* cursor_ = nullptr;
	WadPaper* wadPaper_ = nullptr;


	KamataEngine::Vector2 mouthPos_ {};
	KamataEngine::Vector2 mouthScale_{};

	bool inGame_ = false;
	bool isGrab_ = false;
	bool isTouch_ = false;
};
