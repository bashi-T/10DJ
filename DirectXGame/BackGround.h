#pragma once
#include <KamataEngine.h>

class BackGround {
public:
	BackGround();
	~BackGround();

	void Inisialize();
	void Update();
	void Draw();

private:

	KamataEngine::Sprite* backGround_ = nullptr;
	uint32_t textureHandle_ = 0;
};
