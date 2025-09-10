#include "EffectController.h"
#include "TextureLoader.h"

using namespace KamataEngine;

EffectController::EffectController(const TextureLoader* textureLoader)
{
    confettiCount_ = 20;
	confetti_ = new Confetti(textureLoader->GetConfettiTextureHandle(), confettiCount_);

    showLife_ = new ShowLife(textureLoader->GetWadPaperTexture(), {60, 40},50);
}

EffectController::~EffectController() 
{
    delete confetti_;
	delete showLife_;
}


void EffectController::Initialize() 
{
    showLife_->Initialize();
}

void EffectController::Update(int life) 
{
    showLife_->Update(life);
}

void EffectController::Draw() 
{
    showLife_->Draw();
}