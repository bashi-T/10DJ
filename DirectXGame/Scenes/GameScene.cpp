#include "GameScene.h"

using namespace KamataEngine;

GameScene::GameScene() {}

GameScene::~GameScene()
{
	delete model_;
	delete debugCamera_;
}

void GameScene::Initialize() 
{
	sceneManager_ = SceneManager::GetInstance();

	model_ = Model::Create();
	worldTransform_.Initialize();
	camera_.Initialize();
	debugCamera_ = new DebugCamera(KamataEngine::WinApp::kWindowWidth, KamataEngine::WinApp::kWindowHeight);

	textureHandle_ = TextureManager::Load("sample.png");

	textureHandleSprite_ = TextureManager::Load("white1x1.png");
	sprite_ = Sprite::Create(textureHandleSprite_, {600, 50}, {1, 1, 1, 1}, {0.5, 0.5});
	sprite_->SetSize({5.0, 5.0});
	sceneManager_->Initialize();
}

void GameScene::Update()
{
	debugCamera_->Update();
	sceneManager_->Update();

	POINT pos;
	HWND hwnd = WinApp::GetInstance()->GetHwnd();
	GetCursorPos(&pos);
	ScreenToClient(hwnd, &pos);
	Vector2 mousePos = {(float)pos.x, (float)pos.y};
	sprite_->SetPosition(mousePos);

#ifdef _DEBUG
	ImGui::Begin("DEBUG1");
	ImGui::Text("mousePos %f,%f", mousePos.x, mousePos.y);
	ImGui::End();
#endif
}

void GameScene::Draw() 
{
	Model::PreDraw();
	model_->Draw(worldTransform_, debugCamera_->GetCamera(), textureHandle_);
	Model::PostDraw();

	Sprite::PreDraw();
	sprite_->Draw();
	Sprite::PostDraw();

	sceneManager_->Draw();
}
