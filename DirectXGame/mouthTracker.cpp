#include "MouthTracker.h"


using namespace KamataEngine;

MouthTracker::MouthTracker()
{
	ShowCursor(false);
}

MouthTracker::~MouthTracker()
{
}

void MouthTracker::Update()
{
	mouthPos_ = Input::GetInstance()->GetMousePosition();
}

Vector2 MouthTracker::GetMouthPos()
{
	return mouthPos_; 
}




