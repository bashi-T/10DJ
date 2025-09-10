#include "GameSelect.h"
#include"input/Input.h"


GameSelect::GameSelect()
{
}

GameSelect::~GameSelect()
{
	for(int i = 0; i < kStageCount; i++) {
	delete sprites_[i];
	}
	delete debugCamera_;
}

void GameSelect::Initialize()
{
	// カメラの初期化
	camera_.Initialize();
	debugCamera_ = new DebugCamera(screenWidth, screenHeight);

	
	textureHandles_[0]=TextureManager::Load("Stage1.png");
	textureHandles_[1]=TextureManager::Load("Stage2.png");
	
	for (int i = 0; i < kStageCount; i++) {
		Vector2 position={0,0};

		// iの値によって座標を直接指定する
		if (i == 0) {
			// 1番目の画像の座標
			position = {350.0f, 400.0f};
		} else if (i == 1) {
			// 2番目の画像の座標
			position = {500.0f, 400.0f};
		}
		
        sprites_[i] = Sprite::Create(textureHandles_[i], position);
        baseSpriteSize_[i] = sprites_[i]->GetSize();  // 元サイズを保存
	}


	uint32_t whiteTexture = TextureManager::Load("Fade.png");
    fadeSprite_ = Sprite::Create(whiteTexture, {screenWidth / 2.0f, screenHeight / 2.0f});
    fadeSprite_->SetSize({(float)screenWidth, (float)screenHeight});

    // フェードインをしたいなら最初は黒（不透明）にしておく
    fadeAlpha_ = 1.0f;      // 1.0 = 完全黒（画面覆う）
    isFadingIn_ = true;     // シーン開始時にフェードインを行う
    isFadingOut_ = false;
    fadeSpeed_ = 0.02f;
    fadeSprite_->SetColor({0.0f, 0.0f, 0.0f, fadeAlpha_});
}

void GameSelect::Update()
{
    debugCamera_->Update();
    Input* input = Input::GetInstance();

    // --- フェードイン処理 ---
    if (isFadingIn_) {
        fadeAlpha_ -= fadeSpeed_;
        if (fadeAlpha_ <= 0.0f) {
            fadeAlpha_ = 0.0f;
            isFadingIn_ = false;
        }
        fadeSprite_->SetColor({0.0f, 0.0f, 0.0f, fadeAlpha_});
        return;
    }

    // --- フェードアウト処理 ---
    if (isFadingOut_) {
        fadeAlpha_ += fadeSpeed_;
        if (fadeAlpha_ >= 1.0f) {
            fadeAlpha_ = 1.0f;
            // SceneManager::GetInstance()->ChangeScene(nextScene_);
        }
        fadeSprite_->SetColor({0.0f, 0.0f, 0.0f, fadeAlpha_});
        return;
    }

    // マウス座標の取得
    Vector2 mousePos = input->GetMousePosition();

    // ホバー判定
hoveredSprite_ = -1;
for (int i = 0; i < kStageCount; i++) {
    Vector2 spritePos = sprites_[i]->GetPosition();
    Vector2 spriteSize = sprites_[i]->GetSize();

    float left   = spritePos.x - spriteSize.x ;
    float right  = spritePos.x + spriteSize.x ;
    float top    = spritePos.y - spriteSize.y ;
    float bottom = spritePos.y + spriteSize.y ;

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
}
	

void GameSelect::Draw()
{
	Sprite::PreDraw();

	for(int i = 0; i < kStageCount; i++) {
	    sprites_[i]->Draw();
	}
if (fadeAlpha_ > 0.0f) {
    fadeSprite_->Draw();
}
	Sprite::PostDraw();
}
