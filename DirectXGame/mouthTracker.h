#pragma once
#include <math/Vector2.h>
#include <KamataEngine.h>

using namespace KamataEngine;

class MouthTracker
{
public:

	MouthTracker();
	
	~MouthTracker();
	
	//位置情報更新
	void Update();

	//位置情報取得
	KamataEngine::Vector2 GetMouthPos();



	static MouthTracker* GetInstance() {
		static MouthTracker instance;
		return &instance;
	}

private:
	
	//マウス座標格納用
	KamataEngine::Vector2 mouthPos_ { };


};

