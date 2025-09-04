#include "InGameController.h"

using namespace KamataEngine;


InGameController::InGameController() {}

InGameController::~InGameController() {}



void InGameController::Initialize() {}


void InGameController::Update() {}


void InGameController::Draw() {
	KamataEngine::Sprite::PreDraw();


	KamataEngine::Sprite::PostDraw();
}