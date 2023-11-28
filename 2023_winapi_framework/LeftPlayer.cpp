#include "pch.h"
#include "LeftPlayer.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "Bullet.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Texture.h"
#include "PathMgr.h"
#include "ResMgr.h"
#include "Collider.h"
#include "Animator.h"
#include "Animation.h"
LeftPlayer::LeftPlayer()
	: m_pTex(nullptr)
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"Player1", L"Player\\Player1.bmp");
	CreateCollider();
	GetCollider()->SetScale(Vec2(20.f, 30.f));

	CreateAnimator();
	GetAnimator()->CreateAnim(L"Idle", m_pTex, Vec2(0.f, 0.f),
		Vec2(135.f, 135.f), Vec2(135.f, 0.f), 10, 0.1f);
	GetAnimator()->CreateAnim(L"Run", m_pTex, Vec2(0.f, 270.f),
		Vec2(135.f, 135.f), Vec2(135.f, 0.f), 6, 0.1f);
	GetAnimator()->CreateAnim(L"Jump", m_pTex, Vec2(0.f, 135.f),
		Vec2(135.f, 135.f), Vec2(135.f, 0.f), 2, 0.1f);
	GetAnimator()->CreateAnim(L"Fall", m_pTex, Vec2(0.f, 945.f),
		Vec2(135.f, 135.f), Vec2(135.f, 0.f), 2, 0.1f);
	GetAnimator()->CreateAnim(L"Attack1", m_pTex, Vec2(0.f, 405.f),
		Vec2(135.f, 135.f), Vec2(135.f, 0.f), 4, 0.1f);

	GetAnimator()->PlayAnim(L"Idle", true);
}

LeftPlayer::~LeftPlayer()
{
}

void LeftPlayer::Update()
{
	Vec2 vPos = GetPos();

	if (KEY_PRESS(KEY_TYPE::W))
	{
		vPos.y -= 160 * fDT;
		GetAnimator()->PlayAnim(L"Jump", true);
		GetAnimator()->PlayAnim(L"fall", true);
		//do jump
	}
	if (KEY_PRESS(KEY_TYPE::A)) 
	{
		vPos.x -= 160 * fDT;
		SetDir(false);
		GetAnimator()->PlayAnim(L"Run", true);
	}
	if (KEY_PRESS(KEY_TYPE::D)) 
	{
		vPos.x += 160 * fDT;
		SetDir(true);
		GetAnimator()->PlayAnim(L"Run", true);
	}
	if (KEY_DOWN(KEY_TYPE::F)) 
	{ //공격키 1 
		GetAnimator()->PlayAnim(L"Attack1", false, 1);
	}
	if (KEY_PRESS(KEY_TYPE::G)) 
	{ //공격키 2 

	}
	if (KEY_UP(KEY_TYPE::A) || KEY_UP(KEY_TYPE::D))
	{
		GetAnimator()->PlayAnim(L"Idle", true);
	}
	SetPos(vPos);
	GetAnimator()->Update();
}

void LeftPlayer::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	int Width = m_pTex->GetWidth();
	int Height = m_pTex->GetHeight();
	//// 1. 기본 옮기기
	//BitBlt(_dc
	//	, (int)(vPos.x - vScale.x / 2)
	//	, (int)(vPos.y - vScale.y / 2)
	//	, Width, Height, m_pTex->GetDC()
	//	, 0, 0, SRCCOPY);
	/*StretchBlt(_dc
		, (int)(vPos.x - vScale.x / 2)
		, (int)(vPos.y - vScale.y / 2)
		, Width, Height, m_pTex->GetDC()
		, 0, 0, Width, Height, SRCCOPY);*/
	Component_Render(_dc);
}

void LeftPlayer::GetDamage(UINT damage)
{
}
