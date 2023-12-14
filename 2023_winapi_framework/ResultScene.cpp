#include "pch.h"
#include "ResultScene.h"
#include "Core.h"
#include "SceneMgr.h"
#include "KeyMgr.h"
void ResultScene::Init()
{
}

void ResultScene::Update()
{
	Scene::Update();

	if (KEY_DOWN(KEY_TYPE::F)) {
		if (Core::GetInst()->GetWinner()) {
			SceneMgr::GetInst()->LoadScene(L"Start_Scene");
		}
		else {
			SceneMgr::GetInst()->LoadScene(L"In_Game_Scene");
		}
	}


}

void ResultScene::Render(HDC _dc)
{
	Scene::Render(_dc);

	SetBkMode(_dc, 0);

	SetTextColor(_dc, RGB(0, 0, 0));
	TextOutW(_dc, 525, 550, Core::GetInst()->GetWinner() ? L"Left Player Won!" : L"Right Player Won!", 20);

}

void ResultScene::Release()
{
	Scene::Release();

}
