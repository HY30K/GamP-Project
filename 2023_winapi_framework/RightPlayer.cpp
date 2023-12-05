#include "pch.h"
#include "RightPlayer.h"
#include "Texture.h"
#include "Core.h"
#include "ResMgr.h"
#include "KeyMgr.h"

RightPlayer::RightPlayer() :
	m_pTex(nullptr)
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"Player", L"Texture\\plane.bmp");
}

RightPlayer::~RightPlayer()
{
}

void RightPlayer::Update()
{
	Vec2 vPos = GetPos();

	if (KEY_PRESS(KEY_TYPE::UP))
	{
		vPos.y -= 1;
		//do jump
	}
	if (KEY_PRESS(KEY_TYPE::LEFT)) {
		vPos.x -= 1;
	}
	if (KEY_PRESS(KEY_TYPE::RIGHT)) {
		vPos.x += 1;
	}
	if (KEY_PRESS(KEY_TYPE::PERIOD)) { //����Ű 1 => �ӽ÷� �س���

	}
	if (KEY_PRESS(KEY_TYPE::COMMA)) { //����Ű 2 => �̰͵� �ӽ÷� �س���

	}

	SetPos(vPos);

}

void RightPlayer::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	int Width = m_pTex->GetWidth();
	int Height = m_pTex->GetHeight();
	// 1. �⺻ �ű��
	BitBlt(_dc
		, (int)(vPos.x - vScale.x / 2)
		, (int)(vPos.y - vScale.y / 2)
		, Width, Height, m_pTex->GetDC()
		, 0, 0, SRCCOPY);

	Component_Render(_dc);
}

void RightPlayer::GetDamage(UINT damage)
{

}
