#include "Block.h"

using namespace KamataEngine;

Block::Block(uint32_t textureHandle,float size)
{
	textureHandle_ = textureHandle;
	size_ = size;
}

Block::~Block()
{
	delete block_;
}

void Block::Initialize(Vector2 position)
{
	block_ = KamataEngine::Sprite::Create(textureHandle_, position);
	block_->SetSize({ size_,size_ });
	block_->SetAnchorPoint({ 0.5f ,0.5f });
}

void Block::Update()
{
	block_->Draw();
}

void Block::Draw()
{
	block_->Draw();
}
