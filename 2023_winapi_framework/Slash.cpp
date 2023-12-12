#include "pch.h"
#include "Slash.h"
#include "TimeMgr.h"
#include "Animator.h"
#include "ResMgr.h"
#include "Texture.h"

Slash::Slash()
	: m_fTheta(0.f)
	, m_vDir(Vec2(0.f, 0.f))
	, m_pTex(nullptr)
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"SlashL", L"Player\\SlashLeft.bmp");
	CreateCollider();
}

Slash::~Slash()
{
}

void Slash::Update()
{
	Vec2 vPos = GetPos();
	vPos.x += 500.f * fDT * m_vDir.x;
	vPos.y += 500.f * fDT * m_vDir.y;
	SetPos(vPos);
}

void Slash::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	int Width = m_pTex->GetWidth();
	int Height = m_pTex->GetHeight();

	TransparentBlt(_dc
		, (int)(vPos.x - vScale.x / 2)
		, (int)(vPos.y - vScale.y / 2 - 30)
		, vScale.x + 100, vScale.y + 100, m_pTex->GetDC()
		, 0, 0, Width, Height, RGB(255, 255, 255));
	/*Stretchblt(_dc
		, (int)(vPos.x - vScale.x / 2)
		, (int)(vPos.y - vScale.y / 2)
		, Width, Height, m_pTex->GetDC()
		, 0, 0, Width, Height, RGB(255, 255, 255));*/
	Component_Render(_dc);
}
