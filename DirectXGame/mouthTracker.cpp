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
		mouthPos.x = static_cast<float>(point.x);
		mouthPos.y = static_cast<float>(point.y);
	}
}

Vector2 mouthTracker::GetMouthPos()
{
	return mouthPos;
}


