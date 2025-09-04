#pragma once
#include <math/Vector2.h>
#include <KamataEngine.h>

using namespace KamataEngine;


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
	
	//マウス座標格納用
	Vector2 mouthPos_ { };

};

