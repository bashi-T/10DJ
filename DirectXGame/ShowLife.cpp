#include "ShowLife.h"

using namespace KamataEngine;

ShowLife::ShowLife(uint32_t textureHandle,Vector2 pos,float size) 
{
	position_ = pos;
	life_ = 3;
	textureHandle_ = textureHandle;
	size_ = size;
}

ShowLife::~ShowLife() 
{
	delete showLife1_;
	delete showLife2_;
	delete showLife3_;
}

void ShowLife::Initialize() 
{
	showLife1_ = KamataEngine::Sprite::Create(textureHandle_, position_);
	showLife2_ = KamataEngine::Sprite::Create(textureHandle_, {position_.x + (size_*1), position_.y});
	showLife3_ = KamataEngine::Sprite::Create(textureHandle_, {position_.x + (size_*2), position_.y});

	showLife1_->SetSize({size_, size_});
	showLife2_->SetSize({size_, size_});
	showLife3_->SetSize({size_, size_});

	showLife1_->SetAnchorPoint({0.5f, 0.5f});
	showLife2_->SetAnchorPoint({0.5f, 0.5f});
	showLife3_->SetAnchorPoint({0.5f, 0.5f});
}

void ShowLife::Update(int life) 
{
	life_=life;
}

void ShowLife::Draw() 
{
	if (life_ == 3) {
		showLife1_->Draw();
		showLife2_->Draw();
		showLife3_->Draw();
	}
	if (life_ == 2) {
		showLife1_->Draw();
		showLife2_->Draw();
	}
	if (life_ == 1) {
		showLife1_->Draw();
	}

	if (life_ == 0) {
	
	}
}