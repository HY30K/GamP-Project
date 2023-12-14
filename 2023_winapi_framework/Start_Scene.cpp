#include "pch.h"
#include "Start_Scene.h"
#include "Object.h"
#include "Core.h"
#include "TItle.h"
#include "KeyMgr.h"
#include "CollisionMgr.h"
#include "ResMgr.h"
#include "SceneMgr.h"
void Start_Scene::Init() 
{
	// 이미지 세팅
	Object* tObj = new Title;
	tObj->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 })));
	tObj->SetScale(Vec2(100.f, 100.f));
	AddObject(tObj, OBJECT_GROUP::UI);

	// 사운드 세팅
	ResMgr::GetInst()->LoadSound(L"StartBGM", L"Sound\\StartBgm.wav", true);
	ResMgr::GetInst()->Play(L"StartBGM");
	
	Core::GetInst()->SetWinner(true);
}

void Start_Scene::Update()
{
	Scene::Update();
	if(KEY_DOWN(KEY_TYPE::ENTER))
		SceneMgr::GetInst()->LoadScene(L"In_Game_Scene");
}

void Start_Scene::Render(HDC _dc)
{
	Scene::Render(_dc);
	
	SetBkMode(_dc, 0);
	
	SetTextColor(_dc, RGB(255, 255, 255));
	HFONT nameFont = CreateFont(80, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	SelectObject(_dc, nameFont);
	TextOutW(_dc, (Core::GetInst()->GetResolution().x - GameName.size() * 60)/2, 20, GameName.c_str(), GameName.size());
	HFONT infoFont = CreateFont(20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	SelectObject(_dc, infoFont);
	TextOutW(_dc, 525, 550, L"Press Enter To Start", 20);

	DeleteObject(nameFont);
	DeleteObject(infoFont);
}

void Start_Scene::Release()
{
	Scene::Release();
	CollisionMgr::GetInst()->CheckReset();
}
