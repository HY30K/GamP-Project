#include "pch.h"
#include "In_Game_Scene.h"
#include "Core.h"
#include "LeftPlayer.h" //여기서부터 필요한 오브젝트들 include 해주면 된다
#include "Rightplayer.h"
#include "CollisionMgr.h"
void In_Game_Scene::Init()
{
	Object* pObj = new LeftPlayer;
	pObj->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2 - 400, Core::GetInst()->GetResolution().y / 2 })));
	pObj->SetScale(Vec2(100.f, 100.f));
	AddObject(pObj, OBJECT_GROUP::PLAYER);

	Object* rpObj = new RightPlayer;
	rpObj->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2 + 400, Core::GetInst()->GetResolution().y / 2 })));
	rpObj->SetScale(Vec2(100.f, 100.f));
	AddObject(rpObj, OBJECT_GROUP::PLAYER);
}

void In_Game_Scene::Update()
{
	Scene::Update();
}

void In_Game_Scene::Render(HDC _dc)
{
	Scene::Render(_dc);
}

void In_Game_Scene::Release()
{
	Scene::Release();
	CollisionMgr::GetInst()->CheckReset();
}
