#include "TextureLoader.h"

using namespace KamataEngine;

TextureLoader::TextureLoader()
{
	playerTextureHandle_ = TextureManager::Load("hand_1.png");
	wadPaperTextureHandle_ = TextureManager::Load("wadPaper.png");
	trashCanTextureHandle_ = TextureManager::Load("trashCan.png");
	blockTextureHandle_ = TextureManager::Load("block.png");
	grabAreaTextureHandle_ = TextureManager::Load("grabArea.png");
	portalTextureHandle_ = TextureManager::Load("portal_1.png");
	confettiTextureHandle_ = TextureManager::Load("white1x1.png");
	backGroundTextureHandle_ = TextureManager::Load("backGround.png");
}
