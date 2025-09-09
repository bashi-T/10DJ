#include "TextureLoader.h"

using namespace KamataEngine;

TextureLoader::TextureLoader()
{
	playerTextureHandle_ = TextureManager::Load("sample.png");
	wadPaperTextureHandle_ = TextureManager::Load("sample.png");
	trashCanTextureHandle_ = TextureManager::Load("sample.png");
	brockTextureHandle_ = TextureManager::Load("sample.png");
}
