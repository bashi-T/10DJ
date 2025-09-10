#include "KamataEngine.h"

using namespace KamataEngine;

// 静的メンバ変数の実体
ID3D12Device* Sprite::sDevice_ = nullptr;
UINT Sprite::sDescriptorHandleIncrementSize_ = 0;
ID3D12GraphicsCommandList* Sprite::sCommandList_ = nullptr;
Microsoft::WRL::ComPtr<ID3D12RootSignature> Sprite::sRootSignature_;
std::array<Microsoft::WRL::ComPtr<ID3D12PipelineState>, size_t(Sprite::BlendMode::kCountOfBlendMode)> Sprite::sPipelineStates_;
Matrix4x4 Sprite::sMatProjection_;

Sprite::Sprite() {}
Sprite::Sprite(uint32_t textureHandle, Vector2 position, Vector2 size, Vector4 color, Vector2 anchorpoint, bool isFlipX, bool isFlipY) {
    textureHandle_ = textureHandle;
    position_ = position;
    size_ = size;
    color_ = color;
    anchorPoint_ = anchorpoint;
    isFlipX_ = isFlipX;
    isFlipY_ = isFlipY;
}

Sprite* Sprite::Create(uint32_t textureHandle, Vector2 position, Vector4 color, Vector2 anchorpoint, bool isFlipX, bool isFlipY) {
    Sprite* sprite = new Sprite(textureHandle, position, { 100.0f,100.0f }, color, anchorpoint, isFlipX, isFlipY);
    sprite->Initialize();
    return sprite;
}

bool Sprite::Initialize() {
    // 頂点バッファ作成
    // 定数バッファ作成
    // vbView_ の設定
    // constMap_ に初期データ書き込み
    TransferVertices();
    return true;
}

void Sprite::TransferVertices() {
    // position_, size_, anchorPoint_ から頂点座標を計算して vertMap_ に書き込む
}

void Sprite::SetTextureHandle(uint32_t textureHandle) {
    textureHandle_ = textureHandle;
}

void Sprite::SetPosition(const Vector2& position) {
    position_ = position;
    TransferVertices();
}

void Sprite::SetRotation(float rotation) {
    rotation_ = rotation;
}

void Sprite::SetSize(const Vector2& size) {
    size_ = size;
    TransferVertices();
}

void Sprite::SetAnchorPoint(const Vector2& anchorpoint) {
    anchorPoint_ = anchorpoint;
    TransferVertices();
}

void Sprite::SetIsFlipX(bool isFlipX) {
    isFlipX_ = isFlipX;
    TransferVertices();
}

void Sprite::SetIsFlipY(bool isFlipY) {
    isFlipY_ = isFlipY;
    TransferVertices();
}

void Sprite::SetTextureRect(const Vector2& texBase, const Vector2& texSize) {
    texBase_ = texBase;
    texSize_ = texSize;
    TransferVertices();
}

void Sprite::PreDraw(ID3D12GraphicsCommandList* cmdList, BlendMode blendMode) {
    sCommandList_ = cmdList;
    // ここでPSOやRootSignatureをセット
}

void Sprite::PostDraw() {
    sCommandList_ = nullptr;
}

void Sprite::Draw() {
    if (!sCommandList_) return;

    // TextureManagerからSRVを取得
    TextureManager::GetInstance()->SetGraphicsRootDescriptorTable(sCommandList_, 1, textureHandle_);

    // 定数バッファ更新
    constMap_->color = color_;
    constMap_->mat = KamataEngine::MultiplyMatrix4x4(matWorld_, sMatProjection_);
    // VBVセット
    sCommandList_->IASetVertexBuffers(0, 1, &vbView_);
    sCommandList_->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

    // ドローコール
    sCommandList_->DrawInstanced(4, 1, 0, 0);
}
