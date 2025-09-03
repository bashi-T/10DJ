#pragma once
#include "Vector2.h"

class mouthTracker
{
public:
	mouthTracker();
	~mouthTracker();
	void UpdateMouthTracker();
	 Vector2 GetMouthPos();
private:
	Vector2 mouthPos;
};

