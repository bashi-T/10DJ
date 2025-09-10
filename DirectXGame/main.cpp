#include <Windows.h>
#include "KamataEngine.h"
#include "Scenes/GameScene.h"
#include "Fade.h"

using namespace KamataEngine;

int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
    DirectXCommon* dxCommon = DirectXCommon::GetInstance();


	Initialize(L"4022_バウンダリック");
	GameScene* gameScene = new GameScene;
	gameScene->Initialize();
	ImGuiManager* imguiManager = ImGuiManager::GetInstance();
	while (true)
	{
		if (Update())
		{
			break;
		}

        imguiManager->Begin();

		gameScene->Update();
		
		imguiManager->End();

        // 描画開始
        dxCommon->PreDraw();

		gameScene->Draw();
		
		imguiManager->Draw();

        // 描画終了
        dxCommon->PostDraw();
    }

    // メモリ解放
    delete gameScene;

    Finalize();
    return 0;
}
