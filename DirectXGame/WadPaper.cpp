#include "WadPaper.h"

using namespace KamataEngine;

WadPaper::WadPaper(uint32_t textureHandle, float paperSize) {
	textureHandle_ = textureHandle;
	paperSize_ = paperSize;
	isGrabed_ = true;
	gravity_ = 9.8f;
}

WadPaper::~WadPaper() {
	delete wadPaper_;
}


void WadPaper::Initialize(const Vector2 position,const Vector2 AnchorPoint) {
	wadPaper_ = Sprite::Create(textureHandle_, position);
	wadPaper_->SetSize({paperSize_, paperSize_});
	wadPaper_->SetAnchorPoint( AnchorPoint);
}

void WadPaper::Update() {
	
	if (isGrabed_)
	{
		AddGravity();
	}
}

void WadPaper::Draw() {
	wadPaper_->Draw();
}

void WadPaper::AddGravity()
{
	Vector2 pos = wadPaper_->GetPosition();
	pos.y += gravity_;
	wadPaper_->SetPosition(pos);
}
