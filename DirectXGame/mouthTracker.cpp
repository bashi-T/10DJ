#include "mouthTracker.h"
#include <Windows.h>


mouthTracker::mouthTracker()
{
}

mouthTracker::~mouthTracker()
{
}

void mouthTracker::Update()
{
	mouthPos_ = Input::GetInstance()->GetMousePosition();

#ifdef _DEBUG
		ImGui::Begin("DEBUG2");
		ImGui::Text("MouthPos %d,%d", (int)mouthPos_.x, (int)mouthPos_.y);
		ImGui::End();
#endif
	
}

Vector2 mouthTracker::GetMouthPos()
{
	return mouthPos_; 
}




