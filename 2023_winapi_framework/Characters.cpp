#include "pch.h"
#include "Characters.h"
#include "ResMgr.h"
#include "Texture.h"

Characters::Characters()
	: m_pTex(nullptr)
{
	//m_pTex = ResMgr::GetInst()->TexLoad(L"CharImg1", L"UI\Char1.bmp");
}

Characters::~Characters()
{
}

void Characters::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	int Width = m_pTex->GetWidth();
	int Height = m_pTex->GetHeight();

	//1. 기본 옮기기
	BitBlt(_dc
		,(int)(vPos.x - vScale.x /2)
		,(int)(vPos.y - vScale.y /2)
		, Width,Height, m_pTex->GetDC()
		,0,0,SRCCOPY);
}
