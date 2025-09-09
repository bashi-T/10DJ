#include "TextureLoader.h"

using namespace KamataEngine;

TextureLoader::TextureLoader()
{
	playerTextureHandle_ = TextureManager::Load("hand_1.png");
	wadPaperTextureHandle_ = TextureManager::Load("wadPaper.png");
	trashCanTextureHandle_ = TextureManager::Load("trashCan.png");
	blockTextureHandle_ = TextureManager::Load("block.png");
}
