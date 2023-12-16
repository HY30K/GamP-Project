#include "pch.h"
#include "ResultScene.h"
#include "Core.h"
#include "SceneMgr.h"
#include "KeyMgr.h"
#include "Title.h"
#include "EventMgr.h"
void ResultScene::Init()
{
	Object* tObj = new Title;
	tObj->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 })));
	tObj->SetScale(Vec2(100.f, 100.f));
	AddObject(tObj, OBJECT_GROUP::UI);

	restart = { 300,800 };
	GameQuit = { 800,800 };
}

void ResultScene::Update()
{
	Scene::Update();

	if (KEY_PRESS(KEY_TYPE::SPACE)) {
		EventMgr::GetInst()->SceneChange(L"Start_Scene");
	}
	if (KEY_PRESS(KEY_TYPE::X)) {
		PostQuitMessage(0);
	}
}

void ResultScene::Render(HDC _dc)
{
	Scene::Render(_dc);

	SetBkMode(_dc, 0);

	SetTextColor(_dc, RGB(255, 255, 255));
	HFONT nameFont = CreateFont(80, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	SelectObject(_dc, nameFont);
	TextOutW(_dc, 400, 20, Core::GetInst()->GetWinner() ? L"Left Player Won!" : L"Right Player Won!", 20);
	HFONT infoFont = CreateFont(20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	SelectObject(_dc, infoFont);
	TextOutW(_dc, 525, 550, L"스페이스바를 눌러 메인화면으로 돌아가기", 24);
	TextOutW(_dc, 580, 580, L"x키를 눌러 게임 종료", 13);

	DeleteObject(nameFont);
	DeleteObject(infoFont);

}

void ResultScene::Release()
{
	Scene::Release();

}
