#pragma once
#include <KamataEngine.h>
class Confetti {
public:
	Confetti();
	~Confetti();

	void Initialize();
	void Update();
	void Draw();

private:
	float lifeTime_ = 0.0f;
};
