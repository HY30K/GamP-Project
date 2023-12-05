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

	if (KEY_DOWN(KEY_TYPE::ENTER)) {
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


}

void ResultScene::Release()
{
	Scene::Release();

}
