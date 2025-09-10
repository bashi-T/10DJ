#include "Portal.h"
#include "Math/Collision.h"

using namespace KamataEngine;

Portal::Portal(const Vector2& position, const Vector2& conectPosition,const Vector2& size,uint32_t textureHandle) 
{
	position_ = position;
	distance_ = {position.x - conectPosition.x, position.y - conectPosition.y};
	textureHandle_ = textureHandle;
	size_ = size;
}

Portal::~Portal()
{
	delete portal_;
}

void Portal::Initialize()
{ portal_ = KamataEngine::Sprite::Create(textureHandle_, position_);
	portal_->SetSize(size_);
	portal_->SetAnchorPoint({0.5f, 0.5f});
	warp = false;
}

void Portal::Update()
{

}

void Portal::Draw()
{
	portal_->Draw();
}

bool Portal::Collision(const ::Vector2& paperPos, const ::Vector2& paperSize) 
{
	if (isCollision(portal_->GetPosition(), size_, paperPos, paperSize)) {
		warp = true;
	}
	else
	{
		warp = false;
	}
	return warp;
}