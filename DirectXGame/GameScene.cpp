#include "GameScene.h"

using namespace KamataEngine;

GameScene::GameScene() {}

GameScene::~GameScene()
{
	delete model_;
	delete debugCamera_;
	delete mouthTracker_;
}

void GameScene::Initialize() 
{
	model_ = Model::Create();
	worldTransform_.Initialize();
	camera_.Initialize();
	debugCamera_ = new DebugCamera(screenWidth,screenHeight);
	mouthTracker_ = new mouthTracker();

	textureHandle_ = TextureManager::Load("sample.png");
}

void GameScene::Update()
{

	debugCamera_->Update();
	mouthTracker_->Update();
	#ifdef _DEBUG
	ImGui::Begin("DEBUG1");
	ImGui::Text("DebugText %d,%d,%d", 2025, 12, 31);
	ImGui::Text("MouthPos %f,%f", mouthTracker_->GetMouthPos().x, mouthTracker_->GetMouthPos().y);
	ImGui::End();
	#endif
}

void GameScene::Draw() 
{
	Model::PreDraw();

	model_->Draw(worldTransform_, debugCamera_->GetCamera(), textureHandle_);

	Model::PostDraw();
}
