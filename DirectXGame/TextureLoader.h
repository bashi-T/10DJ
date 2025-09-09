#pragma once
#include <KamataEngine.h>

class TextureLoader
{
public:
	TextureLoader();

	uint32_t GetPlayerTexture() { return playerTextureHandle_; };
	uint32_t GetWadPaperTexture() { return wadPaperTextureHandle_; };
	uint32_t GetTrashCanTexture() { return trashCanTextureHandle_; };
	uint32_t GetBlockTexture() { return blockTextureHandle_; };

private:
	uint32_t playerTextureHandle_ = 0;
	uint32_t wadPaperTextureHandle_ = 0;
	uint32_t trashCanTextureHandle_ = 0;
	uint32_t blockTextureHandle_ = 0;

};

