#include "testDebug.h"

using namespace KamataEngine;


testDebug::testDebug() {
	mouthTracker_=new mouthTracker();
	textureHandle_ = TextureManager::Load("sample.png");
}

testDebug::~testDebug() {
	delete mouthTracker_;
	delete sprite_;
}

void testDebug::Initialize() {

	sprite_ = Sprite::Create(textureHandle_, {mouthTracker_->GetMouthPos().x, mouthTracker_->GetMouthPos().y});
}


void testDebug::Update() {
	mouthTracker_->Update();

	sprite_->SetPosition(mouthTracker_->GetMouthPos());


	#ifdef _DEBUG
	ImGui::Begin("Debug2");
	//ImGui::SliderFloat("testZ", &testZ_, 0.0f, 300.0f);
	ImGui::Text("MouthPos %d,%d", (int)mouthTracker_->GetMouthPos().x, (int)mouthTracker_->GetMouthPos().y);
	ImGui::End();
	#endif // _DEBUG
}

void testDebug::Draw() {

	Sprite::PreDraw();

	sprite_->Draw();

}
