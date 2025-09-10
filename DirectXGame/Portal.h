#pragma once
#include <KamataEngine.h>
class Portal
{
public:
	Portal(const KamataEngine::Vector2& position, const KamataEngine::Vector2& conectPosition,  const KamataEngine::Vector2& size, uint32_t textureHandle);
	~Portal();

	void Initialize();
	void Update();
	void Draw();

	bool Collision(const KamataEngine::Vector2& paperPos, const KamataEngine::Vector2& paperSize);
	KamataEngine::Vector2 GetDistance() { return distance_; }

	KamataEngine::Vector2 GetPosition() const { return position_; }
	KamataEngine::Vector2 GetSize() const { return size_; }
private:

	KamataEngine::Sprite* portal_ = nullptr;
	KamataEngine::Vector2 position_{};
	KamataEngine::Vector2 size_{};
	KamataEngine::Vector2 distance_{};
	uint32_t textureHandle_ = 0;
	bool warp = false;
};

