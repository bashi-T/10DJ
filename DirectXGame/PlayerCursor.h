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

private:
	MouthTracker* mouthTracker_ = nullptr;
	Sprite* cursor_ = nullptr;

	KamataEngine::Vector2 mouthPos_ {};
	KamataEngine::Vector2 mouthScale_{};
};
