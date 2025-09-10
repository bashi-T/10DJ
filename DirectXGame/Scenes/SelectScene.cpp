#include "SelectScene.h"

SelectScene::SelectScene()
{
}

SelectScene::~SelectScene()
{
	for(int i = 0; i < kStageCount; i++) {
	delete sprites_[i];
	}
	delete debugCamera_;
}

void SelectScene::Initialize() {

// カメラの初期化
	camera_.Initialize();
	debugCamera_ = new DebugCamera(screenWidth, screenHeight);

    //soundDataHandle_=Audio::GetInstance()->LoadWave("GameSelectBGM.mp3");
    //Audio::GetInstance()->PlayWave(soundDataHandle_,true);

	
	textureHandles_[0]=TextureManager::Load("Stage0.png");
	textureHandles_[1]=TextureManager::Load("Stage1.png");
	textureHandles_[2]=TextureManager::Load("Stage2.png");
	
    backGroundTextureHandle_ = TextureManager::Load("backGround.png");
    backGround_ = Sprite::Create(backGroundTextureHandle_, { 640,360 });
    backGround_->SetAnchorPoint({ 0.5f,0.5f });
    backGround_->SetSize({ 2000,1000 });

	for (int i = 0; i < kStageCount; i++) {
		Vector2 position={0,0};

		// iの値によって座標を直接指定する
		if (i == 0) {
			// 0番目の画像の座標
			position = {350.0f, 300.0f};
		} else if (i == 1) {
			// 1番目の画像の座標
			position = {650.0f, 300.0f};
		}
        else if (i == 2) {
			// 2番目の画像の座標
			position = {800.0f, 300.0f};
		}
		
        sprites_[i] = Sprite::Create(textureHandles_[i], position);
        sprites_[i]->SetAnchorPoint({0.5f, 0.5f});

        baseSpriteSize_[i] = sprites_[i]->GetSize();  // 元サイズを保存
	}

}

std::unique_ptr<BaseScene> SelectScene::Update()
{
    ShowCursor(true);
	debugCamera_->Update();
    Input* input = Input::GetInstance();

   
    // マウス座標取得
    Vector2 mousePos = input->GetMousePosition();

    // ホバー判定
    hoveredSprite_ = -1;
    for (int i = 0; i < kStageCount; i++) {
        Vector2 spritePos = sprites_[i]->GetPosition();
        Vector2 spriteSize = sprites_[i]->GetSize();

        float left   = spritePos.x - spriteSize.x / 2.0f;
        float right  = spritePos.x + spriteSize.x / 2.0f;
        float top    = spritePos.y - spriteSize.y / 2.0f;
        float bottom = spritePos.y + spriteSize.y / 2.0f;

        if(i==0){
            right  = spritePos.x + spriteSize.x / 2.0f*2;
        }

        if (mousePos.x >= left && mousePos.x <= right &&
            mousePos.y >= top  && mousePos.y <= bottom) {
            hoveredSprite_ = i;
            break;
        }
    }

    

    // スケーリング処理（判定とは別ループ）
    for (int i = 0; i < kStageCount; i++) {
        if (i == hoveredSprite_) {
            if (!wasHovered_[i]) {
                sprites_[i]->SetSize({baseSpriteSize_[i].x * 2.0f, baseSpriteSize_[i].y * 2.0f});
                animationTimer_ = 0.0f;
                wasHovered_[i] = true;
            } else {
                animationTimer_ += 0.05f;
                float smoothScale = 2.0f + 0.2f * cosf(animationTimer_);
                sprites_[i]->SetSize({baseSpriteSize_[i].x * smoothScale, baseSpriteSize_[i].y * smoothScale});
            }
        } else {
            sprites_[i]->SetSize(baseSpriteSize_[i]);
            wasHovered_[i] = false;
        }
    }

      // 左クリックで遷移処理
    if (input->IsTriggerMouse(0)) {
        if (hoveredSprite_ == 0) {
            Audio::GetInstance()->StopWave(soundDataHandle_);
            return std::make_unique<TitleScene>();
        }
        else if (hoveredSprite_ == 1) {
            Audio::GetInstance()->StopWave(soundDataHandle_);
            return std::make_unique<InGameScene>();
        }
        else if (hoveredSprite_ == 2) {
            Audio::GetInstance()->StopWave(soundDataHandle_);
            return std::make_unique<InGameScene>();
        }
}

#ifdef _DEBUG 
	ImGui::Begin("SELECT");
	ImGui::End();
#endif
	return nullptr;
}

void SelectScene::Draw() {
	Sprite::PreDraw();
    backGround_->Draw();

	for(int i = 0; i < kStageCount; i++) {
	    sprites_[i]->Draw();
	}

	Sprite::PostDraw();}
