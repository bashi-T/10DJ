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
	POINT point;
	if (GetCursorPos(&point))
	{
		mouthPos_.x = static_cast<float>(point.x);
		mouthPos_.y = static_cast<float>(point.y);

#ifdef _DEBUG
		ImGui::Begin("DEBUG2");
		ImGui::Text("MouthPos %d,%d", (int)mouthPos_.x, (int)mouthPos_.y);
		ImGui::End();
#endif
	}
}

Vector2 mouthTracker::GetMouthPos()
{
	return mouthPos_;
}


