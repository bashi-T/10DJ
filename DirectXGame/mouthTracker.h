#pragma once


class mouthTracker
{
public:

	mouthTracker();
	
	~mouthTracker();
	
	//位置情報更新
	void Update();
	
	//位置情報取得
	Vector2 GetMouthPos();

private:
	
	Vector2 mouthPos;

};

