#include "mouthTracker.h"


using namespace KamataEngine;

mouthTracker::mouthTracker()
{
	//Update();
}

mouthTracker::~mouthTracker()
{
}

void mouthTracker::Update()
{
	mouthPos_ = Input::GetInstance()->GetMousePosition();
}

Vector2 mouthTracker::GetMouthPos()
{
	return mouthPos_; 
}




