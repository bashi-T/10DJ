#pragma once
#include <KamataEngine.h>

class TextureLoader
{
public:
	TextureLoader();

	uint32_t GetPlayerTexture() { return playerTextureHandle_; }
	uint32_t GetWadPaperTexture() { return wadPaperTextureHandle_; }
	uint32_t GetTrashCanTexture() { return trashCanTextureHandle_; }
	uint32_t GetBlockTexture() { return blockTextureHandle_; }
	uint32_t GetGrabAreaTexture() { return grabAreaTextureHandle_; }
	uint32_t GetPortalTextureHandle() { return portalTextureHandle_; }
	uint32_t GetConfettiTextureHandle() const{ return confettiTextureHandle_; }

private:
	uint32_t playerTextureHandle_ = 0;
	uint32_t wadPaperTextureHandle_ = 0;
	uint32_t trashCanTextureHandle_ = 0;
	uint32_t blockTextureHandle_ = 0;
	uint32_t grabAreaTextureHandle_ = 0;
	uint32_t portalTextureHandle_ = 0;
	uint32_t confettiTextureHandle_ = 0;
};

