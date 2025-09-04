#pragma once
#include "BaseScene.h"
#include "SelectScene.h"
#include "ResultScene.h"
#include "InGameScene.h"
#include "TitleScene.h"

class SceneManager 
{
public:
	SceneManager();

	void Initialize();
	void Update();
	void Draw() { currentScene->Draw(); }

	static SceneManager* GetInstance();

	void SetStageNumber(int32_t number) { stageNumber = number; }
	int32_t GetStageNumber() { return stageNumber; }
	void SetIsClear(bool isClear) { isClear_ = isClear; }
	bool GetIsClear() { return isClear_; }
	void SetNumThrow(int num) { numThrow = num; }
	int32_t GetNumRhrow() { return numThrow; }

protected:
	int32_t stageNumber = 0;
	bool isClear_ = false;
	int32_t numThrow = 0;

private:
	std::unique_ptr<BaseScene> currentScene;
	static inline std::unique_ptr<SceneManager> instance;
};
