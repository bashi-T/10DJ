#pragma once
#include "BaseScene.h"
#include "KamataEngine.h"
#include "Fade.h"

class TitleScene : public BaseScene
{
public:

    TitleScene();
    ~TitleScene();
	void Initialize();

	std::unique_ptr<BaseScene> Update();

	void Draw();

private:
	bool isSelectScene_ = false;

	 Sprite* bgSprite_ = nullptr;
    Sprite* titleSprite_ = nullptr;
    uint32_t bgHandle_ = 0;
    uint32_t titleHandle_ = 0;

    int screenWidth = 1280;
    int screenHeight = 720;

    Fade*fade_=nullptr;
};
