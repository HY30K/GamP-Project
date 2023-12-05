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
	/*GetAnimator()->CreateAnim(L"Jump", m_pTex, Vec2(0.f, 135.f),
		Vec2(135.f, 135.f), Vec2(135.f, 0.f), 2, 0.1f);
	GetAnimator()->CreateAnim(L"Fall", m_pTex, Vec2(0.f, 945.f),
		Vec2(135.f, 135.f), Vec2(135.f, 0.f), 2, 0.1f);*/
	GetAnimator()->CreateAnim(L"Attack1", m_pTex, Vec2(0.f, 405.f),
		Vec2(135.f, 135.f), Vec2(135.f, 0.f), 4, 0.1f);
	GetAnimator()->CreateAnim(L"Attack2", m_pTex, Vec2(0.f, 675.f),
		Vec2(135.f, 135.f), Vec2(135.f, 0.f), 5, 0.1f);
	GetAnimator()->CreateAnim(L"Die", m_pTex, Vec2(0.f, 810.f),
		Vec2(135.f, 135.f), Vec2(135.f, 0.f), 9, 0.1f);
	GetAnimator()->CreateAnim(L"Hit", m_pTex, Vec2(0.f, 1080.f),
		Vec2(135.f, 135.f), Vec2(135.f, 0.f), 3, 0.1f);

	SetDir(true);
	GetAnimator()->PlayAnim(L"Idle", true);
}

LeftPlayer::~LeftPlayer()
{
}

void LeftPlayer::Update()
{
	Vec2 vPos = GetPos();

	if (KEY_PRESS(KEY_TYPE::A))
	{
		vPos.x -= 260 * fDT;
		SetDir(false);
		GetAnimator()->PlayAnim(L"Run", true);
	}
	if (KEY_PRESS(KEY_TYPE::D))
	{
		vPos.x += 260 * fDT;
		SetDir(true);
		GetAnimator()->PlayAnim(L"Run", true);
	}
	if (KEY_DOWN(KEY_TYPE::F))
	{
		//공격 키 1
		GetAnimator()->PlayAnim(L"Attack1", false, 1);
	}
	if (KEY_PRESS(KEY_TYPE::G))
	{
		//공격 키 2
		GetAnimator()->PlayAnim(L"Attack2", false, 1);
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
	Component_Render(_dc);
}

void LeftPlayer::GetDamage(UINT damage)
{
}
