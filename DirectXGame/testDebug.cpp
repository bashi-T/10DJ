#include "testDebug.h"

using namespace KamataEngine;


testDebug::testDebug() {
	mouthTracker_=new mouthTracker();
	textureHandle_ = TextureManager::Load("sample.png");
}

testDebug::~testDebug() {
	delete mouthTracker_;
	delete Cursor_;
	delete testBox_;
}

void testDebug::Initialize() {

	textureScale_ = 30.0f;
	Cursor_ = Sprite::Create(textureHandle_, {mouthTracker_->GetMouthPos().x, mouthTracker_->GetMouthPos().y});
	Cursor_->SetSize({textureScale_, textureScale_});

	testBox_ = Sprite::Create(textureHandle_, {200-300/2, 200-300/2});
	testBox_->SetSize({300, 300});

	Cursor_->SetAnchorPoint({0.0f, 0.0f});
	testBox_->SetAnchorPoint({0.0f, 0.0f});
}


void testDebug::Update() {
	mouthTracker_->Update();

	Cursor_->SetPosition({mouthTracker_->GetMouthPos().x - textureScale_/2 , mouthTracker_->GetMouthPos().y - textureScale_/2 });


	bool test = isCollision(Cursor_->GetPosition(), Cursor_->GetSize(), testBox_->GetPosition(), testBox_->GetSize());

	if (test) {
		Cursor_->SetColor({0, 0, 0, 1});
	}
	else {
		Cursor_->SetColor({1, 1, 1, 1});
	}
	

	#ifdef _DEBUG
	ImGui::Begin("Debug2");
	ImGui::Text("MouthPos %d,%d", (int)mouthTracker_->GetMouthPos().x, (int)mouthTracker_->GetMouthPos().y);
	ImGui::End();
	#endif // _DEBUG
}

void testDebug::Draw() {

	Sprite::PreDraw();

	testBox_->Draw();
	Cursor_->Draw();


	Sprite::PostDraw();
}
