#pragma once
#include <KamataEngine.h>
class TrashCan
{
public:
	TrashCan(uint32_t textureHandle);
	~TrashCan();

	void Initialize();
	void Update();
	void Draw();

	KamataEngine::Vector2 GetPosition() const { return position_; }
	KamataEngine::Vector2 GetSize() const { return size_; }

	bool ClearFlag(const KamataEngine::Vector2& squarePos, const KamataEngine::Vector2& squareScale);
	void ResetClearFlag();

private:

	

	KamataEngine::Sprite* trashCan_ = nullptr;
	KamataEngine::Vector2 position_{  };
	KamataEngine::Vector2 size_{  };

	uint32_t textureHandle_ = 0;
	float trashCanSize_ = 100.0f;
	bool clearFlag_ = false;
};

