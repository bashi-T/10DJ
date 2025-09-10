#include <Windows.h>
#include "KamataEngine.h"
#include "SceneManager.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "Fade.h"

using namespace KamataEngine;

int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
    DirectXCommon* dxCommon = DirectXCommon::GetInstance();

    Initialize(L"Boundrick");

    // シーン作成
    TitleScene* titleScene = new TitleScene;
    GameScene* gameScene = new GameScene;
    Fade fade;

    // 各シーンの初期化
    titleScene->Initialize();
    gameScene->Initialize();

    // 最初はタイトルから
    SceneManager::ChangeScene(TITLE);
    
    ImGuiManager* imguiManager = ImGuiManager::GetInstance();

    while (true) {
        if (Update()) {
            break;
        }

        imguiManager->Begin();

        // シーンごとにUpdate
        switch (SceneManager::current) {
        case TITLE:
            titleScene->Update();
            break;
        case STAGE_SELECT:
            break;
        }

        imguiManager->End();

        // 描画開始
        dxCommon->PreDraw();

        // シーンごとにDraw
        switch (SceneManager::current) {
        case TITLE:
            titleScene->Draw();
            break;
        case STAGE_SELECT:
            break;
        }

        imguiManager->Draw();

        // 描画終了
        dxCommon->PostDraw();
    }

    // メモリ解放
    delete titleScene;
    delete gameScene;

    Finalize();
    return 0;
}
