#include "TrashCan.h"

TrashCan::TrashCan(uint32_t textureHandle)
{
	textureHandle_ = textureHandle;
	trashCan_ = KamataEngine::Sprite::Create(textureHandle_, { 800, 600 });
	trashCan_->SetSize({ trashCanSize_, trashCanSize_ });
	trashCan_->SetAnchorPoint({ 0.5f, 0.5f });
	
}

TrashCan::~TrashCan()
{
	delete trashCan_;
}

void TrashCan::Initialize()
{

}

void TrashCan::Update()
{

}

void TrashCan::Draw()
{
	trashCan_->Draw();
}
