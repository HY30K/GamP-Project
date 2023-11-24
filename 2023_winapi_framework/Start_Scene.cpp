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
	ResMgr::GetInst()->LoadSound(L"BGM", L"Sound\\Retro_bgm.wav", true);
	ResMgr::GetInst()->LoadSound(L"Shoot", L"Sound\\laserShoot.wav", false);
	ResMgr::GetInst()->Play(L"BGM");
	

}

void Start_Scene::Update()
{
	Scene::Update();
	if(KEY_DOWN(KEY_TYPE::ENTER))
		SceneMgr::GetInst()->LoadScene(L"Game_Scene");

}

void Start_Scene::Render(HDC _dc)
{
	Scene::Render(_dc);
}

void Start_Scene::Release()
{
	Scene::Release();
	CollisionMgr::GetInst()->CheckReset();
}
