#include "EffectController.h"
#include "TextureLoader.h"

using namespace KamataEngine;

EffectController::EffectController(const TextureLoader* textureLoader)
{
    confettiCount_ = 20;
	confetti_ = new Confetti(textureLoader->GetConfettiTextureHandle(), confettiCount_);
}

EffectController::~EffectController() 
{
    delete confetti_;
}


void EffectController::Initialize() {}

void EffectController::Update() {}

void EffectController::Draw() 
{
}