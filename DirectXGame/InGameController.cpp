#include "InGameController.h"


using namespace KamataEngine;


InGameController::InGameController(const Vector2 screenSize,int32_t stageNumber) {
	ShowCursor(false);
	screenSize_ = screenSize;
	screenEdgeOffset_ = 2000.0f;
	textureLoader_ = new TextureLoader();
	effectController_ = new EffectController(textureLoader_);
	mouthTracker_ = new MouthTracker();
	audioLoader_ = new AudioLoader();
	playerCursor_ = new PlayerCursor();
	trashCan_ = new TrashCan(textureLoader_->GetTrashCanTexture());
	wadPaper_ = new WadPaper(textureLoader_->GetWadPaperTexture(), 15.0f);

	if (stageNumber == 0) {
		initialPaperPos_ = { 400, 300 };
		grabArea_ = new GrabArea(textureLoader_->GetGrabAreaTexture(), initialPaperPos_, { 400,400 });
		portalA_ = new Portal({ 400, 0 }, { 400, screenSize_.y }, { 400, 50 }, textureLoader_->GetPortalTextureHandle());
		portalB_ = new Portal({ 400, screenSize_.y }, { 400, 0 }, { 400, 50 }, textureLoader_->GetPortalTextureHandle());
	}
	else {
		initialPaperPos_ = { 400, 300 };
		grabArea_ = new GrabArea(textureLoader_->GetGrabAreaTexture(), initialPaperPos_, { 400,400 });

		Vector2 portalApos = { 0,300 };
		Vector2 portalASize = { 50,400 };

		Vector2 portalBpos = { screenSize_.x,400 };
		Vector2 portalBSize = { 50,400 };
		portalA_ = new Portal(portalApos, portalBpos, portalASize, textureLoader_->GetPortalTextureHandle());
		portalB_ = new Portal(portalBpos, portalApos, portalBSize, textureLoader_->GetPortalTextureHandle());
	}
}

InGameController::~InGameController() {
	delete mouthTracker_;
	delete playerCursor_;
	delete textureLoader_;
	delete trashCan_;
	delete audioLoader_;
	delete grabArea_;
	delete portalA_;
	delete portalB_;
	delete effectController_;
	delete backGround_;
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

	portalA_->Initialize();
	portalB_->Initialize();
	effectController_->Initialize();

	textureHandle_ = textureLoader_->GetBackGroundTextureHandle();
	backGround_ = KamataEngine::Sprite::Create(textureHandle_, {600,300});
	backGround_->SetSize({4000, 4000});
	backGround_->SetAnchorPoint({0.5f, 0.5f});

	//Audio::GetInstance()->PlayWave(audioLoader_->GetBGM());
	
}


void InGameController::Update() {

	playerCursor_->Update();
	if (!gameEndFlag_)
	{ 
		wadPaper_->Update(isCanGrab_); 
	}

	trashCan_->Update();
	grabArea_->Update();
	portalA_->Update();
	portalB_->Update();
	effectController_->Update(life_);

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
		Warp();
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

	backGround_->Draw();

	portalA_->Draw();
	portalB_->Draw();

	grabArea_->Draw();
	if (!gameEndFlag_) 
	{ 
		wadPaper_->Draw();
	}



	trashCan_->Draw();

	playerCursor_->Draw();

	effectController_->Draw();

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

void InGameController::Warp() 
{
	bool warpA=portalA_->Collision(wadPaper_->GetPosition(),wadPaper_->GetSize());
	bool warpB=portalB_->Collision(wadPaper_->GetPosition(),wadPaper_->GetSize());

	if (!warpA && !warpB) {
		wadPaper_->SetWarping(false);
	}
	if ( wadPaper_->GetWarping()==true) {
		return;
	}

	if (warpA) 
	{
		wadPaper_->SetPosition({wadPaper_->GetPosition().x - portalA_->GetDistance().x, wadPaper_->GetPosition().y - portalA_->GetDistance().y});
		wadPaper_->SetWarping(true);
	}
	if (warpB) 
	{
		wadPaper_->SetPosition({wadPaper_->GetPosition().x - portalB_->GetDistance().x, wadPaper_->GetPosition().y - portalB_->GetDistance().y});
		wadPaper_->SetWarping(true);
	}

}
