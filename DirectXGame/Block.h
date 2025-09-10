#pragma once
#include <KamataEngine.h>

class Block
{
public:
	Block(uint32_t textureHandle,float size);
	~Block();

	void Initialize(KamataEngine::Vector2 position);
	void Update();
	void Draw();


private:

	KamataEngine::Sprite* block_ = nullptr;
	KamataEngine::Vector2 position_{};

	float size_ = 0;
	uint32_t textureHandle_ = 0;
	

};

