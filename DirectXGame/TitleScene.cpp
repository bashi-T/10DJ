#include "TitleScene.h"
#include "Input.h"
#include "SceneManager.h"

TitleScene::TitleScene()
    : paper(100, 100, 64, 64), bin(600, 400, 128, 128), isDragging(false) 
{
    //初期化時に画像をロード
    

}

void TitleScene::Update(HWND hwnd, Fade& fade) {
    POINT mouse = Input::GetMousePosition(hwnd);

    if (Input::IsMouseDown()) {
        if (!isDragging && paper.HitTest(mouse.x, mouse.y)) {
            isDragging = true;
        }
    }
    else {
        if (isDragging) {
            if (paper.CheckCollision(bin)) {
                fade.Start(FadeState::FADE_OUT, 0.02f); // フェードアウト開始
            }
        }
        isDragging = false;
    }

    if (isDragging) {
        paper.rect.x = mouse.x - paper.rect.w / 2;
        paper.rect.y = mouse.y - paper.rect.h / 2;
    }

    fade.Update();

    // フェードアウト完了でシーン遷移
    if (fade.GetState() == FadeState::NONE && fade.GetAlpha() >= 1.0f) {
        SceneManager::ChangeScene(GAME);
        fade.Start(FadeState::FADE_IN, 0.02f); // ゲームシーンに入ったらフェードイン
    }
}

void TitleScene::Draw(ID3D12GraphicsCommandList* cmdList, Fade& fade) {
    // TODO: paper と bin をテクスチャ付きで描画

    // 最後にフェードを上から重ねる
    fade.Draw(cmdList);
}
