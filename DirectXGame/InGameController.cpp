#include "InGameController.h"


using namespace KamataEngine;


InGameController::InGameController(const Vector2 screenSize) {

	initialPaperPos_ = { 400, 300 };

	ShowCursor(false);
	screenSize_ = screenSize;
	screenEdgeOffset_ = 200.0f;
	mouthTracker_ = new MouthTracker();
	textureLoader_ = new TextureLoader();
	audioLoader_ = new AudioLoader();
	playerCursor_ = new PlayerCursor();
	trashCan_ = new TrashCan(textureLoader_->GetTrashCanTexture());
	wadPaper_ = new WadPaper(textureLoader_->GetWadPaperTexture(), 15.0f);
	grabArea_ = new GrabArea(textureLoader_->GetGrabAreaTexture(), initialPaperPos_, { 400,400 });
}

InGameController::~InGameController() {
	delete mouthTracker_;
	delete playerCursor_;
	delete textureLoader_;
	delete trashCan_;
	delete audioLoader_;
	delete grabArea_;
	blocks_.clear();
}



void InGameController::Initialize() {

	clearFlag_ = false;
	gameOverFlag_ = false;
	gameEndFlag_ = false;
	isCanGrab_ = false;
	life_ = 3;
	textureScale_ = 30.0f;
	playerCursor_->Initialize(textureLoader_->GetPlayerTexture(), 0.5f, textureScale_);


	wadPaper_->~WadPaper();
	wadPaper_->Initialize(initialPaperPos_,*playerCursor_);
	
	trashCan_->Initialize();
	grabArea_->Initialize();
	for (int i = 0; i < numChipY; i++) 
	{
		for (int j = 0; j < numChipX; j++) 
		{
			if (stage[0][i][j] == 1) 
			{
				Block* block_ = new Block(textureLoader_->GetBlockTexture(), 36.0f);
				block_->Initialize({(float)chipSize * j, (float)chipSize * i});
				blocks_.push_back(block_);
			}
		}
	}
}


void InGameController::Update() 
{

	for (int i = 0; i < numChipY; i++)
	{
		for (int j = 0; j < numChipX; j++)
		{
			if (stage[0][i][j] == 1)
			{
				if (isCollision(wadPaper_->GetPosition(), wadPaper_->GetSize(), {(float)j, (float)i}))
				{
					Vector2 chipPos = {(float)chipSize * j, (float)chipSize * i};
					Vector2 chipsSize = {(float)chipSize, (float)chipSize};
					wadPaper_->PushBack(chipPos, chipsSize);
				}
			}
		}
	}

	playerCursor_->Update();
	if (!gameEndFlag_)
	if (!gameEndFlag_)
	{ 
		wadPaper_->Update(isCanGrab_); 
	}

	trashCan_->Update();
	grabArea_->Update();

	for (const auto& block : blocks_)
	{
		block->Update();
	}


	if (!gameEndFlag_)
	{
		bool grabBuff= wadPaper_->Collision(playerCursor_->GetPosition(), playerCursor_->GetSize());
		bool grabBuff2 = grabArea_->Collision(playerCursor_->GetPosition(), playerCursor_->GetSize());
		clearFlag_ = trashCan_->ClearFlag(wadPaper_->GetPosition(), wadPaper_->GetSize());

		if (Input::GetInstance()->IsPressMouse(0) && grabBuff && grabBuff2)
		{
			isCanGrab_ = true;
		}
		else 
		{
			isCanGrab_ = false;
		}
	}


#ifdef _DEBUG
	ImGui::Begin("INGAME");
	ImGui::Text("clearFlag %d", (int)clearFlag_);
	ImGui::Text("life %d", (int)life_);
	ImGui::End();
#endif // _DEBUG

	if (gameEndFlag_) {
		return;
	}
	IsClear();
	RespornWadPaper();

}


void InGameController::Draw() {
	Sprite::PreDraw();

	grabArea_->Draw();
	if (!gameEndFlag_) 
	{ 
		wadPaper_->Draw();
	}
	trashCan_->Draw();

	playerCursor_->Draw();

	for (const auto& block : blocks_)
	{
		block->Draw();
	}

	Sprite::PostDraw();
}

void InGameController::RespornWadPaper()
{

	ScreenOutSide();
	if (wadPaper_->GetIsLife()) {
		return;
	}
	wadPaper_->~WadPaper();
	wadPaper_->Initialize(initialPaperPos_,*playerCursor_);
	trashCan_->ResetClearFlag();
	Audio::GetInstance()->PlayWave(audioLoader_->GetPaperBrake_());

	GameOver();
}

void InGameController::IsClear()
{
	if (clearFlag_)
	{
		gameEndFlag_ = true;
		Audio::GetInstance()->PlayWave(audioLoader_->GetFanfare());
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
