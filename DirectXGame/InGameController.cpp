#include "InGameController.h"


using namespace KamataEngine;


InGameController::InGameController(const Vector2 screenSize) {
	ShowCursor(false);
	screenSize_ = screenSize;
	screenEdgeOffset_ = 200.0f;
	mouthTracker_ = new MouthTracker();
	textureLoader_ = new TextureLoader();
	playerCursor_ = new PlayerCursor();
	trashCan_ = new TrashCan(textureLoader_->GetTrashCanTexture());
	wadPaper_ = new WadPaper(textureLoader_->GetWadPaperTexture(), 15.0f);
}

InGameController::~InGameController() {
	delete mouthTracker_;
	delete playerCursor_;
	delete textureLoader_;
	delete trashCan_;
}



void InGameController::Initialize() {

	clearFlag_ = false;
	gameOverFlag_ = false;
	gameEndFlag_ = false;
	life_ = 3;
	textureScale_ = 30.0f;
	playerCursor_->Initialize(textureLoader_->GetPlayerTexture(), 0.5f, textureScale_);

	initialPaperPos_ = { 400, 300 };
	wadPaper_->~WadPaper();
	wadPaper_->Initialize(initialPaperPos_,*playerCursor_);

	trashCan_->Initialize();
}


void InGameController::Update() {

	playerCursor_->Update();
	if (!gameEndFlag_)
	{ 
		wadPaper_->Update(); 
	}

	trashCan_->Update();

	if (!gameEndFlag_)
	{
		wadPaper_->Collision(playerCursor_->GetPosition(), playerCursor_->GetSize());
		clearFlag_ = trashCan_->ClearFlag(wadPaper_->GetPosition(), wadPaper_->GetSize());
	}

	IsClear();
	RespornWadPaper();

#ifdef _DEBUG
	ImGui::Begin("Debug2");
	ImGui::Text("clearFlag %d", (int)clearFlag_);
	ImGui::Text("life %d", (int)life_);
	ImGui::End();
#endif // _DEBUG
}


void InGameController::Draw() {
	Sprite::PreDraw();

	if (!gameEndFlag_) 
	{ 
		wadPaper_->Draw();
	}
	trashCan_->Draw();

	playerCursor_->Draw();


	Sprite::PostDraw();
}

void InGameController::RespornWadPaper()
{
	if(wadPaper_ == nullptr) {
		return;
	}
	ScreenOutSide();
	if (wadPaper_->GetIsLife()) {
		return;
	}
	wadPaper_->~WadPaper();
	wadPaper_->Initialize(initialPaperPos_,*playerCursor_);
	trashCan_->ResetClearFlag();

	GameOver();
}

void InGameController::IsClear()
{
	if (clearFlag_)
	{
		//wadPaper_ ->~WadPaper();
		gameEndFlag_ = true;
	}
}

void InGameController::ScreenOutSide()
{
	if (wadPaper_->GetPosition().x<0.0f-screenEdgeOffset_) {
		wadPaper_->SetIsLife(false);
		return;
	}
	if (wadPaper_->GetPosition().x > screenSize_.x + screenEdgeOffset_) {
		wadPaper_->SetIsLife(false);
		return;
	}
	if (wadPaper_->GetPosition().y < 0.0f - screenEdgeOffset_) {
		wadPaper_->SetIsLife(false);
		return;
	}
	if (wadPaper_->GetPosition().y > screenSize_.y + screenEdgeOffset_) {
		wadPaper_->SetIsLife(false);
		return;
	}

}

void InGameController::GameOver()
{
	if (gameOverFlag_) {
		return;
	}
	life_--;
	if (life_ <= 0) {
		gameOverFlag_ = true;
		gameEndFlag_ = true;
		//wadPaper_->~WadPaper();
		
	}

}
