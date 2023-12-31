#include "pch.h"
#include "RightPlayer.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "Slash.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Texture.h"
#include "PathMgr.h"
#include "ResMgr.h"
#include "Collider.h"
#include "Animator.h"
#include "Animation.h"
#include "HPBar.h"
#include "Core.h"
#include "EventMgr.h"
RightPlayer::RightPlayer() :
	m_pTex(nullptr)
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"Player2", L"Player\\Player2.bmp");
	CreateCollider();
	GetCollider()->SetScale(Vec2(20.f, 30.f));

	CreateAnimator();
	GetAnimator()->CreateAnim(L"Idle", m_pTex, Vec2(0.f, 800.f),
		Vec2(200.f, 200.f), Vec2(200.f, 0.f), 4, 0.1f);
	GetAnimator()->CreateAnim(L"Run", m_pTex, Vec2(0.f, 1200.f),
		Vec2(200.f, 200.f), Vec2(200.f, 0.f), 8, 0.1f);
	/*GetAnimator()->CreateAnim(L"Jump", m_pTex, Vec2(0.f, 135.f),
		Vec2(200.f, 200.f), Vec2(200.f, 0.f), 2, 0.1f);
	GetAnimator()->CreateAnim(L"Fall", m_pTex, Vec2(0.f, 945.f),
		Vec2(200.f, 200.f), Vec2(200.f, 0.f), 2, 0.1f);*/
	GetAnimator()->CreateAnim(L"Attack1", m_pTex, Vec2(0.f, 0.f),
		Vec2(200.f, 200.f), Vec2(200.f, 0.f), 4, 0.1f);
	GetAnimator()->CreateAnim(L"Attack2", m_pTex, Vec2(0.f, 200.f),
		Vec2(200.f, 200.f), Vec2(200.f, 0.f), 4, 0.1f);
	GetAnimator()->CreateAnim(L"Die", m_pTex, Vec2(0.f, 400.f),
		Vec2(200.f, 200.f), Vec2(200.f, 0.f), 7, 0.1f);
	GetAnimator()->CreateAnim(L"Hit", m_pTex, Vec2(0.f, 1400.f),
		Vec2(200.f, 200.f), Vec2(200.f, 0.f), 3, 0.1f);

	GetAnimator()->PlayAnim(L"Idle", true);
	SetHPBar();
}

RightPlayer::~RightPlayer()
{
}

void RightPlayer::Update()
{
	Vec2 vPos = GetPos();

	if (KEY_PRESS(KEY_TYPE::LEFT))
	{
		vPos.x -= 260 * fDT;
		SetDir(false);
		GetAnimator()->PlayAnim(L"Run", true);
	}
	if (KEY_PRESS(KEY_TYPE::RIGHT))
	{
		vPos.x += 260 * fDT;
		SetDir(true);
		GetAnimator()->PlayAnim(L"Run", true);
	}
	if (KEY_DOWN(KEY_TYPE::PERIOD))
	{
		//���� Ű 1
		CreateSlash();
		ResMgr::GetInst()->Play(L"Attack");
		GetAnimator()->PlayAnim(L"Attack1", false, 1);
	}
	if (KEY_UP(KEY_TYPE::LEFT) || KEY_UP(KEY_TYPE::RIGHT))
	{
		GetAnimator()->PlayAnim(L"Idle", true);
	}

	SetPos(vPos);
	GetAnimator()->Update();
}

void RightPlayer::CreateSlash()
{
	Slash* pSlash = new Slash;
	Vec2 vSlashPos = GetPos();
	vSlashPos.y -= GetScale().y / 6;
	pSlash->SetPos(vSlashPos);
	pSlash->SetScale(Vec2(25.f, 25.f));
	pSlash->SetDir(Vec2(-5.f, 0.f));
	pSlash->SetName(L"Player_Slash2");
	SceneMgr::GetInst()->GetCurScene()->AddObject(pSlash,
		OBJECT_GROUP::SLASH2);
}

void RightPlayer::Render(HDC _dc)
{
	Component_Render(_dc);
}

void RightPlayer::EnterCollision(Collider* _pOther)
{
	if (_pOther == nullptr)
		return;
	const Object* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"Player_Slash1")
	{
		//�Ǹ� ����ָ� ��.
		GetAnimator()->PlayAnim(L"Hit", false, 1);
		GetDamage(5);
	}
}

void RightPlayer::ExitCollision(Collider* _pOther)
{
}

void RightPlayer::StayCollision(Collider* _pOther)
{
}

void RightPlayer::GetDamage(UINT damage)
{
	int leftHP = p_HPBar->GetHP() - damage;
	p_HPBar->SetHP(leftHP);
	if (leftHP <= 0) {
		Core::GetInst()->SetWinner(true);
		EventMgr::GetInst()->SceneChange(L"ResultScene");
	}
}

void RightPlayer::SetHPBar()
{
	Vec2 hpbarPos = Vec2(880, 0);
	p_HPBar = new HPBar(100,false);
	p_HPBar->SetPos(hpbarPos);
	p_HPBar->SetScale(Vec2(25.f, 25.f));
	p_HPBar->SetName(L"Right_HP_BAR");
	SceneMgr::GetInst()->GetCurScene()->AddObject(p_HPBar, OBJECT_GROUP::UI);
}