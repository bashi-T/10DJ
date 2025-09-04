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
	debugCamera_ = new DebugCamera(screenWidth,screenHeight);

	textureHandle_ = TextureManager::Load("sample.png");

	sceneManager_->Initialize();
}

void GameScene::Update()
{
	debugCamera_->Update();
	sceneManager_->Update();
#ifdef _DEBUG
	ImGui::Begin("DEBUG1");
	ImGui::Text("DebugText %d,%d,%d", 2025, 12, 31);
	ImGui::End();
#endif
}

void GameScene::Draw() 
{
	Model::PreDraw();
	model_->Draw(worldTransform_, debugCamera_->GetCamera(), textureHandle_);
	Model::PostDraw();

	sceneManager_->Draw();
}
