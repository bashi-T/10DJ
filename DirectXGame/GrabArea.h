#pragma once
#include <KamataEngine.h>

class GrabArea
{
public:
	GrabArea(uint32_t textureHandle, KamataEngine::Vector2 position, KamataEngine::Vector2 size);
	~GrabArea();

	void Initialize();
	void Update();
	void Draw();

	bool Collision(const KamataEngine::Vector2& squarePos, const KamataEngine::Vector2& squareSize);

	KamataEngine::Vector2 GetPos() { return position_; }
	KamataEngine::Vector2 GetSize() { return size_; }

private:
	KamataEngine::Sprite* grabArea_ = nullptr;

	uint32_t textureHandle_ = 0;
	KamataEngine::Vector2 position_={};
	KamataEngine::Vector2 size_={};
};

