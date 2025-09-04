#include "PlayerCursor.h"
#include "Math/\Collision.h"


using namespace KamataEngine;

PlayerCursor::PlayerCursor() {
	mouthTracker_=new MouthTracker();
}

PlayerCursor::~PlayerCursor() {
	delete mouthTracker_;
	delete cursor_;
}


void PlayerCursor::Initialize(uint32_t TextureHandle,float AnchorPoint,float Scale) {

	cursor_ = Sprite::Create(TextureHandle,mouthTracker_->GetMouthPos());
	cursor_->SetAnchorPoint({AnchorPoint, AnchorPoint});
	cursor_->SetSize({Scale,Scale});
}

void PlayerCursor::Update() {

    mouthTracker_->Update();
	mouthPos_ = mouthTracker_->GetMouthPos();
	cursor_->SetPosition(mouthPos_);

}

void PlayerCursor::Draw() {
	cursor_->Draw();
}


bool PlayerCursor::MouthCollsion(const Vector2& SquarePos, const Vector2& SquareScale) {
	
	bool flag = false;

	if (isCollision(mouthPos_ , mouthScale_, SquarePos, SquareScale)) {
		flag = true;
		return true;
	}

	return false; 

}
