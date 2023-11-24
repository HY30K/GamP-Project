#include "pch.h"
#include "LeftPlayer.h"
#include "ResMgr.h"
#include "Texture.h"

LeftPlayer::LeftPlayer():
	health(0)
	,coolTime(0)
	,m_pTex(nullptr)
	,leftPlayerState(PlayerState::IDLE)
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"Player", L"Texture\\plane.bmp");
}

LeftPlayer::~LeftPlayer()
{
}

void LeftPlayer::Init()
{
}

void LeftPlayer::Update()
{
}

void LeftPlayer::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	int Width = m_pTex->GetWidth();
	int Height = m_pTex->GetHeight();
	// 1. 기본 옮기기
	BitBlt(_dc
		, (int)(vPos.x - vScale.x / 2)
		, (int)(vPos.y - vScale.y / 2)
		, Width, Height, m_pTex->GetDC()
		, 0, 0, SRCCOPY);

	Component_Render(_dc);
}

void LeftPlayer::GetDamage(UINT damage)
{
}
