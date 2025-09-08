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
	}
}

void GameSelect::Update()
{
	// デバッグカメラの更新
	debugCamera_->Update();

	// マウスカーソルの座標を取得 (KamataEngineの関数に置き換えてください)
	Input* input = Input::GetInstance(); 

	Vector2 mousePosition = input->GetMousePosition();

	// マウスが重なっているスプライトを探す
	hoveredSprite_ = -1; // いったんリセット
	for (int i = 0; i < kStageCount; i++) {
		Vector2 pos = sprites_[i]->GetPosition();
		Vector2 size = sprites_[i]->GetSize(); // スプライトのサイズを取得

		// マウスがスプライトの矩形内にあるか判定
		if (mousePosition.x >= pos.x - size.x / 2 && mousePosition.x <= pos.x + size.x / 2 &&
		    mousePosition.y >= pos.y - size.y / 2 && mousePosition.y <= pos.y + size.y / 2) {
			hoveredSprite_ = i;
			break; // 見つかったらループを抜ける
		}
	}

	// 各スプライトのスケールを更新
	for (int i = 0; i < kStageCount; i++) {
		if (i == hoveredSprite_) {
			// マウスが重なっているスプライトのアニメーション
			animationTimer_ += 0.05f; // アニメーションの速度を少しずつ加算

			// ▼▼▼ この部分をシンプルに修正 ▼▼▼
			// cosfを使うと1.0から1.3の間を滑らかに往復する
			float smoothScale = 1.15f + 0.15f * cosf(animationTimer_);
			sprites_[i]->SetScale({smoothScale, smoothScale});

		} else {
			// マウスが重なっていないスプライトは元のサイズに戻す
			sprites_[i]->SetScale({1.0f, 1.0f});
		}
	}

	// animationTimer_が大きくなりすぎないようにリセット
	if (animationTimer_ > 2.0f * 3.14159265f) {
		animationTimer_ = 0.0f;
	}
	
	
#ifdef _DEBUG
	ImGui::Begin("GameSelect");
	ImGui::Text("This is GameSelect scene.");
	// ▼▼▼ 3Dモデル用からスプライト用に修正 ▼▼▼
	for (int i = 0; i < kStageCount; i++) {
		// スプライトの2D座標をImGuiで調整できるようにする
		KamataEngine::Vector2 pos = sprites_[i]->GetPosition();
		ImGui::DragFloat2(("Sprite Pos " + std::to_string(i)).c_str(), &pos.x, 1.0f);
		sprites_[i]->SetPosition(pos);
	}
	ImGui::End();
#endif
}

void GameSelect::Draw()
{
	Sprite::PreDraw();

	for(int i = 0; i < kStageCount; i++) {
	    sprites_[i]->Draw();
	}
	Sprite::PostDraw();
}
