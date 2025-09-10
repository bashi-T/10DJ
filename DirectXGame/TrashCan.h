#pragma once
#include <KamataEngine.h>
#include "Confetti.h"
class TrashCan
{
public:
	TrashCan(uint32_t textureHandle, const KamataEngine::Vector2& pos);
	~TrashCan();

	void Initialize();
	void Update();
	void Draw();

	KamataEngine::Vector2 GetPosition() const { return position_; }
	float GetSize() const { return trashCanSize_; }

	bool ClearFlag(const KamataEngine::Vector2& squarePos, const KamataEngine::Vector2& squareScale);
	void ResetClearFlag();

private:

	
	KamataEngine::Sprite* trashCan_ = nullptr;
	KamataEngine::Vector2 position_{  };

	uint32_t textureHandle_ = 0;
	float trashCanSize_ = 100.0f;
	bool clearFlag_ = false;
};

