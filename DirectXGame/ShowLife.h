#pragma once
#include <KamataEngine.h>

class ShowLife 
{
public:
	ShowLife(uint32_t textureHandle, KamataEngine::Vector2 pos, float size);
	~ShowLife();

	void Initialize();
	void Update(int life);
	void Draw();

private:
	uint32_t textureHandle_ = 0;
	KamataEngine::Sprite* showLife1_{};
	KamataEngine::Sprite* showLife2_{};
	KamataEngine::Sprite* showLife3_{};
	KamataEngine::Vector2 position_{};
	float size_;
	int life_;
};
