#include "Confetti.h"

using namespace std;
using namespace KamataEngine;
Confetti::Confetti(uint32_t textureHandle,const int& count)
{
	confettiCount_ = count;
	positions_.resize(confettiCount_);
	velocitys_.resize(confettiCount_);
	confettis_.resize(confettiCount_);
	sizes_.resize(confettiCount_);
	textureHandle_ = textureHandle;
}


Confetti::~Confetti() {}

void Confetti::Initialize()
{
	for (int i = 0; i < confettiCount_; i++) {
        confettis_[i] = KamataEngine::Sprite::Create(textureHandle_, positions_[i]);
		confettis_[i]->SetSize({sizes_[i], sizes_[i]});
		confettis_[i]->SetAnchorPoint({0.5f, 0.5f});
	}
}
void Confetti::Update() {}
void Confetti::Draw() 
{
	for (int i = 0; i < confettiCount_; i++) {
		confettis_[i]->Draw();
	}
}