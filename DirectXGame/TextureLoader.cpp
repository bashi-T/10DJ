#include "TextureLoader.h"

using namespace KamataEngine;

TextureLoader::TextureLoader()
{
	playerTextureHandle_ = TextureManager::Load("hand_1.png");
	wadPaperTextureHandle_ = TextureManager::Load("wadPaper.png");
	trashCanTextureHandle_ = TextureManager::Load("tex1.png");
	brockTextureHandle_ = TextureManager::Load("sample.png");
}
