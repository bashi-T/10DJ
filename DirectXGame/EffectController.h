#pragma once
#include <KamataEngine.h>
#include "Confetti.h"
#include "TextureLoader.h"

class EffectController {
public:
	EffectController(const TextureLoader* textureLoader);
	~EffectController();

	void Initialize();
	void Update();
	void Draw();

    Confetti* GetConfetti() { return confetti_; }

	private:

		Confetti* confetti_ = nullptr;
	    int confettiCount_ = 1;

	
};
