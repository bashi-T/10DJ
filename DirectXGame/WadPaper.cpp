#include "WadPaper.h"
#include "Math/Collision.h"
#include <chrono>

using namespace KamataEngine;

WadPaper::WadPaper(uint32_t textureHandle, float paperSize) {
	textureHandle_ = textureHandle;
	paperSize_ = paperSize;
	gravity_ = 0.5f;
}

WadPaper::~WadPaper() {
	delete wadPaper_;
}


void WadPaper::Initialize(const Vector2 position,const PlayerCursor& playerCursor) {
	wadPaper_ = Sprite::Create(textureHandle_, position);
	wadPaper_->SetSize({paperSize_, paperSize_});
	wadPaper_->SetAnchorPoint({ 0.5f ,0.5f });
	playerCursor_ = &playerCursor;
	moveVelocity_ = { 0,0 };
	isGrabed_ = false;
	lifeTime_ = 5.0f;
	isLife_ = true;
	warping_ = false;
}

void WadPaper::Update(bool isGrab) {
	
	if (isTouching_) 
	{
		if (isGrab) 
		{
			wadPaper_->SetPosition(playerCursor_->GetPosition());
			CalculationForce();
			isGrabing_ = true;
			isGrabed_ = true;
			return;
		}
		else 
		{
			if (isGrabing_) 
			{
				isGrabing_ = false;
				moveVelocity_ = force_;
				startTime_ = std::chrono::high_resolution_clock::now();
			}
			
		}
	}
	if (!isGrabed_) 
	{
		return;
	}

	Vector2 pos= wadPaper_->GetPosition();
	AddGravity();
	MoveAtVelocity(pos);

	time_ = std::chrono::high_resolution_clock::now();
	CountDownLifeTime();

#ifdef _DEBUG
	ImGui::Begin("INGAME");
	ImGui::Text("PaperPos %d,%d", (int)wadPaper_->GetPosition().x, (int)wadPaper_->GetPosition().y);

	ImGui::End();
#endif // _DEBUG
}

void WadPaper::Draw() {

	wadPaper_->Draw();
}

bool WadPaper::Collision(const KamataEngine::Vector2& squarePos,const KamataEngine::Vector2& squareScale)
{
	if (isCollision(wadPaper_->GetPosition(), {paperSize_,paperSize_}, squarePos, squareScale)) 
	{
		isTouching_ = true;
		return true;
	}
	isTouching_ = false;
	return false;
}

void WadPaper::CountDownLifeTime()
{
	if (!isGrabed_)
	{
		return;
	}
	float timeBuff_ = (float)std::chrono::duration<double>(time_ - startTime_).count();
	if (lifeTime_ - timeBuff_ < 0.0f)
	{
		isLife_ = false;
	}
#ifdef _DEBUG
	ImGui::Begin("Debug2");
	ImGui::Text("Time %d", (int)timeBuff_);

	ImGui::End();
#endif // _DEBUG
}

void WadPaper::Grab(const KamataEngine::Vector2& cursorPos)
{
	wadPaper_->SetPosition(cursorPos);
}

void WadPaper::AddGravity()
{

	moveVelocity_.y += gravity_;
	
}

void WadPaper::MoveAtVelocity(KamataEngine::Vector2 pos)
{
	pos.x += moveVelocity_.x;
	pos.y += moveVelocity_.y;
	wadPaper_->SetPosition(pos);
}

void WadPaper::CalculationForce()
{
	Vector2 distance = { wadPaper_->GetPosition().x - prePos_.x , wadPaper_->GetPosition().y - prePos_.y };
	force_ = { distance.x * forceScale_ , distance.y * forceScale_ };
	prePos_ = wadPaper_->GetPosition();
}