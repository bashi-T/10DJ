#include "GameScene.h"
#include "Math\CGVector.h"

using namespace KamataEngine;

inline static float testZ_ = 0.0f;

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

	//debugCamera_->Update();
	mouthTracker_->Update();

	worldTransform_.translation_.x = mouthTracker_->GetMouthPos().x-screenWidth/2;
	worldTransform_.translation_.y = -mouthTracker_->GetMouthPos().y+screenHeight/2;
	worldTransform_.translation_.z = testZ_;


	worldTransform_.matWorld_ = MakeAffineMatrix(worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);
	worldTransform_.TransferMatrix();

	#ifdef _DEBUG
	ImGui::Begin("DEBUG1");
	ImGui::Text("DebugText %d,%d,%d", 2025, 12, 31);
	ImGui::SliderFloat("testZ", &testZ_, 0.0f, 300.0f);
	ImGui::End();
	#endif
}

void GameScene::Draw() 
{
	Model::PreDraw();

	model_->Draw(worldTransform_, debugCamera_->GetCamera(), textureHandle_);

	Model::PostDraw();
}
