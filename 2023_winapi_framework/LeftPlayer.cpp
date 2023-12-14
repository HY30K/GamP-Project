#include "pch.h"
#include "LeftPlayer.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "HPBar.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Texture.h"
#include "PathMgr.h"
#include "ResMgr.h"
#include "Collider.h"
#include "Animator.h"
#include "Animation.h"
#include "HPBar.h"
#include "SlashR.h"
#include "Core.h"
LeftPlayer::LeftPlayer()
	: m_pTex(nullptr),
	p_HPBar (new HPBar)
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
	SetHPBar();
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
		CreateSlash();
		GetAnimator()->PlayAnim(L"Attack1", false, 1);
	}
	if (KEY_PRESS(KEY_TYPE::G))
	{
		//공격 키 2
		GetAnimator()->PlayAnim(L"Attack2", false, 1);
	}
	if (KEY_DOWN(KEY_TYPE::P)) {
		GetAnimator()->PlayAnim(L"Hit", false, 1);
		GetDamage(5);
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

void LeftPlayer::EnterCollision(Collider* _pOther)
{
	const Object* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"Player_Slash2")
	{
		//피를 깎아주면 됨.
	}
}

void LeftPlayer::ExitCollision(Collider* _pOther)
{
}

void LeftPlayer::StayCollision(Collider* _pOther)
{
}

void LeftPlayer::CreateSlash()
{
	SlashR* pSlash = new SlashR;
	Vec2 vSlashPos = GetPos();
	vSlashPos.y -= GetScale().y / 6;
	pSlash->SetPos(vSlashPos);
	pSlash->SetScale(Vec2(25.f, 25.f));
	pSlash->SetDir(Vec2(5.f, 0.f));
	pSlash->SetName(L"Player_Slash1");
	SceneMgr::GetInst()->GetCurScene()->AddObject(pSlash,
		OBJECT_GROUP::SLASH1);
}

void LeftPlayer::GetDamage(int damage)
{
	int leftHP = p_HPBar->GetHP() - damage;
	p_HPBar->SetHP(leftHP);
	if (leftHP <= 0) {
		Core::GetInst()->SetWinner(false);
		SceneMgr::GetInst()->LoadScene(L"Resultscene");
	}
}

void LeftPlayer::SetHPBar()
{
	Vec2 vBulletPos = GetPos();
	vBulletPos.y -= GetScale().y / 2.f;
	p_HPBar = new HPBar(100,true);
	p_HPBar->SetPos(vBulletPos);
	p_HPBar->SetScale(Vec2(25.f, 25.f));
	p_HPBar->SetName(L"Left_HP_BAR");
	SceneMgr::GetInst()->GetCurScene()->AddObject(p_HPBar, OBJECT_GROUP::UI);
}
