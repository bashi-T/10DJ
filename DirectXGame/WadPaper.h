#pragma once
#include <KamataEngine.h>

class WadPaper {
public:
	WadPaper(uint32_t textureHandle,float paperSize);
	~WadPaper();


	void Initialize(const KamataEngine::Vector2 position, const KamataEngine::Vector2 AnchorPoint);
	void Update();
	void Draw();


	void SetPosition(const KamataEngine::Vector2 position) { wadPaper_->SetPosition(position); }

	KamataEngine::Vector2 GetPosition() const { return wadPaper_->GetPosition(); }
	KamataEngine::Vector2 GetSize() const { return wadPaper_->GetSize(); }

private:

	void AddGravity();

	KamataEngine::Sprite* wadPaper_ = nullptr;
	uint32_t textureHandle_ = 0;
	float paperSize_ = 0;
	bool isGrabed_ = false;
	float gravity_ = 1.0f;
};
