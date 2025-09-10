#include "GrabArea.h"
#include "Math/Collision.h"

using namespace KamataEngine;

GrabArea::GrabArea(uint32_t textureHandle,Vector2 position,Vector2 size)
{
	textureHandle_ = textureHandle;
	position_ = position;
	size_ = size;
}

GrabArea::~GrabArea()
{
	delete grabArea_;
}

void GrabArea::Initialize()
{
	grabArea_ = KamataEngine::Sprite::Create(textureHandle_, position_);
	grabArea_->SetSize(size_);
	grabArea_->SetAnchorPoint({ 0.5f ,0.5f });
}

void GrabArea::Update()
{
}

void GrabArea::Draw()
{
	grabArea_->Draw();
}

bool GrabArea::Collision(const KamataEngine::Vector2& squarePos, const KamataEngine::Vector2& squareSize)
{
	if (isCollision(grabArea_->GetPosition(), size_, squarePos, squareSize))
	{
		return true;
	}
	return false;
}
