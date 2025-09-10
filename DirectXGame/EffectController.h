#pragma once
#include <KamataEngine.h>
#include "Confetti.h"
#include "TextureLoader.h"
#include "ShowLife.h"

class EffectController {
public:
	EffectController(const TextureLoader* textureLoader);
	~EffectController();

	void Initialize();
	void Update(int life);
	void Draw();



	private:

		Confetti* confetti_ = nullptr;
	    int confettiCount_ = 1;

		ShowLife* showLife_ = nullptr;

	
};
