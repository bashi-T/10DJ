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
	mouthScale_ = {Scale, Scale};
	forceScale_ = 2.0f;
}

void PlayerCursor::Update() {

    mouthTracker_->Update();
	mouthPos_ = mouthTracker_->GetMouthPos();
	cursor_->SetPosition(mouthPos_);

}

void PlayerCursor::Draw() {
	cursor_->Draw();


#ifdef _DEBUG
	ImGui::Begin("Debug2");
	ImGui::Text("MouthPos %d,%d", (int)mouthTracker_->GetMouthPos().x, (int)mouthTracker_->GetMouthPos().y);
	ImGui::End();
#endif // _DEBUG
}


bool PlayerCursor::MouthCollsion(const Vector2& SquarePos, const Vector2& SquareScale) {
	
	bool flag = false;

	if (isCollision(mouthPos_ , mouthScale_, SquarePos, SquareScale)) {
		flag = true;
		return true;
	}

	return false; 

}

void PlayerCursor::CalculationForce()
{
	Vector2 distance = { mouthPos_.x - prePos_.x , mouthPos_.y - prePos_.y };
	force_ = { distance.x * forceScale_ , distance.y * forceScale_ };
	prePos_ = mouthPos_;
}

