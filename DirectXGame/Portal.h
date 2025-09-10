#pragma once
#include <KamataEngine.h>
class Portal
{
public:
	Portal();
	~Portal();
	void Initialize();
	void Update();
	void Draw();
	KamataEngine::Vector2 GetPosition() const { return position_; }
	KamataEngine::Vector2 GetSize() const { return size_; }
private:
	KamataEngine::Sprite* portal_ = nullptr;
	KamataEngine::Vector2 position_{};
	KamataEngine::Vector2 size_{};
	uint32_t textureHandle_ = 0;
	float portalSize_ = 100.0f;
};

