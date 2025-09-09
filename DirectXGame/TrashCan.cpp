#include "TrashCan.h"
#include "Math/Collision.h"

TrashCan::TrashCan(uint32_t textureHandle)
{
	textureHandle_ = textureHandle;

}

TrashCan::~TrashCan()
{
	delete trashCan_;
}

void TrashCan::Initialize()
{
	trashCan_ = KamataEngine::Sprite::Create(textureHandle_, { 800, 600 });
	trashCan_->SetSize({ trashCanSize_, trashCanSize_ });
	trashCan_->SetAnchorPoint({ 0.5f, 0.5f });
	clearFlag_ = false;
}

void TrashCan::Update()
{

}

void TrashCan::Draw()
{
	trashCan_->Draw();
}

bool TrashCan::ClearFlag(const KamataEngine::Vector2& squarePos, const KamataEngine::Vector2& squareScale)
{
	if (isCollision(trashCan_->GetPosition(), { trashCanSize_ ,trashCanSize_ }, squarePos, squareScale)) {
		clearFlag_ = true;
	}
	return clearFlag_;
}

void TrashCan::ResetClearFlag()
{
	clearFlag_ = false;
}


