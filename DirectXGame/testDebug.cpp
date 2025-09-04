#include "testDebug.h"

using namespace KamataEngine;


testDebug::testDebug() {

	ShowCursor(false);

	mouthTracker_=new MouthTracker();
	textureHandle_ = TextureManager::Load("sample.png");
	playerCursor_ = new PlayerCursor();

}

testDebug::~testDebug() {
	delete mouthTracker_;
	delete testBox_;
	delete playerCursor_;
}

void testDebug::Initialize() {
	

	textureScale_ = 30.0f;
	
	playerCursor_->Initialize(textureHandle_, 0.5f, textureScale_);

	testBox_ = Sprite::Create(textureHandle_, {200, 200});
	testBox_->SetSize({300, 300});

	testBox_->SetAnchorPoint({0.5f, 0.5f});
	
	wadPaper_ = new WadPaper(textureHandle_, 15.0f);
	wadPaper_->Initialize({400, 300}, {0.5f, 0.5f});
	playerCursor_->SetWadPaper(wadPaper_);
}


void testDebug::Update() {
	mouthTracker_->Update();

	playerCursor_->Update();
	wadPaper_->Update();


	bool test = playerCursor_->MouthCollsion(wadPaper_->GetPosition(), wadPaper_->GetSize());
	bool test2 = playerCursor_->MouthCollsion(testBox_->GetPosition(), testBox_->GetSize());

	playerCursor_->TouchWadPaper(test);
	

	#ifdef _DEBUG
	ImGui::Begin("Debug2");
	ImGui::Text("MouthPos %d,%d", (int)mouthTracker_->GetMouthPos().x, (int)mouthTracker_->GetMouthPos().y);
	ImGui::Text("CursorCollision %d", test);
	ImGui::Text("CursorCollision2 %d", test2);
	ImGui::End();
	#endif // _DEBUG
}

void testDebug::Draw() {

	Sprite::PreDraw();

	testBox_->Draw();
	wadPaper_->Draw();
	playerCursor_->Draw();


	Sprite::PostDraw();
}
