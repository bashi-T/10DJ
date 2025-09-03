#include <Windows.h>
#include "KamataEngine.h"
#include "GameScene.h"

using namespace KamataEngine;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int)
{
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();
	GameScene* gameScene = new GameScene;

	Initialize(L"Boundrick");
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

		//描画開始
		dxCommon->PreDraw();

		gameScene->Draw();
	
		imguiManager->Draw();

		//描画終了
		dxCommon->PostDraw();
	}

	delete gameScene;
	gameScene = nullptr;
	Finalize();
	return 0;
}
