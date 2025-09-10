#pragma once
#include <KamataEngine.h>
#include <vector>



class Confetti {
public:
	Confetti(uint32_t textureHandle, const int& count);
	~Confetti();

	void Initialize();
	void Update();
	void Draw();

private:
	float lifeTime_ = 0.0f;
	int confettiCount_ = 1;
	std::vector<KamataEngine::Vector2> positions_;
	std::vector<KamataEngine::Vector2> velocitys_;
	std::vector<KamataEngine::Sprite*> confettis_ = {};
	std::vector<float> sizes_;
	uint32_t textureHandle_ = 0;
};
